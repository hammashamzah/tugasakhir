#include "backgroundmodeltuningdialog.h"
#include "ui_backgroundmodeltuningdialog.h"

BackgroundModelTuningDialog::BackgroundModelTuningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackgroundModelTuningDialog)
{
    ui->setupUi(this);
    parameters.resize(2);
    parameters[0].resize(6);
    parameters[1].resize(6);
    parameters[0].fill(0);
    parameters[1].fill(0);
}

BackgroundModelTuningDialog::~BackgroundModelTuningDialog()
{
    delete ui;
}

void BackgroundModelTuningDialog::on_slider_min_area_1_valueChanged(int value)
{
	parameters[0][0] = value;
    emit setValueParameter(parameters);
}

void BackgroundModelTuningDialog::on_slider_min_area_2_valueChanged(int value)
{
	parameters[1][0] = value;
    emit setValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_max_area_1_valueChanged(int value)
{
	parameters[0][1] = value;
    emit setValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_max_area_2_valueChanged(int value)
{
	parameters[1][1] = value;
    emit setValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_morp_element_size_1_valueChanged(int value)
{
	parameters[0][2] = value;
    emit setValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_morp_element_size_2_valueChanged(int value)
{
	parameters[1][2] = value;
    emit setValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_gaussian_size_1_valueChanged(int value)
{
	parameters[0][3] = value;
    emit setValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_gaussian_size_2_valueChanged(int value)
{
	parameters[1][3] = value;
    emit setValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_pixel_threshold_1_valueChanged(int value)
{
    parameters[0][4] = value;
    emit setValueParameter(parameters);
}

void BackgroundModelTuningDialog::on_slider_transformed_threshold_1_valueChanged(int value)
{
    parameters[0][5] = value;
    emit setValueParameter(parameters);
}

void BackgroundModelTuningDialog::on_slider_pixel_threshold_2_valueChanged(int value)
{
    parameters[1][4] = value;
    emit setValueParameter(parameters);
}


void BackgroundModelTuningDialog::on_slider_transformed_threshold_2_valueChanged(int value)
{
    parameters[1][5] = value;
    emit setValueParameter(parameters);
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

