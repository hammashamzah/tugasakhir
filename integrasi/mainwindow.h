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
#include "dynamicassociation.h"
#include "datawindow.h"
#include "distortioncorrectiondialog.h"

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

    bool isSetTrapezium;
    bool isSetThresholds;
    QImage soccerField;
    QImage logoLV;
    QImage playerIconTeamA;
    QImage playerIconTeamB;

public slots:
    void displayProcessedData(QList<Player>);
    void initListPlayer();
    void setCameraViewFirstFrameImage(QVector<QImage>);
    void updateCameraViewFrameImage(QVector< QVector<QImage> > image);
    void setValueParameter(QVector< QVector<int> > valueParameter);
    void displayAssignedTransformedPosition(QList<Player> assignedTransformedPosition);

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
    void on_actionData_View_triggered();
    //button slot
    void on_pushButton_play_released();
    void on_pushButton_single_play_released();

    //slot
    void assignIdFromList(QPoint& pos);

    void on_listTeamA_itemClicked(QListWidgetItem *item);


    void on_listTeamB_itemClicked(QListWidgetItem *item);

    void on_slider_global_frame_sliderPressed();

    void on_slider_global_frame_sliderReleased();

    void on_slider_global_frame_valueChanged(int value);

    void on_pushButton_send_id_clicked();

    void on_pushButton_load_default_video_released();

    void on_pushButton_initialize_background_model_released();
    void on_actionFirst_Image_1_triggered();
    void on_actionFirst_Image_2_triggered();

    void on_actionDistortion_Correction_triggered();

private:
    Ui::MainWindow *ui;
    //initialize windows
    CameraViewDialog *myCVDialog;
    ErrorCalculationDialog *myECDialog;
    FieldSelectionDialog *myFSDialog;
    SystemPerformanceDialog *mySPDialog;
    TrackingViewDialog *myTVDialog;
    BackgroundModelTuningDialog *myBMTDialog;
    DynamicAssociation *myDynamicAssociation;
    DataWindow *myDVDialog;
    DistortionCorrectionDialog *myDistortionCorrection;
    //initialize processor
    ObjectDetector *myObjectDetector;
    CoordinateTransform *myCoordinateTransform;
    //intialize temp filename variable
    QString filename;
    bool videoLoaded[2];
    QString getFormattedTime(int timeInSeconds);
    int idToAssign;
    bool isIdAssigned[22];
    QList<Player> playerDisplayed_scaling;
    QList<Player> playerDisplayed;
    int assignedId;
    //hanya untuk debug
    QVector<QList<Player> > setRandomPlayer();   
    //Internal Procedure
    void displayModifiedId();
    QVector<QVector<int> > myValueParameter;
    QVector<QList<QPoint> > myTrapeziumCoordinates;


signals:
       void sendAllIdAssigned(QList<Player>);
};

#endif // MAINWINDOW_H
