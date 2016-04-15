#ifndef COORDINATETRANSFORM_H
#define COORDINATETRANSFORM_H

#define GLOBAL_FIELD_LENGTH 100
#define GLOBAL_FIELD_WIDTH 50

#include "player.h"
#include <QObject>
#include <QPoint>
#include <QVector>
#include <QSize>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class CoordinateTransform : public QObject
{   Q_OBJECT

private:

public:
    CoordinateTransform();
    ~CoordinateTransform();
    Mat transform_mat1;
    Mat transform_mat2;
    QSize image_size_1;
    QSize image_size_2;
    Point2f transformPointToGlobal(Point2f pos, int cameraID);
    Point2f transformPointToCamera(Point2f picture_coordinate, Mat transform_matrix);
    Point2f transformCamera1ToGlobal(Point2f camera_coordinate, Mat transform_matrix);
    Point2f transformCamera2ToGlobal(Point2f camera_coordinate, Mat transform_matrix);
signals:
    void sendTransformedRawData(QList<Player>);
    void sendPlayerformed1(QList<QList<Player> >);
    void sendPlayerformed2(QList<QList<Player> >);
    void sendTransformedPosition(QVector<QList<Player> >);

public slots:
    void getTransformMatrix(QList<Mat>);
    void getImageSize(QList<QSize>);
    void processTransformPosition(QVector<QList<Player> >);
};

#endif // COORDINATETRANSFORM_H
