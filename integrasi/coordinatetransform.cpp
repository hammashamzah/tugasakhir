#include "coordinatetransform.h"

CoordinateTransform::CoordinateTransform()
{

}
CoordinateTransform::~CoordinateTransform()
{

}
/* Melakukan transformasi untuk player yang melakukan keluar masuk frame kamera
 * input : QList dari player yang keluar (lost) dan masuk (found) untuk dua kamera
 * Output : QList dari player yang keluar (lost) dan masuk (found) untuk dua kamera
 *          dengan koordinat global lapangan*/


void CoordinateTransform::processTransformPosition(QVector<QList<Player> > data_camera)
{
    //vector 0 -> kamera 1; vector 1 camera 2
    QList<Player> transformed;
    //process

    emit sendTransformedRawData(transformed);
}
//slot dari dialog untuk menyimpan nilai transformer
void CoordinateTransform::getTransformMatrix(QList<Mat> transformer)
{
    //belum selesai
}

//slot untuk menyimpan informasi mat camera dari dialog ke variabel lokal
void CoordinateTransform::getImageSize(QList<QSize> mat_size)
{

}


Point2f CoordinateTransform::transformPointToGlobal(Point2f pos, int cameraID)
{
  Point2f embek;
  return embek;
}

Point2f CoordinateTransform::transformPointToCamera(Point2f picture_coordinate, Mat transform_matrix)
{
    Point2f dst;
    /*Mat result;
        Point2f dst;
        double src[3]={(double)picture_coordinate.x, (double)picture_coordinate.y, 1};
        Mat src_coordinate = Mat(3,1,CV_64FC1, src);

        result=transform_matrix*src_coordinate;

        dst.setX((int)(result.at<double>(0,0)/result.at<double>(0,2)));
        dst.setY((int)(result.at<double>(0,1)/result.at<double>(0,2)));
*/
        return dst;
}

Point2f CoordinateTransform::transformCamera1ToGlobal(Point2f camera_coordinate, Mat transform_matrix)
{
   Point2f dst;
   //= TransformPointToCamera(camera_coordinate, transform_matrix1)*PANJANG_LAPANGAN_ASLI/mat_camera1_size.width();
    return dst;
}

Point2f CoordinateTransform::transformCamera2ToGlobal(Point2f camera_coordinate, Mat transform_matrix)
{
    Point2f dst;
   //= TransformPointToCamera(camera_coordinate, transform_matrix1)*PANJANG_LAPANGAN_ASLI/mat_camera1_size.width();
    return dst;
}


void CoordinateTransform::setTransformationCoordinates(QVector<QList<QPoint> > transformationCoordinates){

}