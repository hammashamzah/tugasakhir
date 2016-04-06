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
	void updateRawImage_1(QImage);
	void updateRawImage_2(QImage);
	void updateRawImage_3(QImage);
	void updateMaskedImage_1(QImage);
	void updateMaskedImage_2(QImage);
	void updateMaskedImage_3(QImage);
	void updateObjectImage_1(QImage);
	void updateObjectImage_2(QImage);
	void updateObjectImage_3(QImage);
	void updateOpenedImage_1(QImage);
	void updateOpenedImage_2(QImage);
	void updateOpenedImage_3(QImage);
	void updateBluredImage_1(QImage);
	void updateBluredImage_2(QImage);
	void updateBluredImage_3(QImage);
    void updateObjectWithKeypointsImage_1(QImage);
    void updateObjectWithKeypointsImage_2(QImage);
    void updateObjectWithKeypointsImage_3(QImage);
private:
    Ui::CameraViewDialog *ui;
};

#endif // CAMERAVIEWDIALOG_H
