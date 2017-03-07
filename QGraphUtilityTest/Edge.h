#pragma once

#include <QObject>
#include "Vertex.h"

class Edge : public QObject
{
	Q_OBJECT

	Vertex* _start;
	Vertex* _end;

	bool _oriented;
	int _weight;

public:
	Edge(Vertex* start, Vertex* end, bool oriented = false);
	Edge(Vertex* start, Vertex* end, int weight, bool oriented = false);
	~Edge();

    Vertex* getStart() const;
    Vertex* getEnd() const;
};
