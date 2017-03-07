#include "Edge.h"

Edge::Edge(Vertex* start, Vertex * end, bool oriented) : _start(start), _end(end), _weight(0), _oriented(oriented)
{
    start->addEdge(this);
    end->addEdge(this);
}

Edge::Edge(Vertex* start, Vertex * end, int weight, bool oriented) : _start(start), _end(end), _weight(weight), _oriented(oriented)
{	
    start->addEdge(this);
    end->addEdge(this);
}

Edge::~Edge()
{
}

Vertex* Edge::getStart() const
{
	return _start;
}

Vertex* Edge::getEnd() const
{
	return _end;
}
