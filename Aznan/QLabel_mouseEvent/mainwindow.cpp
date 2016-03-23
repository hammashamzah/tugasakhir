#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QTextStream>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

Mat Transformed(Mat input);
QImage Mat2QImage(const cv::Mat3b &src);
 QPoint clickedPoint1, clickedPoint2, clickedPoint3, clickedPoint4;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Mat_Display, SIGNAL(sendMousePosition(QPoint&)),this, SLOT(showMousePosition(QPoint&)));
    connect(ui->Mat_Display, SIGNAL(sendClickPosition(QPoint&)),this, SLOT(showClickPosition(QPoint&)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMousePosition(QPoint &pos)
{
    ui->mouse_position_label->setText("x: "+ QString::number(pos.x())+",y: "+QString::number(pos.y()));
}

void MainWindow::showClickPosition(QPoint &pos)
{
    if(ui->radioButton_P1->isChecked())
    {
        clickedPoint1= pos;
        ui->radioButton_P1->setText("P1 ("+QString::number(clickedPoint1.x())+", "+QString::number(clickedPoint1.y())+")");
    }
    else if(ui->radioButton_P2->isChecked())
    {
        clickedPoint2= pos;
        ui->radioButton_P2->setText("P2 ("+QString::number(clickedPoint2.x())+", "+QString::number(clickedPoint2.y())+")");
    }
    if(ui->radioButton_P3->isChecked())
    {
        clickedPoint3= pos;
        ui->radioButton_P3->setText("P3 ("+QString::number(clickedPoint3.x())+", "+QString::number(clickedPoint3.y())+")");
    }
    if(ui->radioButton_P4->isChecked())
    {
        clickedPoint4= pos;
        ui->radioButton_P4->setText("P4 ("+QString::number(clickedPoint4.x())+", "+QString::number(clickedPoint4.y())+")");
    }

}

Mat Transformed(Mat input)
{
    Point2f inputQuad[4];
    // Output Quadilateral or World plane coordinates
    Point2f outputQuad[4];
    Mat output;
    // Lambda Matrix
    Mat lambda( 2, 4, CV_32FC1 );
    //Input and Output Image;


    //Load the image

    // Set the lambda matrix the same type and size as input
    lambda = Mat::zeros( input.rows, input.cols, input.type() );

    inputQuad[0] =Point2f (clickedPoint1.x(), clickedPoint1.y());
    inputQuad[1] =Point2f (clickedPoint2.x(), clickedPoint2.y());
    inputQuad[2] =Point2f (clickedPoint3.x(), clickedPoint3.y());
    inputQuad[3] =Point2f (clickedPoint4.x(), clickedPoint4.y());

    // The 4 points where the mapping is to be done , from top-left in clockwise order
    outputQuad[0] = Point2f( 0, 0 );
    outputQuad[1] = Point2f( input.cols, 0);
    outputQuad[2] = Point2f( input.cols, input.rows);
    outputQuad[3] = Point2f( 0, input.rows );

    // Get the Perspective Transform Matrix i.e. lambda
    lambda = getPerspectiveTransform( inputQuad, outputQuad );
    cout << "lambda = "<< endl << " "  << lambda << endl << endl;

    //imshow("lambda", lambda);
    // Apply the Perspective Transform just found to the src image
    warpPerspective(input,output,lambda,input.size());
    imwrite("output.jpg", output);
    return output;
    //Display input and output
}

void MainWindow::on_pushButton_generateTransMat_clicked()
{
    Mat input=imread("field.jpg");
    Mat output = Transformed(input);
    //imwrite("output.jpg", output);
     QPixmap pixmap("output.jpg");
    pixmap = pixmap.scaled(QSize(800, 600), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_transformed->setPixmap(pixmap);
}

QImage Mat2QImage(const cv::Mat3b &src) {
        QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
        for (int y = 0; y < src.rows; ++y) {
                const cv::Vec3b *srcrow = src[y];
                QRgb *destrow = (QRgb*)dest.scanLine(y);
                for (int x = 0; x < src.cols; ++x) {
                        destrow[x] = qRgba(srcrow[x][2], srcrow[x][1], srcrow[x][0], 255);
                }
        }
        return dest;
}
