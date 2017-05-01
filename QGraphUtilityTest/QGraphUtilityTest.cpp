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

        randomGraph->drawGraph(ui.graphShowLabel);
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
