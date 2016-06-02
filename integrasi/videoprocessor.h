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
#include <cvmatandqimage.h>
#include <iostream>
#include <QDebug>
#include <QList>
#include <QVector>
#include "player.h"
#include "betterblobdetector.h"

using namespace cv;

class VideoProcessor : public QThread
{	Q_OBJECT
private:
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	int frameRate;
	VideoCapture *capture;
	Mat frame, objectFrame, mask, backgroundFrame, maskedFrame, openedFrame, bluredFrame, objectWithKeypointsFrame, image;
	QImage qRawFrame, qMaskedFrame, qBackgroundFrame, qObjectFrame, qOpenedFrame, qBluredFrame, qObjectWithKeypointsFrame;
	BetterBlobDetector::Params params;
	Ptr<BackgroundSubtractor> pMOG2;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	vector<KeyPoint> keypoints;
	vector<Point2f> points;
	QList<Player> outputData;
	Mat morphElement;
	QVector<QImage> allFrames;
	int minArea;
	int maxArea;
	int morphElementSize;
	int gaussianSize;
	int mode;
signals:
	//Signal to output frame to be displayed
	void sendSingleCameraViewImage(const QVector<QImage>);
	void sendCameraObjectData(QList<Player>);
public slots:
	//update parameters
	void setValueParameter(QVector<int>);
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
	bool loadImageForBackgroundModel(String filename);
	//check if the player has been stopped
	//set video properties
	void setCurrentFrame( int frameNumber);
	//Play the processor
	void Play();
	//Stop the processor
	void Stop();
	//check if the player has been stopped
	bool isStopped() const;

	//Get video properties
	double getFrameRate();
	double getCurrentFrame();
	double getNumberOfFrames();
	QImage getFirstFrame();
	void processSingleFrame(int mode);

private:
	void convertMatToQImage(Mat frame, QImage result);
	void maskImage(Mat& frame, Mat& maskedFrame);
	Point maskPoint[1][10];
	int numberOfMaskPoints;
	bool isSetMask;
};

#endif // VIDEOPROCESSOR_H
