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
#include <datainputcam.h>
#include <iostream>
#include <QDebug>

using namespace cv;

class VideoProcessor : public QObject
{	Q_OBJECT
private:
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	int frameRate;
	VideoCapture *capture;
	Mat frame, objectFrame, mask, maskedFrame, openedFrame, bluredFrame, objectWithKeypointsFrame;
	QImage qRawFrame, qMaskedFrame, qObjectFrame, qOpenedFrame, qBluredFrame, qObjectWithKeypointsFrame;
    SimpleBlobDetector::Params params;
	Ptr<BackgroundSubtractor> pMOG2;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	vector<KeyPoint> keypoints;
	vector<Point2f> points;
	QList<DataInputCam> outputData;
    Mat morphElement;
    QVector<QImage> allFrames;
    int minArea;
    int maxArea;
    int morphElementSize;
    int gaussianSize;
    int mode;

signals:
	//Signal to output frame to be displayed
	void setSingleCameraViewImage(const QVector<QImage>);
	void setObjectData(QList<DataInputCam>);

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
    VideoProcessor();
	//Destructor
	~VideoProcessor();
	//Load a video from memory
	bool loadVideo(string filename);
	//check if the player has been stopped
	//set video properties
	void setCurrentFrame( int frameNumber);

	//Get video properties
	double getFrameRate();
	double getCurrentFrame();
	double getNumberOfFrames();
    QImage getFirstFrame();
	void processSingleFrame();


private:
    void convertMatToQImage(Mat frame, QImage result);
    void maskImage(Mat& frame, Mat& maskedFrame);
	Point maskPoint[1][10];
	int numberOfMaskPoints;
	bool isSetMask;
};

#endif // VIDEOPROCESSOR_H
