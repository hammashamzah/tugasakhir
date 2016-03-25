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

void CameraViewDialog::updateRawPlayerUI_1(QImage img) {
	if (!img.isNull())
	{
		ui->raw_1->setAlignment(Qt::AlignCenter);
        ui->raw_1->setPixmap(QPixmap::fromImage(img).scaled(ui->raw_1->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateRawPlayerUI_2(QImage img) {
	if (!img.isNull())
	{
		ui->raw_2->setAlignment(Qt::AlignCenter);
        ui->raw_2->setPixmap(QPixmap::fromImage(img).scaled(ui->raw_2->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void CameraViewDialog::updateRawPlayerUI_3(QImage img) {
	if (!img.isNull())
	{
		ui->raw_3->setAlignment(Qt::AlignCenter);
        ui->raw_3->setPixmap(QPixmap::fromImage(img).scaled(ui->raw_3->size(),
		                     Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}
