#include "dialogloggerviewer.h"
#include "ui_dialogloggerviewer.h"

DialogLoggerViewer::DialogLoggerViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLoggerViewer)
{
    ui->setupUi(this);
}

DialogLoggerViewer::~DialogLoggerViewer()
{
    delete ui;
}
