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

private:
    Ui::FieldSelectionDialog *ui;
    QImage frameCamera_1;
    QImage frameCamera_2;
    QImage frameCamera_3;
    QPoint clickCoordinates[4];
    Point maskPoint[4];
    int currentCameraIndex;
    int entryMode;
    int entryCounter;

signals:
    void maskCoordinates_1_a(QPoint& pos);
    void maskCoordinates_1_b(QPoint& pos);
    void maskCoordinates_1_c(QPoint& pos);
    void maskCoordinates_1_d(QPoint& pos);

    void maskCoordinates_2_a(QPoint& pos);
    void maskCoordinates_2_b(QPoint& pos);
    void maskCoordinates_2_c(QPoint& pos);
    void maskCoordinates_2_d(QPoint& pos);

    void maskCoordinates_3_a(QPoint& pos);
    void maskCoordinates_3_b(QPoint& pos);
    void maskCoordinates_3_c(QPoint& pos);
    void maskCoordinates_3_d(QPoint& pos);
};



#endif // FIELDSELECTIONDIALOG_H
