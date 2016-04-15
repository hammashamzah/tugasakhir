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



void CoordinateTransform::setTransformationCoordinates(QVector<QList<QPoint> > transformationCoordinates){
 //asumsi lebar lapangan adalah 0.5 panjang lapangan
    double size_ratio = 0.5;

    // Output Quadilateral or World plane coordinates
    cv::Point2f outputQuad[4];
    // Lambda Matrix
    QVector<cv::Mat> lambda;
    lambda.clear();
    lambda.resize(2);

    for (int cameraId = 0; cameraId < 2; cameraId++) {
        //size_mat_camera[cameraId].setWidth(clickedPoint[cameraId][3].x - clickedPoint[cameraId][4].x);
        //size_mat_camera[cameraId].setHeight(size_ratio * size_mat_camera[cameraId].width(););

        // Set the lambda matrix the same type and size as input
        lambda[cameraId] = Mat::zeros( 1920, 1080, CV_8UC1);

        // The 4 points where the mapping is to be done , from top-left in clockwise order
        outputQuad[0] = Point2f( 0, 0 );
        outputQuad[1] = Point2f( 1920 , 0);
        outputQuad[2] = Point2f( 1920, 1080);
        outputQuad[3] = Point2f( 0, 1080);

        Point2f temp[4];

        temp[0].x = transformationCoordinates[cameraId][0].x();
        temp[0].y = transformationCoordinates[cameraId][0].y();
        temp[1].x = transformationCoordinates[cameraId][1].x();
        temp[1].y = transformationCoordinates[cameraId][1].y();
        temp[2].x = transformationCoordinates[cameraId][2].x();
        temp[2].y = transformationCoordinates[cameraId][2].y();
        temp[3].x = transformationCoordinates[cameraId][3].x();
        temp[3].y = transformationCoordinates[cameraId][3].y();

        // Get the Perspective Transform Matrix i.e. lambda
        lambda[cameraId] = getPerspectiveTransform(temp, outputQuad );
        //qDebug << "lambda = "<< endl << " "  << lambda << endl << endl;
        //size_mat_camera[cameraID].setWidth(clickedPoint[cameraId][3].x-clickedPoint[cameraId][4].x), );
        
    }

    emit setLambdaValue(lambda);
