#include "videoprocessor.h"


using namespace cv;

VideoProcessor::VideoProcessor(QObject *parent): QThread(parent)
{
	stop = true;
	pMOG = new BackgroundSubtractorMOG();

	minArea = 0;
	maxArea = 200;
	morphElementSize = 3;
	gaussianSize = 3;
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
		if (!capture->read(frame))
		{
			stop = true;
		}

		//emit raw image
		cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
		qRawImage = QImage((const unsigned char*)(RGBframe.data),
		                   RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
		emit rawImage(qRawImage);

		if(entryCounter == 4){
			//do masking
			maskImage(frame, frame, maskPoint);
		}
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

		//masking object
		//maskedFrame = frame;
		//update the background model
		pMOG->operator()(frame, objectFrame);

		morphologyEx(objectFrame, openedFrame, 2, morphElement);
		GaussianBlur(openedFrame, bluredFrame, Size(gaussianSize, gaussianSize), 0, 0, BORDER_DEFAULT);


		blob_detector.detect(bluredFrame, keypoints);

		drawKeypoints(objectFrame, keypoints, objectFrame, Scalar(0, 0, 255), DrawMatchesFlags::DEFAULT);
		
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

void VideoProcessor::getMaskCoordinate_a(QPoint &pos){
    //std::cout << "coordinate a: " << pos.x() << "," << pos.y() << "\n";
	maskPoint[1] = Point(pos.x(), pos.y());    
}

void VideoProcessor::getMaskCoordinate_b(QPoint &pos){
    //std::cout << "coordinate b: " << pos.x() << "," << pos.y() << "\n";
	maskPoint[2] = Point(pos.x(), pos.y());
}

void VideoProcessor::getMaskCoordinate_c(QPoint &pos){
    //std::cout << "coordinate c: " << pos.x() << "," << pos.y() << "\n";
	maskPoint[3] = Point(pos.x(), pos.y());
}

void VideoProcessor::getMaskCoordinate_d(QPoint &pos){
    //std::cout << "coordinate d: " << pos.x() << "," << pos.y() << "\n";
	maskPoint[0] = Point(pos.x(), pos.y());
}

void VideoProcessor::maskImage(Mat &img, Mat &result, Point maskPoint[]){
	int lineType = 8;
	Point mask_point[1][5];
    mask_point[0][0] = maskPoint[1];
    mask_point[0][1] = maskPoint[2];
    mask_point[0][2] = maskPoint[3];
    mask_point[0][3] = maskPoint[0];
    const Point * ppt[1] = {mask_point[0]};
    int npt[] = {5};
    fillPoly(img, ppt, npt, 1, Scalar(0,0,0), lineType);
}