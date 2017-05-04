#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QGraphUtilityTest.h"

class QGraphUtilityTest : public QMainWindow
{
    Q_OBJECT

public:
    QGraphUtilityTest(QWidget *parent = Q_NULLPTR);

private slots:
    void on_generateButton_clicked();

    void on_vertexSpinBox_valueChanged(int arg1);

    void on_drawButton_clicked();

private:
    Ui::QGraphUtilityTestClass ui;
};
