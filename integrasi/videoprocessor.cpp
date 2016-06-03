#include "videoprocessor.h"


using namespace cv;

VideoProcessor::VideoProcessor(QObject *parent): QThread(parent)
{
    qRegisterMetaType<QVector<QImage> >("QVector<QImage>");
    qRegisterMetaType<QList<Player> >("QList<Player>");

	stop = true;
    //pMOG2 = new BackgroundSubtractorMOG2();
	
    pMOG2_g.history = 3000; //300;
    pMOG2_g.varThreshold = 64; //128; //64; //32;//;
    pMOG2_g.bShadowDetection = true;
	minArea = 0;
	maxArea = 200;
	morphElementSize = 3;
	gaussianSize = 3;
	isSetMask = false;
	mode = 0;
	allFrames.resize(7);

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

bool VideoProcessor::loadImageForBackgroundModel(String filename) {
	image = imread(filename, CV_LOAD_IMAGE_COLOR);

	if (!image.data) {
		return false;
	} else {
		processSingleFrame(1);
		return true;
	}
}

QImage VideoProcessor::getFirstFrame() {
	Mat firstFrame;
	QImage qFirstImage;
	setCurrentFrame(2);
	capture->read(firstFrame);
	setCurrentFrame(1);

	qFirstImage = QtOcv::mat2Image_shared(firstFrame).rgbSwapped().copy();
	//////qDebug()("Aku siap");
	return qFirstImage;
	//emit firstFrameImage(qFirstImage);
}


void VideoProcessor::processSingleFrame(int mode)
{
	//set parameters based on tuning from background model tuning window
	params.filterByArea = true;
	params.filterByInertia = false;
	params.filterByConvexity = false;
	params.filterByColor = false;
	params.filterByCircularity = false;
	if (minArea > 0) {
		params.minArea = minArea;
	}

	if (maxArea > 0) {
		params.maxArea = maxArea;
	}
	BetterBlobDetector blob_detector(params);
	if (morphElementSize > 0) {
		morphElement = getStructuringElement(2, Size(morphElementSize, morphElementSize));
	}
	if (mode == 0) {
		if (!capture->read(frame))
		{
			stop = true;
		}
	} else if (mode == 1) {
		image.copyTo(frame);
	}

	//mask object
	//maskImage(frame, maskedFrame);
	mask = Mat::zeros(frame.size(), CV_8UC3);
	if (isSetMask) {
		const Point * ppt[1] = {maskPoint[0]};
		int npt[] = {numberOfMaskPoints};
		fillPoly(mask, ppt, npt, 1, Scalar(255, 255, 255), 8);
		frame.copyTo(maskedFrame, mask);
	} else {
		frame.copyTo(maskedFrame);
	}
	//update the background model
    gpuMaskedFrame.upload(maskedFrame);
    pMOG2_g.operator()(gpuMaskedFrame, gpuObjectFrame, 0.001);
    pMOG2_g.getBackgroundImage(gpuBackgroundFrame);
    //pMOG2->operator()(maskedFrame, objectFrame, 0);
    //pMOG2->getBackgroundImage(backgroundFrame);

    gpuObjectFrame.download(objectFrame);
    gpuBackgroundFrame.download(backgroundFrame);
	if (gaussianSize > 0) {
		GaussianBlur(objectFrame, bluredFrame, Size(gaussianSize, gaussianSize), 0, 0, BORDER_DEFAULT);
	} else {
		objectFrame.copyTo(bluredFrame);
	}

	if (morphElementSize > 0) {
		morphologyEx(bluredFrame, openedFrame, 2, morphElement);
	} else {
		bluredFrame.copyTo(openedFrame);
	}

	frame.copyTo(objectWithKeypointsFrame);

	std::vector < std::vector<cv::Point> > contours_detected;

	blob_detector.detectImpl(openedFrame, keypoints, contours_detected);
//	contours_detected = blob_detector.getContours();
	drawKeypoints(objectWithKeypointsFrame, keypoints, objectWithKeypointsFrame, Scalar(0, 0, 255), DrawMatchesFlags::DEFAULT);

	vector<Rect> boundRect(contours_detected.size());

	//calculate contour area then using k-means clustering to cluster it into two labels; noise and real object
	int dataLabel;
	Mat centers;
	Mat contour_area(contours_detected.size(), 1, CV_32FC1), labels;
	/*for(int i = 0; i < contours_detected.size(); i++){
		contour_area.at<float>(i,1) = contourArea(contours_detected.at(i));
	}
	if(contours_detected.size() > 2){
	    kmeans(contour_area, 2, labels, TermCriteria(TermCriteria::EPS+TermCriteria::COUNT, 10, 1.0), 3, KMEANS_RANDOM_CENTERS, centers);
	    if(centers.at<float>(0,0) < centers.at<float>(1,0)){
	        dataLabel = 1;
	        //qDebug() << "center 1: " << centers.at<float>(0,0) << " center 2: " << centers.at<float>(1,0);
	    }else{
	        dataLabel = 0;
	        //qDebug() << "center 1: " << centers.at<float>(1,0) << " center 2: " << centers.at<float>(0,0);
	    }
	}*/

	for (int i = 0; i < contours_detected.size(); i++) {
		boundRect[i] = boundingRect(contours_detected[i]);
	}

	for (int i = 0; i < contours_detected.size(); i++) {
		//if(contour_area.at<float>(i,1) > 10){
		//if(labels.at<int>(i,0) == dataLabel){
		rectangle(objectWithKeypointsFrame, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 255, 255), 2);
		//   }else{
		//       rectangle(objectWithKeypointsFrame, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 0));
		//   }
		//}
	}

	KeyPoint::convert(keypoints, points);

	qRawFrame = QtOcv::mat2Image_shared(frame).copy().rgbSwapped();
	qMaskedFrame = QtOcv::mat2Image_shared(maskedFrame).copy().rgbSwapped();
	qBackgroundFrame = QtOcv::mat2Image_shared(backgroundFrame).copy().rgbSwapped();
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
	allFrames[6] = qBackgroundFrame;

	//convert points to Player
	outputData.clear();
	for (int i = 0; i < points.size(); i++) {
		outputData.append(Player((int)this->getCurrentFrame(), 0, Point2f(points[i].x, points[i].y)));
	}
	emit sendCameraObjectData(outputData);
	emit sendSingleCameraViewImage(allFrames);

}

void VideoProcessor::run() {
	int delay = (1000 / frameRate);
	while (!stop) {
		processSingleFrame(0);
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

void VideoProcessor::setValueParameter(QVector<int> value) {
	minArea = value.at(0);
	maxArea = value.at(1);
	morphElementSize = value.at(2);
	gaussianSize = value.at(3);
}

void VideoProcessor::getMaskCoordinate(QList<QPoint> maskPoints) {
	numberOfMaskPoints = maskPoints.count();
	//clean coordinate of mask
	for (int j = 0; j < 10; j++)
	{
		maskPoint[0][j] = Point(0, 0);
	}
	//convert QPoint to OpenCV Point
	if (numberOfMaskPoints > 2 && numberOfMaskPoints <= 10) {
		int i = 0;
		foreach (QPoint point, maskPoints) {
			maskPoint[0][i] = Point(point.x(), point.y());
			i++;
		}
		isSetMask = true;
	} else {
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

