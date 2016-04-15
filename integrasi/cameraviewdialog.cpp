#include "cameraviewdialog.h"
#include "ui_cameraviewdialog.h"

using namespace cv;

CameraViewDialog::CameraViewDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CameraViewDialog)
{
	ui->setupUi(this);
}

CameraViewDialog::~CameraViewDialog()
{
	delete ui;
}

void CameraViewDialog::updateCameraViewImage(QVector< QVector<QImage> > images) {
	ui->raw_1->setAlignment(Qt::AlignCenter);
	ui->raw_2->setAlignment(Qt::AlignCenter);
	ui->masked_1->setAlignment(Qt::AlignCenter);
	ui->masked_2->setAlignment(Qt::AlignCenter);
	ui->object_1->setAlignment(Qt::AlignCenter);
	ui->object_2->setAlignment(Qt::AlignCenter);
	ui->opened_1->setAlignment(Qt::AlignCenter);
	ui->opened_2->setAlignment(Qt::AlignCenter);
	ui->blured_1->setAlignment(Qt::AlignCenter);
	ui->blured_2->setAlignment(Qt::AlignCenter);
	ui->keypoint_1->setAlignment(Qt::AlignCenter);
	ui->keypoint_2->setAlignment(Qt::AlignCenter);

    ui->raw_1->setPixmap(QPixmap::fromImage(((images.at(0)).at(0)).scaled(ui->raw_1->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->masked_1->setPixmap(QPixmap::fromImage(((images.at(0)).at(1)).scaled(ui->masked_1->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->object_1->setPixmap(QPixmap::fromImage(((images.at(0)).at(2)).scaled(ui->object_1->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->opened_1->setPixmap(QPixmap::fromImage(((images.at(0)).at(3)).scaled(ui->opened_1->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->blured_1->setPixmap(QPixmap::fromImage(((images.at(0)).at(4)).scaled(ui->blured_1->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->keypoint_1->setPixmap(QPixmap::fromImage(((images.at(0)).at(5)).scaled(ui->keypoint_1->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    
    ui->raw_2->setPixmap(QPixmap::fromImage(((images.at(1)).at(0)).scaled(ui->raw_2->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->masked_2->setPixmap(QPixmap::fromImage(((images.at(1)).at(1)).scaled(ui->masked_2->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->object_2->setPixmap(QPixmap::fromImage(((images.at(1)).at(2)).scaled(ui->object_2->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->opened_2->setPixmap(QPixmap::fromImage(((images.at(1)).at(3)).scaled(ui->opened_2->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->blured_2->setPixmap(QPixmap::fromImage(((images.at(1)).at(4)).scaled(ui->blured_2->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->keypoint_2->setPixmap(QPixmap::fromImage(((images.at(1)).at(5)).scaled(ui->keypoint_2->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
}
