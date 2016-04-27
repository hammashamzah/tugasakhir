#include "mainwindow.h"
#include <QApplication>
#include "datawindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    DataWindow d;
    d.show();
    //w.show();
    return a.exec();
}
