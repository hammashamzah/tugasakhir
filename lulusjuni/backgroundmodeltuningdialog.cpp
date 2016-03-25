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

void BackgroundModelTuningDialog::on_comboBox_activated(int index)
{
	
}

void BackgroundModelTuningDialog::on_slider_min_area_1_valueChanged(int value)
{
	emit valueMinArea_1(value);
}

void BackgroundModelTuningDialog::on_slider_min_area_2_valueChanged(int value)
{
	emit valueMinArea_2(value);
}

void BackgroundModelTuningDialog::on_slider_min_area_3_valueChanged(int value)
{
	emit valueMinArea_3(value);
}

void BackgroundModelTuningDialog::on_slider_max_area_1_valueChanged(int value)
{
	emit valueMaxArea_1(value);
}

void BackgroundModelTuningDialog::on_slider_max_area_2_valueChanged(int value)
{
	emit valueMaxArea_2(value);
}

void BackgroundModelTuningDialog::on_slider_max_area_3_valueChanged(int value)
{
	emit valueMaxArea_3(value);
}

void BackgroundModelTuningDialog::on_slider_morp_element_size_1_valueChanged(int value)
{
	emit valueMorpElementSize_1(value);
}

void BackgroundModelTuningDialog::on_slider_morp_element_size_2_valueChanged(int value)
{
	emit valueMorpElementSize_2(value);
}

void BackgroundModelTuningDialog::on_slider_morp_element_size_3_valueChanged(int value)
{
	emit valueMorpElementSize_3(value);
}

void BackgroundModelTuningDialog::on_slider_gaussian_size_1_valueChanged(int value)
{
	emit valueGaussianSize_1(value);
}

void BackgroundModelTuningDialog::on_slider_gaussian_size_2_valueChanged(int value)
{
	emit valueGaussianSize_2(value);
}

void BackgroundModelTuningDialog::on_slider_gaussian_size_3_valueChanged(int value)
{
	emit valueGaussianSize_3(value);
}


void BackgroundModelTuningDialog::on_pushButton_load_released()
{
/*	QString filename = QFileDialog::getOpenFileName(this,
                       tr("Load Background Model Tuning File"), ".",
                       tr("Background Model Tuning File (*.inf)"));
    QFileInfo name = filename;
    if (!filename.isEmpty()) {
    	TuningFileHandler tuningFileHandler();
    	if(!tuningFileHandler.loadFile(filename)){
    		QMessageBox msgBox;
            msgBox.setText("The selected file is not valid!");
            msgBox.exec();	
    	}else{
    		//set all value of slider
    		ui->slider_min_area_1->setValue(tuningFileHandler.getData(1));
    		ui->slider_min_area_2->setValue(tuningFileHandler.getData(2));
    		ui->slider_min_area_3->setValue(tuningFileHandler.getData(3));
    		ui->slider_max_area_1->setValue(tuningFileHandler.getData(4));
    		ui->slider_max_area_2->setValue(tuningFileHandler.getData(5));
    		ui->slider_max_area_3->setValue(tuningFileHandler.getData(6));
    		ui->slider_morp_element_size_1->setValue(tuningFileHandler.getData(7));
    		ui->slider_morp_element_size_2->setValue(tuningFileHandler.getData(8));
    		ui->slider_morp_element_size_3->setValue(tuningFileHandler.getData(9));
    		ui->slider_gaussian_size_1->setValue(tuningFileHandler.getData(10));
    		ui->slider_gaussian_size_2->setValue(tuningFileHandler.getData(11));
    		ui->slider_gaussian_size_3->setValue(tuningFileHandler.getData(12));

			QMessageBox msgBox;
            msgBox.setText("Setting has been Loaded!");
            msgBox.exec();	    	
    	}
    }
*/
}
