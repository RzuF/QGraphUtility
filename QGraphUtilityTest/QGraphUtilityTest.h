#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QGraphUtilityTest.h"

class QGraphUtilityTest : public QMainWindow
{
    Q_OBJECT

public:
    QGraphUtilityTest(QWidget *parent = Q_NULLPTR);

private:
    Ui::QGraphUtilityTestClass ui;
};
