#ifndef DIALOGCAMERACALIBRATION_H
#define DIALOGCAMERACALIBRATION_H

#include <QDialog>
#include <QFileDialog>
#include "opencv2/opencv.hpp"
using namespace cv;

namespace Ui {
class DialogCameraCalibration;
}

class DialogCameraCalibration : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCameraCalibration(QWidget *parent = 0);
    ~DialogCameraCalibration();
    VideoCapture *capture;
    Mat frame;
    int selected_counter;
    QList <Mat> frame_selected;

private slots:
    void on_pushButton_OpenVideoCal_clicked();

    void on_horizontalSlider_VideoFrame_valueChanged(int value);

    void on_pushButton_selectFrame_clicked();

private:
    Ui::DialogCameraCalibration *ui;
};

#endif // DIALOGCAMERACALIBRATION_H
