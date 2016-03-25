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
    pMOG = new BackgroundSubtractorMOG();
}


bool Player::loadVideo(String filename) {
    capture = new cv::VideoCapture(filename);
    if (capture->isOpened())
    {
        frameRate = (int) capture->get(CV_CAP_PROP_FPS);
        if(frameRate < 1){
            frameRate = 24;
        }
        return true;
    }
    else
        return false;
}


void Player::Play()
{
    if (!isRunning()) {
        if (isStopped()) {
            stop = false;
        }
        start(NormalPriority);
    }
}

void Player::run()
{
    int delay = (1000 / frameRate);
    while (!stop) {
        if (!capture->read(frame))
        {
            stop = true;
        }

        pMOG->operator()(frame, fgMaskMOG);

        if (fgMaskMOG.channels() == 3) {
            cv::cvtColor(fgMaskMOG, RGBframe, CV_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),
                         RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
        }
        else
        {
            img = QImage((const unsigned char*)(fgMaskMOG.data),
                         fgMaskMOG.cols, fgMaskMOG.rows, QImage::Format_Indexed8);
        }
        emit processedImage(img);
        this->msleep(delay);
    }
}

void Player::Stop()
{
    stop = true;
}
void Player::msleep(int ms) {
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}
bool Player::isStopped() const {
    return this->stop;
}

double Player::getCurrentFrame() {
    return capture->get(CV_CAP_PROP_POS_FRAMES);
}
double Player::getNumberOfFrames() {
    return capture->get(CV_CAP_PROP_FRAME_COUNT);
}
double Player::getFrameRate() {
    return frameRate;
}
void Player::setCurrentFrame( int frameNumber )
{
    capture->set(CV_CAP_PROP_POS_FRAMES, frameNumber);
}

Player::~Player()
{
    mutex.lock();
    stop = true;
    capture->release();
    delete capture;
    condition.wakeOne();
    mutex.unlock();
    wait();
}
