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
    Mat getMatrix(String imageFileName);
    ~perspectiveTransformation();
public slots:
    void get4Point(QPoint &pos);

private slots:
    void on_buttonBox_accepted();


private:
    Ui::perspectiveTransformation *ui;
    Point2f clickedPoint[4];


};

#endif // PERSPECTIVETRANSFORMATION_H
