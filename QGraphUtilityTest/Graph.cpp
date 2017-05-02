#include "Graph.h"
#include <QLabel>
#include <QPainter>
#include <QPicture>
#include <QtDebug>
#include <QDebug>
#include <ctime>
#include <stack>
#include <climits>
#include <queue>
#include <functional>
#include <QPointer>

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

    //_vertexList.clear();
    //_edgeList.clear();
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

bool Graph::importFromAdjacencyMatrix(Graph::AdjacenecyMatrixType adjacencyMatrix, bool digraph)
{
    //this->~Graph();

    for(int i = 0; i < adjacencyMatrix.size(); i++)
    {
        addVertex(new Vertex(i));
    }

    bool isSymetric = true;
    if(!digraph)
    {
        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            for(int j = i; j < adjacencyMatrix.size(); j++)
                if(!(isSymetric = adjacencyMatrix[i][j] == adjacencyMatrix[j][i]))
                    break;
            if(!isSymetric)
                break;
        }
    }
    else
        isSymetric = false;

    if(isSymetric)
    {
        for(int i = 0; i < adjacencyMatrix.size(); i++)
        {
            for(int j = i; j < adjacencyMatrix.size(); j++)
            {
                if(adjacencyMatrix[i][j] != 0)
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
                if(adjacencyMatrix[i][j] != 0)
                    addEdge(new Edge(this->operator [](i), this->operator [](j), adjacencyMatrix[i][j], true));
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
    for(int i = 0; i < _vertexList.size(); i++)
        adjacencyMatrix[i] = std::vector<int>(_vertexList.size(), 0);

    for(int i = 0; i < _edgeList.size(); i++)
    {
        adjacencyMatrix[_edgeList[i]->getStart()->getId()][_edgeList[i]->getEnd()->getId()] = _edgeList[i]->getWeight();
        if(!_edgeList[i]->isOriented())
            adjacencyMatrix[_edgeList[i]->getEnd()->getId()][_edgeList[i]->getStart()->getId()] = _edgeList[i]->getWeight();
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

void Graph::drawGraph(QLabel* label, bool colorize, int radius) const
{
    QPicture myPicture;
    QPainter painter(&myPicture);
    QBrush brush(Qt::black);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(brush, 3, Qt::SolidLine, Qt::RoundCap));
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

    bool drawWeights = isWeighted();
    int color = 2;

    foreach (auto edge, _edgeList)
    {
        if(colorize)
        {
            color++;
            brush.setColor(static_cast<Qt::GlobalColor>(color % 17 + 2));
            painter.setBrush(brush);
            painter.setPen(QPen(brush, 3, Qt::SolidLine, Qt::RoundCap));
        }
        painter.drawLine(listOfPoints[edge->getStart()], listOfPoints[edge->getEnd()]);
        if(edge->isOriented())
        {
            QLineF currentEdgeReversed(listOfPoints[edge->getEnd()], listOfPoints[edge->getStart()]);
            QLineF wingLeft = QLineF::fromPolar(30, currentEdgeReversed.angle() + 10).translated(listOfPoints[edge->getEnd()]);
            QLineF wingRight = QLineF::fromPolar(30, currentEdgeReversed.angle() - 10).translated(listOfPoints[edge->getEnd()]);
            QPointF arrow[3] = {wingLeft.p2(), wingRight.p2(), currentEdgeReversed.p1()};
            painter.drawPolygon(arrow, 3);
        }
        if(drawWeights)
        {
            QLineF currentEdgeReversed(listOfPoints[edge->getEnd()], listOfPoints[edge->getStart()]);
            QLineF textLine = QLineF::fromPolar(15, currentEdgeReversed.angle() + 90).translated(listOfPoints[edge->getStart()] + (listOfPoints[edge->getEnd()] - listOfPoints[edge->getStart()])/2);

            painter.drawText(textLine.p2(), QString::number(edge->getWeight()));
        }

    }

    painter.setBrush(QBrush(Qt::white));
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));

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

Graph* Graph::Prim(QLabel *label, int startVertex)
{
    auto compareLambda = [&](Edge* first, Edge* second)->bool {return first->getWeight() > second->getWeight();};
    std::priority_queue<Edge*, std::vector<Edge*>, decltype(compareLambda)> edgeQueue(compareLambda);

    foreach (auto vertex, _vertexList)
    {
        vertex->UnVisit();
    }

    Graph* minimumSpanningTree = new Graph;

    _vertexList[startVertex]->Visit();

    Vertex* currentVertex = _vertexList[startVertex];

    for(int i = 0; i < _vertexList.size() - 1; i++)
    {
        foreach(auto edge, currentVertex->getEdges())
        {
            if(edge->getStart() != currentVertex)
                continue;

            if(!edge->getEnd()->isVisited())
                edgeQueue.push(edge);
        }

        Edge* currentEdge = edgeQueue.top();
        edgeQueue.pop();

        if(currentEdge->getEnd()->isVisited())
            continue;

        minimumSpanningTree->addEdge(currentEdge);
        currentEdge->getEnd()->Visit();

        currentVertex = currentEdge->getEnd();
    }

    return minimumSpanningTree;
}

int Graph::Kosaraju(QLabel* label)
{
    foreach (auto vertex, _vertexList)
    {
        vertex->UnVisit();
    }

    QString output;

    std::stack<int> Stack;

    foreach(auto vertex, _vertexList)
    {
        if(!vertex->isVisited())
            vertex->DFS(Stack);
    }

    auto adjacencyMatrix = this->exportToAdjacenecyMatrix();
    for(int i = 0; i < _vertexList.size(); i++)
    {
        for(int j = i+1; j < _vertexList.size(); j++)
        {
            int tmp = adjacencyMatrix[i][j];
            adjacencyMatrix[i][j] = adjacencyMatrix[j][i];
            adjacencyMatrix[j][i] = tmp;
        }
    }

    Graph TransponatedGraph;
    TransponatedGraph.importFromAdjacencyMatrix(adjacencyMatrix, true);

    int StrongConnectedComponentCounter = 0;
    int maxSCC = 0;

    while(!Stack.empty())
    {
        int currentId = Stack.top();
        Stack.pop();
        if(TransponatedGraph[currentId]->isVisited())
            continue;

        StrongConnectedComponentCounter++;
        std::stack<int> currentMembersOfSCC;

        TransponatedGraph[currentId]->DFS(currentMembersOfSCC, true);

        if(currentMembersOfSCC.size() > maxSCC)
            maxSCC = currentMembersOfSCC.size();

        output.append(QString::number(StrongConnectedComponentCounter)).append(" : ");
        while(!currentMembersOfSCC.empty())
        {
            int currentId = currentMembersOfSCC.top();
            currentMembersOfSCC.pop();
            output.append(QString::number(currentId)).append(", ");
        }
        output.append("\n");
    }

    label->setText(output);

    return maxSCC;
}

std::vector<int> Graph::Dijkstra(QLabel *label, int startVertex)
{
    QList<Vertex*> unvisited =_vertexList;

    std::vector<int> distance(_vertexList.size(), _edgeList.size() * 100);
    std::vector<int> predecessor(_vertexList.size(), -1);
    distance[startVertex] = 0;

    while(!unvisited.empty())
    {
        Vertex* minDistanceVertex = unvisited[0];
        foreach (auto vertex, unvisited)
        {
            if(distance[minDistanceVertex->getId()] > distance[vertex->getId()])
                minDistanceVertex = vertex;
        }

        unvisited.removeOne(minDistanceVertex);

        foreach (auto edge, minDistanceVertex->getEdges())
        {
            if(edge->getStart() != _vertexList[minDistanceVertex->getId()])
                continue;

            if(!unvisited.contains(edge->getEnd()))
                continue;

            if(distance[edge->getEnd()->getId()] > distance[edge->getStart()->getId()] + edge->getWeight())
            {
                distance[edge->getEnd()->getId()] = distance[edge->getStart()->getId()] + edge->getWeight();
                predecessor[edge->getEnd()->getId()] = edge->getStart()->getId();
            }
        }
    }


    QString output = "Results of Dijkstra algorithm:\n\n";
    for(int i = 0; i < distance.size(); i++)
    {
        output.append("Vertex ").append(QString::number(i)).append(" distance: ").append(QString::number(distance[i])).append("; predecessor: ").append(QString::number(predecessor[i])).append("\n");
    }

    if(label != 0)
        label->setText(output);

    return distance;
}

std::vector<int> Graph::BellmanFord(QLabel *label, int startVertex)
{
    std::vector<int> distance(_vertexList.size(), _edgeList.size() * 100);
    std::vector<int> predecessor(_vertexList.size(), -1);
    distance[startVertex] = 0;

    for(int i = 1; i < _vertexList.size(); i++)
    {
        bool NoChange = true;

        for(int j = 0; j < _vertexList.size(); j++)
        {
            foreach(auto edge, _vertexList[j]->getEdges())
            {
                if(edge->getStart() != _vertexList[j])
                    continue;
                if(distance[edge->getEnd()->getId()] > distance[j] + edge->getWeight())
                {
                    NoChange = false;
                    distance[edge->getEnd()->getId()] = distance[j] + edge->getWeight();
                    predecessor[edge->getEnd()->getId()] = j;
                }
            }
        }
        if(NoChange)
            break;
    }

    bool negativeCycle = false;
    for(int j = 0; j < _vertexList.size(); j++)
    {
        foreach(auto edge, _vertexList[j]->getEdges())
        {
            if(edge->getStart() != _vertexList[j])
                continue;
            if(distance[edge->getEnd()->getId()] > distance[j] + edge->getWeight())
            {
                negativeCycle = true;
                break;
            }
        }
        if(negativeCycle)
            break;
    }

    if(negativeCycle)
    {
        if(label != 0)
            label->setText("Negative cycle occured!");
        distance.clear();
    }
    else
    {
        QString output = "Results of Bellman-Ford algorithm:\n\n";
        for(int i = 0; i < distance.size(); i++)
        {
            output.append("Vertex ").append(QString::number(i)).append(" distance: ").append(QString::number(distance[i])).append("; predecessor: ").append(QString::number(predecessor[i])).append("\n");
        }

        if(label != 0)
            label->setText(output);
    }

    return distance;
}

bool Graph::Johnson(QLabel *label, bool original)
{
    //Bottom line for debug purposes!
    //drawGraph(label, true);
    //*******************************

    QPointer<Graph> currentGraph;

    if(original)
    {
        currentGraph = new Graph;
        currentGraph->importFromAdjacencyMatrix(this->exportToAdjacenecyMatrix(), true);
    }
    else
        currentGraph = this;

    int qId = currentGraph->addVertex(new Vertex(currentGraph->getVertexCount(), "Johnson node"));
    for(int i = 0; i < currentGraph->getVertexCount() - 1; i++)
    {
        currentGraph->addEdge(new Edge(currentGraph->operator [](qId), currentGraph->operator [](i), 0, true));
    }

    auto distance = currentGraph->BellmanFord(0, qId);
    if(distance.empty())
        return false;

    for(int i = 0; i < currentGraph->getEdgeCount(); i++)
    {
        currentGraph->getEdge(i)->setWeight(currentGraph->getEdge(i)->getWeight() + distance[currentGraph->getEdge(i)->getStart()->getId()] - distance[currentGraph->getEdge(i)->getEnd()->getId()]);
    }

    currentGraph->removeVertex(currentGraph->operator [](qId));

    QString output = "Results of Johnson algorithm:\n\n";

    for(int i = 0; i < currentGraph->getVertexCount(); i++)
    {
        auto distance = currentGraph->Dijkstra(0, i);

        for(int j = 0; j < distance.size(); j++)
        {
            output.append("Path (").append(QString::number(i)).append("-").append(QString::number(j)).append(") distance: ").append(QString::number(distance[j])).append("; ");
        }
        output.append("\n");
    }

    if(label != 0)
        label->setText(output);

    return true;
}

bool Graph::DistanceMatrix(QLabel *label)
{
    QPointer<Graph> currentGraph = this;

    std::vector<std::vector<int>> distanceMatrix;
    int centerVertexIndex = -1, minmaxVertexIndex = -1;
    int centerVertexValue = INT_MAX, minmaxVertexValue = INT_MAX;

    QString output = "Distance Matrix of Dijkstra algorithm:\n\n";

    for(int i = 0; i < currentGraph->getVertexCount(); i++)
    {
        auto distance = currentGraph->Dijkstra(0, i);
        distanceMatrix.push_back(distance);
        int currentDistanceValue = 0;
        int currentMaxDistanceValue = distance[0];

        output.append(QString::number(i)).append(" | ");

        for(int j = 0; j < distance.size(); j++)
        {
            currentDistanceValue += distance[j];
            if(currentMaxDistanceValue < distance[j])
                currentMaxDistanceValue = distance[j];

            output.append(QString::number(distance[j])).append(" ");
        }
        //Bottom line for debug purposes!
        //output.append("= ").append(QString::number(currentDistanceValue)).append(" | ").append(QString::number(currentMaxDistanceValue));
        //*******************************

        output.append("\n");

        if(centerVertexValue > currentDistanceValue)
        {
            centerVertexValue = currentDistanceValue;
            centerVertexIndex = i;
        }

        if(minmaxVertexValue > currentMaxDistanceValue)
        {
            minmaxVertexValue = currentMaxDistanceValue;
            minmaxVertexIndex = i;
        }
    }

    output.append("\nCenter vertex: ").append(QString::number(centerVertexIndex)).append("\nMinmax center vertex: ").append(QString::number(minmaxVertexIndex));

    if(label != 0)
        label->setText(output);

    return true;
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

bool Graph::removeVertex(Vertex *vertex)
{
    for(int i = 0; i < vertex->getEdges().size(); i++)
    {
        removeEdge(vertex->getEdges()[i]);
    }
    vertex->clearEdgeList();

    _vertexList.removeOne(vertex);

    delete vertex;

    return true;
}

bool Graph::removeEdge(Edge *edge)
{
    edge->getStart()->getEdges().removeOne(edge);
    edge->getEnd()->getEdges().removeOne(edge);

    edge->getStart()->getNeighbours().removeOne(edge->getEnd());
    if(!edge->isOriented())
        edge->getEnd()->getNeighbours().removeOne(edge->getStart());

    _edgeList.removeOne(edge);

    delete edge;

    return true;
}

void Graph::setRandomWeights(int start, int end)
{
    for(int i = 0; i < _edgeList.size(); i++)
        _edgeList[i]->setWeight(qrand() % (end - start) + start);
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

bool Graph::isWeighted() const
{
    foreach(auto edge, _edgeList)
        if(edge->getWeight() != 1)
            return true;

    return false;
}

bool Graph::isConnected() const
{
    foreach (auto vertex, _vertexList)
    {
        if(vertex->getEdges().size() < 1)
            return false;
    }

    return true;
}
