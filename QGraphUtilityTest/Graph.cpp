#include "Graph.h"
#include <QLabel>
#include <QPainter>
#include <QPicture>
#include <ctime>

Graph::GraphException Graph::VertexAlreadyInGraph("Vertex already in Graph object");
Graph::GraphException Graph::VertexNumberCannotBeOneOrLess("Vertex number of random Graph object cannot be one or less");

Graph* Graph::generateRandomGraphFixedEdges(int n, int l)
{
    Graph* newRandomGraph = new Graph;
    for(int i = 0; i < n; i++)
    {
        newRandomGraph->addVertex(new Vertex(i));
    }

    int maxEdgeCount = n*(n-1)/2;
    QList<Edge*> absentEdgeList;

    if(l < maxEdgeCount/2)
    {
        while(newRandomGraph->getEdgeCount() < l)
        {
            auto startVertex = newRandomGraph->operator [](qrand() % n);
            auto endVertex = newRandomGraph->operator [](qrand() % n);
            if(startVertex == endVertex)
                continue;

            if(!newRandomGraph->isVertexesConnected(startVertex, endVertex))
                newRandomGraph->addEdge(new Edge(startVertex, endVertex));
        }
    }
    else
    {
        while(absentEdgeList.size() < maxEdgeCount - l)
        {
            auto startVertex = newRandomGraph->operator [](qrand() % n);
            auto endVertex = newRandomGraph->operator [](qrand() % n);
            if(startVertex == endVertex)
                continue;

            Edge* candidateEdge = new Edge(startVertex, endVertex);
            if(!absentEdgeList.contains(candidateEdge))
                absentEdgeList.append(candidateEdge);
            else
                delete candidateEdge;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                auto startVertex = newRandomGraph->operator [](i);
                auto endVertex = newRandomGraph->operator [](j);

                bool absentEdge = false;
                foreach (auto edge, absentEdgeList)
                {
                    if((edge->getStart() == startVertex && edge->getEnd() == endVertex)
                            || (edge->getStart() == endVertex && edge->getEnd() == startVertex))
                    {
                        absentEdge = true;
                        break;
                    }
                }

                if(!absentEdge)
                {
                    newRandomGraph->addEdge(new Edge(startVertex, endVertex));
                }
            }
        }
    }

    return newRandomGraph;
}

Graph* Graph::generateRandomGraphFixedProbability(int n, double p)
{
    Graph* newRandomGraph = new Graph;
    for(int i = 0; i < n; i++)
    {
        newRandomGraph->addVertex(new Vertex(i));
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            auto startVertex = newRandomGraph->operator [](i);
            auto endVertex = newRandomGraph->operator [](j);

            double probablitity = static_cast<double>(qrand()) / RAND_MAX;

            if(!newRandomGraph->isVertexesConnected(startVertex, endVertex) && probablitity < p)
                newRandomGraph->addEdge(new Edge(startVertex, endVertex));
        }
    }

    return newRandomGraph;
}

Graph *Graph::generateRandomDigraphFixedProbability(int n, double p)
{
    Graph* newRandomGraph = new Graph;
    for(int i = 0; i < n; i++)
    {
        newRandomGraph->addVertex(new Vertex(i));
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i==j)
                continue;

            auto startVertex = newRandomGraph->operator [](i);
            auto endVertex = newRandomGraph->operator [](j);

            double probablitity = static_cast<double>(qrand()) / RAND_MAX;

            if(probablitity < p)
                newRandomGraph->addEdge(new Edge(startVertex, endVertex, true));
        }
    }

    return newRandomGraph;
}

Graph::Graph(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Create Graph object from QString using given format of graph scheme
 * @param source
 * @param format AdjencyList, AdjencyMatrix or IncidenceList
 */

Graph::Graph(QString source, Graph::Format format)
{
    switch (format)
    {
    case AdjacencyList:

        break;
    case AdjacencyMatrix:

        break;
    case IncidenceList:

        break;
    default:
        break;
    }
}

Graph::Graph(const Graph &graph)
{
    _vertexList = graph._vertexList;
    _edgeList = graph._edgeList;
    _nextId = graph._nextId;
}

Graph::~Graph()
{
    foreach (auto vertex, _vertexList)
    {
        if(vertex != nullptr)
        {
            delete vertex;
            vertex = nullptr;
        }
    }

    _vertexList.clear();
    _edgeList.clear();
}

bool Graph::importFromAdjacencyList(Graph::AdjacencyListType adjacencyList, bool digraph)
{
    this->~Graph();

    for(int i = 0; i < adjacencyList.size(); i++)
    {
        addVertex(new Vertex(i));
    }


    for(int i = 0; i < adjacencyList.size(); i++)
    {
        for(int vertex : adjacencyList.at(i))
        {
            addUniqueEdge(new Edge(this->operator [](i), this->operator [](vertex), digraph));
        }
    }

    return true;
}

bool Graph::importFromAdjacencyMatrix(Graph::AdjacenecyMatrixType adjacencyMatrix)
{
    this->~Graph();

    for(int i = 0; i < adjacencyMatrix.size(); i++)
    {
        addVertex(new Vertex(i));
    }

    bool isSymetric = true;
    for(int i = 0; i < adjacencyMatrix.size(); i++)
    {
        for(int j = i; j < adjacencyMatrix.size(); j++)
            if(!(isSymetric = adjacencyMatrix[i][j] == adjacencyMatrix[j][i]))
                break;
    }

    if(isSymetric)
    {
        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            for(int j = i; j < adjacencyMatrix.size(); j++)
            {
                if(adjacencyMatrix[i][j] > 0)
                    addUniqueEdge(new Edge(this->operator [](i), this->operator [](j)));
            }
        }
    }
    else
    {
        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            for(int j = 0; j < adjacencyMatrix.size(); j++)
            {
                if(adjacencyMatrix[i][j] > 0)
                    addUniqueEdge(new Edge(this->operator [](i), this->operator [](j), true));
            }
        }
    }

    return true;
}

bool Graph::importFromIncidenceMatrix(Graph::IncidenceMatrixType incidenceMatrix)
{
    this->~Graph();

    for(int i = 0; i < incidenceMatrix.size(); i++)
    {
        addVertex(new Vertex(i));
    }

    for(int i = 0; i < incidenceMatrix[0].size(); i++)
    {
        addEdge(new Edge(0,0, true));
    }

    for(int i = 0; i < incidenceMatrix.size(); i++)
    {
        for(int j = 0; j < incidenceMatrix[i].size(); j++)
        {
            if(incidenceMatrix[i][j] > 0)
                getEdge(i)->setStart(this->operator [](j));
            if(incidenceMatrix[i][j] < 0)
                getEdge(i)->setEnd(this->operator [](j));
        }
    }

    return true;
}

Graph::AdjacencyListType Graph::exportToAdjacencyList() const
{
    std::vector<std::list<int>> adjacencyList(_vertexList.size());

    for(int i = 0; i < adjacencyList.size(); i++)
    {
        std::list<int> tmpList;
        adjacencyList.at(i) = tmpList;
    }

    for(int i = 0; i < _edgeList.size(); i++)
    {
        if(!_edgeList[i]->isOriented())
            adjacencyList.at(_edgeList[i]->getEnd()->getId()).push_back(_edgeList[i]->getStart()->getId());
        adjacencyList.at(_edgeList[i]->getStart()->getId()).push_back(_edgeList[i]->getEnd()->getId());
    }

    return adjacencyList;
}

Graph::AdjacenecyMatrixType Graph::exportToAdjacenecyMatrix() const
{
    std::vector<std::vector<int>> adjacencyMatrix(_vertexList.size());
    foreach (auto vertexVector, adjacencyMatrix)
    {
        std::vector<int> tmpVector(_vertexList.size(), 0);
        vertexVector = tmpVector;
    }

    for(int i = 0; i < _edgeList.size(); i++)
    {
        adjacencyMatrix[_edgeList[i]->getEnd()->getId()][_edgeList[i]->getStart()->getId()] = _edgeList[i]->getWeight();
        adjacencyMatrix[_edgeList[i]->getStart()->getId()][_edgeList[i]->getEnd()->getId()] = _edgeList[i]->isOriented() ? 0 : _edgeList[i]->getWeight();
    }

    return adjacencyMatrix;
}

Graph::IncidenceMatrixType Graph::exportToIncidenceMatrix() const
{
    std::vector<std::vector<int>> incidenceMatrix(_vertexList.size());
    foreach (auto vertexVector, incidenceMatrix)
    {
        std::vector<int> tmpVector(_edgeList.size(), 0);
        vertexVector = tmpVector;
    }

    for(int i = 0; i < _edgeList.size(); i++)
    {
        incidenceMatrix[i][_edgeList[i]->getStart()->getId()] = _edgeList[i]->getWeight();
        incidenceMatrix[i][_edgeList[i]->getEnd()->getId()] = _edgeList[i]->isOriented() ? -_edgeList[i]->getWeight() : _edgeList[i]->getWeight();
    }

    return incidenceMatrix;
}

/**
 * @brief Add Vertex* to Graph object.
 * @param newVertex Pointer to Vertex object
 * @param force If false vertex must be connected with the rest of the graph to be added. Default set to TRUE. !!!NOT IMPLEMENTED YET!!!
 * @return Returns index of new added Vertex*. In case of failure to add new Vertex* -1 is returned.
 */

int Graph::addVertex(Vertex *newVertex, bool force)
{
    int index = -1;

    if(!_vertexList.contains(newVertex))
    {
        _vertexList.append(newVertex);
        index = _vertexList.indexOf(newVertex);
    }
    else
        throw VertexAlreadyInGraph;

    foreach (auto edge, newVertex->getEdges())
    {
        if(!_edgeList.contains(edge))
            _edgeList.append(edge);
    }

    return index;
}

int Graph::getVertexCount() const
{
    return _vertexList.size();
}

int Graph::getEdgeCount() const
{
    return _edgeList.size();
}

int Graph::getNextId()
{
    return this->_nextId++;
}

Edge *Graph::getEdge(int i) const
{
    return _edgeList[i];
}

Vertex *Graph::operator[](int i) const
{
    foreach (auto vertex, _vertexList)
    {
        if(vertex->getId() == i)
            return vertex;
    }

    return nullptr;
}

Graph* Graph::generateRandomGraph(int n, double l, Graph::RandomGraph method)
{
    if(n < 2)
        throw VertexNumberCannotBeOneOrLess;

    qsrand(time(NULL));

    if(method == Graph::RandomGraph::FixedEdges)
        return Graph::generateRandomGraphFixedEdges(n, l);

    if(method == Graph::RandomGraph::FixedProbability)
        return Graph::generateRandomGraphFixedProbability(n, l);

    if(method == Graph::RandomGraph::DigraphFixedProbability)
        return Graph::generateRandomDigraphFixedProbability(n, l);
}

void Graph::drawGraph(QLabel* label, int radius) const
{
    QPicture myPicture;
    QPainter painter(&myPicture);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
    painter.setBrush(QBrush(Qt::white));
    QFont font(painter.font());
    font.setBold(true);
    painter.setFont(font);

    double angleDelta = 2 * 3.14159265358979323846 / _vertexList.size();

    typedef QPair<int, int> VertexPoint;
    typedef QMap<Vertex*, QPointF> VertexWithPosition;

    VertexWithPosition listOfPoints;

    for(int i = 0; i < _vertexList.size(); i++)
    {
        listOfPoints.insert(this->_vertexList.at(i), QPointF(radius + radius*cos(i*angleDelta), radius + radius*sin(i*angleDelta)));
    }

    foreach (auto edge, _edgeList)
    {
        painter.drawLine(listOfPoints[edge->getStart()], listOfPoints[edge->getEnd()]);
        if(edge->isOriented())
        {
            QLineF currentEdgeReversed(listOfPoints[edge->getEnd()], listOfPoints[edge->getStart()]);
            QLineF wingLeft = QLineF::fromPolar(30, currentEdgeReversed.angle() + 15).translated(listOfPoints[edge->getEnd()]);
            QLineF wingRight = QLineF::fromPolar(30, currentEdgeReversed.angle() - 15).translated(listOfPoints[edge->getEnd()]);
            painter.drawLine(wingLeft);
            painter.drawLine(wingRight);
        }
    }

    foreach (auto vertex, _vertexList)
    {
        double ellipseRadius = 15;
        painter.drawEllipse(listOfPoints[vertex], ellipseRadius, ellipseRadius);
        painter.drawText(QRectF(listOfPoints[vertex] - QPointF(ellipseRadius, ellipseRadius), 
                                listOfPoints[vertex] + QPointF(ellipseRadius, ellipseRadius)),
                         Qt::AlignVCenter | Qt::AlignHCenter, 
                         QString::number(vertex->getId()));
    }

    painter.end();

    label->setPicture(myPicture);
    label->show();
}

/**
 * @brief Add Edge* to Graph object and returns bool true adding was successful
 * @param newEdge Pointer to Edge object
 * @param force If false edge mus be connected with the rest of the graph to be added. Default set to TRUE. !!!NOT IMPLEMENTED YET!!!
 * @return
 */

bool Graph::addEdge(Edge *newEdge, bool force)
{
    bool success = false;

    if(!(success = _edgeList.contains(newEdge)))
        _edgeList.append(newEdge);

    if(!_vertexList.contains(newEdge->getStart()))
        _vertexList.append(newEdge->getStart());

    if(!_vertexList.contains(newEdge->getEnd()))
        _vertexList.append(newEdge->getEnd());

    return success;
}

bool Graph::addUniqueEdge(Edge *newEdge)
{
    bool success = false, alreadyInGraph = false;

    foreach (auto edge, newEdge->getEnd()->getEdges())
    {
        if(edge->getEnd() == newEdge->getStart())
        {
            alreadyInGraph = true;
            break;
        }
    }

    if(success = (!_edgeList.contains(newEdge)) && !alreadyInGraph)
        _edgeList.append(newEdge);

    return success;
}

bool Graph::isVertexesConnected(Vertex *start, Vertex *end, bool oriented)
{
    foreach (auto edge, _edgeList)
    {
        if(edge->getStart() == start && edge->getEnd() == end)
            return true;
        if(!oriented && edge->getStart() == end && edge->getEnd() == start)
            return true;
    }

    return false;
}
