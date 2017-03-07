#include "QGraphUtilityTest.h"
#include "Graph.h"

QGraphUtilityTest::QGraphUtilityTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    Graph myTestGraph;

    myTestGraph.addEdge(new Edge(new Vertex(myTestGraph.getNextId()), new Vertex(myTestGraph.getNextId())));
    myTestGraph.addVertex(new Vertex(myTestGraph.getNextId()));

    auto myEdge = new Edge(myTestGraph[0], myTestGraph[2]);
    myTestGraph.addEdge(myEdge);
}
