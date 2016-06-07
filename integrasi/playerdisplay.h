#ifndef PLAYERDISPLAY_H
#define PLAYERDISPLAY_H
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <QString>
#include <QImage>
#include <QPixmap>

using namespace cv;
using namespace std;


class PlayerDisplay
{

public:

    PlayerDisplay();
    PlayerDisplay& operator=(PlayerDisplay b);
    //destructor
    ~PlayerDisplay();
    //variable
    int trackedID;
    QString  nama;
    double height;
    double averageSpeed;
    double averageAcceleration;
    double maximumSpeed;
    double maximumAcceleration;
    QImage  photo;
    QPixmap heatmap;

    friend void swap(PlayerDisplay& first, PlayerDisplay& second) {
        using std::swap;
        swap(first.trackedID, second.trackedID);
        swap(first.nama, second.nama);
        swap(first.height, second.height);
        swap(first.averageSpeed, second.averageSpeed);
        swap(first.averageAcceleration, second.averageAcceleration);
        swap(first.maximumSpeed, second.maximumSpeed);
        swap(first.maximumAcceleration, second.maximumAcceleration);
        swap(first.photo, second.photo);
        swap(first.heatmap, second.heatmap);
  }
};

#endif // PLAYERDISPLAY_H
