#ifndef COORDINATECONVERTER_H
#define COORDINATECONVERTER_H

#define HEAT_MAP_RESOLUTION_X 20
#define HEAT_MAP_RESOLUTION_Y 10
#define PANJANG_LAPANGAN_ASLI 110      //dalam meter
#define LEBAR_LAPANGAN_ASLI 60          //dalam meter

#include <QObject>
#include <QString>
#include <QPoint>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

class CoordinateConverter : public QObject
{
    Q_OBJECT
public:
    explicit CoordinateConverter(QObject *parent = 0);
    QPoint pixelToHeatMap(QPoint pos, int pixel_width, int pixel_height, int offset_x, int offset_y);
    QPoint pixelToReal(QPoint pos, int pixel_width, int pixel_height, int offset_x, int offset_y);
    Mat getPersTransformMatrix(String imageFileName);

signals:

public slots:
};

#endif // COORDINATECONVERTER_H
