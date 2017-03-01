#include "Vertex.h"

Vertex::Vertex(int id, QString name) : _id(id), _edges(QList<Edge*>()), _name(name)
{
	_id = id;	
	_name = name;
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
}
