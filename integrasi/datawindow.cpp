#include "datawindow.h"
#include "ui_datawindow.h"
#include <QMessageBox>
//#include <QDebug>


DataWindow::DataWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataWindow)
{
    playerStatistics.resize(22);
    ui->setupUi(this);
    //construct datalogger
    myDataLogger = new DataLogger();
    myDataLoggerAssociated = new DataLogger();
    //construct new object
    timer = new QTimer(this);
    model = new QStandardItemModel();

    //connect signal and SLOT
    connect(timer, SIGNAL(timeout()), this,SLOT(updatePosition()));
    //set configuration
    ui->pushButton_load->setEnabled(true);
    ui->pushButton_save->setEnabled(true);

    //initialization
    tempPlayersData.clear();
    updateModel(tempPlayersData);
    QPixmap pixmapField("field_new2.jpg");
    ui->label_playbackVisual->setPixmap(pixmapField);

    ui->tableView_result->Begin(model);
    frameNumbert = 0;
    frameNumber = 0;
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
    //determine object posistion in cerain frame
    frameNumbert++;
    if(frameNumbert< maximumFrameNumber){
        updatePositionbySlider(frameNumbert);
        qDebug()<<"frameNumber"<<frameNumbert;
    }
    else{
        timer->stop();
    }
}

/**
 * this function will advance to next frame for playing back visualization by frame number
 */
void DataWindow::updatePositionbySlider(int frameNumber)
{
    QPixmap pixmapField("field_new2.jpg");   //ukuran pixmap
    QPainter painterField(&pixmapField);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);
    tempSinglePlayer.clear();
    painterField.setRenderHint(QPainter::Antialiasing, true);
    painterField.setPen(pen);
    for (int id = 0; id < tempPlayersData.size(); id++)
    {
        brush.setColor(Qt::red);
        painterField.setBrush(brush);
        tempSinglePlayer.append(tempPlayersData.at(id));
        int iterNumber=-1;
        if(!tempSinglePlayer.isEmpty()){
            for(int j=0;j<tempSinglePlayer.size();j++){
                if(tempSinglePlayer.at(j).framePosition==frameNumber){
                    iterNumber = j;
                }
            }
            //qDebug()<<"size"<<tempSinglePlayer.size();
            //qDebug()<<"iterator"<<iterNumber;
            if(iterNumber!=-1){
                painterField.drawRect(tempSinglePlayer.at(iterNumber).pos.x * pixmapField.width() / 100,
                                      tempSinglePlayer.at(iterNumber).pos.y * pixmapField.height() / 50, 10, 10); //posisi x, y, dan ukuran elips
                painterField.setFont(QFont ("Arial"));
                painterField.drawText(QPoint(tempSinglePlayer.at(iterNumber).pos.x * pixmapField.width() / 100,
                                             tempSinglePlayer.at(iterNumber).pos.y * pixmapField.height() / 50),
                                      QString::number(tempSinglePlayer.at(iterNumber).id)); //posisi x, y, dan ukuran elips
            }
        }
        tempSinglePlayer.clear();
    }
    ui->label_playbackVisual->setPixmap(pixmapField);
    ui->label_playback_time->setText("Frame " + QString::number(frameNumber));
}

/**
 * get cell selected indexes on the table
 */
void DataWindow::getItemSelected()
{
    idSelected = ui->tableView_result->getIndexesSelected().at(0).row();
    frameSelected.clear();
    for (int i = 0; i < ui->tableView_result->getIndexesSelected().size(); i++)
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
    if (!resultData.isEmpty()) {
        for (int frame = 0; frame < resultData.size(); frame++)
        {
            if (frame == 0) labels.append("ID");
            else labels.append(QString::number(frame));
        }

        model->setHorizontalHeaderLabels(labels);
        for (int id = 0; id < resultData.size(); ++id)
        {
            for (int rec = 0; rec < resultData.at(id).size(); ++rec)
            {
                if (rec == 0) newItem = new QStandardItem(QString::number(resultData.at(id).at(0).id));
                else newItem = new QStandardItem(QString::number(1));
                switch (id % 10) {
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
                model->setItem(resultData.at(id).at(0).id, resultData.at(id).at(rec).framePosition, newItem);
            }
        }
    }
}

void DataWindow::processData(QList<Player> dataPlayer) {
    myDataLogger->add(dataPlayer);
}

void DataWindow::processDataAssociated(QList<Player> dataPlayerAssociated){
    myDataLoggerAssociated->add(dataPlayerAssociated);
}

void DataWindow::on_pushButton_cut_clicked()
{
    tempSinglePlayerRec.clear();
    getItemSelected();
    for (int i = 0; i < frameSelected.size(); i++)
    {
        //update model
        model->setItem(idSelected, frameSelected.at(i), new QStandardItem(QString::null));
        //looking for frame number in QList Rec of Player and copy that
        for (int j = 0; j < tempPlayersData.at(idSelected).size(); j++)
        {
            if (tempPlayersData.at(idSelected).at(j).framePosition == frameSelected.at(i))
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
    int destIndex = 0;
    int recIndex = 0;
    //find QList index that have frame value > first frame selected
    do {
        if (tempSinglePlayerRec.at(0).framePosition <= tempPlayersData.at(idSelected).at(recIndex).framePosition)
            destIndex = recIndex;
        recIndex++;
    } while (recIndex < tempPlayersData.at(idSelected).size() && destIndex == 0);

    for (int i = 0; i < tempSinglePlayerRec.size() ; i++)
    {
        if (tempSinglePlayerRec.at(i).framePosition < tempPlayersData.at(idSelected).at(destIndex + i).framePosition)
            tempPlayersData[idSelected].insert(destIndex + i, tempSinglePlayerRec.at(i));
    }
    //qDebug()<<"iterator(frame)";
    for (int i = 0; i < tempPlayersData.at(idSelected).size(); i++)
    {
        //qDebug()<<i<<'('<<tempPlayersData[idSelected].at(i).framePosition<<')'<<' ';
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
 * Play Back
 */
void DataWindow::on_pushButton_playbackStart_clicked()
{
    frameNumbert = minimumFrameNumber;
    timer->start(100);
    updatePosition();
}

/**
 * [DataWindow::on_slider_playback_valueChanged description]
 * @param value [current frame]
 */
void DataWindow::on_slider_playback_valueChanged(int value)
{
    if(value > minimumFrameNumber && value< maximumFrameNumber){
        qDebug()<<"masuk";
        frameNumber = value;
        qDebug()<<frameNumber;
        updatePositionbySlider(frameNumber);
    }
}


/*
 * [DataWindow::on_pushButton_reconstruct_clicked description]
 * Generate miss data from QList
 */
void DataWindow::on_pushButton_reconstruct_clicked()
{
    Player newPlayer;
    Point2f increment(0, 0);
    getItemSelected();
    //qDebug()<<"sebeluminterpolasi:";
    for (int i = 0; i < tempPlayersData.at(idSelected).size(); i++)
    {
        //qDebug()<<i<<'('<<tempPlayersData[idSelected].at(i).framePosition<<')'<<' '<<"pos: "<<tempPlayersData.at(idSelected).at(i).pos.x<<", "<<tempPlayersData.at(idSelected).at(i).pos.y;
    }

    for (int rec = 0; rec < tempPlayersData.size(); rec++)
    {
        //jika ditemukan ada yang kosong
        if (tempPlayersData.at(idSelected).at(rec).framePosition != rec)
        {
            //hitung incrment interpolasi
            increment.x = (tempPlayersData.at(idSelected).at(rec).pos.x - tempPlayersData.at(idSelected).at(rec - 1).pos.x) /
                          (tempPlayersData.at(idSelected).at(rec).framePosition - (rec - 1));

            increment.y = (tempPlayersData.at(idSelected).at(rec).pos.y - tempPlayersData.at(idSelected).at(rec - 1).pos.y) /
                          (tempPlayersData.at(idSelected).at(rec).framePosition - (rec - 1));
            //qDebug()<<increment.x<<", "<<increment.y;
            //lakukan pengisian QList dengan interpolasi
            for (rec = rec; rec < tempPlayersData.at(idSelected).at(rec).framePosition; rec++)
            {
                newPlayer = tempPlayersData.at(idSelected).at(rec);
                tempPlayersData[idSelected].insert(rec, newPlayer);
                tempPlayersData[idSelected][rec].pos = tempPlayersData.at(idSelected).at(rec - 1).pos + increment;
                tempPlayersData[idSelected][rec].framePosition = rec;

            }
        }
    }
    //qDebug()<<"setelah interpolasi";
    for (int i = 0; i < tempPlayersData.at(idSelected).size(); i++)
    {
        //qDebug()<<i<<'('<<tempPlayersData[idSelected].at(i).framePosition<<')'<<' '<<"pos: "<<tempPlayersData.at(idSelected).at(i).pos.x<<", "<<tempPlayersData.at(idSelected).at(i).pos.y;
    }
    updateModel(tempPlayersData);
}

void DataWindow::on_pushButton_display_data_released()
{
    tempPlayersData.clear();
    tempPlayersData = myDataLogger->dataLog.toVector();
    updateModel(tempPlayersData);
}

double DataWindow::euclidean(double x,double y){
    return(sqrt((x*x)+(y*y)));
}



void DataWindow::generateHeatMapperPlayer(QList<Player> players){
    playerPosition.clear();
    Counter.clear();
    for(int i=0;i<players.size();i++){
        QPoint HMPosition(qFloor(players.at(i).pos.x),qFloor(players.at(i).pos.y));
        if(playerPosition.isEmpty()){
            playerPosition.append(HMPosition);
            Counter.append(1);
        }
        else{
            for(int j=0;j<playerPosition.size();j++){
                if((playerPosition.at(j).x()==qFloor(players.at(i).pos.x))&&(playerPosition.at(j).y()==qFloor(players.at(i).pos.y))){
                    Counter[j]+=1;
                }else{
                    playerPosition.append(HMPosition);
                    Counter.append(1);
                }
            }
        }

    }
}

void DataWindow::generateAllPlayerHeatmap(){
    for(int id=0;id < tempPlayersData.size();id++){
        int maxCounter = 0;
        int refferenceHeatMap = 0;
        QPixmap pixmapFieldHeatMap("field_new2.jpg");   //ukuran pixmap
        QPainter painterFieldHeatMap(&pixmapFieldHeatMap);
        QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
        QBrush brush(Qt::white);
        painterFieldHeatMap.setRenderHint(QPainter::Antialiasing, true);
        painterFieldHeatMap.setPen(pen);
        generateHeatMapperPlayer(tempPlayersData.at(id));
        //determine maximum counter

        for(int i=0;i<Counter.size();i++){
            if(maxCounter < Counter.at(i)){
                maxCounter = Counter.at(i);
            }
        }
        refferenceHeatMap = maxCounter/3;
        for(int i=0;i<Counter.size();i++){
            if(Counter.at(i)>=refferenceHeatMap && Counter.at(i) < 2*refferenceHeatMap){
                brush.setColor(Qt::yellow);
                painterFieldHeatMap.drawRect(playerPosition.at(i).x() * pixmapFieldHeatMap.width() / 100,
                                             playerPosition.at(i).y() * pixmapFieldHeatMap.height() / 50, pixmapFieldHeatMap.width() / 100, pixmapFieldHeatMap.width() / 100); //posisi x, y, dan ukuran elips

            }
            else if(Counter.at(i)>= 2*refferenceHeatMap && Counter.at(i) < 3*refferenceHeatMap){
                brush.setColor(Qt::red);
                painterFieldHeatMap.drawRect(playerPosition.at(i).x() * pixmapFieldHeatMap.width() / 100,
                                             playerPosition.at(i).y() * pixmapFieldHeatMap.height() / 50, pixmapFieldHeatMap.width() / 100, pixmapFieldHeatMap.width() / 100); //posisi x, y, dan ukuran elips

            }
            else if(Counter.at(i) >= 3*refferenceHeatMap){
                brush.setColor(Qt::darkRed);
                painterFieldHeatMap.drawRect(playerPosition.at(i).x() * pixmapFieldHeatMap.width() / 100,
                                             playerPosition.at(i).y() * pixmapFieldHeatMap.height() / 50, pixmapFieldHeatMap.width() / 100, pixmapFieldHeatMap.width() / 100); //posisi x, y, dan ukuran elips

            }
        }
        playerStatistics[tempPlayersData.at(id).at(0).id].heatmap = pixmapFieldHeatMap;//heatmap yang dihasilkan
    }
}


void DataWindow::updatePlayerSpeed(){
    tempSinglePlayer.clear();
    for(int i=0;i<tempPlayersData.size();i++){
        playerStatistics[i].maximumSpeed = 0;
        double sumSinglePlayerSpeed = 0;
        double maximumSpeed = 0;
        tempSinglePlayer.append(tempPlayersData[i]);

        if(!tempSinglePlayer.isEmpty()){
            for(int j = 0;j<tempSinglePlayer.size();j++){
                if(maximumSpeed < euclidean(tempSinglePlayer.at(j).speed.x,tempSinglePlayer.at(j).speed.y)){
                    maximumSpeed = euclidean(tempSinglePlayer[j].speed.x,tempSinglePlayer[j].speed.y);
                }
                sumSinglePlayerSpeed += euclidean(tempSinglePlayer[j].speed.x,tempSinglePlayer[j].speed.y);
            }
            tempSinglePlayer.clear();
        }
        playerStatistics[i].averageSpeed = sumSinglePlayerSpeed/(double(tempSinglePlayer.size()));
        playerStatistics[i].maximumSpeed = maximumSpeed;
    }
}

void DataWindow::updatePlayerAcceleration(){
    tempSinglePlayer.clear();
    for(int i=0;i<tempPlayersData.size();i++){
        playerStatistics[i].maximumAcceleration = 0;
        double sumSinglePlayerAcceleration = 0;
        double maximumAcceleration = 0;
        tempSinglePlayer.append(tempPlayersData[i]);

        if(!tempSinglePlayer.isEmpty()){
            for(int j = 0;j<tempSinglePlayer.size();j++){
                if(maximumAcceleration < euclidean(tempSinglePlayer.at(j).acceleration.x,tempSinglePlayer.at(j).acceleration.y)){
                    maximumAcceleration = euclidean(tempSinglePlayer[j].acceleration.x,tempSinglePlayer[j].acceleration.y);
                }
                sumSinglePlayerAcceleration += euclidean(tempSinglePlayer[j].acceleration.x,tempSinglePlayer[j].acceleration.y);
            }
            tempSinglePlayer.clear();
        }
        playerStatistics[i].averageAcceleration = sumSinglePlayerAcceleration/(double(tempSinglePlayer.size()));
        playerStatistics[i].maximumAcceleration = maximumAcceleration;
    }
}

void DataWindow::on_pushButton_load_released()
{
    filename = QFileDialog::getOpenFileName(this,
                                            tr("Open Log File"), ".",
                                            tr("Log File (*.log)"));
    myDataLogger->loadFromFile(filename);
    tempPlayersData.clear();
    tempPlayersData = myDataLogger->dataLog.toVector();
    //determine minimum Framestate of Frame inside tempPlayersData
    minimumFrameNumber = tempPlayersData.at(0).at(1).framePosition;
    tempSinglePlayer.clear();
    for(int i=1;i<tempPlayersData.size()-1;i++){
        tempSinglePlayer.append(tempPlayersData[i]);
        if(minimumFrameNumber > tempPlayersData.at(i).at(0).framePosition && !tempPlayersData.isEmpty()){
            minimumFrameNumber = tempPlayersData.at(i).at(0).framePosition;
        }
        tempSinglePlayer.clear();
    }
    //determine maximum Frame state inside tempPlayersData
    maximumFrameNumber = 0;
    tempSinglePlayer.clear();
    for(int i=0;i<tempPlayersData.size();i++){
        tempSinglePlayer.append(tempPlayersData[i]);
        if(maximumFrameNumber < tempPlayersData.at(i).at(tempSinglePlayer.size()-1).framePosition){
            maximumFrameNumber = tempPlayersData.at(i).at(tempSinglePlayer.size()-1).framePosition;
        }
        tempSinglePlayer.clear();
    }
    updatePlayerSpeed();
    updatePlayerAcceleration();
    generateAllPlayerHeatmap();
}

void DataWindow::on_pushButton_save_released()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save Log File"), "data.log",
                                            tr("Log File (*.log)"));
    myDataLogger->saveToFile(filename);

}


void DataWindow::on_pushButton_save_raw_released()
{
    filename = QFileDialog::getSaveFileName(this, tr("Save Log File"), "data-raw.log",
                                            tr("Log File (*.log)"));
    myDataLoggerAssociated->saveToFile(filename);
}

void DataWindow::on_pushButton_load_raw_released()
{

}
