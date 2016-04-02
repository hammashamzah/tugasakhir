#include "fieldselectiondialog.h"
#include "ui_fieldselectiondialog.h"

FieldSelectionDialog::FieldSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldSelectionDialog)
{
    ui->setupUi(this);
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
        if (!frameCamera_1.isNull()){
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_1).scaled(ui->imageView->size(),
                         Qt::KeepAspectRatio, Qt::FastTransformation));
        }
        break;
    case 1:
        if (!frameCamera_2.isNull()){
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_2).scaled(ui->imageView->size(),
                                     Qt::KeepAspectRatio, Qt::FastTransformation));

        }
        break;
    case 2:
        if (!frameCamera_3.isNull()){
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera_3).scaled(ui->imageView->size(),
                                     Qt::KeepAspectRatio, Qt::FastTransformation));

        }
        break;
    }

}

void FieldSelectionDialog::on_pushButton_set_released()
{
    
}
