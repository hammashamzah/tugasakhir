#include "fieldselectiondialog.h"
#include "ui_fieldselectiondialog.h"

FieldSelectionDialog::FieldSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldSelectionDialog)
{
    ui->setupUi(this);
    QObject::connect(ui->imageView, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(processMouse(QPoint&)));
    QObject::connect(ui->imageView, SIGNAL(sendClickPosition(QPoint&)), this, SLOT(processClick(QPoint&)));
    entryMode = 0;
    currentCameraIndex = 0;
    for (int i = 0; i < 4; ++i)
    {
        set[i] = false;
    }

    frameCamera.resize(2);
    listOfClickCoordinates.resize(2);
    listOfTrapeziumCoordinates.resize(2);
    listOfTransformationCoordinates.resize(2);
}

FieldSelectionDialog::~FieldSelectionDialog()
{
    delete ui;
}

void FieldSelectionDialog::setFirstFrameImage(QVector<QImage> img) {
    ui->imageView->setAlignment(Qt::AlignCenter);
    frameCamera[0] = img.at(0);
    frameCamera[1] = img.at(1);
    imageSize.clear();
    imageSize.append(frameCamera[0].size());
    imageSize.append(frameCamera[1].size());
    emit sendImageSize(imageSize);
    if (currentCameraIndex == 0) {
        ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(0)));
    }
}

void FieldSelectionDialog::on_cameraSelectCombo_currentIndexChanged(int index)
{
    currentCameraIndex = index;
    switch (index) {
    case 0:
    case 2:
    case 4:
        if (!frameCamera.at(0).isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(0)));
        }
        break;
    case 1:
    case 3:
    case 5:
        if (!frameCamera.at(1).isNull()) {
            ui->imageView->setAlignment(Qt::AlignCenter);
            ui->imageView->setPixmap(QPixmap::fromImage(frameCamera.at(1)));
        }
        break;
    }
}

void FieldSelectionDialog::processMouse(QPoint &pos) {
    //for display. not really necessary
}

void FieldSelectionDialog::processClick(QPoint &pos) {
    if (entryMode == 1) {
        clickCoordinates.append(pos);
    }
}

void FieldSelectionDialog::on_pushButton_set_released()
{
    //set to entry mode
    entryMode = 1;
    //clean up coordinate of mask
    clickCoordinates.clear();
}


void FieldSelectionDialog::on_pushButton_apply_released()
{
    entryMode = 0;
    //assign data then emit
    switch (currentCameraIndex + 1) {
    case 1:
        listOfClickCoordinates[0] = clickCoordinates;
        set[0] = true;
        break;
    case 2:
        listOfClickCoordinates[1] = clickCoordinates;
        set[1] = true;
        break;
    case 3:
        listOfTrapeziumCoordinates[0] = clickCoordinates;
        break;
    case 4:
        listOfTrapeziumCoordinates[1] = clickCoordinates;
        break;
    case 5:
        listOfTransformationCoordinates[0] = clickCoordinates;
        set[2] = true;
        break;
    case 6:
        listOfTransformationCoordinates[1] = clickCoordinates;
        set[3] = true;
        break;
    }

    if (set[0] && set[1] && set[2] && set[3]) {

        emit sendMaskCoordinates(listOfClickCoordinates);
        //emit sendTrapeziumCoordinates(listOfTrapeziumCoordinates);
        emit sendTransformationCoordinates(listOfTransformationCoordinates);
    }

}

void FieldSelectionDialog::fileHandler(QString filename, int mode) {
    QFile file(filename);
    qDebug() << filename;
    switch (mode) {
    case 1: //loading mode
        if (file.open(QIODevice::ReadOnly)) {
            QStringList lines = QString(file.readAll()).split(QRegExp("[\r\n]"));
            
            listOfClickCoordinates[0].clear();
            numberOfMaskPoints[0] = lines.at(0).count(QLatin1Char(' ')) / 2;
            for (int i = 0; i < (numberOfMaskPoints[0]); i++) {
                listOfClickCoordinates[0].append(QPoint((lines.at(0)).section(" ",2*i,2*i).toInt(),(lines.at(0)).section(" ",2*i + 1,2*i + 1).toInt()));
            }

            listOfClickCoordinates[1].clear();
            numberOfMaskPoints[1] = lines.at(1).count(QLatin1Char(' ')) / 2;
            for (int i = 0; i < (numberOfMaskPoints[1]); i++) {
                listOfClickCoordinates[1].append(QPoint((lines.at(1)).section(" ",2*i,2*i).toInt(),(lines.at(1)).section(" ",2*i + 1,2*i + 1).toInt()));
            }

            listOfTransformationCoordinates[0].clear();
            numberOfTransformationPoints[0] = lines.at(2).count(QLatin1Char(' ')) / 2;
            for (int i = 0; i < (numberOfTransformationPoints[0]); i++) {
                listOfTransformationCoordinates[0].append(QPoint((lines.at(2)).section(" ",2*i,2*i).toInt(),(lines.at(2)).section(" ",2*i + 1,2*i + 1).toInt()));
            }

            listOfTransformationCoordinates[1].clear();
            numberOfTransformationPoints[1] = lines.at(3).count(QLatin1Char(' ')) / 2;
            for (int i = 0; i < (numberOfTransformationPoints[1]); i++) {
                listOfTransformationCoordinates[1].append(QPoint((lines.at(3)).section(" ",2*i,2*i).toInt(),(lines.at(3)).section(" ",2*i + 1,2*i + 1).toInt()));
            }
        }
        qDebug() << listOfClickCoordinates;
        qDebug() << listOfTransformationCoordinates;
    file.close();
    emit sendMaskCoordinates(listOfClickCoordinates);
    //emit sendTrapeziumCoordinates(listOfTrapeziumCoordinates);
    emit sendTransformationCoordinates(listOfTransformationCoordinates);
    break;
case 2: //saving mode
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        if (set[0] && set[1] && set[2] && set[3]) {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < listOfClickCoordinates[i].size(); j++)
                {
                    stream << listOfClickCoordinates[i][j].x() << " " << listOfClickCoordinates[i][j].y() << " ";
                }
                stream << "\n";
            }
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < listOfTransformationCoordinates[i].size(); j++)
                {
                    stream << listOfTransformationCoordinates[i][j].x() << " " << listOfTransformationCoordinates[i][j].y() << " ";
                }
                stream << "\n";
            }
        }
    }

    file.close();

        break;
}


}

void FieldSelectionDialog::on_pushButton_load_file_released()
{
    filename = QFileDialog::getOpenFileName(this,
                                            tr("Open Masking Coordinate File"), ".",
                                            tr("Masking Coordinate File (*.txt)"));
    fileHandler(filename, 1);
}

void FieldSelectionDialog::on_pushButton_load_default_file_released()
{
    filename = QString("maskingcoordinate.txt");
    fileHandler(filename, 1);
}

void FieldSelectionDialog::on_pushButton_save_file_released()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save Masking Coordinate File"), "maskingcoordinate.txt",
                                            tr("Masking Coordinate File (*.txt)"));
    fileHandler(filename, 2);
}
