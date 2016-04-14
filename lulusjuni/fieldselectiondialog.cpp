#include "fieldselectiondialog.h"
#include "ui_fieldselectiondialog.h"

FieldSelectionDialog::FieldSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldSelectionDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->imageView, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(processMouse(QPoint&)));
    QObject::connect(ui->imageView, SIGNAL(sendClickPosition(QPoint&)), this, SLOT(processClick(QPoint&)));
    QObject::connect(this, SIGNAL(setTransformationCoordinates(QVector<QList<QPoint> >)), this, SLOT(getMatrix(QVector<QList<QPoint> >)));
    entryMode = 0;
    currentCameraIndex = 0;
    set[0] = false;
    set[1] = false;
    set[2] = false;
    set[3] = false;
    frameCamera.resize(2);
    listOfClickCoordinates.resize(4);
    listOfTrapeziumCoordinates.resize(2);
    listOfTransformationCoordinates.resize(2);
}

FieldSelectionDialog::~FieldSelectionDialog()
{
    delete ui;
}

void FieldSelectionDialog::setFrame(QVector<QImage> img) {
    ui->imageView->setAlignment(Qt::AlignCenter);
    frameCamera[0] = img.at(0);
    frameCamera[1] = img.at(1);
    if (currentCameraIndex == 0) {
        ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(0)));
    }
}

void FieldSelectionDialog::on_cameraSelectCombo_currentIndexChanged(int index)
{
    currentCameraIndex = index;
    switch (index) {
    case 0:
        if (!frameCamera.at(0).isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(0)));
        }
        break;
    case 1:
        if (!frameCamera.at(1).isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(1)));
        }
        break;
    case 2:
        if (!frameCamera.at(0).isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(0)));
        }
        break;
    case 3:
        if (!frameCamera.at(1).isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(1)));
        }
        break;
    case 4:
        if (!frameCamera.at(0).isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(0)));
        }
        break;
    case 5:
        if (!frameCamera.at(1).isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(1)));
        }
        break;
    }
}

void FieldSelectionDialog::processMouse(QPoint &pos) {
    //for display. not really necessary
}

void FieldSelectionDialog::processClick(QPoint &pos) {
    if (entryMode == 1) {
        clickCoordinates.append(pos);
    }
}

void FieldSelectionDialog::on_pushButton_set_released()
{
    //set to entry mode
    entryMode = 1;
    //clean up coordinate of mask
    clickCoordinates.clear();
}


void FieldSelectionDialog::on_pushButton_apply_released()
{
    entryMode = 0;
    //assign data then emit
    switch (currentCameraIndex + 1) {
    case 1:
        listOfClickCoordinates[0] = clickCoordinates;
        set[0] = true;
        break;
    case 2:
        listOfClickCoordinates[1] = clickCoordinates;
        set[1] = true;
        break;
    case 3:
        listOfTrapeziumCoordinates[0] = clickCoordinates;
        break;
    case 4:
        listOfTrapeziumCoordinates[1] = clickCoordinates;
        break;
    case 5:
        listOfTransformationCoordinates[0] = clickCoordinates;
        set[2] = true;
        break;
    case 6:
        listOfTransformationCoordinates[1] = clickCoordinates;
        set[3] = true;
        break;
    }

    if (set[0] && set[1] && set[2] && set[3]) {

        emit setMaskCoordinates(listOfClickCoordinates);
        emit setTrapeziumCoordinates(listOfTrapeziumCoordinates);
        emit setTransformationCoordinates(listOfTransformationCoordinates);
    }
}


void FieldSelectionDialog::getMatrix(QVector<QList<QPoint> > coordinates)
{
    //asumsi lebar lapangan adalah 0.5 panjang lapangan
    double size_ratio = 0.5;

    // Output Quadilateral or World plane coordinates
    cv::Point2f outputQuad[4];
    // Lambda Matrix
    QVector<cv::Mat> lambda;
    lambda.clear();
    lambda.resize(2);

    for (int cameraId = 0; cameraId < 2; cameraId++) {
        //size_mat_camera[cameraId].setWidth(clickedPoint[cameraId][3].x - clickedPoint[cameraId][4].x);
        //size_mat_camera[cameraId].setHeight(size_ratio * size_mat_camera[cameraId].width(););

        // Set the lambda matrix the same type and size as input
        lambda[cameraId] = Mat::zeros( 1920, 1080, CV_8UC1);

        // The 4 points where the mapping is to be done , from top-left in clockwise order
        outputQuad[0] = Point2f( 0, 0 );
        outputQuad[1] = Point2f( 1920 , 0);
        outputQuad[2] = Point2f( 1920, 1080);
        outputQuad[3] = Point2f( 0, 1080);

        Point2f temp[4];

        temp[0].x = listOfTransformationCoordinates[cameraId][0].x();
        temp[0].y = listOfTransformationCoordinates[cameraId][0].y();
        temp[1].x = listOfTransformationCoordinates[cameraId][1].x();
        temp[1].y = listOfTransformationCoordinates[cameraId][1].y();
        temp[2].x = listOfTransformationCoordinates[cameraId][2].x();
        temp[2].y = listOfTransformationCoordinates[cameraId][2].y();
        temp[3].x = listOfTransformationCoordinates[cameraId][3].x();
        temp[3].y = listOfTransformationCoordinates[cameraId][3].y();

        // Get the Perspective Transform Matrix i.e. lambda
        lambda[cameraId] = getPerspectiveTransform(temp, outputQuad );
        //qDebug << "lambda = "<< endl << " "  << lambda << endl << endl;
        //size_mat_camera[cameraID].setWidth(clickedPoint[cameraId][3].x-clickedPoint[cameraId][4].x), );
        
    }

    emit setLambdaValue(lambda);
}
