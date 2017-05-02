#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <exception>
#include <QLabel>
#include "QList"
#include "Edge.h"


class Graph : public QObject
{
    Q_OBJECT

    QList<Vertex*> _vertexList;
    QList<Edge*> _edgeList;

    int _nextId = 1;

    static Graph* generateRandomGraphFixedEdges(int n, int l);
    static Graph* generateRandomGraphFixedProbability(int n, double p);
    static Graph* generateRandomDigraphFixedProbability(int n, double p);

public:
    class GraphException: public std::exception
    {
        const char* _message;

    public:
        GraphException(const char* message) : _message(message) {}

        virtual const char* what() const throw()
        {
            return _message;
        }
    };

    enum Format
    {
        AdjacencyList,
        AdjacencyMatrix,
        IncidenceList
    };

    enum RandomGraph
    {
        FixedEdges,
        FixedProbability,
        DigraphFixedProbability
    };

    //Typedefs
    typedef std::vector<std::list<int>> AdjacencyListType;
    typedef std::vector<std::vector<int>> AdjacenecyMatrixType;
    typedef std::vector<std::vector<int>> IncidenceMatrixType;

    //Exceptions
    static GraphException VertexAlreadyInGraph;
    static GraphException VertexNumberCannotBeOneOrLess;

    //Constructors and destructors
    explicit Graph(QObject *parent = 0);
    Graph(QString source, Graph::Format format);
    Graph(const Graph& graph);
    ~Graph();

    //Import methods
    bool importFromAdjacencyList(AdjacencyListType adjacencyList, bool digraph = false);
    bool importFromAdjacencyMatrix(AdjacenecyMatrixType adjacencyMatrix, bool digraph = false);
    bool importFromIncidenceMatrix(IncidenceMatrixType incidenceMatrix);

    //Export methods
    AdjacencyListType exportToAdjacencyList() const;
    AdjacenecyMatrixType exportToAdjacenecyMatrix() const;
    IncidenceMatrixType exportToIncidenceMatrix() const;

    bool importFromString(QString source, Graph::Format format);

    //Modifiers methods
    int addVertex(Vertex* newVertex, bool force = true);
    bool addEdge(Edge* newEdge, bool force = true);
    bool addUniqueEdge(Edge* newEdge);

    void setRandomWeights(int start, int end);

    //State announcers
    bool isVertexesConnected(Vertex* start, Vertex* end, bool oriented = false);
    bool isWeighted() const;

    //Getters
    int getVertexCount() const;
    int getEdgeCount() const;
    int getNextId();
    Edge* getEdge(int i) const;

    Vertex *operator[](int i) const;

    //Static public method for random
    static Graph* generateRandomGraph(int n, double l, RandomGraph method);

    //Drawing methods
    void drawGraph(QLabel* label, bool colorize = false, int radius = 200) const;

    //Algorith methos
    int Kosaraju(QLabel* label);
    bool BellmanFord(QLabel* label, int startVertex = 0);


signals:

public slots:
};

#endif // GRAPH_H
