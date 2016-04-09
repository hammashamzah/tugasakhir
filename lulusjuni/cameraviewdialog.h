#ifndef CAMERAVIEWDIALOG_H
#define CAMERAVIEWDIALOG_H

#include <QDialog>
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QPainter>
#include <QTime>

namespace Ui {
class CameraViewDialog;
}

class CameraViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CameraViewDialog(QWidget *parent = 0);
    ~CameraViewDialog();

public slots:
	void updateCameraViewImage(QVector< QVector<QImage> >);
private:
    Ui::CameraViewDialog *ui;
};

#endif // CAMERAVIEWDIALOG_H
