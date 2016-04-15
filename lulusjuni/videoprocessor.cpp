#include "videoprocessor.h"


using namespace cv;

VideoProcessor::VideoProcessor()
{
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
    return qFirstImage;
}

void VideoProcessor::processSingleFrame()
{
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

        //convert points to DataInputCam
        outputData.clear();
        for(int i =0; i < points.size(); i++){
            DataInputCam temp(points[i]);
            outputData.append(temp);
            //outputData.append(DataInputCam(points[i]));
        }

        emit setObjectData(outputData);
        emit setSingleCameraViewImage(allFrames);

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


