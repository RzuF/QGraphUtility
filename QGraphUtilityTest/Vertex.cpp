#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(int id, QString name) : _id(id), _edges(QList<Edge*>()), _name(name), _visited(false)
{
}

Vertex::Vertex(int id, QList<Edge*> edges, QString name) : _id(id), _edges(edges), _name(name), _visited(false)
{
}

Vertex::Vertex(int id, Edge* edge, QString name) : _id(id), _name(name), _visited(false)
{
	_edges.append(edge);
}

Vertex::~Vertex()
{
    foreach (auto edge, _edges)
	{
		edge->getStart()->_edges.removeOne(edge);
		edge->getEnd()->_edges.removeOne(edge);

        if(edge != nullptr)
        {
            delete edge;
            edge = nullptr;
        }
    }
}

QList<Edge *> Vertex::getEdges() const
{
    return _edges;
}

QList<Vertex *> Vertex::getNeighbours() const
{
    return _neighbours;
}

void Vertex::addNeighbour(Vertex *newNeighbour)
{
    if(!_neighbours.contains(newNeighbour))
        _neighbours.append(newNeighbour);
}

void Vertex::addEdge(Edge *newEdge)
{
    if((newEdge->getStart() == this || newEdge->getEnd() == this) && !_edges.contains(newEdge))
        _edges.append(newEdge);
}

void Vertex::deleteNeighbour(Vertex *neighbour)
{
    if(_neighbours.contains(neighbour))
        _neighbours.removeAll(neighbour);
}

void Vertex::Visit()
{
    _visited = true;
}

void Vertex::UnVisit()
{
    _visited = false;
}

void Vertex::DFS(std::stack<int> &currentStack, bool reverse)
{
    _visited = true;
    if(reverse)
        currentStack.push(_id);
    foreach (auto vertex, _neighbours)
    {
        if(!vertex->isVisited())
            vertex->DFS(currentStack, reverse);
    }
    if(!reverse)
        currentStack.push(_id);
}

int Vertex::getId() const
{
    return _id;
}

bool Vertex::isVisited() const
{
    return _visited;
}
