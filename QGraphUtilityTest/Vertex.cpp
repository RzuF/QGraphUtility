#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(int id, QString name) : _id(id), _edges(QList<Edge*>()), _name(name)
{
}

Vertex::Vertex(int id, QList<Edge*> edges, QString name) : _id(id), _edges(edges), _name(name)
{
}

Vertex::Vertex(int id, Edge* edge, QString name) : _id(id), _name(name)
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

void Vertex::addEdge(Edge *newEdge)
{
    if((newEdge->getStart() == this || newEdge->getEnd() == this) && !_edges.contains(newEdge))
        _edges.append(newEdge);
}
