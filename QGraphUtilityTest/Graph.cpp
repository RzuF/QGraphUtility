#include "Graph.h"

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
    case AdjencyList:

        break;
    case AdjencyMatrix:

        break;
    case IncidenceList:

        break;
    default:
        break;
    }
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
}

bool Graph::importFromAdjacencyList(Graph::AdjacencyListType adjecencyList)
{
    for(int i = 0; i < adjecencyList.size(); i++)
    {
        addVertex(new Vertex(i));
    }


}

/**
 * @brief Add Vertex* to Graph object and returns index of new added Vertex*. In case of failure to add new Vertex* -1 is returned.
 * @param newVertex Pointer to Vertex object
 * @param force If false vertex mus be connected with the rest of the graph to be added. Default set to TRUE. !!!NOT IMPLEMENTED YET!!!
 * @return
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

int Graph::getNextId()
{
    return this->_nextId++;
}

Vertex *Graph::operator[](int i) const
{
    foreach (auto vertex, _vertexList)
    {
        if(vertex->getId() == i)
            return vertex;
    }
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
