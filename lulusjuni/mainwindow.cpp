#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "objectvariable.h"
#include <string>
#include <iostream>



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
<<<<<<< Updated upstream
    GameVisual();
=======
    QObject::connect(myBMTDialog, SIGNAL(valueGaussianSize_1(int)), myCVDialog, SLOT(updateLabel(int)));

    connect(ui->label_game_visual, SIGNAL(sendMousePosition(QPoint&)),this, SLOT(showMousePosition(QPoint&)));
    connect(ui->label_game_visual, SIGNAL(sendClickPosition(QPoint&)),this, SLOT(showClickPosition(QPoint&)));

    setRandomPlayerProperties();
    updateGameVisual();


>>>>>>> Stashed changes

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

void MainWindow::showMousePosition(QPoint &pos)
{
    //ui->label_mouse_pos->setText("x: "+ QString::number(pos.x())+",y: "+QString::number(pos.y()));

}

void MainWindow::showClickPosition(QPoint &pos)
{
    int isPlayer=false;

    for(int i=0;i<JUMLAH_PLAYER;i++)
    {
        if((pos.x()>=player_visual[i].Position.x() && pos.x()<=player_visual[i].Position.x()+10) && (pos.y()>=player_visual[i].Position.y() && pos.y()<=player_visual[i].Position.y()+10))
        {
            playerIdSelected = player_visual[i].id;
            isPlayer = true;
            if(player_visual[i].id<900)
            {
                ui->lineEdit_setIDplayer->setText(QString::number(playerIdSelected));
            }
            else ui->lineEdit_setIDplayer->setText("???");


        }
    }
    if(!isPlayer)
    {
        playerIdSelected = 999;
        setRandomPlayerProperties();
        updateGameVisual();
    }

}

void MainWindow::updateGameVisual()
{
    int i;
    QPixmap pixmapField("lapangan.png");   //ukuran pixmap
    QPainter painterField(&pixmapField);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);
    QString id;
    QPoint batas_lapang_kiri_atas(34, 28);
    QPoint batas_lapang_kiri_bawah(34, pixmapField.height()-28);
    QPoint batas_lapang_kanan_atas(pixmapField.width()-34, 28);
    QPoint batas_lapang_kanan_bawah(pixmapField.width()-34, pixmapField.height()-28);

    painterField.setRenderHint(QPainter::Antialiasing, true);
    painterField.setPen(pen);
    for(i=0;i<JUMLAH_PLAYER; i++)
    {
          if(player_visual[i].TeamSide=='A') brush.setColor(Qt::yellow);      //warna pengisi lingkaran player_visual
          else if(player_visual[i].TeamSide=='B') brush.setColor(Qt::red);
          painterField.setBrush(brush);

          painterField.drawRect(player_visual[i].Position.x(), player_visual[i].Position.y(), rect_player_size, rect_player_size);  //posisi x, y, dan ukuran elips
          painterField.setFont(QFont ("Arial"));
            id = QString::number(player_visual[i].id);
          if(player_visual[i].id<900) painterField.drawText(QPoint(player_visual[i].Position.x(), player_visual[i].Position.y()), id); //posisi x, y, dan ukuran elips
          else painterField.drawText(QPoint(player_visual[i].Position.x(), player_visual[i].Position.y()), "??");

     }
      ui->label_game_visual->setPixmap (pixmapField);

}

void MainWindow::setRandomPlayerProperties()
{
    //set random value of player
    for(int i=0; i<JUMLAH_PLAYER; i++)
        {
            player_visual[i].id=i+999;
            if(i<=12) player_visual[i].TeamSide='A';
            else player_visual[i].TeamSide='B';
            player_visual[i].Position.setX(qrand() % (640-68)+34);
            //cout<<player_visual[i].pos_x<<" ";
            player_visual[i].Position.setY(qrand() % (434-56) + 28);
        }
}

void MainWindow::setIDplayer()
{

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

void MainWindow::on_pushButton_clicked()
{
    for(int i=0; i<JUMLAH_PLAYER;i++)
    {
        if (player_visual[i].id==playerIdSelected)
        {
            player_visual[i].id= ui->lineEdit_setIDplayer->text().toInt();
            updateGameVisual();
        }
    }
}
