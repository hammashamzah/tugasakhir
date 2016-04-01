#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	myStream_1 = new VideoProcessor();
	myStream_2 = new VideoProcessor();
	myStream_3 = new VideoProcessor();

	myCVDialog = new CameraViewDialog(this);
	myECDialog = new ErrorCalculationDialog(this);
	mySPDialog = new SystemPerformanceDialog(this);
	myTVDialog = new TrackingViewDialog(this);
	myBMTDialog = new BackgroundModelTuningDialog(this);
	myFSDialog = new FieldSelectionDialog(this);

	//connect slot
	QObject::connect(myStream_1, SIGNAL(rawImage(QImage)), myCVDialog, SLOT(updateRawPlayerUI_1(QImage)));
	QObject::connect(myStream_2, SIGNAL(rawImage(QImage)), myCVDialog, SLOT(updateRawPlayerUI_2(QImage)));
	QObject::connect(myStream_3, SIGNAL(rawImage(QImage)), myCVDialog, SLOT(updateRawPlayerUI_3(QImage)));

	//connect slot from
	QObject::connect(myBMTDialog, SIGNAL(valueMinArea_1(int)), myStream_1, SLOT(updateValueMinArea(int)));
	QObject::connect(myBMTDialog, SIGNAL(valueMinArea_2(int)), myStream_2, SLOT(updateValueMinArea(int)));
	QObject::connect(myBMTDialog, SIGNAL(valueMinArea_3(int)), myStream_3, SLOT(updateValueMinArea(int)));

	QObject::connect(myBMTDialog, SIGNAL(valueMaxArea_1(int)), myStream_1, SLOT(updateValueMaxArea(int)));
	QObject::connect(myBMTDialog, SIGNAL(valueMaxArea_2(int)), myStream_2, SLOT(updateValueMaxArea(int)));
	QObject::connect(myBMTDialog, SIGNAL(valueMaxArea_3(int)), myStream_3, SLOT(updateValueMaxArea(int)));

	QObject::connect(myBMTDialog, SIGNAL(valueMorpElementSize_1(int)), myStream_1, SLOT(updateValueMorphElementSize(int)));
	QObject::connect(myBMTDialog, SIGNAL(valueMorpElementSize_2(int)), myStream_2, SLOT(updateValueMorphElementSize(int)));
	QObject::connect(myBMTDialog, SIGNAL(valueMorpElementSize_3(int)), myStream_3, SLOT(updateValueMorphElementSize(int)));

	QObject::connect(myBMTDialog, SIGNAL(valueGaussianSize_1(int)), myStream_1, SLOT(updateValueGaussianSize(int)));
	QObject::connect(myBMTDialog, SIGNAL(valueGaussianSize_2(int)), myStream_2, SLOT(updateValueGaussianSize(int)));
	QObject::connect(myBMTDialog, SIGNAL(valueGaussianSize_3(int)), myStream_3, SLOT(updateValueGaussianSize(int)));
    GameVisual();

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionTuning_Background_Model_triggered()
{
	/*BackgroundModelTuningDialog myBMTDialog;
	myBMTDialog.setModal(true);
	myBMTDialog.exec();
	*/

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
	filename_1 = QFileDialog::getOpenFileName(this,
	             tr("Open Video Stream 1"), ".",
	             tr("Video Files (*.avi *.mpg *.mp4)"));
	if (!filename_1.isEmpty()) {
		if (!myStream_1->loadVideo(filename_1.toLatin1().data())) {
			QMessageBox msgBox;
			msgBox.setText("The selected video could not be opened!");
			msgBox.exec();
		} else {
			ui->label_videostream_1->setText("Video Stream 1:" +  filename_1);
		}
	}
	

}

void MainWindow::on_actionVideo_2_triggered()
{
	filename_2 = QFileDialog::getOpenFileName(this,
	             tr("Open Video Stream 2"), ".",
	             tr("Video Files (*.avi *.mpg *.mp4)"));
	if (!filename_2.isEmpty()) {
		if (!myStream_2->loadVideo(filename_2.toLatin1().data())) {
			QMessageBox msgBox;
			msgBox.setText("The selected video could not be opened!");
			msgBox.exec();
		} else {
			ui->label_videostream_2->setText("Video Stream 2:" +  filename_2);
		}
	}
	

}

void MainWindow::on_actionVideo_3_triggered()
{
	
	filename_3 = QFileDialog::getOpenFileName(this,
	             tr("Open Video Stream 3"), ".",
	             tr("Video Files (*.avi *.mpg *.mp4)"));
	if (!filename_3.isEmpty()) {
		if (!myStream_3->loadVideo(filename_3.toLatin1().data())) {
			QMessageBox msgBox;
			msgBox.setText("The selected video could not be opened!");
			msgBox.exec();
		} else {
			ui->label_videostream_3->setText("Video Stream 3:" +  filename_3);
		}
	}
	


}

void MainWindow::on_pushButton_play_released()
{
	if (myStream_1->isStopped() && myStream_2->isStopped() && myStream_3->isStopped())
	{
		myStream_1->Play();
		myStream_2->Play();
		myStream_3->Play();
	} else
	{
		myStream_1->Stop();
		myStream_2->Stop();
		myStream_3->Stop();
	}
}

void MainWindow::GameVisual()
{
    int i;
    QPixmap pm(800,400);    //ukuran pixmap
    QPainter p(&pm);
    QPen pen(Qt::blue, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);
    QString id;
    player_visual pemain[JUMLAH_PLAYER];

      //pm.fill();
      //pm.load("lapangan.jpg");
       ui->label_game_visual->setPixmap (pm);
       //cout<< l.width();
    //set random value of player
        for(i=0; i<JUMLAH_PLAYER; i++)
        {
            pemain[i].id=rand()%JUMLAH_PLAYER;
            if(i<=12) pemain[i].tim='A';
            else pemain[i].tim='B';
            pemain[i].pos_x=rand()% pm.width();
            pemain[i].pos_y=rand()% pm.height();
        }

          p.setRenderHint(QPainter::Antialiasing, true);
          p.setPen(pen);
          for(i=0;i<JUMLAH_PLAYER; i++)
          {
          if(pemain[i].tim=='A') brush.setColor(Qt::yellow);      //warna pengisi lingkaran pemain
          else if(pemain[i].tim=='B') brush.setColor(Qt::red);
          p.setBrush(brush);

          p.drawEllipse(pemain[i].pos_x, pemain[i].pos_y, 20, 20);  //posisi x, y, dan ukuran elips
            p.setFont(QFont ("Arial"));
            id = QString::number(pemain[i].id);
          p.drawText(QPoint(pemain[i].pos_x, pemain[i].pos_y), id); //posisi x, y, dan ukuran elips
      }
      ui->label_game_visual->setPixmap (pm);
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
