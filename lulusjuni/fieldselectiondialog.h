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
    void setFrame_1(QImage img);
    void setFrame_2(QImage img);
    void setFrame_3(QImage img);
    void processMouse(QPoint& pos);
    void processClick(QPoint& pos);

public:
    explicit FieldSelectionDialog(QWidget *parent = 0);
    ~FieldSelectionDialog();

private slots:
    void on_cameraSelectCombo_currentIndexChanged(int index);
    void on_pushButton_set_released();
    void on_pushButton_apply_released();

private:
    Ui::FieldSelectionDialog *ui;
    QImage frameCamera_1;
    QImage frameCamera_2;
    QImage frameCamera_3;
    QList<QPoint> clickCoordinates;
//    QPoint clickCoordinates[4];
    //cv::Point maskPoint[10];
    int currentCameraIndex;
    int entryMode;
    int entryCounter;

signals:
    void maskCoordinates_1(QList<QPoint>);
    void maskCoordinates_2(QList<QPoint>);
    void maskCoordinates_3(QList<QPoint>);
    
};



#endif // FIELDSELECTIONDIALOG_H
