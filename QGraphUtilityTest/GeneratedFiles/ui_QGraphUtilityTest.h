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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGraphUtilityTestClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
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
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_6;
    QSpinBox *degreeSpinBox;
    QComboBox *graphTypeComboBox;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *transponeGraphRadio;
    QRadioButton *dijkstraRadio;
    QRadioButton *distanceMatrixRadio;
    QRadioButton *primRadio;
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
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QPlainTextEdit *sequenceTextEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *colorize2CheckBox;
    QRadioButton *gccRadio;
    QRadioButton *replaceEdgesRadio;
    QSpinBox *replaceSpinBox;
    QPushButton *drawButton;
    QLabel *graphShowLabel;
    QLabel *additionalInfoLabel;
    QMenuBar *menuBar;
    QMenu *menuTest;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QGraphUtilityTestClass)
    {
        if (QGraphUtilityTestClass->objectName().isEmpty())
            QGraphUtilityTestClass->setObjectName(QStringLiteral("QGraphUtilityTestClass"));
        QGraphUtilityTestClass->resize(803, 523);
        centralWidget = new QWidget(QGraphUtilityTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        vertexSpinBox = new QSpinBox(tab);
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
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        edgeSpinBox = new QSpinBox(tab);
        edgeSpinBox->setObjectName(QStringLiteral("edgeSpinBox"));

        horizontalLayout_5->addWidget(edgeSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        probabilitySpinBox = new QDoubleSpinBox(tab);
        probabilitySpinBox->setObjectName(QStringLiteral("probabilitySpinBox"));
        probabilitySpinBox->setDecimals(4);
        probabilitySpinBox->setMaximum(1);
        probabilitySpinBox->setSingleStep(0.0001);

        horizontalLayout_6->addWidget(probabilitySpinBox);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_13->addWidget(label_6);

        degreeSpinBox = new QSpinBox(tab);
        degreeSpinBox->setObjectName(QStringLiteral("degreeSpinBox"));

        horizontalLayout_13->addWidget(degreeSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_13);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        graphTypeComboBox = new QComboBox(tab);
        graphTypeComboBox->setObjectName(QStringLiteral("graphTypeComboBox"));

        horizontalLayout_3->addWidget(graphTypeComboBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        transponeGraphRadio = new QRadioButton(tab);
        transponeGraphRadio->setObjectName(QStringLiteral("transponeGraphRadio"));

        horizontalLayout_4->addWidget(transponeGraphRadio);

        dijkstraRadio = new QRadioButton(tab);
        dijkstraRadio->setObjectName(QStringLiteral("dijkstraRadio"));

        horizontalLayout_4->addWidget(dijkstraRadio);

        distanceMatrixRadio = new QRadioButton(tab);
        distanceMatrixRadio->setObjectName(QStringLiteral("distanceMatrixRadio"));

        horizontalLayout_4->addWidget(distanceMatrixRadio);

        primRadio = new QRadioButton(tab);
        primRadio->setObjectName(QStringLiteral("primRadio"));

        horizontalLayout_4->addWidget(primRadio);

        kosarajuRadio = new QRadioButton(tab);
        kosarajuRadio->setObjectName(QStringLiteral("kosarajuRadio"));

        horizontalLayout_4->addWidget(kosarajuRadio);

        bellmanFordRadio = new QRadioButton(tab);
        bellmanFordRadio->setObjectName(QStringLiteral("bellmanFordRadio"));

        horizontalLayout_4->addWidget(bellmanFordRadio);

        johnsonRadio = new QRadioButton(tab);
        johnsonRadio->setObjectName(QStringLiteral("johnsonRadio"));
        johnsonRadio->setContextMenuPolicy(Qt::PreventContextMenu);

        horizontalLayout_4->addWidget(johnsonRadio);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        colorizeCheckBox = new QCheckBox(tab);
        colorizeCheckBox->setObjectName(QStringLiteral("colorizeCheckBox"));
        colorizeCheckBox->setChecked(true);

        horizontalLayout_7->addWidget(colorizeCheckBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_2);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        originalGraphCheckBox = new QCheckBox(groupBox_2);
        originalGraphCheckBox->setObjectName(QStringLiteral("originalGraphCheckBox"));

        horizontalLayout_9->addWidget(originalGraphCheckBox);


        horizontalLayout_7->addWidget(groupBox_2);

        groupBox = new QGroupBox(tab);
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


        verticalLayout_3->addLayout(horizontalLayout_7);

        generateButton = new QPushButton(tab);
        generateButton->setObjectName(QStringLiteral("generateButton"));

        verticalLayout_3->addWidget(generateButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_11->addWidget(label_5);

        sequenceTextEdit = new QPlainTextEdit(tab_2);
        sequenceTextEdit->setObjectName(QStringLiteral("sequenceTextEdit"));

        horizontalLayout_11->addWidget(sequenceTextEdit);


        verticalLayout_4->addLayout(horizontalLayout_11);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        colorize2CheckBox = new QCheckBox(groupBox_3);
        colorize2CheckBox->setObjectName(QStringLiteral("colorize2CheckBox"));
        colorize2CheckBox->setChecked(true);

        horizontalLayout_12->addWidget(colorize2CheckBox);

        gccRadio = new QRadioButton(groupBox_3);
        gccRadio->setObjectName(QStringLiteral("gccRadio"));

        horizontalLayout_12->addWidget(gccRadio);

        replaceEdgesRadio = new QRadioButton(groupBox_3);
        replaceEdgesRadio->setObjectName(QStringLiteral("replaceEdgesRadio"));

        horizontalLayout_12->addWidget(replaceEdgesRadio);

        replaceSpinBox = new QSpinBox(groupBox_3);
        replaceSpinBox->setObjectName(QStringLiteral("replaceSpinBox"));
        replaceSpinBox->setMinimum(0);
        replaceSpinBox->setValue(0);

        horizontalLayout_12->addWidget(replaceSpinBox);


        verticalLayout_4->addWidget(groupBox_3);

        drawButton = new QPushButton(tab_2);
        drawButton->setObjectName(QStringLiteral("drawButton"));

        verticalLayout_4->addWidget(drawButton);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

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
        menuBar->setGeometry(QRect(0, 0, 803, 20));
        menuTest = new QMenu(menuBar);
        menuTest->setObjectName(QStringLiteral("menuTest"));
        QGraphUtilityTestClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(QGraphUtilityTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QGraphUtilityTestClass->setStatusBar(statusBar);

        menuBar->addAction(menuTest->menuAction());

        retranslateUi(QGraphUtilityTestClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QGraphUtilityTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QGraphUtilityTestClass)
    {
        QGraphUtilityTestClass->setWindowTitle(QApplication::translate("QGraphUtilityTestClass", "QGraphUtilityTest", Q_NULLPTR));
        label->setText(QApplication::translate("QGraphUtilityTestClass", "Vertexes:", Q_NULLPTR));
        label_2->setText(QApplication::translate("QGraphUtilityTestClass", "Edges", Q_NULLPTR));
        label_3->setText(QApplication::translate("QGraphUtilityTestClass", "Probability", Q_NULLPTR));
        label_6->setText(QApplication::translate("QGraphUtilityTestClass", "Degree", Q_NULLPTR));
        graphTypeComboBox->clear();
        graphTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("QGraphUtilityTestClass", "Fixed Edges", Q_NULLPTR)
         << QApplication::translate("QGraphUtilityTestClass", "Fixed Probability (Digraph)", Q_NULLPTR)
         << QApplication::translate("QGraphUtilityTestClass", "Strong Connected Digraph", Q_NULLPTR)
         << QApplication::translate("QGraphUtilityTestClass", "Fixed Probability", Q_NULLPTR)
         << QApplication::translate("QGraphUtilityTestClass", "Fixed Degree", Q_NULLPTR)
        );
        transponeGraphRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Transponed Graph", Q_NULLPTR));
        dijkstraRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Dijkstra", Q_NULLPTR));
        distanceMatrixRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Distance Matrix", Q_NULLPTR));
        primRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Prim", Q_NULLPTR));
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
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QGraphUtilityTestClass", "Zestaw 1, 3, 4, 2.3", Q_NULLPTR));
        label_5->setText(QApplication::translate("QGraphUtilityTestClass", "Number sequence", Q_NULLPTR));
        sequenceTextEdit->setPlainText(QApplication::translate("QGraphUtilityTestClass", "1 2 3 4 4 3 5", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("QGraphUtilityTestClass", "Preferences", Q_NULLPTR));
        colorize2CheckBox->setText(QApplication::translate("QGraphUtilityTestClass", "Colorize", Q_NULLPTR));
        gccRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Greatest Connected Compound", Q_NULLPTR));
        replaceEdgesRadio->setText(QApplication::translate("QGraphUtilityTestClass", "Replace Edges", Q_NULLPTR));
        drawButton->setText(QApplication::translate("QGraphUtilityTestClass", "Draw Graph", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QGraphUtilityTestClass", "Zestaw 2", Q_NULLPTR));
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
