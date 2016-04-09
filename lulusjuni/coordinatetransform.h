#ifndef COORDINATETRANSFORM_H
#define COORDINATETRANSFORM_H

#include <QObject>
#include "objectvariable.h"

class CoordinateTransform : public QObject
{
    Q_OBJECT
public:
    explicit CoordinateTransform(QObject *parent = 0);
    Point2f TransformPoint(Point2f pos, int cameraID);

signals:
    void sendDataInputTransformed(QList<DataInputTrans>,QList<DataInputTrans>,QList<DataInputTrans>,QList<DataInputTrans>);
public slots:
    void processDataQFoundLost(QList<DataInputCam> lostCam1,QList<DataInputCam> foundCam1,QList<DataInputCam> lostCam2,QList<DataInputCam> foundCam2);
};

#endif // COORDINATETRANSFORM_H
