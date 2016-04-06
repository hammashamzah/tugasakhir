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

void CameraViewDialog::updateRawImage_1(QImage img) {
	if (!img.isNull())
	{
		ui->raw_1->setAlignment(Qt::AlignCenter);
        ui->raw_1->setPixmap(QPixmap::fromImage(img).scaled(ui->raw_1->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateRawImage_2(QImage img) {
	if (!img.isNull())
	{
		ui->raw_2->setAlignment(Qt::AlignCenter);
        ui->raw_2->setPixmap(QPixmap::fromImage(img).scaled(ui->raw_2->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateRawImage_3(QImage img) {
	if (!img.isNull())
	{
		ui->raw_3->setAlignment(Qt::AlignCenter);
        ui->raw_3->setPixmap(QPixmap::fromImage(img).scaled(ui->raw_3->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}


void CameraViewDialog::updateMaskedImage_1(QImage img) {
	if (!img.isNull())
	{
		ui->masked_1->setAlignment(Qt::AlignCenter);
        ui->masked_1->setPixmap(QPixmap::fromImage(img).scaled(ui->masked_1->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateMaskedImage_2(QImage img) {
	if (!img.isNull())
	{
		ui->masked_2->setAlignment(Qt::AlignCenter);
        ui->masked_2->setPixmap(QPixmap::fromImage(img).scaled(ui->masked_2->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateMaskedImage_3(QImage img) {
	if (!img.isNull())
	{
		ui->masked_3->setAlignment(Qt::AlignCenter);
        ui->masked_3->setPixmap(QPixmap::fromImage(img).scaled(ui->masked_3->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateObjectImage_1(QImage img) {
	if (!img.isNull())
	{
		ui->object_1->setAlignment(Qt::AlignCenter);
        ui->object_1->setPixmap(QPixmap::fromImage(img).scaled(ui->object_1->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateObjectImage_2(QImage img) {
	if (!img.isNull())
	{
		ui->object_2->setAlignment(Qt::AlignCenter);
        ui->object_2->setPixmap(QPixmap::fromImage(img).scaled(ui->object_2->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateObjectImage_3(QImage img) {
	if (!img.isNull())
	{
		ui->object_3->setAlignment(Qt::AlignCenter);
        ui->object_3->setPixmap(QPixmap::fromImage(img).scaled(ui->object_3->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateOpenedImage_1(QImage img) {
	if (!img.isNull())
	{
		ui->opened_1->setAlignment(Qt::AlignCenter);
        ui->opened_1->setPixmap(QPixmap::fromImage(img).scaled(ui->opened_1->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void CameraViewDialog::updateOpenedImage_2(QImage img) {
	if (!img.isNull())
	{
		ui->opened_2->setAlignment(Qt::AlignCenter);
        ui->opened_2->setPixmap(QPixmap::fromImage(img).scaled(ui->opened_2->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateOpenedImage_3(QImage img) {
	if (!img.isNull())
	{
		ui->opened_3->setAlignment(Qt::AlignCenter);
        ui->opened_3->setPixmap(QPixmap::fromImage(img).scaled(ui->opened_3->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateBluredImage_1(QImage img) {
	if (!img.isNull())
	{
		ui->blured_1->setAlignment(Qt::AlignCenter);
        ui->blured_1->setPixmap(QPixmap::fromImage(img).scaled(ui->blured_1->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateBluredImage_2(QImage img) {
	if (!img.isNull())
	{
		ui->blured_2->setAlignment(Qt::AlignCenter);
        ui->blured_2->setPixmap(QPixmap::fromImage(img).scaled(ui->blured_2->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateBluredImage_3(QImage img) {
	if (!img.isNull())
	{
		ui->blured_3->setAlignment(Qt::AlignCenter);
        ui->blured_3->setPixmap(QPixmap::fromImage(img).scaled(ui->blured_3->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateObjectWithKeypointsImage_1(QImage img) {
	if (!img.isNull())
	{
		ui->keypoint_1->setAlignment(Qt::AlignCenter);
        ui->keypoint_1->setPixmap(QPixmap::fromImage(img).scaled(ui->keypoint_1->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateObjectWithKeypointsImage_2(QImage img) {
	if (!img.isNull())
	{
		ui->keypoint_2->setAlignment(Qt::AlignCenter);
        ui->keypoint_2->setPixmap(QPixmap::fromImage(img).scaled(ui->keypoint_2->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateObjectWithKeypointsImage_3(QImage img) {
	if (!img.isNull())
	{
		ui->keypoint_3->setAlignment(Qt::AlignCenter);
        ui->keypoint_3->setPixmap(QPixmap::fromImage(img).scaled(ui->keypoint_3->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}
