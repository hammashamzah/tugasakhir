#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QPainter>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>


using namespace cv;

Player::Player(QObject *parent): QThread(parent)
{
    stop = true;
    pMOG = new BackgroundSubtractorMOG2();
}


bool Player::loadVideo(String filename) {
    capture.open(filename);
    if (capture.isOpened())
    {
        frameRate = (int) capture.get(CV_CAP_PROP_FPS);
        return true;
    }
    else
        return false;
}


void Player::Play()
{
    if (!isRunning()) {
        if (isStopped()){
            stop = false;
        }
        start(NormalPriority);
    }
}

void Player::run()
{
    int delay = (1000/frameRate);
    while(!stop){
        if (!capture.read(frame))
        {
            stop = true;
        }

        pMOG->operator()(frame,fgMaskMOG);

        if (fgMaskMOG.channels()== 3){
            cv::cvtColor(fgMaskMOG, RGBframe, CV_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),
                              RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {
            img = QImage((const unsigned char*)(fgMaskMOG.data),
                                 fgMaskMOG.cols,fgMaskMOG.rows,QImage::Format_Indexed8);
        }
        emit processedImage(img);
        this->msleep(delay);
    }
}

Player::~Player()
{
    mutex.lock();
    stop = true;
    capture.release();
    condition.wakeOne();
    mutex.unlock();
    wait();
}
void Player::Stop()
{
    stop = true;
}
void Player::msleep(int ms){
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}
bool Player::isStopped() const{
    return this->stop;
}
