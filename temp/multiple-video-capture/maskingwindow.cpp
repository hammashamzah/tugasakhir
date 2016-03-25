#include "maskingwindow.h"
#include "ui_maskingwindow.h"

MaskingWindow::MaskingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaskingWindow)
{
    ui->setupUi(this);
}

MaskingWindow::~MaskingWindow()
{
    delete ui;
}
