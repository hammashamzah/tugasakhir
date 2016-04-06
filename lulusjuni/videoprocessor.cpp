#include "videoprocessor.h"


using namespace cv;

VideoProcessor::VideoProcessor(QObject *parent): QThread(parent)
{
	stop = true;
    pMOG2 = new BackgroundSubtractorMOG2();

	minArea = 0;
	maxArea = 200;
	morphElementSize = 3;
	gaussianSize = 3;
	isSetMask = false;
	mode = 1;
}
//destructor
VideoProcessor::~VideoProcessor()
{
	mutex.lock();
	stop = true;
	capture->release();
	delete capture;
	condition.wakeOne();
	mutex.unlock();
	wait();
}

bool VideoProcessor::loadVideo(String filename) {
	capture = new cv::VideoCapture(filename);
	if (capture->isOpened())
	{
		frameRate = (int) capture->get(CV_CAP_PROP_FPS);
		//normalize to 24 fps if fps of the video can't be detected
		if (frameRate < 1) {
			frameRate = 24;
		}
		return true;
	}
	else
		return false;
}

void VideoProcessor::getFirstFrame(){
	Mat firstFrame;
	QImage qFirstImage;
	setCurrentFrame(2);
	capture->read(firstFrame);
	setCurrentFrame(1);

    qFirstImage = QtOcv::mat2Image_shared(firstFrame).rgbSwapped().copy();
    emit firstFrameImage(qFirstImage);
}

void VideoProcessor::Play()
{
	if (!isRunning()) {
		if (isStopped()) {
			stop = false;
		}
		start(NormalPriority);
	}
}

void VideoProcessor::run()
{
	int delay = (1000 / frameRate);
	while (!stop) {
		//set parameters based on tuning from background model tuning window
		params.filterByArea = true;
		params.filterByInertia = false;
		params.filterByConvexity = false;
		params.filterByColor = false;
		params.filterByCircularity = false;
		params.minArea = minArea;
		params.maxArea = maxArea;
		SimpleBlobDetector blob_detector(params);
		morphElement = getStructuringElement(2, Size(morphElementSize, morphElementSize));

		if (!capture->read(frame))
		{
			stop = true;
		}

		//mask object
        //maskImage(frame, maskedFrame);
        mask = Mat::zeros(frame.size(), CV_8UC3);
        if(isSetMask){
            const Point * ppt[1] = {maskPoint[0]};
            int npt[] = {numberOfMaskPoints};
            fillPoly(mask, ppt, npt, 1, Scalar(255,255,255), 8);
            frame.copyTo(maskedFrame, mask);
        }else{
            maskedFrame = frame;
        }
		//update the background model
		pMOG2->operator()(maskedFrame, objectFrame);

		morphologyEx(objectFrame, openedFrame, 2, morphElement);
		GaussianBlur(openedFrame, bluredFrame, Size(gaussianSize, gaussianSize), 0, 0, BORDER_DEFAULT);

        objectWithKeypointsFrame = frame;

		if(mode == 0){
			blob_detector.detect(bluredFrame, keypoints);
        	drawKeypoints(objectWithKeypointsFrame, keypoints, objectWithKeypointsFrame, Scalar(0, 0, 255), DrawMatchesFlags::DEFAULT);
		}else if(mode == 1){
			findContours(bluredFrame, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
        	vector<Rect>boundRect(contours.size());

	        for (int i = 0; i < contours.size(); i++)
	        {
	            boundRect[i] = boundingRect(contours[i]);
	        }

	        for (int i = 0; i < contours.size(); i++)
	        {
	            rectangle(bluredFrame, boundRect[i].tl(), boundRect[i].br(), Scalar(255,255,255), 2, 8, 0) ;
	        }
		}



        qRawImage = QtOcv::mat2Image_shared(frame).copy().rgbSwapped();
        qMaskedFrame = QtOcv::mat2Image_shared(maskedFrame).copy().rgbSwapped();
        qObjectFrame = QtOcv::mat2Image_shared(objectFrame).copy().rgbSwapped();
        qOpenedFrame = QtOcv::mat2Image_shared(openedFrame).copy().rgbSwapped();
        qBluredFrame = QtOcv::mat2Image_shared(bluredFrame).copy().rgbSwapped();
        qObjectWithKeypointsFrame = QtOcv::mat2Image_shared(objectWithKeypointsFrame).copy().rgbSwapped();
        //emit raw image
        emit rawImage(qRawImage);
        emit maskedImage(qMaskedFrame);
        emit objectImage(qObjectFrame);
        emit openedImage(qOpenedFrame);
        emit bluredImage(qBluredFrame);
        emit objectWithKeypointsImage(qObjectWithKeypointsFrame);

        this->msleep(delay);
	}
}

void VideoProcessor::Stop()
{
	stop = true;
}
void VideoProcessor::msleep(int ms) {
	struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
	nanosleep(&ts, NULL);
}
bool VideoProcessor::isStopped() const {
	return this->stop;
}

double VideoProcessor::getCurrentFrame() {
	return capture->get(CV_CAP_PROP_POS_FRAMES);
}
double VideoProcessor::getNumberOfFrames() {
	return capture->get(CV_CAP_PROP_FRAME_COUNT);
}
double VideoProcessor::getFrameRate() {
	return frameRate;
}
void VideoProcessor::setCurrentFrame( int frameNumber )
{
	capture->set(CV_CAP_PROP_POS_FRAMES, frameNumber);
}

void VideoProcessor::updateValueMinArea(int value) {
	minArea = value; 
}
void VideoProcessor::updateValueMaxArea(int value) {
	maxArea = value;
}
void VideoProcessor::updateValueMorphElementSize(int value) {
	morphElementSize = value;
}
void VideoProcessor::updateValueGaussianSize(int value) {
	gaussianSize = value;
}

void VideoProcessor::getMaskCoordinate(QList<QPoint> maskPoints){
    numberOfMaskPoints = maskPoints.count();
    QString message = "Number of points is: " + QString::number(numberOfMaskPoints);
    qDebug() << message;
	//clean coordinate of mask
    for (int j = 0; j < 10; j++)
	{
        maskPoint[0][j] = Point(0,0);
	}
	//convert QPoint to OpenCV Point
	if(numberOfMaskPoints > 2 && numberOfMaskPoints <= 10){
		int i= 0;
        foreach(QPoint point, maskPoints){
			qDebug() << point;
            maskPoint[0][i] = Point(point.x(), point.y());
			i++;
		}
		isSetMask = true;
	}else{
        qDebug("Too many points, Baby");
		isSetMask = false;
	}
}

void VideoProcessor::maskImage(){
    mask = Mat::ones(frame.size(), CV_8UC3) * 255;
	if(isSetMask){
	    const Point * ppt[1] = {maskPoint[0]};
	    int npt[] = {numberOfMaskPoints};
	    fillPoly(mask, ppt, npt, 1, Scalar(0,0,0), 8);
	}
	mask = Mat::zeros(frame.size(), CV_8UC3) - mask;
	maskedFrame = frame.mul(mask);
}

void VideoProcessor::maskImage(Mat& frame, Mat& maskedFrame){
    mask = Mat::zeros(frame.size(), CV_8UC3);
	if(isSetMask){
	    const Point * ppt[1] = {maskPoint[0]};
	    int npt[] = {numberOfMaskPoints};
	    fillPoly(mask, ppt, npt, 1, Scalar(255,255,255), 8);
		frame.copyTo(maskedFrame, mask);
	}else{
		maskedFrame = frame;
	}
}


