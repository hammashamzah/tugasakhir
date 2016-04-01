#include "fieldselectiondialog.h"
#include "ui_fieldselectiondialog.h"

FieldSelectionDialog::FieldSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldSelectionDialog)
{
    ui->setupUi(this);
    ui->imageview->setAlignment(Qt::AlignCenter);
    ui->imageview->setPixmap(QPixmap::fromImage(firstFrameCamera_1).scaled(ui->imageview->size(),
                 Qt::KeepAspectRatio, Qt::FastTransformation));
}

FieldSelectionDialog::~FieldSelectionDialog()
{
    delete ui;
}


void FieldSelectionDialog::setFirstFrame_1(QImage img) {
    firstFrameCamera_1 = img;
}

void FieldSelectionDialog::setFirstFrame_2(QImage img) {
    firstFrameCamera_2 = img;
}

void FieldSelectionDialog::setFirstFrame_3(QImage img) {
    firstFrameCamera_3 = img;
}
void FieldSelectionDialog::on_cameraSelectCombo_currentIndexChanged(int index)
{
   /* switch (index) {
    case 0:
        if (!firstFrameCamera_1.isNull()){
            ui->imageview->setAlignment(Qt::AlignCenter);
            ui->imageview->setPixmap(QPixmap::fromImage(firstFrameCamera_1).scaled(ui->imageview->size(),
                         Qt::KeepAspectRatio, Qt::FastTransformation));
        }
        break;
    case 1:
        if (!firstFrameCamera_2.isNull()){
            ui->imageview->setAlignment(Qt::AlignCenter);
            ui->imageview->setPixmap(QPixmap::fromImage(firstFrameCamera_2).scaled(ui->imageview->size(),
                                     Qt::KeepAspectRatio, Qt::FastTransformation));

        }
        break;
    case 2:
        if (!firstFrameCamera_3.isNull()){
            ui->imageview->setAlignment(Qt::AlignCenter);
            ui->imageview->setPixmap(QPixmap::fromImage(firstFrameCamera_3).scaled(ui->imageview->size(),
                                     Qt::KeepAspectRatio, Qt::FastTransformation));

        }
        break;
    }
    */
}
