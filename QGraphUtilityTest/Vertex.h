#pragma once

#include <QObject>

class Edge;

class Vertex : public QObject
{
	Q_OBJECT

	int _id;
	QString _name;
	int _weight;
	QList<Edge*> _edges;	

public:
	Vertex(int id, QString name = "noName");
	Vertex(int id, QList<Edge*> edges, QString name = "noName");
	Vertex(int id, Edge* edge, QString name = "noName");
	~Vertex();


};
