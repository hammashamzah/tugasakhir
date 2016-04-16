#include "videoprocessor.h"


using namespace cv;

VideoProcessor::VideoProcessor(QObject *parent): QThread(parent)
{
    qRegisterMetaType<QVector<QImage> >("QVector<QImage>");
    qRegisterMetaType<QList<Player> >("QList<Player>");
    
	stop = true;
    pMOG2 = new BackgroundSubtractorMOG2();
    minArea = 0;
    maxArea = 200;
    morphElementSize = 3;
    gaussianSize = 3;
	isSetMask = false;
	mode = 0;
	allFrames.resize(6);

}
//destructor
VideoProcessor::~VideoProcessor()
{
	mutex.lock();
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

QImage VideoProcessor::getFirstFrame(){
	Mat firstFrame;
	QImage qFirstImage;
	setCurrentFrame(2);
	capture->read(firstFrame);
	setCurrentFrame(1);

    qFirstImage = QtOcv::mat2Image_shared(firstFrame).rgbSwapped().copy();
    qDebug("Aku siap");
    return qFirstImage;
    //emit firstFrameImage(qFirstImage);
}


void VideoProcessor::processSingleFrame()
{
        //set parameters based on tuning from background model tuning window
		params.filterByArea = true;
		params.filterByInertia = false;
		params.filterByConvexity = false;
		params.filterByColor = false;
		params.filterByCircularity = false;
        if(minArea == 0 && maxArea == 0){
            params.filterByArea = false;
        }
		if(minArea > 0){
			params.minArea = minArea;
		}

		if(maxArea > 0){
			params.maxArea = maxArea;
		}
		SimpleBlobDetector blob_detector(params);
        if(morphElementSize > 0){
			morphElement = getStructuringElement(2, Size(morphElementSize, morphElementSize));
		}

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
            qDebug("0");
            frame.copyTo(maskedFrame);
        }
		//update the background model
		pMOG2->operator()(maskedFrame, objectFrame);
        if(morphElementSize > 0){
        	morphologyEx(objectFrame, openedFrame, 2, morphElement);
        }else{
            qDebug("1");
            objectFrame.copyTo(openedFrame);
        }
		if(gaussianSize > 0){
			GaussianBlur(openedFrame, bluredFrame, Size(gaussianSize, gaussianSize), 0, 0, BORDER_DEFAULT);
        }else{
            qDebug("2");
            openedFrame.copyTo(bluredFrame);
        }
        qDebug("3");
        frame.copyTo(objectWithKeypointsFrame);

		if(mode == 0){
			blob_detector.detect(bluredFrame, keypoints);
        	drawKeypoints(objectWithKeypointsFrame, keypoints, objectWithKeypointsFrame, Scalar(0, 0, 255), DrawMatchesFlags::DEFAULT);
        	KeyPoint::convert(keypoints, points);
		}else if(mode == 1){
			findContours(bluredFrame, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
        	vector<Rect>boundRect(contours.size());

	        for (int i = 0; i < contours.size(); i++)
	        {
	            boundRect[i] = boundingRect(contours[i]);
	        }

	        for (int i = 0; i < contours.size(); i++)
	        {
	            rectangle(objectWithKeypointsFrame, boundRect[i].tl(), boundRect[i].br(), Scalar(255,255,255), 2, 8, 0) ;
	        }
		}

        qRawFrame = QtOcv::mat2Image_shared(frame).copy().rgbSwapped();
        qMaskedFrame = QtOcv::mat2Image_shared(maskedFrame).copy().rgbSwapped();
        qObjectFrame = QtOcv::mat2Image_shared(objectFrame).copy().rgbSwapped();
        qOpenedFrame = QtOcv::mat2Image_shared(openedFrame).copy().rgbSwapped();
        qBluredFrame = QtOcv::mat2Image_shared(bluredFrame).copy().rgbSwapped();
        qObjectWithKeypointsFrame = QtOcv::mat2Image_shared(objectWithKeypointsFrame).copy().rgbSwapped();
        //emit raw image
        allFrames[0] = qRawFrame;
        allFrames[1] = qMaskedFrame;
        allFrames[2] = qObjectFrame;
        allFrames[3] = qOpenedFrame;
        allFrames[4] = qBluredFrame;
        allFrames[5] = qObjectWithKeypointsFrame;

        //convert points to Player
        outputData.clear();
        for(int i =0; i < points.size(); i++){
            outputData.append(Player(points[i]));
        }

        emit sendCameraObjectData(outputData);
        emit sendSingleCameraViewImage(allFrames);

}

void VideoProcessor::run(){
    int delay = (3000/frameRate);
	while(!stop){
		processSingleFrame();
		this->msleep(delay);
	}
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

void VideoProcessor::setValueParameter(QVector<int> value){
	minArea = value.at(0);
	maxArea = value.at(1);
	morphElementSize = value.at(2);
	gaussianSize = value.at(3);
}

void VideoProcessor::getMaskCoordinate(QList<QPoint> maskPoints){
    numberOfMaskPoints = maskPoints.count();
	//clean coordinate of mask
    for (int j = 0; j < 10; j++)
	{
        maskPoint[0][j] = Point(0,0);
	}
	//convert QPoint to OpenCV Point
	if(numberOfMaskPoints > 2 && numberOfMaskPoints <= 10){
		int i= 0;
        foreach(QPoint point, maskPoints){
            maskPoint[0][i] = Point(point.x(), point.y());
			i++;
		}
		isSetMask = true;
	}else{
		isSetMask = false;
	}
}

void VideoProcessor::msleep(int ms) {
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
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

void VideoProcessor::Stop()
{
    stop = true;
}

bool VideoProcessor::isStopped() const {
    return this->stop;
}
