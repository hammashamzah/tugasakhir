#include "dialogcameracalibration.h"
#include "ui_dialogcameracalibration.h"
#include <QDebug>

DialogCameraCalibration::DialogCameraCalibration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCameraCalibration)
{
    ui->setupUi(this);
    selected_counter=0;
}

DialogCameraCalibration::~DialogCameraCalibration()
{
    delete ui;
}

void DialogCameraCalibration::on_pushButton_OpenVideoCal_clicked()
{
    QString video_filename = QFileDialog::getOpenFileName(this,
                 tr("Open Video Calib"), ".",
                 tr("Video Files (*.avi *.mpg *.mp4 *.MOV *.webm)"));
    QPixmap video;
    QImage frameImage;

    if (!video_filename.isEmpty()) {
            ui->label_VideoCal->setText("Video:" +  video_filename);
            capture = new cv::VideoCapture(video_filename.toLatin1().data());
            capture->read(frame);
            cv::resize(frame, frame, cv::Size(400,300));
            frameImage = QImage((const unsigned char*)(frame.data),frame.cols, frame.rows, QImage::Format_RGB888);
            ui->label_VideoCal->setPixmap(QPixmap::fromImage(frameImage));
    }

    else qDebug() <<"file kosong";
}

//void updateCurrentFrame()
void DialogCameraCalibration::on_horizontalSlider_VideoFrame_valueChanged(int value)
{
        qDebug()<<value<<" ";
        QImage frameImage;
        int numFrame=1;
        capture->set(CV_CAP_PROP_FRAME_COUNT, numFrame);
        int currentFrame=value;
        capture->set(CV_CAP_PROP_POS_FRAMES, currentFrame);
        ui->lineEdit_FrameIdx->setText(QString::number(currentFrame));
        capture->read(frame);
        frameImage = QImage((const unsigned char*)(frame.data),frame.cols, frame.rows, QImage::Format_RGB888);
        ui->label_VideoCal->setPixmap(QPixmap::fromImage(frameImage));
}



void DialogCameraCalibration::on_pushButton_selectFrame_clicked()
{
    selected_counter++;
    ui->label_CounterSelectedImage->setText(QString::number(selected_counter));
    frame_selected.append(frame);
    qDebug()<<frame_selected.size()<<"---";
}
