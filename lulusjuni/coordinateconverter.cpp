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

/* input: koordinat piksel gambar asli, matriks transformasi
 * output: koordinat piksel hasil transformasi
 */
QPoint CoordinateConverter::perspectiveTrans(QPoint picture_coordinate, Mat transformer)
{

    Mat result;
    QPoint dst;
    double src[3]={(double)picture_coordinate.x(), (double)picture_coordinate.y(), 1};
    Mat src_coordinate = Mat(3,1,CV_64FC1, src);

    result=transformer*src_coordinate;

    dst.setX((int)(result.at<double>(0,0)/result.at<double>(0,2)));
    dst.setY((int)(result.at<double>(0,1)/result.at<double>(0,2)));

    return dst;
}

