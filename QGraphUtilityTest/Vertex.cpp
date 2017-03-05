#include "Vertex.h"
#include "Edge.h"

Vertex::Vertex(int id, QString name) : _id(id), _edges(QList<Edge*>()), _name(name)
{
}

Vertex::Vertex(int id, QList<Edge*> edges, QString name) : _id(id), _edges(edges), _name(name)
{
}

Vertex::Vertex(int id, Edge* edge, QString name) : _id(id), _edges(QList<Edge*>()), _name(name)
{
	_edges.append(edge);
}

Vertex::~Vertex()
{
	for each (auto edge in _edges)
	{
		edge->getStart()->_edges.removeOne(edge);
		edge->getEnd()->_edges.removeOne(edge);

		delete edge;
	}
}
