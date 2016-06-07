#include "distortioncorrectiondialog.h"
#include "ui_distortioncorrectiondialog.h"

DistortionCorrectionDialog::DistortionCorrectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DistortionCorrectionDialog)
{
    ui->setupUi(this);
    originalImage.resize(2);
    koef.resize(4);
    cameraIndex = 0;
    koef[0] = 0;
    koef[1] = 0;
}

DistortionCorrectionDialog::~DistortionCorrectionDialog()
{
    delete ui;
}

void DistortionCorrectionDialog::on_doubleSpinBox_koefisien_valueChanged(double arg1)
{

    Mat_<double> camMat(3,3);
    camMat<<640,0,640,0,360,360,0,0,1;
    if(cameraIndex==0){
        ori = image2Mat(originalImage[0]);
        koef[0]=(double)arg1*(double)pow(10,(-1)*ui->spinBox_orde->value())*(-1);
        undistort(ori,undistorted, camMat, koef);
        output = mat2Image(undistorted);
    }else if(cameraIndex==1){
        ori = image2Mat(originalImage[1]);
        koef[1]=(double)arg1*(double)pow(10,(-1)*ui->spinBox_orde->value())*(-1);
        undistort(ori,undistorted, camMat, koef);
        output = mat2Image(undistorted);
    }

    ui->label_undistorted->setPixmap(QPixmap::fromImage(output));
}

void DistortionCorrectionDialog::setFirstFrameImage(QVector<QImage> firstFrame)
{
    originalImage[0] = firstFrame.at(0);
    originalImage[1] = firstFrame.at(1);
    ui->label_undistorted->setPixmap(QPixmap::fromImage(originalImage[0]));
}


void DistortionCorrectionDialog::on_verticalSlider_valueChanged(int value)
{
    ui->doubleSpinBox_koefisien->setValue(value);
}

void DistortionCorrectionDialog::on_buttonBox_accepted()
{
    QList<double> distCoeffisient;
    distCoeffisient.append(koef[0]);
    distCoeffisient.append(koef[1]);
    emit sendDistortionCoeffisient(distCoeffisient);
    emit sendUndistortedImage(output);
}

void DistortionCorrectionDialog::on_comboBox_camera_activated(int index)
{
    cameraIndex = index;
    switch(index){
    case 0:
        ui->label_undistorted->setPixmap(QPixmap::fromImage(originalImage[0]));
        break;
    case 1:
        ui->label_undistorted->setPixmap(QPixmap::fromImage(originalImage[1]));
        break;
    default:
        ui->label_undistorted->setPixmap(QPixmap::fromImage(originalImage[0]));
        break;
    }
}
