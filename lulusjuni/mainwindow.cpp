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
//	myBMTDialog = new BackgroundModelTuningDialog(this);
	myFSDialog = new FieldSelectionDialog(this);

	//connect slot
	QObject::connect(myStream_1, SIGNAL(rawImage(QImage)), myCVDialog, SLOT(updateRawPlayerUI_1(QImage)));
	QObject::connect(myStream_2, SIGNAL(rawImage(QImage)), myCVDialog, SLOT(updateRawPlayerUI_2(QImage)));
	QObject::connect(myStream_3, SIGNAL(rawImage(QImage)), myCVDialog, SLOT(updateRawPlayerUI_3(QImage)));

	//connect slot from
/*	QObject::connect(myBMTDialog, SIGNAL(valueMinArea_1(int)), myStream_1, SLOT(updateValueMinArea(int)));
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
    QObject::connect(myBMTDialog, SIGNAL(valueGaussianSize_1(int)), myCVDialog, SLOT(updateLabel(int)));
*/
    connect(ui->label_game_visual, SIGNAL(sendMousePosition(QPoint&)),this, SLOT(showMousePosition(QPoint&)));
    connect(ui->label_game_visual, SIGNAL(sendClickPosition(QPoint&)),this, SLOT(mainGameDisplayClickEvent(QPoint&)));
    connect(ui->label_formationTeamA, SIGNAL(sendClickPosition(QPoint&)),this, SLOT(selectPlayerFromFormationA(QPoint&)));
    connect(ui->label_formationTeamB, SIGNAL(sendClickPosition(QPoint&)),this, SLOT(selectPlayerFromFormationB(QPoint&)));
    connect(ui->label_game_visual, SIGNAL(sendRightClickPosition(QPoint&)),this, SLOT(mainGameDisplayRightClickEvent(QPoint&)));

    setRandomPlayerProperties();


    updateGameVisual();
    teamA.setFormation(442);
    teamB.setFormation(442);
    updateDisplayFormationTeamA();
    updateDisplayFormationTeamB();

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
    //ui->label

}

void MainWindow::mainGameDisplayClickEvent(QPoint &pos)
{
    int isPlayer=false;

    for(int i=0;i<JUMLAH_PLAYER;i++)
    {
        if((pos.x()>=player_visual[i].Position.x() && pos.x()<=player_visual[i].Position.x()+10) && (pos.y()>=player_visual[i].Position.y() && pos.y()<=player_visual[i].Position.y()+10))
        {
            playerIdSelected = player_visual[i].id;
            isPlayer = true;
            if(player_visual[i].id<1100)
            {
                ui->idLabel->setText("ID    :"+QString::number(playerIdSelected));
            }
            else ui->idLabel->setText("ID                   :not set");


        }
    }
    if(!isPlayer)
    {
        playerIdSelected = 999;
        setRandomPlayerProperties();
        updateGameVisual();
    }

}

void MainWindow::mainGameDisplayRightClickEvent(QPoint &pos)
{
    int isPlayer=false;
    if(idToAssign<JUMLAH_PLAYER)
    {
        for(int i=0;i<JUMLAH_PLAYER;i++)
        {
            if((pos.x()>=player_visual[i].Position.x() && pos.x()<=player_visual[i].Position.x()+10) && (pos.y()>=player_visual[i].Position.y() && pos.y()<=player_visual[i].Position.y()+10))
            {
                isPlayer = true;

                //handle kondisi user meng-Assign id ke player yang sudah punya id valid sebelumnya
                //ketahui id player sebelum diubah idnya
                if(player_visual[i].id<JUMLAH_PLAYER)
                idAssignedFlag[player_visual[i].id]=false;  //set player yang punya id tersebut dengan flag idAssignedFlag=0


                //handle kondisi ketika meng-Assigned id yang sudah ada di lapangan
                //cek terlebih dahulu apakah id yang ingin di Assigned <jumlah pemain
                if(idToAssign<JUMLAH_PLAYER)
                {
                    if(idAssignedFlag[idToAssign])
                    {

                        //cari player yang punya idlama;
                        for(int j=0; j<JUMLAH_PLAYER; j++)
                        {
                            if(player_visual[j].id==idToAssign) // cari id lama yang terdapat dalam player
                            {
                                player_visual[j].id=999;        //jika ditemukan, set id tersebut dengan jadi unknown

                            }
                        }
                        //set id player lama jadi unknown;
                    }
                }


                player_visual[i].id=idToAssign;

                //jika id yang ingin di assigned tidak valid, mkaa tidak perlu mengubah variabel idAssignedFlag
                if(idToAssign<JUMLAH_PLAYER)idAssignedFlag[player_visual[i].id]=true;

                //idToSigned default
                idToAssign=999;

                updateGameVisual();
                updateDisplayFormationTeamA();
                updateDisplayFormationTeamB();
            }
        }
    }
}



void MainWindow::updateGameVisual()
{
    int i;
    QPixmap pixmapField("lapangan.png");   //ukuran pixmap
    QPainter painterField(&pixmapField);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);

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

          if(player_visual[i].id<900) painterField.drawText(QPoint(player_visual[i].Position.x(), player_visual[i].Position.y()), QString::number(player_visual[i].id)); //posisi x, y, dan ukuran elips
          else painterField.drawText(QPoint(player_visual[i].Position.x(), player_visual[i].Position.y()), "??");

     }
      ui->label_game_visual->setPixmap (pixmapField);
      this->updateDisplayFormationTeamA();
      this->updateDisplayFormationTeamB();

}

void MainWindow::setRandomPlayerProperties()
{
    //set random value of player
    for(int i=0;i<=JUMLAH_PLAYER;i++)
    {
        idAssignedFlag[i]=false;
    }
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

void MainWindow::selectPlayerFromFormationA(QPoint &pos)
{
    bool isPlayer=false;
    for(int id=0; id<=10; id++)
    {
        if(pos.x() > playerFormation[id].x()*220/192 && pos.x() <= (playerFormation[id].x()*220/192 + 20) && pos.y() > playerFormation[id].y()*150/130 && pos.y() <= (playerFormation[id].y()*150/130 +20))
        {
            ui->playerNameLabel->setText("ID to Assign-->"+QString::number(id));
            isPlayer=true;
            idToAssign=id;
        }

        //qDebug() << playerFormation[id].x();
    }
    if(!isPlayer)
    {
        ui->playerNameLabel->setText("Not Player");
        idToAssign=999;
    }
    ui->positionLabel->setText(QString::number(pos.x())+"  "+QString::number(pos.y()));
}

void MainWindow::selectPlayerFromFormationB(QPoint &pos)
{
    bool isPlayer=false;
    for(int id=0; id<=10; id++)
    {
        if(pos.x() < 192-playerFormation[id].x()*220/192 && pos.x() >= (192-playerFormation[id].x()*220/192 - 20) && pos.y() > playerFormation[id].y()*150/130 && pos.y() <= (playerFormation[id].y()*150/130+20))
        {
            ui->playerNameLabel->setText("ID to Assign-->"+QString::number(id+JUMLAH_PLAYER_TEAM_A));
            isPlayer=true;
            idToAssign=id+JUMLAH_PLAYER_TEAM_A;
        }

        //qDebug() << playerFormation[id].x();
    }
    if(!isPlayer)
    {
        ui->playerNameLabel->setText("Not Player");
        idToAssign=999;
    }
    ui->positionLabel->setText(QString::number(pos.x())+"  "+QString::number(pos.y()));
}


void MainWindow::updateDisplayFormationTeamA()
{
    QPixmap pixmapFieldTeam("lapanganTeamA.png");
    qDebug()<<pixmapFieldTeam.width()<<' '<<pixmapFieldTeam.height();
    qDebug()<<ui->label_formationTeamA->width()<<' '<<ui->label_formationTeamA->height();
    QPainter painterField(&pixmapFieldTeam);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush fill(Qt::yellow);
    QBrush empty;
    painterField.setPen(pen);
    //painterField
    for(int i=0;i<JUMLAH_PLAYER_TEAM_A;i++)
    {
        if(idAssignedFlag[i]) painterField.setBrush(fill);
        else painterField.setBrush(empty);
        painterField.drawRect(playerFormation[i].x()*220/192 , playerFormation[i].y()*150/130 , 20, 20);
        painterField.drawText(QPoint(playerFormation[i].x()*220/192+2, playerFormation[i].y()*150/130+15), QString::number(i));
    }

   // painterField.
    ui->label_formationTeamA->setPixmap(pixmapFieldTeam);

}

void MainWindow::updateDisplayFormationTeamB()
{
    QPixmap pixmapFieldTeam("lapanganTeamA.png");
    qDebug()<<pixmapFieldTeam.width()<<' '<<pixmapFieldTeam.height();
    qDebug()<<ui->label_formationTeamB->width()<<' '<<ui->label_formationTeamB->height();
    QPainter painterField(&pixmapFieldTeam);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush empty;
    QBrush fill(Qt::red);
    painterField.setPen(pen);
    //painterField

    for(int i=0;i<JUMLAH_PLAYER_TEAM_B;i++)
    {
        if(idAssignedFlag[i+11]) painterField.setBrush(fill);
        else painterField.setBrush(empty);
        painterField.drawRect(192-playerFormation[i].x()*220/192 , playerFormation[i].y()*150/130 , -20, 20);
        painterField.drawText(QPoint(192-playerFormation[i].x()*220/192-18, playerFormation[i].y()*150/130+15), QString::number(i+11));
    }

   // painterField.
    ui->label_formationTeamB->setPixmap(pixmapFieldTeam);

}

