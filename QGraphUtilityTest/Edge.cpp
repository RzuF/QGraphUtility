#include "Edge.h"

Edge::Edge(Vertex * start, Vertex * end, bool oriented) : _start(start), _end(end), _weight(0), _oriented(oriented)
{
}

Edge::Edge(Vertex * start, Vertex * end, int weight, bool oriented) : _start(start), _end(end), _weight(weight), _oriented(oriented)
{	
}

Edge::~Edge()
{
}
