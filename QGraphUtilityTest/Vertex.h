#pragma once

#include <QObject>

class Edge;

class Vertex : public QObject
{
	Q_OBJECT

	int _id;
	QString _name;
	QList<Edge*> _edges;	
    QList<Vertex*> _neighbours;

    bool _visited;

public:
	Vertex(int id, QString name = "noName");
	Vertex(int id, QList<Edge*> edges, QString name = "noName");
	Vertex(int id, Edge* edge, QString name = "noName");
	~Vertex();

    QList<Edge*> getEdges() const;
    QList<Vertex*> getNeighbours() const;

    void addNeighbour(Vertex* newNeighbour);
    void addEdge(Edge* newEdge);
    void deleteNeighbour(Vertex* neighbour);

    void Visit();
    void UnVisit();

    int getId() const;
    bool isVisited() const;
};
