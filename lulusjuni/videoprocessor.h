#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QPainter>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <iostream>
#include <QDebug>

using namespace cv;

class VideoProcessor : public QThread
{	Q_OBJECT
private:
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	Mat frame;
	int frameRate;
	VideoCapture *capture;
	Mat Mask, RGBframe, objectFrame, maskedFrame, openedFrame, bluredFrame, withKeypointsFrame;
	QImage qRawImage, qMaskedFrame, qOpenedFrame, qBluredFrame, qWithKeypointsFrame;
    SimpleBlobDetector::Params params;
	Ptr<BackgroundSubtractor> pMOG;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	vector<KeyPoint> keypoints;
    Mat morphElement;
    int entryCounter;

    int minArea;
    int maxArea;
    int morphElementSize;
    int gaussianSize;

signals:
//Signal to output frame to be displayed
	//void processedImage(const QImage &image);
	void rawImage(const QImage &image);
	void maskedImage(const QImage &image);
public slots:
	//update parameters
	void updateValueMinArea(int value);
	void updateValueMaxArea(int value);
	void updateValueMorphElementSize(int value);
	void updateValueGaussianSize(int value);
	void getMaskCoordinate(QList<QPoint>);
protected:
	void run();
	void msleep(int ms);
	void maskImage();
public:
	//Constructor
	VideoProcessor(QObject *parent = 0);
	//Destructor
	~VideoProcessor();
	//Load a video from memory
	bool loadVideo(string filename);
	//Play the video
	void Play();
	//Stop the video
	void Stop();
	//check if the player has been stopped
	bool isStopped() const;

	//set video properties
	void setCurrentFrame( int frameNumber);

	//Get video properties
	double getFrameRate();
	double getCurrentFrame();
	double getNumberOfFrames();
	QImage getFirstFrame();

private:
	Point maskPoint[1][10];
	int numberOfMaskPoints;
	bool isSetMask;
};

#endif // VIDEOPROCESSOR_H
