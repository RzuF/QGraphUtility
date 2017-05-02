/********************************************************************************
** Form generated from reading UI file 'QGraphUtilityTest.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGRAPHUTILITYTEST_H
#define UI_QGRAPHUTILITYTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGraphUtilityTestClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *vertexSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpinBox *edgeSpinBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QDoubleSpinBox *probabilitySpinBox;
    QComboBox *graphTypeComboBox;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *transponeGraphRadio;
    QRadioButton *dijkstraRadio;
    QRadioButton *distanceMatrixRadio;
    QRadioButton *kosarajuRadio;
    QRadioButton *bellmanFordRadio;
    QRadioButton *johnsonRadio;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *colorizeCheckBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *originalGraphCheckBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *negativeCyclesCheckBox;
    QLabel *label_4;
    QSpinBox *bellmanFordSpinBox;
    QPushButton *generateButton;
    QLabel *graphShowLabel;
    QLabel *additionalInfoLabel;
    QMenuBar *menuBar;
    QMenu *menuTest;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QGraphUtilityTestClass)
    {
        if (QGraphUtilityTestClass->objectName().isEmpty())
            QGraphUtilityTestClass->setObjectName(QStringLiteral("QGraphUtilityTestClass"));
        QGraphUtilityTestClass->resize(655, 398);
        centralWidget = new QWidget(QGraphUtilityTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        vertexSpinBox = new QSpinBox(centralWidget);
        vertexSpinBox->setObjectName(QStringLiteral("vertexSpinBox"));

        horizontalLayout->addWidget(vertexSpinBox);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        edgeSpinBox = new QSpinBox(centralWidget);
        edgeSpinBox->setObjectName(QStringLiteral("edgeSpinBox"));

        horizontalLayout_5->addWidget(edgeSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        probabilitySpinBox = new QDoubleSpinBox(centralWidget);
        probabilitySpinBox->setObjectName(QStringLiteral("probabilitySpinBox"));
        probabilitySpinBox->setDecimals(4);
        probabilitySpinBox->setMaximum(1);
        probabilitySpinBox->setSingleStep(0.0001);

        horizontalLayout_6->addWidget(probabilitySpinBox);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        graphTypeComboBox = new QComboBox(centralWidget);
        graphTypeComboBox->setObjectName(QStringLiteral("graphTypeComboBox"));

        horizontalLayout_3->addWidget(graphTypeComboBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        transponeGraphRadio = new QRadioButton(centralWidget);
        transponeGraphRadio->setObjectName(QStringLiteral("transponeGraphRadio"));

        horizontalLayout_4->addWidget(transponeGraphRadio);

        dijkstraRadio = new QRadioButton(centralWidget);
        dijkstraRadio->setObjectName(QStringLiteral("dijkstraRadio"));

        horizontalLayout_4->addWidget(dijkstraRadio);

        distanceMatrixRadio = new QRadioButton(centralWidget);
        distanceMatrixRadio->setObjectName(QStringLiteral("distanceMatrixRadio"));

        horizontalLayout_4->addWidget(distanceMatrixRadio);

        kosarajuRadio = new QRadioButton(centralWidget);
        kosarajuRadio->setObjectName(QStringLiteral("kosarajuRadio"));

        horizontalLayout_4->addWidget(kosarajuRadio);

        bellmanFordRadio = new QRadioButton(centralWidget);
        bellmanFordRadio->setObjectName(QStringLiteral("bellmanFordRadio"));

        horizontalLayout_4->addWidget(bellmanFordRadio);

        johnsonRadio = new QRadioButton(centralWidget);
        johnsonRadio->setObjectName(QStringLiteral("johnsonRadio"));
        johnsonRadio->setContextMenuPolicy(Qt::PreventContextMenu);

        horizontalLayout_4->addWidget(johnsonRadio);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        colorizeCheckBox = new QCheckBox(centralWidget);
        colorizeCheckBox->setObjectName(QStringLiteral("colorizeCheckBox"));
        colorizeCheckBox->setChecked(true);

        horizontalLayout_7->addWidget(colorizeCheckBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_2);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        originalGraphCheckBox = new QCheckBox(groupBox_2);
        originalGraphCheckBox->setObjectName(QStringLiteral("originalGraphCheckBox"));

        horizontalLayout_9->addWidget(originalGraphCheckBox);


        horizontalLayout_7->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAutoFillBackground(false);
        horizontalLayout_10 = new QHBoxLayout(groupBox);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        negativeCyclesCheckBox = new QCheckBox(groupBox);
        negativeCyclesCheckBox->setObjectName(QStringLiteral("negativeCyclesCheckBox"));

        horizontalLayout_8->addWidget(negativeCyclesCheckBox);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        bellmanFordSpinBox = new QSpinBox(groupBox);
        bellmanFordSpinBox->setObjectName(QStringLiteral("bellmanFordSpinBox"));

        horizontalLayout_8->addWidget(bellmanFordSpinBox);


        horizontalLayout_10->addLayout(horizontalLayout_8);


        horizontalLayout_7->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_7);

        generateButton = new QPushButton(centralWidget);
        generateButton->setObjectName(QStringLiteral("generateButton"));

        verticalLayout->addWidget(generateButton);

        graphShowLabel = new QLabel(centralWidget);
        graphShowLabel->setObjectName(QStringLiteral("graphShowLabel"));
        graphShowLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(graphShowLabel);

        additionalInfoLabel = new QLabel(centralWidget);
        additionalInfoLabel->setObjectName(QStringLiteral("additionalInfoLabel"));
        additionalInfoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(additionalInfoLabel);

        QGraphUtilityTestClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QGraphUtilityTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 20));
        menuTest = new QMenu(menuBar);
        menuTest->setObjectName(QStringLiteral("menuTest"));
        QGraphUtilityTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QGraphUtilityTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QGraphUtilityTestClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QGraphUtilityTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QGraphUtilityTestClass->setStatusBar(statusBar);

        menuBar->addAction(menuTest->menuAction());

        retranslateUi(QGraphUtilityTestClass);

        QMetaObject::connectSlotsByName(QGraphUtilityTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QGraphUtilityTestClass)
    {
        QGraphUtilityTestClass->setWindowTitle(QApplication::translate("QGraphUtilityTestClass", "QGraphUtilityTest", Q_NULLPTR));
        label->setText(QApplication::translate("QGraphUtilityTestClass", "Vertexes:", Q_NULLPTR));
        label_2->setText(QApplication::translate("QGraphUtilityTestClass", "Edges", Q_NULLPTR));
        label_3->setText(QApplication::translate("QGraphUtilityTestClass", "Probability", Q_NULLPTR));
        graphTypeComboBox->clear();
        graphTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("QGraphUtilityTestClass", "Fixed Edges", Q_NULLPTR)
         << QApplication::translate("QGraphUtilityTestClass", "Fixed Probability (Digraph)", Q_NULLPTR)
         << QApplication::translate("QGraphUtilityTestClass", "Strong Connected Digraph", Q_NULLPTR)
         << QApplication::translate("QGraphUtilityTestClass", "Fixed Probability", Q_NULLPTR)
        );
        transponeGraphRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Transponed Graph", Q_NULLPTR));
        dijkstraRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Dijkstra", Q_NULLPTR));
        distanceMatrixRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Distance Matrix", Q_NULLPTR));
        kosarajuRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Kosaraju", Q_NULLPTR));
        bellmanFordRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Bellman-Ford", Q_NULLPTR));
        johnsonRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Johnson", Q_NULLPTR));
        colorizeCheckBox->setText(QApplication::translate("QGraphUtilityTestClass", "Colorise", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QGraphUtilityTestClass", "Johnson", Q_NULLPTR));
        originalGraphCheckBox->setText(QApplication::translate("QGraphUtilityTestClass", "Original Graph", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QGraphUtilityTestClass", "Bellman-Ford", Q_NULLPTR));
        negativeCyclesCheckBox->setText(QApplication::translate("QGraphUtilityTestClass", "Avoid Negative Cycles", Q_NULLPTR));
        label_4->setText(QApplication::translate("QGraphUtilityTestClass", "Start Vertex", Q_NULLPTR));
        generateButton->setText(QApplication::translate("QGraphUtilityTestClass", "Generate new graph", Q_NULLPTR));
        graphShowLabel->setText(QApplication::translate("QGraphUtilityTestClass", "First Graph", Q_NULLPTR));
        additionalInfoLabel->setText(QString());
        menuTest->setTitle(QApplication::translate("QGraphUtilityTestClass", "Test", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QGraphUtilityTestClass: public Ui_QGraphUtilityTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGRAPHUTILITYTEST_H
