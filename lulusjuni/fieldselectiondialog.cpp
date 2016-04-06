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
}

FieldSelectionDialog::~FieldSelectionDialog()
{
    delete ui;
}

void FieldSelectionDialog::setFrame_1(QImage img1) {
    frameCamera_1 = img1;
    if(currentCameraIndex == 0){
        ui->imageView->setAlignment(Qt::AlignCenter);
        ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_1));
    }
}

void FieldSelectionDialog::setFrame_2(QImage img2) {
    frameCamera_2 = img2;
}

void FieldSelectionDialog::setFrame_3(QImage img3) {
    frameCamera_3 = img3;
}
void FieldSelectionDialog::on_cameraSelectCombo_currentIndexChanged(int index)
{
    currentCameraIndex = index;
    switch (index) {
    case 0:
        if (!frameCamera_1.isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_1));
        }
        break;
    case 1:
        if (!frameCamera_2.isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_2));

        }
        break;
    case 2:
        if (!frameCamera_3.isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_3));

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
        emit maskCoordinates_1(clickCoordinates);
        break;
    case 2:
        emit maskCoordinates_2(clickCoordinates);
        break;
    case 3:
        emit maskCoordinates_3(clickCoordinates);
    }
}
