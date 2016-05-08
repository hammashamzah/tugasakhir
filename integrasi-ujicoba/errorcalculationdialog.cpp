#include "errorcalculationdialog.h"
#include "ui_errorcalculationdialog.h"

ErrorCalculationDialog::ErrorCalculationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorCalculationDialog)
{
    ui->setupUi(this);
}

ErrorCalculationDialog::~ErrorCalculationDialog()
{
    delete ui;
}
