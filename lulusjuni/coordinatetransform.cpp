#include "coordinatetransform.h"

CoordinateTransform::CoordinateTransform(QObject *parent) : QObject(parent)
{

}
/* Melakukan transformasi untuk player yang melakukan keluar masuk frame kamera
 * input : QList dari player yang keluar (lost) dan masuk (found) untuk dua kamera
 * Output : QList dari player yang keluar (lost) dan masuk (found) untuk dua kamera
 *          dengan koordinat global lapangan*/
void CoordinateTransform::processDataQFoundLost(QList<DataInputCam> lostCam1, QList<DataInputCam> foundCam1, QList<DataInputCam> lostCam2, QList<DataInputCam> foundCam2)
{
    QList<DataInputTrans> lostCamTrans1;
    QList<DataInputTrans> foundCamTrans1;
    QList<DataInputTrans> lostCamTrans2;
    QList<DataInputTrans> foundCamTrans2;
    Point2f cam_coordinate;

    for (int i = 0; i < lostCamTrans1.size(); ++i)
    {
        lostCamTrans1[i].id =lostCam1.at(i).id;
        cam_coordinate.x = lostCam1.at(i).dataplayer.x;
        cam_coordinate.y = lostCam1.at(i).dataplayer.y;
        lostCamTrans1[i].Pos_trans = this->TransformPoint(cam_coordinate, lostCam1.at(i).camera);
    }

    for (int i = 0; i < foundCamTrans1.size(); ++i)
    {
        foundCamTrans1[i].id =foundCam1.at(i).id;
        cam_coordinate.x = foundCam1.at(i).dataplayer.x;
        cam_coordinate.y = foundCam1.at(i).dataplayer.y;
        foundCamTrans1[i].Pos_trans = this->TransformPoint(cam_coordinate, foundCam1.at(i).camera);
    }

    for (int i = 0; i < lostCamTrans2.size(); ++i)
    {
        lostCamTrans2[i].id =lostCam2.at(i).id;
        cam_coordinate.x = lostCam2.at(i).dataplayer.x;
        cam_coordinate.y = lostCam2.at(i).dataplayer.y;
        lostCamTrans2[i].Pos_trans = this->TransformPoint(cam_coordinate, lostCam2.at(i).camera);
    }

    for (int i = 0; i < foundCamTrans2.size(); ++i)
    {
        foundCamTrans2[i].id =foundCam2.at(i).id;
        cam_coordinate.x = foundCam2.at(i).dataplayer.x;
        cam_coordinate.y = foundCam2.at(i).dataplayer.y;
        foundCamTrans2[i].Pos_trans = this->TransformPoint(cam_coordinate, foundCam2.at(i).camera);
    }

    emit sendDataInputTransformed(lostCamTrans1, foundCamTrans1, lostCamTrans2, foundCamTrans2);
}

void CoordinateTransform::getTransformMat(QPoint clicked1, QPoint clicked2, QPoint clicked3, QPoint clicked4, Mat image)
{

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

        result=transfor_matrix*src_coordinate;

        dst.setX((int)(result.at<double>(0,0)/result.at<double>(0,2)));
        dst.setY((int)(result.at<double>(0,1)/result.at<double>(0,2)));

        return dst;
}
