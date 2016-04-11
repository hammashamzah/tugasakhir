#include "mainwindow.h"
#include <QApplication>
#include "dialogcameracalibration.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.myPersTransDialog->show();
   // w.show();
    DialogCameraCalibration cal;
    cal.show();
    return a.exec();
}
