#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>
#include <QPainter>
#include <QTime>
#include "videoprocessor.h"
#include "backgroundmodeltuningdialog.h"
#include "cameraviewdialog.h"
#include "errorcalculationdialog.h"
#include "fieldselectiondialog.h"
#include "systemperformancedialog.h"
#include "trackingviewdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



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

signals:
    void firstFrame_1(const QImage &image);
    void firstFrame_2(const QImage &image);
    void firstFrame_3(const QImage &image);

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
    bool isFieldSelectionDialogInitialized;

};

#endif // MAINWINDOW_H
