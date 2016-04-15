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
#include "coordinatetransform.h"
#include "perspectivetransformation.h"
#include "processor.h"


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
    perspectiveTransformation *myPersTransDialog;





public slots:

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
        void on_pushButton_single_play_released();


private:
   Ui::MainWindow *ui;
    CameraViewDialog *myCVDialog;
    ErrorCalculationDialog *myECDialog;
    FieldSelectionDialog *myFSDialog;
    SystemPerformanceDialog *mySPDialog;
    TrackingViewDialog *myTVDialog;
    BackgroundModelTuningDialog *myBMTDialog;
    Processor *myProcessor;
    QString filename;
    bool isFieldSelectionDialogInitialized;

    playerVisual player_visual[JUMLAH_PLAYER];
    int playerIdSelected;
//    const int heightOfField=110;
//    const int widthOfField=60;
    QPoint playerFormation[JUMLAH_PLAYER];



    void updateGameVisual();
    void setRandomPlayerProperties();
    void initDisplayFormation();
    int idToAssign;
    bool idAssignedFlag[JUMLAH_PLAYER];


};

#endif // MAINWINDOW_H
