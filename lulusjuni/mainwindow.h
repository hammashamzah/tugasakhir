#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPainter>
#include <QTime>
#include <QLabel>
#include <string>
#include <iostream>
#include <QDebug>
#include "objectvariable.h"
#include "playervisual.h"
#include <opencv2/opencv.hpp>
#include <allaboutteam.h>
#include "cameraviewdialog.h"
#include "videoprocessor.h"
#include "backgroundmodeltuningdialog.h"
#include "errorcalculationdialog.h"
#include "fieldselectiondialog.h"
#include "systemperformancedialog.h"
#include "trackingviewdialog.h"
#include "coordinateconverter.h"


using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    AllAboutTeam teamA;
    AllAboutTeam teamB;

    void updateDisplayFormationTeamA();
    void updateDisplayFormationTeamB();





public slots:
    void mainGameDisplayClickEvent(QPoint& pos);
    void mainGameDisplayRightClickEvent(QPoint& pos);
    void selectPlayerFromFormationA(QPoint& pos);
    void selectPlayerFromFormationB(QPoint& pos);

private slots:
    void on_actionTuning_Background_Model_triggered();

    void on_actionPer_Camera_Raw_View_triggered();

    void on_actionError_Calculation_triggered();

    void on_actionSystem_Performance_Testing_Metrics_triggered();

    void on_actionField_Selection_triggered();

    void on_actionTracking_View_triggered();

    void on_actionVideo_1_triggered();

    void on_actionVideo_2_triggered();

    void on_actionVideo_3_triggered();

    void on_pushButton_play_released();

private:
    Ui::MainWindow *ui;
    CameraViewDialog *myCVDialog;
    ErrorCalculationDialog *myECDialog;
    FieldSelectionDialog *myFSDialog;
    SystemPerformanceDialog *mySPDialog;
    TrackingViewDialog *myTVDialog;
    BackgroundModelTuningDialog *myBMTDialog;

    QString filename_1;
    QString filename_2;
    QString filename_3;

    VideoProcessor *myStream_1;
    VideoProcessor *myStream_2;
    VideoProcessor *myStream_3;



    void updateGameVisual();
    void setRandomPlayerProperties();
    void initDisplayFormation();
    int idToAssign;
    bool idAssignedFlag[JUMLAH_PLAYER];


};

#endif // MAINWINDOW_H
