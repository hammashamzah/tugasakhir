#ifndef COORDINATETRANSFORM_H
#define COORDINATETRANSFORM_H

#include <QObject>
#include "objectvariable.h"

class CoordinateTransform : public QObject
{
    Q_OBJECT
public:    
    explicit CoordinateTransform(QObject *parent = 0);
    Mat transform_mat;
    Point2f TransformPointToGlobal(Point2f pos, int cameraID);
    Point2f TransformPointToCamera(Point2f picture_coordinate, Mat transform_matrix);

signals:
    void sendDataInputTransformed(QList<DataInputTrans>,QList<DataInputTrans>,QList<DataInputTrans>,QList<DataInputTrans>);
public slots:
    void processDataQFoundLost(QList<DataInputCam> lostCam1,QList<DataInputCam> foundCam1,QList<DataInputCam> lostCam2,QList<DataInputCam> foundCam2);
    void getTransformMat(QList<QPoint> clicked, Mat image);

};

#endif // COORDINATETRANSFORM_H
