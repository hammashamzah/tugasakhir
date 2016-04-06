#include "coordinateconverter.h"

CoordinateConverter::CoordinateConverter(QObject *parent) : QObject(parent)
{

}

/*fungsi ini menerima koordinat pixel kemudian mengembalikan koordinat heat map dilihat dari sudut kiri atas lapangan
 * Seandainya titik nol piksel tidak tepat diujung sudut kiri atas, maka dapat diberikan nilai ofset yang merupakan jarak
 * dari sudut kiri atas ke koordinat origin                                                                               */
QPoint CoordinateConverter::pixelToHeatMap(QPoint pos, int pixel_width, int pixel_height, int offset_x, int offset_y)
{
    //cari ukuran satuan heat map koordinat dalam pixel
    int x_size;
    int y_size;


    x_size = pixel_width/HEAT_MAP_RESOLUTION_X;
    y_size = pixel_height/HEAT_MAP_RESOLUTION_Y;

    return QPoint((pos.x()-offset_x)/x_size, (pos.y()-offset_y)/y_size);
}

/* fungsi ini menerima koordinat pixel kemudian mengembalikan koordinat global lapangan yang ditinjau dari sudut kiri
 * atas lapangan. Jika titik origin tidak berada tepat pada sudut kiri atas, maka gunakan nilai offset pada sumbu x
 * dan sumbu y */
QPoint CoordinateConverter::pixelToReal(QPoint pos, int pixel_width, int pixel_height, int offset_x, int offset_y)
{
    //cari ukuran satu pixel dalam satuan centimeter
    int x_size;
    int y_size;
    QPoint posReal;

    x_size = PANJANG_LAPANGAN_ASLI * pixel_width;
    y_size = LEBAR_LAPANGAN_ASLI * pixel_height;
    posReal.setX((pos.x()-offset_x)/x_size);
    posReal.setY((pos.y()-offset_y)/y_size);
    return posReal;
}
/* fungsi ini mentransformasi perspective */
Mat CoordinateConverter::getPersTransformMatrix(String imageFileName)
{
    Point2f inputQuad[4];
    // Output Quadilateral or World plane coordinates
    Point2f outputQuad[4];
    // Lambda Matrix
    Mat lambda( 2, 4, CV_32FC1 );

    //Load the image
    Mat input=imread(imageFileName);

    // Set the lambda matrix the same type and size as input
    lambda = Mat::zeros( input.rows, input.cols, input.type() );

    inputQuad[0] =Point2f (100, 50);
    inputQuad[1] =Point2f (400, 50);
    inputQuad[2] =Point2f (100, 400);
    inputQuad[3] =Point2f (400, 400);

    // The 4 points where the mapping is to be done , from top-left in clockwise order
    outputQuad[0] = Point2f( 0, 0 );
    outputQuad[1] = Point2f( input.cols, 0);
    outputQuad[2] = Point2f( input.cols, input.rows);
    outputQuad[3] = Point2f( 0, input.rows );

    // Get the Perspective Transform Matrix i.e. lambda
    lambda = getPerspectiveTransform( inputQuad, outputQuad );
    //qDebug << "lambda = "<< endl << " "  << lambda << endl << endl;

    //imshow("lambda", lambda);
    // Apply the Perspective Transform just found to the src image
    //warpPerspective(input,output,lambda,input.size());
    //imwrite("output.jpg", output);
    return lambda;
}

