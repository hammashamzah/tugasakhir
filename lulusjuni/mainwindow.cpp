#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	myCVDialog = new CameraViewDialog(this);
	myECDialog = new ErrorCalculationDialog(this);
	mySPDialog = new SystemPerformanceDialog(this);
	myTVDialog = new TrackingViewDialog(this);
	myBMTDialog = new BackgroundModelTuningDialog(this);
	myFSDialog = new FieldSelectionDialog(this);
    myProcessor = new Processor();

	QObject::connect(myProcessor, SIGNAL(firstFrameImage(QVector<QImage>)), myFSDialog, SLOT(setFrame(QVector<QImage>)));
	QObject::connect(myFSDialog, SIGNAL(setMaskCoordinates(QVector< QList<QPoint> >)), myProcessor, SLOT(updateMaskCoordinate(QVector< QList<QPoint> >)));
	QObject::connect(myProcessor, SIGNAL(setCameraViewImage(QVector< QVector<QImage> >)), myCVDialog, SLOT(updateCameraViewImage(QVector< QVector<QImage> >)));
	QObject::connect(myBMTDialog, SIGNAL(setValueParameter(QVector< QVector<int> >)), myProcessor, SLOT(updateValueParameter(QVector< QVector<int> >)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionTuning_Background_Model_triggered()
{
	myBMTDialog->show();
}

void MainWindow::on_actionPer_Camera_Raw_View_triggered()
{
	myCVDialog->show();
}


void MainWindow::on_actionError_Calculation_triggered()
{
	myECDialog->show();
}

void MainWindow::on_actionSystem_Performance_Testing_Metrics_triggered()
{

	mySPDialog->show();
}

void MainWindow::on_actionField_Selection_triggered()
{
	myFSDialog->show();
}

void MainWindow::on_actionTracking_View_triggered()
{
	myTVDialog->show();
}

void MainWindow::on_actionVideo_1_triggered()
{
	filename = QFileDialog::getOpenFileName(this,
	                                        tr("Open Video Stream 1"), ".",
	                                        tr("Video Files (*.avi *.mpg *.mp4)"));
	myProcessor->loadVideo(filename, 1);

}

void MainWindow::on_actionVideo_2_triggered()
{
	filename = QFileDialog::getOpenFileName(this,
	                                        tr("Open Video Stream 2"), ".",
	                                        tr("Video Files (*.avi *.mpg *.mp4)"));
	myProcessor->loadVideo(filename, 2);
}


void MainWindow::on_pushButton_play_released()
{
	/*if (myProcessor->isStopped())
	{
		myProcessor->playContinously();
	} else
	{
		myProcessor->Stop();
	}*/
}

void MainWindow::on_pushButton_single_play_released() {
	myProcessor->playSingleFrame();
}


/*QString MainWindow::getFormattedTime(int timeInSeconds){
    int seconds = (int) (timeInSeconds) % 60 ;
    int minutes = (int) ((timeInSeconds / 60) % 60);
    int hours   = (int) ((timeInSeconds / (60*60)) % 24);
    QTime t(hours, minutes, seconds);
    if (hours == 0 )
        return t.toString("mm:ss");
    else
        return t.toString("h:mm:ss");
}

void MainWindow::on_time_slider_1_sliderPressed()
{
    myStream_1->Stop();
}
void MainWindow::on_time_slider_1_sliderReleased()
{
    myStream_1->Play();
}
void MainWindow::on_time_slider_1_sliderMoved(int position)
{
    myStream_1->setCurrentFrame(position);
    ui->current_time_1->setText( getFormattedTime( position/(int)myStream_1->getFrameRate()) );
}

void MainWindow::on_time_slider_2_sliderPressed()
{
    myStream_2->Stop();
}
void MainWindow::on_time_slider_2_sliderReleased()
{
    myStream_2->Play();
}
void MainWindow::on_time_slider_2_sliderMoved(int position)
{
    myStream_2->setCurrentFrame(position);
    ui->current_time_2->setText( getFormattedTime( position/(int)myStream_2->getFrameRate()) );
}

void MainWindow::on_time_slider_3_sliderPressed()
{
    myStream_3->Stop();
}
void MainWindow::on_time_slider_3_sliderReleased()
{
    myStream_3->Play();
}
void MainWindow::on_time_slider_3_sliderMoved(int position)
{
    myStream_3->setCurrentFrame(position);
    ui->current_time_3->setText( getFormattedTime( position/(int)myStream_3->getFrameRate()) );
}
*/
