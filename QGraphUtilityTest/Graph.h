#ifndef GRAPH_H
#define GRAPH_H

#include "QList"
#include "Edge.h"


class Graph : public QObject
{
    Q_OBJECT

    QList<Vertex*> _vertexList;
    QList<Edge*> _edgeList;

    int _nextId = 1;

    static Graph generateRandomGraphFixedEdges(int n, int l);
    static Graph generateRandomGraphFixedProbability(int n, int p);

public:
    enum Format
    {
        AdjencyList,
        AdjencyMatrix,
        IncidenceList
    };

    enum RandomGraph
    {
        FixedEdges,
        FixedProbability
    };

    explicit Graph(QObject *parent = 0);

    Graph(QString source, Graph::Format format);
    ~Graph();

    bool importFromAdjencyList();
    bool importFromAdjencyMatrix();
    bool importFromIncidenceMatrix();

    bool importFromString(QString source, Graph::Format format);

    int addVertex(Vertex* newVertex, bool force = true);
    bool addEdge(Edge* newEdge, bool force = true);

    int getVertexCount() const;
    int getNextId();

    Vertex *operator[](int i) const;

    static Graph generateRandomGraph(int n, int l, RandomGraph method);


signals:

public slots:
};

#endif // GRAPH_H
