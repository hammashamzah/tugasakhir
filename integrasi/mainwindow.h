#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define RECT_PLAYER_SIZE 10
#define GLOBAL_FIELD_LENGTH 100
#define GLOBAL_FIELD_WIDTH 50

//std part
#include <iostream>

//qt part
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPainter>
#include <QTime>
#include <QLabel>
#include <QDebug>
#include <QListWidgetItem>

//opencv part
#include <opencv2/opencv.hpp>

//our files
#include "objectdetector.h"
#include "videoprocessor.h"
#include "coordinatetransform.h"
#include "player.h"

//window h file
#include "backgroundmodeltuningdialog.h"
#include "errorcalculationdialog.h"
#include "fieldselectiondialog.h"
#include "systemperformancedialog.h"
#include "trackingviewdialog.h"
#include "cameraviewdialog.h"

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

public slots:
    void displayTransformedPosition(QVector<QList<Player> >);
    void initListPlayer();
    void setCameraViewFirstFrameImage(QVector<QImage>);
    void setOriginIdPlayer(QVector<QList<Player> > );

private slots:
    //menu file edit dll
    void on_actionTuning_Background_Model_triggered();
    void on_actionPer_Camera_Raw_View_triggered();
    void on_actionError_Calculation_triggered();
    void on_actionSystem_Performance_Testing_Metrics_triggered();
    void on_actionField_Selection_triggered();
    void on_actionTracking_View_triggered();
    void on_actionVideo_1_triggered();
    void on_actionVideo_2_triggered();
    //button slot
    void on_pushButton_play_released();
    void on_pushButton_single_play_released();

    //slot
    void assignIdFromList(QPoint& pos);

    void on_listTeamA_itemClicked(QListWidgetItem *item);


    void on_listTeamB_itemClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //initialize windows
    CameraViewDialog *myCVDialog;
    ErrorCalculationDialog *myECDialog;
    FieldSelectionDialog *myFSDialog;
    SystemPerformanceDialog *mySPDialog;
    TrackingViewDialog *myTVDialog;
    BackgroundModelTuningDialog *myBMTDialog;
    //initialize processor
    ObjectDetector *myObjectDetector;
    CoordinateTransform *myCoordinateTransform;
    //intialize temp filename variable
    QString filename;
    int idToAssign;
    bool isIdAssigned[22];
    QVector<QList<Player> > playerDisplayed;
    QVector<QList<Player> > playerOrigin;
    int assignedId;
    //hanya untuk debug
    QVector<QList<Player> > setRandomPlayer();   
    //Internal Procedure
    void displayModifiedId(QVector<QList<Player> > modifiedId);

signals:
       void sendAllIdAssigned(QVector<QList<Player> >);

};

#endif // MAINWINDOW_H
