#include "QGraphUtilityTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphUtilityTest w;
    w.show();
    return a.exec();
}
