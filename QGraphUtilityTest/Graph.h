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
    static Graph* generateRandomKRegularGraphFixedDegree(int n, int k);
    static Graph* generateRandomGraphEulerCycle(int n);

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
        IncidenceList,
        Sequence
    };

    enum RandomGraph
    {
        FixedEdges,
        FixedProbability,
        DigraphFixedProbability,
        KRegularFixedDegree,
        EulerCycle
    };

    //Typedefs
    typedef std::vector<std::list<int>> AdjacencyListType;
    typedef std::vector<std::vector<int>> AdjacenecyMatrixType;
    typedef std::vector<std::vector<int>> IncidenceMatrixType;
    typedef std::vector<int> SequenceType;

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
    bool importFromSequence(SequenceType sequence);

    //Export methods
    AdjacencyListType exportToAdjacencyList() const;
    AdjacenecyMatrixType exportToAdjacenecyMatrix() const;
    IncidenceMatrixType exportToIncidenceMatrix() const;

    bool importFromString(QString source, Graph::Format format);

    //Modifiers methods
    int addVertex(Vertex* newVertex, bool force = true);
    bool addEdge(Edge* newEdge, bool force = true);
    bool addUniqueEdge(Edge* newEdge);
    bool removeVertex(Vertex* vertex);
    bool removeEdge(Edge* edge);

    void setRandomWeights(int start, int end);
    void restoreDegreeOfVertexes();

    void replaceEdges(Edge* firstEdge, Edge* secondEdge);
    void randomizeGraphBySwitchingEdges(int changes = 0);

    //State announcers
    bool isVertexesConnected(Vertex* start, Vertex* end, bool oriented = false);
    bool isWeighted() const;
    bool isConnected() const;

    //Getters
    int getVertexCount() const;
    int getEdgeCount() const;
    int getNextId();
    Edge* getEdge(int i) const;

    std::vector<Vertex*> getNonZeroDegreeVertexes() const;

    Vertex *operator[](int i) const;

    //Static public method for random
    static Graph* generateRandomGraph(int n, double l, RandomGraph method);

    //Drawing methods
    void drawGraph(QLabel* label, bool colorize = false, int radius = 200) const;

    //Algorith methos
    Graph* Prim(QLabel* label, int startVertex);
    int Kosaraju(QLabel* label);
    std::vector<int> Dijkstra(QLabel* label, int startVertex = 0);
    std::vector<int> BellmanFord(QLabel* label, int startVertex = 0);
    bool Johnson(QLabel* label, bool original = false);
    bool DistanceMatrix(QLabel* label);
    std::stack<int> GreatestConnectedCompound(QLabel* label);
    std::stack<int> FindEulerCycle(QLabel* label);


signals:

public slots:
};

#endif // GRAPH_H
