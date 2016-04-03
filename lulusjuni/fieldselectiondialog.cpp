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

void FieldSelectionDialog::setFrame_1(QImage img) {
    frameCamera_1 = img;
}

void FieldSelectionDialog::setFrame_2(QImage img) {
    frameCamera_2 = img;
}

void FieldSelectionDialog::setFrame_3(QImage img) {
    frameCamera_3 = img;
}
void FieldSelectionDialog::on_cameraSelectCombo_currentIndexChanged(int index)
{
    currentCameraIndex = index;
    switch (index) {
    case 0:
        if (!frameCamera_1.isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_1).scaled(ui->imageView->size(),
                                     Qt::KeepAspectRatio, Qt::FastTransformation));
        }
        break;
    case 1:
        if (!frameCamera_2.isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_2).scaled(ui->imageView->size(),
                                     Qt::KeepAspectRatio, Qt::FastTransformation));

        }
        break;
    case 2:
        if (!frameCamera_3.isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_3).scaled(ui->imageView->size(),
                                     Qt::KeepAspectRatio, Qt::FastTransformation));

        }
        break;
    }

}

void FieldSelectionDialog::processMouse(QPoint &pos) {
    //for display. not really necessary
}

void FieldSelectionDialog::processClick(QPoint &pos) {
    if (entryMode == 1) {
        clickCoordinates[entryCounter].setX(pos.x());
        clickCoordinates[entryCounter].setY(pos.y());
        if (entryCounter < 3) {
            entryCounter++;
        } else {
            entryCounter = 0;
            entryMode = 0;

            //assign data then emit
            switch (currentCameraIndex + 1) {
            case 1:
                emit maskCoordinates_1_a(clickCoordinates[0]);
                emit maskCoordinates_1_b(clickCoordinates[1]);
                emit maskCoordinates_1_c(clickCoordinates[2]);
                emit maskCoordinates_1_d(clickCoordinates[3]);
                break;
            case 2:
                emit maskCoordinates_2_a(clickCoordinates[0]);
                emit maskCoordinates_2_b(clickCoordinates[1]);
                emit maskCoordinates_2_c(clickCoordinates[2]);
                emit maskCoordinates_2_d(clickCoordinates[3]);
                break;
            case 3:
                emit maskCoordinates_3_a(clickCoordinates[0]);
                emit maskCoordinates_3_b(clickCoordinates[1]);
                emit maskCoordinates_3_c(clickCoordinates[2]);
                emit maskCoordinates_3_d(clickCoordinates[3]);
            }

        }
    }
}

void FieldSelectionDialog::on_pushButton_set_released()
{
    entryMode = 1;
    entryCounter = 0;
    //clean up coordinate of mask
    for (int i = 0; i < 4; i++) {
        clickCoordinates[i].setX(0);
        clickCoordinates[i].setY(0);
    }
}

