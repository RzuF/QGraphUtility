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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGraphUtilityTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QGraphUtilityTestClass)
    {
        if (QGraphUtilityTestClass->objectName().isEmpty())
            QGraphUtilityTestClass->setObjectName(QStringLiteral("QGraphUtilityTestClass"));
        QGraphUtilityTestClass->resize(600, 400);
        menuBar = new QMenuBar(QGraphUtilityTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QGraphUtilityTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QGraphUtilityTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QGraphUtilityTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QGraphUtilityTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QGraphUtilityTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QGraphUtilityTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QGraphUtilityTestClass->setStatusBar(statusBar);

        retranslateUi(QGraphUtilityTestClass);

        QMetaObject::connectSlotsByName(QGraphUtilityTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *QGraphUtilityTestClass)
    {
        QGraphUtilityTestClass->setWindowTitle(QApplication::translate("QGraphUtilityTestClass", "QGraphUtilityTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QGraphUtilityTestClass: public Ui_QGraphUtilityTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGRAPHUTILITYTEST_H
