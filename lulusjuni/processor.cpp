#include "processor.h"

Processor::Processor()
{
	myStream_1 = new VideoProcessor();
	myStream_2 = new VideoProcessor();

	firstFrame_1_set = 0;
	firstFrame_2_set = 0;
	//alocate size of qvector
    
	firstFrame.resize(2);
	cameraViewImage.resize(2);
    cameraViewImage[0].resize(6);
    cameraViewImage[1].resize(6);

    QObject::connect(this, SIGNAL(updateValueParameter_1(QVector<int>)), myStream_1, SLOT(setValueParameter(QVector<int>)));
    QObject::connect(this, SIGNAL(updateValueParameter_2(QVector<int>)), myStream_2, SLOT(setValueParameter(QVector<int>)));
    QObject::connect(this, SIGNAL(updateMaskCoordinate_1(QList<QPoint>)), myStream_1, SLOT(getMaskCoordinate(QList<QPoint>)));
    QObject::connect(this, SIGNAL(updateMaskCoordinate_2(QList<QPoint>)), myStream_2, SLOT(getMaskCoordinate(QList<QPoint>)));
    QObject::connect(myStream_1, SIGNAL(setSingleCameraViewImage(QVector<QImage>)), this, SLOT(updateSingleCameraViewImage_1(QVector<QImage>)));
    QObject::connect(myStream_2, SIGNAL(setSingleCameraViewImage(QVector<QImage>)), this, SLOT(updateSingleCameraViewImage_2(QVector<QImage>)));
}

Processor::~Processor()
{
    //mutex.lock();

	delete myStream_1;
	delete myStream_2;
    //condition.wakeOne();
    //mutex.unlock();
    //wait();
}

void Processor::loadVideo(QString filename, int id) {
	switch (id) {
	case 1:
		if (!filename.isEmpty()) {
			if (!myStream_1->loadVideo(filename.toLatin1().data())) {
				QMessageBox msgBox;
				msgBox.setText("The selected video could not be opened!");
				msgBox.exec();
			} else {
				firstFrame[0] = myStream_1->getFirstFrame();
				qDebug("Aku disini");
				firstFrame_1_set = 1;
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
                firstFrame[1] = (myStream_2->getFirstFrame());
				firstFrame_2_set = 1;
			}
		}
		break;
	}
	if (firstFrame_1_set && firstFrame_2_set) {
		emit firstFrameImage(firstFrame);
	}
}

void Processor::updateValueParameter(QVector< QVector<int> > parameters) {
	emit updateValueParameter_1(parameters.at(0));
	emit updateValueParameter_2(parameters.at(1));
}


void Processor::updateMaskCoordinate(QVector< QList<QPoint> > masks) {
	emit updateMaskCoordinate_1(masks.at(0));
	emit updateMaskCoordinate_2(masks.at(1));
}

void Processor::msleep(int ms) {
	struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
	nanosleep(&ts, NULL);
}

void Processor::playSingleFrame() {
    //cameraViewImage.clear();
    qDebug("Masuk sini");
    myStream_1->processSingleFrame();
    myStream_2->processSingleFrame();
	emit setCameraViewImage(cameraViewImage);

}

void Processor::updateSingleCameraViewImage_1(QVector<QImage> value) {
	cameraViewImage[0] = value;
}

void Processor::updateSingleCameraViewImage_2(QVector<QImage> value) {
	cameraViewImage[1] = value;
}
