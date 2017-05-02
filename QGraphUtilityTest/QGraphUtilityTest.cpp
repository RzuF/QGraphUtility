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
    ui.graphTypeComboBox->setCurrentIndex(2);
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
            if(ui.probabilitySpinBox->value() < 0.4f)
                ui.probabilitySpinBox->setValue(0.5f);
            while((randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.probabilitySpinBox->value(), Graph::RandomGraph::DigraphFixedProbability))->Kosaraju(ui.additionalInfoLabel) != ui.vertexSpinBox->value())
            {
                delete randomGraph;
            }
            break;
        case 3:
            randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.probabilitySpinBox->value(), Graph::RandomGraph::FixedProbability);
            break;
        }

        if(ui.graphTypeComboBox->currentIndex() == 3 && ui.dijkstraRadio->isChecked())
        {
            while(!(randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.probabilitySpinBox->value(), Graph::RandomGraph::FixedProbability))->isConnected())
            {
                delete randomGraph;
            }

            randomGraph->setRandomWeights(1, 10);

            QPointer<Graph> tmpGraph = new Graph;
            tmpGraph->importFromAdjacencyMatrix(randomGraph->exportToAdjacenecyMatrix(), true);

            tmpGraph->Dijkstra(ui.additionalInfoLabel, ui.bellmanFordSpinBox->value());
        }

        if(ui.graphTypeComboBox->currentIndex() == 3 && ui.distanceMatrixRadio->isChecked())
        {
            while(!(randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.probabilitySpinBox->value(), Graph::RandomGraph::FixedProbability))->isConnected())
            {
                delete randomGraph;
            }

            randomGraph->setRandomWeights(1, 10);

            QPointer<Graph> tmpGraph = new Graph;
            tmpGraph->importFromAdjacencyMatrix(randomGraph->exportToAdjacenecyMatrix(), true);

            tmpGraph->DistanceMatrix(ui.additionalInfoLabel);
        }

        if(ui.graphTypeComboBox->currentIndex() == 2 && ui.dijkstraRadio->isChecked())
        {
            randomGraph->setRandomWeights(0, 10);

            randomGraph->Dijkstra(ui.additionalInfoLabel, ui.bellmanFordSpinBox->value());
        }

        if(ui.graphTypeComboBox->currentIndex() == 2 && ui.bellmanFordRadio->isChecked())
        {
            randomGraph->setRandomWeights(-5, 10);

            if(ui.negativeCyclesCheckBox->isChecked())
                while(randomGraph->BellmanFord(ui.additionalInfoLabel, ui.bellmanFordSpinBox->value()).empty())
                {
                    delete randomGraph;
                    while((randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.probabilitySpinBox->value(), Graph::RandomGraph::DigraphFixedProbability))->Kosaraju(ui.additionalInfoLabel) != ui.vertexSpinBox->value())
                    {
                        delete randomGraph;
                    }
                    randomGraph->setRandomWeights(-5, 10);
                }
            else
                randomGraph->BellmanFord(ui.additionalInfoLabel, ui.bellmanFordSpinBox->value());
        }

        if(ui.graphTypeComboBox->currentIndex() == 2 && ui.johnsonRadio->isChecked())
        {
            randomGraph->setRandomWeights(-5, 10);

            if(ui.negativeCyclesCheckBox->isChecked())
                while(randomGraph->BellmanFord(ui.additionalInfoLabel, ui.bellmanFordSpinBox->value()).empty())
                {
                    delete randomGraph;
                    while((randomGraph = Graph::generateRandomGraph(ui.vertexSpinBox->value(), ui.probabilitySpinBox->value(), Graph::RandomGraph::DigraphFixedProbability))->Kosaraju(ui.additionalInfoLabel) != ui.vertexSpinBox->value())
                    {
                        delete randomGraph;
                    }
                    randomGraph->setRandomWeights(-5, 10);
                }

            randomGraph->Johnson(ui.additionalInfoLabel, ui.originalGraphCheckBox->isChecked());
        }

        if(ui.graphTypeComboBox->currentIndex() == 1 && ui.transponeGraphRadio->isChecked())
        {
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

            TransponatedGraph->drawGraph(ui.additionalInfoLabel, ui.colorizeCheckBox->isChecked());
        }

        if(ui.graphTypeComboBox->currentIndex() == 1 && ui.kosarajuRadio->isChecked())
        {
            randomGraph->Kosaraju(ui.additionalInfoLabel);
        }

        randomGraph->drawGraph(ui.graphShowLabel, ui.colorizeCheckBox->isChecked());
    }
    catch(Graph::GraphException exception)
    {
        QMessageBox::warning(this, "Error", exception.what());
    }
}

void QGraphUtilityTest::on_vertexSpinBox_valueChanged(int arg1)
{
    ui.edgeSpinBox->setMaximum(arg1*(arg1-1)/2);
    ui.bellmanFordSpinBox->setMaximum(arg1-1);
}
