#include "Edge.h"

Edge::Edge(Vertex* start, Vertex * end, bool oriented) : _start(start), _end(end), _weight(0), _oriented(oriented)
{
    if(start != nullptr)
        start->addEdge(this);
    if(end != nullptr)
        end->addEdge(this);

    _weight = 1;
}

Edge::Edge(Vertex* start, Vertex * end, int weight, bool oriented) : _start(start), _end(end), _weight(weight), _oriented(oriented)
{	
    if(start != nullptr)
        start->addEdge(this);
    if(end != nullptr)
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

int Edge::getWeight() const
{
    return _weight;
}

bool Edge::isOriented() const
{
    return _oriented;
}

bool Edge::setStart(Vertex *start)
{
    if(this->_start == nullptr)
        _start = start;

    return true;
}

bool Edge::setEnd(Vertex *end)
{
    if(this->_end == nullptr)
        _end = end;

    return true;
}
