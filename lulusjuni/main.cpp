#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.myPersTransDialog->show();
    w.show();
    return a.exec();
}
