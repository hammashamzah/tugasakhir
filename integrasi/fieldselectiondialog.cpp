#include "fieldselectiondialog.h"
#include "ui_fieldselectiondialog.h"

FieldSelectionDialog::FieldSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldSelectionDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->imageView, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(processMouse(QPoint&)));
    QObject::connect(ui->imageView, SIGNAL(sendClickPosition(QPoint&)), this, SLOT(processClick(QPoint&)));
    entryMode = 0;
    currentCameraIndex = 0;
    set[0] = false;
    set[1] = false;
    frameCamera.resize(2);
    listOfClickCoordinates.resize(2);
    listOfTrapeziumCoordinates.resize(2);
}

FieldSelectionDialog::~FieldSelectionDialog()
{
    delete ui;
}

void FieldSelectionDialog::setFrame(QVector<QImage> img) {
    ui->imageView->setAlignment(Qt::AlignCenter);
    frameCamera[0] = img.at(0);
    frameCamera[1] = img.at(1);
    if(currentCameraIndex == 0){
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
    }

    if(set[0] && set[1]){

        emit setMaskCoordinates(listOfClickCoordinates);
        emit setTrapeziumCoordinates(listOfTrapeziumCoordinates);
        qDebug("mantap jaya");
    }

}
