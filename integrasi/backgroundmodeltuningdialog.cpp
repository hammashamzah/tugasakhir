#include "backgroundmodeltuningdialog.h"
#include "ui_backgroundmodeltuningdialog.h"

BackgroundModelTuningDialog::BackgroundModelTuningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackgroundModelTuningDialog)
{
    ui->setupUi(this);
    parameters.resize(3);
    parameters[0].resize(4);
    parameters[1].resize(4);
    parameters[2].resize(2);
    parameters[0].fill(0);
    parameters[1].fill(0);
    parameters[2].fill(0);
}

BackgroundModelTuningDialog::~BackgroundModelTuningDialog()
{
    delete ui;
}

void BackgroundModelTuningDialog::on_slider_min_area_1_valueChanged(int value)
{
    parameters[0][0] = value;
    ui->min_area_1->setText(QString::number(value));
    emit sendValueParameter(parameters);
}

void BackgroundModelTuningDialog::on_slider_min_area_2_valueChanged(int value)
{
    parameters[1][0] = value;
    ui->min_area_2->setText(QString::number(value));
    emit sendValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_max_area_1_valueChanged(int value)
{
    parameters[0][1] = value;
    ui->max_area_1->setText(QString::number(value));
    emit sendValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_max_area_2_valueChanged(int value)
{
    parameters[1][1] = value;
    ui->max_area_2->setText(QString::number(value));
    emit sendValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_morp_element_size_1_valueChanged(int value)
{
    parameters[0][2] = value;
    ui->morph_1->setText(QString::number(value));
    emit sendValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_morp_element_size_2_valueChanged(int value)
{
    parameters[1][2] = value;
    ui->morph_2->setText(QString::number(value));
    emit sendValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_gaussian_size_1_valueChanged(int value)
{
    parameters[0][3] = value;
    ui->gaussian_1->setText(QString::number(value));
    emit sendValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_gaussian_size_2_valueChanged(int value)
{
    parameters[1][3] = value;
    ui->gaussian_2->setText(QString::number(value));
    emit sendValueParameter(parameters);

}

void BackgroundModelTuningDialog::on_slider_occlusion_threshold_valueChanged(int value)
{
    parameters[2][1] = value;
    ui->occlusion->setText(QString::number(value));
    emit sendValueParameter(parameters);
}

void BackgroundModelTuningDialog::on_slider_association_threshold_valueChanged(int value)
{
    parameters[2][0] = value;
    ui->association->setText(QString::number(value));
    emit sendValueParameter(parameters);
}

void BackgroundModelTuningDialog::on_pushButton_load_released()
{
    QString filename = QFileDialog::getOpenFileName(this,
                       tr("Load Background Model Tuning File"), ".",
                       tr("Background Model Tuning File (*.txt)"));
    loadSetting(filename);
    emit sendValueParameter(parameters);
}

void BackgroundModelTuningDialog::on_pushButton_save_released()
{
    QString filename = QFileDialog::getSaveFileName(this,
                       tr("Save Background Model Tuning File"), "backgroundmodel.txt",
                       tr("Background Model Tuning File (*.txt)"));
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        for (int j = 0; j < 4; j++)
        {
            stream << parameters[0][j] << " ";
        }
        stream << "\n";
        for (int j = 0; j < 4; j++)
        {
            stream << parameters[1][j] << " ";
        }
        stream << "\n";
        for(int j = 0; j < 2; j++)
        {
            stream << parameters[2][j] << " ";
        }
    }

    file.close();
}

void BackgroundModelTuningDialog::on_pushButton_load_default_setting_released()
{
    QString filename_default = QString("backgroundmodel.txt");
    loadSetting(filename_default);
    emit sendValueParameter(parameters);
}

void BackgroundModelTuningDialog::loadSetting(QString filename){

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QStringList lines = QString(file.readAll()).split(QRegExp("[\r\n]"));
        parameters.clear();
        parameters.resize(3);
        parameters[0].resize(4);
        parameters[1].resize(4);
        parameters[2].resize(2);
        for (int i = 0; i < 4; i++)
        {
            parameters[0][i] = lines.at(0).section(" ", i, i).toInt();
        }

        for (int i = 0; i < 4; i++)
        {
            parameters[1][i] = lines.at(1).section(" ", i, i).toInt();
        }

        for(int i = 0; i < 2; i++){
            parameters[2][i] = lines.at(2).section(" ", i, i).toInt();
        }
    }

    ui->slider_min_area_1->setValue(parameters[0][0]);
    ui->slider_max_area_1->setValue(parameters[0][1]);
    ui->slider_morp_element_size_1->setValue(parameters[0][2]);
    ui->slider_gaussian_size_1->setValue(parameters[0][3]);

    ui->slider_min_area_2->setValue(parameters[1][0]);
    ui->slider_max_area_2->setValue(parameters[1][1]);
    ui->slider_morp_element_size_2->setValue(parameters[1][2]);
    ui->slider_gaussian_size_2->setValue(parameters[1][3]);

    ui->slider_association_threshold->setValue(parameters[2][0]);
    ui->slider_occlusion_threshold->setValue(parameters[2][1]);
}

void BackgroundModelTuningDialog::on_buttonBox_accepted()
{
    emit sendValueParameter(parameters);
    this->close();
}


void BackgroundModelTuningDialog::on_buttonBox_rejected()
{
    this->close();
}
