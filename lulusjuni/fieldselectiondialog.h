#ifndef FIELDSELECTIONDIALOG_H
#define FIELDSELECTIONDIALOG_H

#include <QDialog>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

namespace Ui {  
class FieldSelectionDialog;
}

class FieldSelectionDialog : public QDialog
{
    Q_OBJECT

public slots:
    void processMouse(QPoint& pos);
    void processClick(QPoint& pos);
    void setFrame(QVector<QImage>);
    void getMatrix(QVector<QList<QPoint> >);
public:
    explicit FieldSelectionDialog(QWidget *parent = 0);
    ~FieldSelectionDialog();

private slots:
    void on_cameraSelectCombo_currentIndexChanged(int index);
    void on_pushButton_set_released();
    void on_pushButton_apply_released();

private:
    Ui::FieldSelectionDialog *ui;
    QVector<QImage> frameCamera;
    QList<QPoint> clickCoordinates;
    QVector<QList<QPoint> > listOfClickCoordinates;
    QVector<QList<QPoint> > listOfTrapeziumCoordinates;
    QVector<QList<QPoint> > listOfTransformationCoordinates;
//    QPoint clickCoordinates[4];
    //cv::Point maskPoint[10];
    int currentCameraIndex;
    int entryMode;
    int entryCounter;
    bool set[4];

signals:
    void setMaskCoordinates(QVector<QList<QPoint> >);
    void setTrapeziumCoordinates(QVector<QList<QPoint> >);
    void setTransformationCoordinates(QVector<QList<QPoint> >);
    void setLambdaValue(QVector<Mat>);
};



#endif // FIELDSELECTIONDIALOG_H
