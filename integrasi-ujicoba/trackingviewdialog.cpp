#include "trackingviewdialog.h"
#include "ui_trackingviewdialog.h"

TrackingViewDialog::TrackingViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrackingViewDialog)
{
    ui->setupUi(this);
}

TrackingViewDialog::~TrackingViewDialog()
{
    delete ui;
}
