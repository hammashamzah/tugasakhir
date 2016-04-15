#include "systemperformancedialog.h"
#include "ui_systemperformancedialog.h"

SystemPerformanceDialog::SystemPerformanceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SystemPerformanceDialog)
{
    ui->setupUi(this);
}

SystemPerformanceDialog::~SystemPerformanceDialog()
{
    delete ui;
}
