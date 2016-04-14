#ifndef PERSPECTIVETRANSFORMATION_H
#define PERSPECTIVETRANSFORMATION_H

#include <QDialog>
#include <QPoint>
#include <opencv2/opencv.hpp>
#include "matdisplay.h"

using namespace cv;

namespace Ui {
class perspectiveTransformation;
}

class perspectiveTransformation : public QDialog
{
    Q_OBJECT

public:
    explicit perspectiveTransformation(QWidget *parent = 0);
    void getMatrix(String imageFileName);
    ~perspectiveTransformation();
    int cameraId;
    Qlist <Mat> lambda;
    QList <QSize> size_mat_camera;
public slots:
    void get4Point(QPoint &pos);

private slots:
    void on_buttonBox_accepted();


private:
    Ui::perspectiveTransformation *ui;
    QList <Point2f> clickedPoint[4];
signals:
    void sendTransformMat(Mat&);
    sendSizeMatCamera(QList <QSize>& size_mat_camera);


};

#endif // PERSPECTIVETRANSFORMATION_H
