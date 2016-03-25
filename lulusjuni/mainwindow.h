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
#include "videoprocessor.h"
#include "backgroundmodeltuningdialog.h"
#include "cameraviewdialog.h"
#include "errorcalculationdialog.h"
#include "fieldselectiondialog.h"
#include "systemperformancedialog.h"
#include "trackingviewdialog.h"

#define JUMLAH_PLAYER 25
using namespace std;

struct player_visual{
    int id;
    char tim;
    int pos_x;
    int pos_y;
};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void GameVisual();



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

};

#endif // MAINWINDOW_H
