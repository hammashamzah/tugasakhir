#ifndef FIELDSELECTIONDIALOG_H
#define FIELDSELECTIONDIALOG_H

#include <QDialog>
#include <iostream>

namespace Ui {  
class FieldSelectionDialog;
}

class FieldSelectionDialog : public QDialog
{
    Q_OBJECT

public slots:
    void processMouse(QPoint& pos);
    void processClick(QPoint& pos);
    void setFirstFrameImage(QVector<QImage>);
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
    void sendMaskCoordinates(QVector<QList<QPoint> >);
    void sendTrapeziumCoordinates(QVector<QList<QPoint> >);
    void sendTransformationCoordinates(QVector<QList<QPoint> >);
};



#endif // FIELDSELECTIONDIALOG_H
