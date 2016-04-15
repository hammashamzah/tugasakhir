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


void CoordinateTransform::processTransformPosition(QVector<QList<Player> > data)
{
    QVector<QList<Player> > dataTransformed;
    dataTransformed.resize(2);
    for(int cameraId=0; cameraId<dataTransformed.size(); cameraId++)
    {
        for(int i=0; i<data.at(cameraId).size() ; i++)
        {
            if(cameraId==0)
                data[cameraId][i].pos = transformCamera1ToGlobal(data[cameraId][i].pos, transform_mat1);
            else
                data[cameraId][i].pos = transformCamera2ToGlobal(data[cameraId][i].pos, transform_mat2);
        }
    }
    emit sendTransformedPosition(data);
}
//slot dari dialog untuk menyimpan nilai transformer
void CoordinateTransform::getTransformMatrix(QList<Mat> transformer)
{
    transform_mat1= transformer.at(0);
    transform_mat2= transformer.at(1);
}

//slot untuk menyimpan informasi mat camera dari dialog ke variabel lokal
void CoordinateTransform::getImageSize(QList<QSize> mat_size)
{
    image_size_1=mat_size.at(0);
    image_size_2=mat_size.at(0);
}

Point2f CoordinateTransform::transformPointToCamera(Point2f picture_coordinate, Mat transform_matrix)
{
    Point2f dst;
    Mat result;
        double src[3]={(double)picture_coordinate.x, (double)picture_coordinate.y, 1};
        Mat src_coordinate = Mat(3,1,CV_64FC1, src);

        result=transform_matrix*src_coordinate;

        dst.x=((int)(result.at<double>(0,0)/result.at<double>(0,2)));
        dst.y=((int)(result.at<double>(0,1)/result.at<double>(0,2)));

        return dst;
}

Point2f CoordinateTransform::transformCamera1ToGlobal(Point2f camera_coordinate, Mat transform_matrix)
{
    Point2f dst;
       dst.x =transformPointToCamera(camera_coordinate, transform_matrix).x * GLOBAL_FIELD_LENGTH / 2 / image_size_1.width();
       dst.y =transformPointToCamera(camera_coordinate, transform_matrix).y * GLOBAL_FIELD_WIDTH / image_size_2.height();
       return dst;
}

Point2f CoordinateTransform::transformCamera2ToGlobal(Point2f camera_coordinate, Mat transform_matrix)
{
    Point2f dst;
        int offset=GLOBAL_FIELD_LENGTH/2;
        dst.x =transformPointToCamera(camera_coordinate, transform_matrix).x * GLOBAL_FIELD_LENGTH / 2 / image_size_2.width()+offset;
        dst.y =transformPointToCamera(camera_coordinate, transform_matrix).y * GLOBAL_FIELD_WIDTH / image_size_2.height();
        return dst;
}



//hanya untuk debug
/*
QVector<QList<Player> > CoordinateTransform::dummyDataInput()
{
    //set random value of player
    QVector<QList<Player> > dummyPlayer;
    Player playerSet;
    dummyPlayer.resize(2);
        for(int i=0; i<dummyPlayer.size(); i++)
        {
            for(int j=0;j<11;j++)
            {
                playerSet.id=j+999;
                playerSet.pos.x=(qrand() % (640-68)+34);
                playerSet.pos.y=(qrand() % (434-56) + 28);
                dummyPlayer[i].append(playerSet);
            }
        }
}
*/
