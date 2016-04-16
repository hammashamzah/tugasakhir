#include "objectdetector.h"

ObjectDetector::ObjectDetector()
{
	qRegisterMetaType<QVector<QImage> >("QVector<QImage>");
	qRegisterMetaType<QList<Player> >("QList<Player>");

	myStream_1 = new VideoProcessor();
	myStream_2 = new VideoProcessor();
	isSetFirstFrame[0] = false;
	isSetFirstFrame[1] = false;
	myTrackingInitialized = false;
	//alocate size of qvector
	setData[0] = false;
	setData[1] = false;
	setImage[0] = false;
	setImage[1] = false;

	allOutputDataCam.resize(2);

	firstFrameImage.resize(2);
	cameraViewImage.resize(2);
	cameraViewImage[0].resize(6);
	cameraViewImage[1].resize(6);
	QObject::connect(this, SIGNAL(updateValueParameter_1(QVector<int>)), myStream_1, SLOT(setValueParameter(QVector<int>)));
	QObject::connect(this, SIGNAL(updateValueParameter_2(QVector<int>)), myStream_2, SLOT(setValueParameter(QVector<int>)));
	QObject::connect(this, SIGNAL(setMaskCoordinate_1(QList<QPoint>)), myStream_1, SLOT(getMaskCoordinate(QList<QPoint>)));
	QObject::connect(this, SIGNAL(setMaskCoordinate_2(QList<QPoint>)), myStream_2, SLOT(getMaskCoordinate(QList<QPoint>)));
	QObject::connect(myStream_1, SIGNAL(sendSingleCameraViewImage(QVector<QImage>)), this, SLOT(updateSingleCameraViewImage_1(QVector<QImage>)));
	QObject::connect(myStream_2, SIGNAL(sendSingleCameraViewImage(QVector<QImage>)), this, SLOT(updateSingleCameraViewImage_2(QVector<QImage>)));

	QObject::connect(myStream_1, SIGNAL(sendCameraObjectData(QList<Player>)), this, SLOT(updateObjectData_1(QList<Player>)));
	QObject::connect(myStream_2, SIGNAL(sendCameraObjectData(QList<Player>)), this, SLOT(updateObjectData_2(QList<Player>)));

}

ObjectDetector::~ObjectDetector()
{
	//mutex.lock();

	delete myStream_1;
	delete myStream_2;
	//condition.wakeOne();
	//mutex.unlock();
	//wait();
}

void ObjectDetector::loadVideo(QString filename, int id) {
	switch (id) {
	case 1:
		if (!filename.isEmpty()) {
			if (!myStream_1->loadVideo(filename.toLatin1().data())) {
				QMessageBox msgBox;
				msgBox.setText("The selected video could not be opened!");
				msgBox.exec();
			} else {
				firstFrameImage[0] = myStream_1->getFirstFrame();
				isSetFirstFrame[0] = true;
			}
		}
		break;
	case 2:
		if (!filename.isEmpty()) {
			if (!myStream_2->loadVideo(filename.toLatin1().data())) {
				QMessageBox msgBox;
				msgBox.setText("The selected video could not be opened!");
				msgBox.exec();
			} else {
				firstFrameImage[1] = (myStream_2->getFirstFrame());
				isSetFirstFrame[1] = true;
			}
		}
		break;
	}
	if (isSetFirstFrame[0] && isSetFirstFrame[1]) {
		emit sendFirstFrameImage(firstFrameImage);
	}
}

void ObjectDetector::updateValueParameter(QVector< QVector<int> > parameters) {
	emit updateValueParameter_1(parameters.at(0));
	emit updateValueParameter_2(parameters.at(1));
	if (!myTrackingInitialized) {
		myAssociationThresholds.clear();
		//pixel threshold 1
		myAssociationThresholds.append(parameters[0][4]);
		//pixel threshold 2
		myAssociationThresholds.append(parameters[0][5]);
		//transformed threshold 1
		myAssociationThresholds.append(parameters[1][4]);
		//transformed threshold 2
		myAssociationThresholds.append(parameters[1][5]);
	}
}


void ObjectDetector::setMaskCoordinate(QVector< QList<QPoint> > masks) {
	emit setMaskCoordinate_1(masks.at(0));
	emit setMaskCoordinate_2(masks.at(1));
}

void ObjectDetector::msleep(int ms) {
	struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
	nanosleep(&ts, NULL);
}

void ObjectDetector::playSingleFrame() {
	myStream_1->processSingleFrame();
	myStream_2->processSingleFrame();
	emit sendCameraViewImage(cameraViewImage);
}

void ObjectDetector::playContinously() {
	if (myStream_1->isStopped() && myStream_2->isStopped()) {
		myStream_1->Play();
		myStream_2->Play();
	} else {
		myStream_1->Stop();
		myStream_2->Stop();
	}
}

void ObjectDetector::stop(){
	if (!myStream_1->isStopped() || !myStream_2->isStopped()) {
		myStream_1->Stop();
		myStream_2->Stop();
	}
}

void ObjectDetector::setCurrentFrame(int value){
    myStream_1->setCurrentFrame(value);
    myStream_2->setCurrentFrame(value);
}

int ObjectDetector::getNumberOfFrames(){
    if(myStream_1->getNumberOfFrames() >= myStream_2->getNumberOfFrames()){
		return (int)myStream_2->getNumberOfFrames();
	}else{
		return (int)myStream_1->getNumberOfFrames();
	}
}

int ObjectDetector::getFrameRate(){
	return (int)myStream_1->getFrameRate();
}

int ObjectDetector::getCurrentFrame(){
	return (int)myStream_1->getCurrentFrame();
}
/*void ObjectDetector::initializeFirstFrameObject(){
	initialFrameObject.clear();
	initialFrameObject.resize(2);
	initialFrameObject[0] = myStream_1->getFirstFrameObject();
	initialFrameObject[1] = myStream_2->getFirstFrameObject();
	unifiedInitialFrameObject = myCoordinateTransform->initialIdentification(initialFrameObject);
	myTrackingInitialized = true;
	myTracking->setParameters(myStream1->getFrameRate(), myTrapeziumCoordinates, myAssociationThresholds,unifiedInitialFrameObject);
}
*/
void ObjectDetector::updateSingleCameraViewImage_1(QVector<QImage> value) {
	cameraViewImage[0] = value;
	setImage[0] = true;
	if (setImage[0] && setImage[1]) {
		emit sendCameraViewImage(cameraViewImage);
		setImage[0] = false;
		setImage[1] = false;
	}
}

void ObjectDetector::updateSingleCameraViewImage_2(QVector<QImage> value) {
	cameraViewImage[1] = value;
	setImage[1] = true;
	if (setImage[0] && setImage[1]) {
		emit sendCameraViewImage(cameraViewImage);
		setImage[0] = false;
		setImage[1] = false;
	}
}

void ObjectDetector::updateTrapeziumCoordinates(QVector<QList<QPoint> > value) {
	myTrapeziumCoordinates.clear();
	myTrapeziumCoordinates.resize(2);
	myTrapeziumCoordinates = value;

}

void ObjectDetector::updateObjectData_1(QList<Player> outputDataCam) {

	allOutputDataCam[0] = outputDataCam;
	setData[0] = true;
}

void ObjectDetector::updateObjectData_2(QList<Player> outputDataCam) {
	allOutputDataCam[1] = outputDataCam;
	setData[1] = true;
	if (setData[0] && setData[1]) {
		emit sendObjectData(allOutputDataCam);
	}
}

void ObjectDetector::showPlayerIdAssigned(QVector<QList<Player> > assignedPlayerData){
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < assignedPlayerData[i].size(); ++j)
		{
			qDebug() << assignedPlayerData[i][j].id << assignedPlayerData[i][j].pos.x << assignedPlayerData[i][j].pos.y;
		}
	}
}
