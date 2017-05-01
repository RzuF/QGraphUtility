#include "QGraphUtilityTest.h"
#include "Graph.h"

#include <QMessageBox>
#include <QPainter>
#include <QPicture>
#include <QPointer>

QGraphUtilityTest::QGraphUtilityTest(QWidget *parent)
	: QMainWindow(parent)
{
    ui.setupUi(this);

    ui.vertexSpinBox->setValue(5);
    ui.probabilitySpinBox->setValue(0.5);
    ui.graphTypeComboBox->setCurrentIndex(1);
}

void QGraphUtilityTest::on_generateButton_clicked()
{
    QPointer<Graph> randomGraph;

    try
    {
        switch(ui.graphTypeComboBox->currentIndex())
        {
        case 0:
            randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.edgeSpinBox->value(), Graph::RandomGraph::FixedEdges);
            break;
        case 1:
            randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.probabilitySpinBox->value(), Graph::RandomGraph::DigraphFixedProbability);
            break;
        case 2:
            randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.probabilitySpinBox->value(), Graph::RandomGraph::FixedProbability);
            break;
        }

        auto adjacencyMatrix = randomGraph->exportToAdjacenecyMatrix();
        for(int i = 0; i < randomGraph->getVertexCount(); i++)
        {
            for(int j = i+1; j < randomGraph->getVertexCount(); j++)
            {
                int tmp = adjacencyMatrix[i][j];
                adjacencyMatrix[i][j] = adjacencyMatrix[j][i];
                adjacencyMatrix[j][i] = tmp;
            }
        }

        QPointer<Graph> TransponatedGraph = new Graph;
        TransponatedGraph->importFromAdjacencyMatrix(adjacencyMatrix, true);

        randomGraph->drawGraph(ui.graphShowLabel);
        TransponatedGraph->drawGraph(ui.graphTransponedShowLabel);
    }
    catch(Graph::GraphException exception)
    {
        QMessageBox::warning(this, "Error", exception.what());
    }
}

void QGraphUtilityTest::on_vertexSpinBox_valueChanged(int arg1)
{
    ui.edgeSpinBox->setMaximum(arg1*(arg1-1)/2);
}
