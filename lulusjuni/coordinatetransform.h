#ifndef COORDINATETRANSFORM_H
#define COORDINATETRANSFORM_H

#include <QObject>
#include "objectvariable.h"

class CoordinateTransform : public QObject
{
    Q_OBJECT
public:    
    explicit CoordinateTransform(QObject *parent = 0);
    Mat transform_mat1;
    Mat transform_mat2;
    void processDataFoundLost(QList<QList<DataInputCam> > data_camera);
    Point2f TransformPointToGlobal(Point2f pos, int cameraID);
    Point2f TransformPointToCamera(Point2f picture_coordinate, Mat transform_matrix);
    Point2f TransformCamera1ToGlobal(Point2f camera_coordinate, Mat transform_matrix);
    Point2f TransformCamera2ToGlobal(Point2f camera_coordinate, Mat transform_matrix);
signals:
    void sendTransformedRawData(QList<DataInputTrans>);
    void sendDataInputTransformed1(QList<QList<DataInputTrans> >);
    void sendDataInputTransformed2(QList<QList<DataInputTrans> >);

public slots:
    void getTransformMat(QList<QPoint> clicked, Mat image);
    void saveTransformMatrix(QList<Mat> transformer);
    void saveSizeMatCamera(QList<QSize> mat_size);
    void receiveDataLostFound1(QList<QList<DataInputCam> > data_camera);
    void receiveDataLostFound2(QList<QList<DataInputCam> > data_camera);
};

#endif // COORDINATETRANSFORM_H
