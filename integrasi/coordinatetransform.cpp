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
    playerImageCoordinate.clear();
    playerImageCoordinate = data;
    for (int cameraId = 0; cameraId < playerImageCoordinate.size(); cameraId++)
    {
        for (int i = 0; i < playerImageCoordinate.at(cameraId).size() ; i++)
        {
            if (cameraId == 0) {
                playerImageCoordinate[cameraId][i].transformedPos = transformCamera1ToGlobal(playerImageCoordinate[cameraId][i].pos, transform_mat1);
            }
            else {
                playerImageCoordinate[cameraId][i].transformedPos = transformCamera2ToGlobal(playerImageCoordinate[cameraId][i].pos, transform_mat2);
            }
        }
    }
    emit sendTransformedPosition(playerImageCoordinate);
}

//slot untuk menyimpan informasi mat camera dari dialog ke variabel lokal
void CoordinateTransform::setImageSize(QList<QSize> value)
{
    imageSize[0] = value.at(0);
    imageSize[1] = value.at(1);
}

Point2f CoordinateTransform::transformPointToCamera(Point2f picture_coordinate, Mat transform_matrix)
{
    Point2f dst;
    Mat result;
    double src[3] = {(double)picture_coordinate.x, (double)picture_coordinate.y, 1};
    Mat src_coordinate = Mat(3, 1, CV_64FC1, src);

    result = transform_matrix * src_coordinate;

    dst.x = ((int)(result.at<double>(0, 0) / result.at<double>(0, 2)));
    dst.y = ((int)(result.at<double>(0, 1) / result.at<double>(0, 2)));

    return dst;
}

Point2f CoordinateTransform::transformCamera1ToGlobal(Point2f camera_coordinate, Mat transform_matrix)
{
    Point2f dst;
    dst.x = transformPointToCamera(camera_coordinate, transform_matrix).x * GLOBAL_FIELD_LENGTH / 2 / imageSize[0].width();
    dst.y = transformPointToCamera(camera_coordinate, transform_matrix).y * GLOBAL_FIELD_WIDTH / imageSize[0].height();
    return dst;
}

Point2f CoordinateTransform::transformCamera2ToGlobal(Point2f camera_coordinate, Mat transform_matrix)
{
    Point2f dst;
    int offset = GLOBAL_FIELD_LENGTH / 2;
    dst.x = transformPointToCamera(camera_coordinate, transform_matrix).x * GLOBAL_FIELD_LENGTH / 2 / imageSize[1].width() + offset;
    dst.y = transformPointToCamera(camera_coordinate, transform_matrix).y * GLOBAL_FIELD_WIDTH / imageSize[1].height();
    return dst;
}

void CoordinateTransform::setTransformMatrix(QVector<QList<QPoint> > transformationCoordinates) {
//asumsi lebar lapangan adalah 0.5 panjang lapangan

    // Output Quadilateral or World plane coordinates
    cv::Point2f outputQuad[4];
    // Lambda Matrix
    QVector<cv::Mat> lambda;
    lambda.clear();
    lambda.resize(2);

    for (int cameraId = 0; cameraId < 2; cameraId++) {
        // Set the lambda matrix the same type and size as input
        lambda[cameraId] = Mat::zeros( 3, 3, CV_8UC1);

        // The 4 points where the mapping is to be done , from top-left in clockwise order
        outputQuad[0] = Point2f( 0, 0 );
        outputQuad[1] = Point2f( imageSize[cameraId].width() , 0);
        outputQuad[2] = Point2f( imageSize[cameraId].width(), imageSize[cameraId].height());
        outputQuad[3] = Point2f( 0, imageSize[cameraId].height());

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

    }
    transform_mat1 = lambda[0];
    transform_mat2 = lambda[1];
}

void CoordinateTransform::returnAssignedPlayer(QVector<QList<Player> > assigned_player)
{
    assignedPlayer.clear();
    assignedPlayer.resize(2);
    assignedPlayer[0] = assigned_player.at(0);
    assignedPlayer[1] = assigned_player.at(1);
    //qDebug()() << "size sebelum dibersihkan: " << assignedPlayer[0].size()
    //        << " " << assignedPlayer[1].size();
    for (int cameraId = 0; cameraId < assignedPlayer.size(); cameraId++)
    {
        for (int i = 0; i < assignedPlayer.at(cameraId).size() && !assignedPlayer.at(cameraId).isEmpty() ; i++)
        {
            if ((assignedPlayer.at(cameraId).at(i).id == 0) && (!assignedPlayer.at(cameraId).at(i).isValid)) {
                assignedPlayer[cameraId].removeAt(i);
                i--;
            }
        }
    }
    //qDebug()() << "size setelah dibersihkan: " << assignedPlayer.size() << " " << assignedPlayer[0].size()
    //         << " " << assignedPlayer[1].size();
    emit sendPlayerIdAssigned(assignedPlayer);
}
