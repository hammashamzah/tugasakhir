#include "datawindow.h"
#include "ui_datawindow.h"
#include <QMessageBox>

DataWindow::DataWindow(QWidget *parent) :
QWidget(parent),
ui(new Ui::DataWindow)
{
	ui->setupUi(this);

	//construct new object
	timer = new QTimer(this);
	model =new QStandardItemModel();

	//connect signal and SLOT
	connect(timer, SIGNAL(timeout()), this,SLOT(updatePosition()));

	//set configuration
	ui->pushButton_load->setEnabled(false);
	ui->pushButton_save->setEnabled(false);

	//initialization
	tempPlayersData=setRandomQList();
	updateModel(tempPlayersData);
    QPixmap pixmapField("field_new2.jpg");
    ui->label_playbackVisual->setPixmap(pixmapField);

	ui->tableView_result->Begin(model);
	frameNumber=0;
}

DataWindow::~DataWindow()
{
	delete ui;
}

/**
 * this function will advance to next frame for playing back visualization 
 */
 void DataWindow::updatePosition()
 {
	QPixmap pixmapField("field_new2.jpg");   //ukuran pixmap
	QPainter painterField(&pixmapField);
	QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
	QBrush brush(Qt::white);

	painterField.setRenderHint(QPainter::Antialiasing, true);
	painterField.setPen(pen);
	frameNumber++;
	if(frameNumber<TOTAL_FRAME){
		for (int id = 0; id < tempPlayersData.size(); id++)
		{
			brush.setColor(Qt::red);
			painterField.setBrush(brush);
			painterField.drawRect( tempPlayersData.at(id).at(frameNumber).pos.x*pixmapField.width()/100, 
									tempPlayersData.at(id).at(frameNumber).pos.y*pixmapField.height()/50, 10, 10);  //posisi x, y, dan ukuran elips
			painterField.setFont(QFont ("Arial"));
			painterField.drawText(QPoint(tempPlayersData.at(id).at(frameNumber).pos.x*pixmapField.width()/100,  
				tempPlayersData.at(id).at(frameNumber).pos.y*pixmapField.height()/50), 
										QString::number( tempPlayersData.at(id).at(frameNumber).id)); //posisi x, y, dan ukuran elips
		}
        ui->label_playbackVisual->setPixmap(pixmapField);
		ui->label_playback_time->setText("Frame "+QString::number(frameNumber));
	}
	else timer->stop();
}

/**
 * get cell selected indexes on the table
 */
 void DataWindow::getItemSelected()
 {
 	idSelected = ui->tableView_result->getIndexesSelected().at(0).row();
 	frameSelected.clear();
 	for(int i=0;i<ui->tableView_result->getIndexesSelected().size();i++)
 	{
 		frameSelected.append(ui->tableView_result->getIndexesSelected().at(i).column());
 	}

 }

/**
 * Model Generator
 * input: final data from tracking on the global frame
 */
 void DataWindow::updateModel(QVector<QList<Player> > resultData)
 {
 	QStandardItem *newItem = 0;
 	QList<QString> labels;

 	model->clear();

 	for(int frame=0;frame<TOTAL_FRAME;frame++)
 	{
 		if (frame==0) labels.append("ID");
 		else labels.append("Frame"+QString::number(frame));
 	}
 	qDebug()<<labels;
 	model->setHorizontalHeaderLabels(labels);
 	for (int id = 0; id < resultData.size(); ++id)
 	{
 		for (int rec = 0; rec < resultData.at(id).size(); ++rec)
 		{
 			if (rec==0) newItem = new QStandardItem(QString::number(id));
 			else newItem = new QStandardItem(QString::number(1));
 			switch (id%10) {
 				case 0:
 				newItem->setBackground(QBrush(QColor(Qt::blue)));
 				break;
 				case 1:
 				newItem->setBackground(QBrush(QColor(Qt::red)));
 				break;
 				case 2:
 				newItem->setBackground(QBrush(QColor(Qt::yellow)));
 				break;
 				case 3:
 				newItem->setBackground(QBrush(QColor(Qt::cyan)));
 				break;
 				case 4:
 				newItem->setBackground(QBrush(QColor(Qt::magenta)));
 				break;
 				case 5:
 				newItem->setBackground(QBrush(QColor(Qt::gray)));
 				break;
 				case 6:
 				newItem->setBackground(QBrush(QColor(Qt::green)));
 				break;
 				case 7:
 				newItem->setBackground(QBrush(QColor(Qt::darkBlue)));
 				break;
 				case 8:
 				newItem->setBackground(QBrush(QColor(Qt::darkCyan)));
 				break;
 				case 9:
 				newItem->setBackground(QBrush(QColor(Qt::darkGray)));
 				break;
 				case 10:
 				newItem->setBackground(QBrush(QColor(Qt::darkGreen)));
 				break;
 				case 11:
 				newItem->setBackground(QBrush(QColor(Qt::darkMagenta)));
 				break;

 				default:
 				break;
 			}
 			model->setItem(id, resultData.at(id).at(rec).framePosition, newItem);
 		}
 	}
 }


 void DataWindow::addData(QList<Player> newData){
 	myDataLogger.add(newData);
 }

 void DataWindow::dataEntryFinished(){
 	ui->pushButton_load->setEnabled(true);
 	ui->pushButton_save->setEnabled(true);
 }

 void DataWindow::on_pushButton_cut_clicked()
 {
 	tempSinglePlayerRec.clear();
 	getItemSelected();
 	qDebug()<<idSelected;
 	qDebug()<<frameSelected;

	//copy selected to temp and then remove it
 	for(int i=0;i<frameSelected.size();i++)
 	{
		//update model
 		model->setItem(idSelected,frameSelected.at(i), new QStandardItem(QString::null));
		//looking for frame number in QList Rec of Player and copy that
 		for(int j=0;j<tempPlayersData.at(idSelected).size();j++)
 		{
 			if(tempPlayersData.at(idSelected).at(j).framePosition==frameSelected.at(i))
 			{
 				tempSinglePlayerRec.append(tempPlayersData.at(idSelected).at(j));
 				tempPlayersData[idSelected].removeAt(j);
 			}
 		}
 	}
 }

 void DataWindow::on_pushButton_paste_clicked()
 {
 	getItemSelected();
 	int destIndex=0;
 	int recIndex=0;
	//find QList index that have frame value > first frame selected
 	do{
 		if(tempSinglePlayerRec.at(0).framePosition <= tempPlayersData.at(idSelected).at(recIndex).framePosition)
 			destIndex = recIndex;
 		recIndex++;
 	}while(recIndex<tempPlayersData.at(idSelected).size()&&destIndex==0);

 	for(int i=0;i<tempSinglePlayerRec.size() ;i++)
 	{
 		if(tempSinglePlayerRec.at(i).framePosition < tempPlayersData.at(idSelected).at(destIndex+i).framePosition)
 			tempPlayersData[idSelected].insert(destIndex+i, tempSinglePlayerRec.at(i));
 	}
 	qDebug()<<"iterator(frame)";
 	for(int i=0;i<tempPlayersData.at(idSelected).size();i++)
 	{
 		qDebug()<<i<<'('<<tempPlayersData[idSelected].at(i).framePosition<<')'<<' ';
 	}

 	updateModel(tempPlayersData);
 }

 void DataWindow::on_pushButton_refresh_clicked()
 {
 	updateModel(tempPlayersData);
 	model->clear();
 	updateModel(tempPlayersData);
 }


/**
 * Generate random QList
 */
 QVector<QList<Player> > DataWindow::setRandomQList()
 {
 	QVector<QList<Player> > playerData;
 	playerData.resize(22);
 	Player playerUnit;

 	for (int i = 0; i < 22; ++i)
 	{
 		for (int j = 0; j < TOTAL_FRAME; ++j)
 		{
 			playerUnit.id = i;
 			playerUnit.framePosition = j;
 			if(j==0){
 				playerUnit.pos.x = qrand()%100;
 				playerUnit.pos.y = qrand()%50;
 			}
 			else{
 				playerUnit.pos.x=(int)(playerUnit.pos.x+1)%100;
 				playerUnit.pos.y=(int)(playerUnit.pos.y+1)%50;
 			}
 			playerData[i].append(playerUnit);
 		}
 	}
 	return playerData;
 }

/**
 * Play Back
 */
 void DataWindow::on_pushButton_playbackStart_clicked()
 {
 	timer->start(100);
 }

/**
 * [DataWindow::on_slider_playback_valueChanged description]
 * @param value [current frame]
 */
 void DataWindow::on_slider_playback_valueChanged(int value)
 {
 	frameNumber=value*TOTAL_FRAME/100;
 	ui->label_playback_time->setText("Frame "+QString::number(frameNumber));
 	updatePosition();
 }

/*
 * [DataWindow::on_pushButton_reconstruct_clicked description]
 * Generate miss data from QList
 */
 void DataWindow::on_pushButton_reconstruct_clicked()
 {
 	Player newPlayer;
 	Point2f increment(0,0);
 	getItemSelected();
 	qDebug()<<"sebeluminterpolasi:";
 	for(int i=0;i<tempPlayersData.at(idSelected).size();i++)
 	{
 		qDebug()<<i<<'('<<tempPlayersData[idSelected].at(i).framePosition<<')'<<' '<<"pos: "<<tempPlayersData.at(idSelected).at(i).pos.x<<", "<<tempPlayersData.at(idSelected).at(i).pos.y;
 	}

 	for(int rec=0;rec<TOTAL_FRAME;rec++)
 	{
			//jika ditemukan ada yang kosong
 		if(tempPlayersData.at(idSelected).at(rec).framePosition!=rec)
 		{
				//hitung incrment interpolasi
 			increment.x = (tempPlayersData.at(idSelected).at(rec).pos.x - tempPlayersData.at(idSelected).at(rec-1).pos.x)/
 			(tempPlayersData.at(idSelected).at(rec).framePosition-(rec-1));

 			increment.y = (tempPlayersData.at(idSelected).at(rec).pos.y - tempPlayersData.at(idSelected).at(rec-1).pos.y)/
 			(tempPlayersData.at(idSelected).at(rec).framePosition-(rec-1));
 			qDebug()<<increment.x<<", "<<increment.y;
				//lakukan pengisian QList dengan interpolasi
 			for(rec=rec;rec<tempPlayersData.at(idSelected).at(rec).framePosition;rec++)
 			{
 				newPlayer = tempPlayersData.at(idSelected).at(rec);
 				tempPlayersData[idSelected].insert(rec, newPlayer);
 				tempPlayersData[idSelected][rec].pos = tempPlayersData.at(idSelected).at(rec-1).pos + increment;
 				tempPlayersData[idSelected][rec].framePosition = rec;

 			}
 		}
 	}
 	qDebug()<<"setelah interpolasi";
 	for(int i=0;i<tempPlayersData.at(idSelected).size();i++)
 	{
 		qDebug()<<i<<'('<<tempPlayersData[idSelected].at(i).framePosition<<')'<<' '<<"pos: "<<tempPlayersData.at(idSelected).at(i).pos.x<<", "<<tempPlayersData.at(idSelected).at(i).pos.y;
 	}
 	updateModel(tempPlayersData);
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
