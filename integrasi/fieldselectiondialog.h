#ifndef FIELDSELECTIONDIALOG_H
#define FIELDSELECTIONDIALOG_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QDialog>
#include <iostream>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <cvmatandqimage.h>


namespace Ui {  
class FieldSelectionDialog;
}

class FieldSelectionDialog : public QDialog
{
    Q_OBJECT

public slots:
    void processMouse(QPoint& pos);
    void processClick(QPoint& pos);
    void processRightClick(QPoint& pos);
    void setFirstFrameImage(QVector<QImage>);
public:
    explicit FieldSelectionDialog(QWidget *parent = 0);
    ~FieldSelectionDialog();
    QList<QSize> imageSize;
    void fileHandler(QString filename, int mode);
    QString filename;
private slots:
    void on_doubleSpinBox_koef_valueChanged(double arg1);
    void on_horizontalSlider_valueChanged(int value);
    void on_cameraSelectCombo_currentIndexChanged(int index);
    void on_pushButton_set_released();
    void on_pushButton_apply_released();

    void on_pushButton_load_file_released();

    void on_pushButton_load_default_file_released();

    void on_pushButton_save_file_released();

    void on_pushButton_ok_pressed();

    void on_spinBox_orde_valueChanged(int arg1);

private:
    Ui::FieldSelectionDialog *ui;
    QVector<QImage> originalFrameCamera;
    QVector<QImage> frameCamera;
    QList<QPoint> clickCoordinates;
    QVector<QList<QPoint> > listOfClickCoordinates;
    QVector<QList<QPoint> > listOfTransformationCoordinates;
    QVector<double> distortionCoefficient;
    int numberOfMaskPoints[2];
    int numberOfTransformationPoints[2];
//    QPoint clickCoordinates[4];
    //cv::Point maskPoint[10];
    int currentCameraIndex;
    int entryMode;
    int entryCounter;
    double koef_1, koef_2, arg_1, arg_2;
    int orde_1, orde_2;
    bool set[4];

signals:
    void sendMaskCoordinates(QVector<QList<QPoint> >);
    void sendTransformationCoordinates(QVector<QList<QPoint> >);
    void sendDistortionCoeffisient(QVector<double>);
    void sendImageSize(QList<QSize>);

};



#endif // FIELDSELECTIONDIALOG_H
