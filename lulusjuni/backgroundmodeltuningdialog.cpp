#include "backgroundmodeltuningdialog.h"
#include "ui_backgroundmodeltuningdialog.h"

BackgroundModelTuningDialog::BackgroundModelTuningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackgroundModelTuningDialog)
{
    ui->setupUi(this);
}

BackgroundModelTuningDialog::~BackgroundModelTuningDialog()
{
    delete ui;
}
