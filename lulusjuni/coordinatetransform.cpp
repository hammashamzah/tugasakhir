#include "coordinatetransform.h"

CoordinateTransform::CoordinateTransform(QObject *parent) : QObject(parent)
{

}
/* Melakukan transformasi untuk player yang melakukan keluar masuk frame kamera
 * input : QList dari player yang keluar (lost) dan masuk (found) untuk dua kamera
 * Output : QList dari player yang keluar (lost) dan masuk (found) untuk dua kamera
 *          dengan koordinat global lapangan*/
void CoordinateTransform::processDataFoundLost(QList<QList<DataInputCam>> data_camera)
{
    //data_camera[0] --> lost 
    //data_camera[1] -> found
    QList<QList<DataInputTrans> > lostFoundTransformed;
    Point2f cam_coordinate;
    /*
    for (int i = 0; i <data_camera.size(); ++i)
    {
        lostCamTrans1[i].id =lostCam1.at(i).id;
        cam_coordinate.x = lostCam1.at(i).dataplayer.x;
        cam_coordinate.y = lostCam1.at(i).dataplayer.y;
        lostCamTrans1[i].Pos_trans = this->TransformPointToGlobal(cam_coordinate, lostCam1.at(i).camera);
    }

    for (int i = 0; i < foundCamTrans1.size(); ++i)
    {
        foundCamTrans1[i].id =foundCam1.at(i).id;
        cam_coordinate.x = foundCam1.at(i).dataplayer.x;
        cam_coordinate.y = foundCam1.at(i).dataplayer.y;
        foundCamTrans1[i].Pos_trans = this->TransformPointToGlobal(cam_coordinate, foundCam1.at(i).camera);
    }

    for (int i = 0; i < lostCamTrans2.size(); ++i)
    {
        lostCamTrans2[i].id =lostCam2.at(i).id;
        cam_coordinate.x = lostCam2.at(i).dataplayer.x;
        cam_coordinate.y = lostCam2.at(i).dataplayer.y;
        lostCamTrans2[i].Pos_trans = this->TransformPointToGlobal(cam_coordinate, lostCam2.at(i).camera);
    }

    for (int i = 0; i < foundCamTrans2.size(); ++i)
    {
        foundCamTrans2[i].id =foundCam2.at(i).id;
        cam_coordinate.x = foundCam2.at(i).dataplayer.x;
        cam_coordinate.y = foundCam2.at(i).dataplayer.y;
        foundCamTrans2[i].Pos_trans = this->TransformPointToGlobal(cam_coordinate, foundCam2.at(i).camera);
    }
    */

    
}


//Slot Data Lost Found
void CoordinateTransform::receiveDataLostFound1(QList<QList<DataInputCam> > data_camera)
{
    //process here
    emit sendDataInputTransformed1(lostFoundTransformed);
}

void CoordinateTransform::receiveDataLostFound2(QList<QList<DataInputCam> > data_camera)
{
    //process here
    emit sendDataInputTransformed2(lostFoundTransformed);
}
void CoordinateTransform::transformRawPosition(QVector<Qpoint> data_camera)
{
    //vector 0 -> kamera 1; vector 1 camera 2
    QList<DataInputTrans> transformed;
    //process

    emit sendTransformedRawData(transformed);
}
//slot dari dialog untuk menyimpan nilai transformer
void CoordinateTransform::saveTransformMatrix(QList<Mat> transformer)
{
    transform_matrix1=transformer.at(0);
    //save Transform Matrix

}

//slot untuk menyimpan informasi mat camera dari dialog ke variabel lokal
void CoordinateTransform::saveSizeMatCamera(QList<QSize> mat_size)
{
    mat_camera1_size = mat_size.at(0);
    mat_camera2_size = mat_size.at(1);
}


Point2f CoordinateTransform::TransformPointToGlobal(Point2f pos, int cameraID)
{
    int offset=0;
    if (cameraID==1) offset=PANJANG_LAPANGAN/2;

    //lakukan transformasi
    //return (pos*lambda).x + offset, (pos*lambda).y)
}

Point2f CoordinateTransform::TransformPointToCamera(Point2f picture_coordinate, Mat transform_matrix)
{
    Mat result;
        Point2f dst;
        double src[3]={(double)picture_coordinate.x, (double)picture_coordinate.y, 1};
        Mat src_coordinate = Mat(3,1,CV_64FC1, src);

        result=transform_matrix*src_coordinate;

        dst.setX((int)(result.at<double>(0,0)/result.at<double>(0,2)));
        dst.setY((int)(result.at<double>(0,1)/result.at<double>(0,2)));

        return dst;
}

Point2f CoordinateTransform::TransformCamera1ToGlobal(Point2f camera_coordinate, Mat transform_matrix)
{
   Point2f dst;
   //= TransformPointToCamera(camera_coordinate, transform_matrix1)*PANJANG_LAPANGAN_ASLI/mat_camera1_size.width();
    return dst 
}

Point2f CoordinateTransform::TransformCamera2ToGlobal(Point2f camera_coordinate, Mat transform_matrix)
{
    Point2f dst;
   //= TransformPointToCamera(camera_coordinate, transform_matrix1)*PANJANG_LAPANGAN_ASLI/mat_camera1_size.width();
    return dst;
}

QVector<QList<DataInputCam> > initialIdentification(QVector<QList<DataInputCam> > initialFrameObject){
    //process here to do manual assignment
    
    //transform initial frame object
    transformedInitialFrameObject = transformQVector(initialFrameObject);

    emit setTransformedInitialFrameObject(initialFrameObject);

    QVector<QList<DataInputCam> > identifiedInitialFrameObject;


    
    return identifiedInitialFrameObject;
}