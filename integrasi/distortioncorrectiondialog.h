#ifndef DISTORTIONCORRECTIONDIALOG_H
#define DISTORTIONCORRECTIONDIALOG_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QDialog>
#include <QDebug>
#include <cvmatandqimage.h>

using namespace cv;
using namespace QtOcv;

namespace Ui {
class DistortionCorrectionDialog;
}

class DistortionCorrectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DistortionCorrectionDialog(QWidget *parent = 0);
    ~DistortionCorrectionDialog();
    Mat ori;
    Mat undistorted;
    Mat camMat;
    cv::vector<double> koef;
    QVector<QImage> originalImage;
    int cameraIndex;
    QImage output;

private slots:
    void on_doubleSpinBox_koefisien_valueChanged(double arg1);
    void on_verticalSlider_valueChanged(int value);
    void on_buttonBox_accepted();
    void setFirstFrameImage(QVector<QImage> firstFrame);
    void on_comboBox_camera_activated(int index);

signals:
    void sendDistortionCoeffisient(QList<double>);
    void sendUndistortedImage(QImage);



private:
    Ui::DistortionCorrectionDialog *ui;
};

#endif // DISTORTIONCORRECTIONDIALOG_H
