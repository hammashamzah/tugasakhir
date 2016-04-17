#include "datawindow.h"
#include "ui_datawindow.h"

DataWindow::DataWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataWindow)
{
    ui->setupUi(this);
    ui->pushButton_load->setEnabled(false);
    ui->pushButton_save->setEnabled(false);

}

DataWindow::~DataWindow()
{
    delete ui;
}

void DataWindow::on_pushButton_display_data_released()
{

}

void DataWindow::on_pushButton_load_released()
{
    filename = QFileDialog::getOpenFileName(this,
                                            tr("Open Log File"), ".",
                                            tr("Log File (*.log)"));
    myDataLogger.saveToFile(filename);
}

void DataWindow::on_pushButton_save_released()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save Masking Coordinate File"), "maskingcoordinate.txt",
                                            tr("Masking Coordinate File (*.txt)"));
    myDataLogger.loadFromFile(filename);
}

void DataWindow::addData(QList<Player> newData){
	myDataLogger.add(newData);
}

void DataWindow::dataEntryFinished(){
    ui->pushButton_load->setEnabled(true);
    ui->pushButton_save->setEnabled(true);
}
