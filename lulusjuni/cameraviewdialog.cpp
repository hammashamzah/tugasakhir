#include "cameraviewdialog.h"
#include "ui_cameraviewdialog.h"

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
