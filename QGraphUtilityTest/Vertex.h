#pragma once

#include <QObject>
#include <stack>

class Edge;

class Vertex : public QObject
{
	Q_OBJECT

	int _id;
	QString _name;
	QList<Edge*> _edges;	
    QList<Vertex*> _neighbours;

    bool _visited;

    int _degree;

public:
    Vertex(int id, QString name = "noName");
    Vertex(int id, int degree, QString name = "noName");
	Vertex(int id, QList<Edge*> edges, QString name = "noName");
	Vertex(int id, Edge* edge, QString name = "noName");
	~Vertex();

    QList<Edge*> getEdges() const;
    QList<Vertex*> getNeighbours() const;

    void addNeighbour(Vertex* newNeighbour);
    void addEdge(Edge* newEdge);
    void deleteNeighbour(Vertex* neighbour);
    void deleteEdge(Edge* edge);
    void clearEdgeList();

    void Visit();
    void UnVisit();

    void DFS(std::stack<int>& currentStack, bool reverse = false);

    int getId() const;
    bool isVisited() const;

    int getDegree() const;
    void setDegree(int degree);
    void reduceDegree();
};
