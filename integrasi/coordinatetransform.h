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
#include <QDebug>
class CoordinateTransform : public QObject
{   Q_OBJECT

private:
    QVector<QList<Player> > playerImageCoordinate;

public:
    CoordinateTransform();
    ~CoordinateTransform();
    Mat transform_mat1;
    Mat transform_mat2;
    Point2f transformPointToGlobal(Point2f pos, int cameraID);
    Point2f transformPointToCamera(Point2f picture_coordinate, Mat transform_matrix);
    Point2f transformCamera1ToGlobal(Point2f camera_coordinate, Mat transform_matrix);
    Point2f transformCamera2ToGlobal(Point2f camera_coordinate, Mat transform_matrix);
    QSize imageSize[2];
    QList<Player> assignedPlayer;
    QList<Player> unifiedPlayerImageCoordinate;
    double distCoeff;

signals:
    void sendPlayerIdAssigned(QList<Player>);
    void sendTransformedPosition(QList<Player>);

public slots:
    void setTransformMatrix(QVector<QList<QPoint> > transformationCoordinates);
    void setImageSize(QList<QSize>);
    void processTransformPosition(QVector<QList<Player> >);
    void returnAssignedPlayer(QList<Player>);
    void setDistotionCoefficient(double value);
};

#endif // COORDINATETRANSFORM_H
