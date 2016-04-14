#ifndef COORDINATETRANSFORM_H
#define COORDINATETRANSFORM_H

#define PANJANG_LAPANGAN_ASLI 500
#define LEBAR_LAPANGAN_ASLI 300

#include <QObject>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QPoint>
#include <QList>
#include <QVector>
#include <datainputtrans.h>
#include <datainputcam.h>
using namespace cv;

class CoordinateTransform : public QObject
{
    Q_OBJECT
public:    
    explicit CoordinateTransform(QObject *parent = 0);
    Mat transform_mat1;
    Mat transform_mat2;
    //QSize mat_camera1_size;
    //QSize mat_camera2_size;
    //void processDataFoundLost(QList<QList<DataInputCam>> data_camera);
    Point2f transformPointToGlobal(Point2f pos, int cameraID);
    Point2f transformPointToCamera(Point2f picture_coordinate, Mat transform_matrix);
    Point2f transformCamera1ToGlobal(Point2f camera_coordinate, Mat transform_matrix);
    Point2f transformCamera2ToGlobal(Point2f camera_coordinate, Mat transform_matrix);

signals:
    void sendTransformedRawData(QList <DataInputTrans> transformed);
    //void sendDataInputTransformed1(lostFoundTransformed);
    //void sendDataInputTransformed2(lostFoundTransformed);

    void sendTransformedToDisplay(QVector<QList<DataInputTrans> > dataTransformed);

public slots:
    //void getTransformMat(QList<QPoint> clicked, Mat image);
    void saveTransformMatrix(QVector<Mat> transformer);
    //void saveSizeMatCamera(QList<QSize> mat_size);
    void transformToDisplay(QVector<QList<DataInputCam> > data);

    //void receiveDataLostFound1(QList<QList<DataInputCam>> data_camera);
    //void receiveDataLostFound2(QList<QList<DataInputCam>> data_camera);
};

#endif // COORDINATETRANSFORM_H
