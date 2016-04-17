#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialize windows
    myCVDialog = new CameraViewDialog();
    myECDialog = new ErrorCalculationDialog();
    mySPDialog = new SystemPerformanceDialog();
    myTVDialog = new TrackingViewDialog();
    myBMTDialog = new BackgroundModelTuningDialog();
    myFSDialog = new FieldSelectionDialog();
    myObjectDetector = new ObjectDetector();
    myCoordinateTransform = new CoordinateTransform();

    isSetTrapezium = false;
    isSetThresholds = false;

    QObject::connect(myObjectDetector, SIGNAL(sendFirstFrameImage(QVector<QImage>)), myFSDialog, SLOT(setFirstFrameImage(QVector<QImage>)));
    QObject::connect(myObjectDetector, SIGNAL(sendFirstFrameImage(QVector<QImage>)), this, SLOT(setCameraViewFirstFrameImage(QVector<QImage>)));
    QObject::connect(myFSDialog, SIGNAL(sendMaskCoordinates(QVector< QList<QPoint> >)), myObjectDetector, SLOT(setMaskCoordinate(QVector< QList<QPoint> >)));
    QObject::connect(myObjectDetector, SIGNAL(sendCameraViewImage(QVector< QVector<QImage> >)), myCVDialog, SLOT(updateCameraViewImage(QVector< QVector<QImage> >)));
    QObject::connect(myObjectDetector, SIGNAL(sendCameraViewImage(QVector<QVector<QImage> >)), this, SLOT(updateCameraViewFrameImage(QVector< QVector<QImage> >)));
    QObject::connect(myBMTDialog, SIGNAL(sendValueParameter(QVector< QVector<int> >)), myObjectDetector, SLOT(updateValueParameter(QVector< QVector<int> >)));
    QObject::connect(myBMTDialog, SIGNAL(sendValueParameter(QVector< QVector<int> >)), this, SLOT(setValueParameter(QVector< QVector<int> >)));
    QObject::connect(myCoordinateTransform, SIGNAL(sendTransformedPosition(QList<Player>)), this, SLOT(displayTransformedPosition(QList<Player>)));
    QObject::connect()
    QObject::connect(myFSDialog, SIGNAL(sendTransformationCoordinates(QList<QPoint>)), myCoordinateTransform, SLOT(setTransformMatrix(QList<QPoint>)));
    QObject::connect(myFSDialog, SIGNAL(sendImageSize(QList<QSize>)), myCoordinateTransform, SLOT(setImageSize(QList<QSize>)));

    QObject::connect(ui->label_game_visual, SIGNAL(sendRightClickPosition(QPoint&)), this, SLOT(assignIdFromList(QPoint&)));
    QObject::connect(this, SIGNAL(sendAllIdAssigned(QVector<QList<Player> >)), myCoordinateTransform, SLOT(returnAssignedPlayer(QVector<QList<Player> >)));

    QObject::connect(myCoordinateTransform, SIGNAL(sendPlayerIdAssigned(QVector<QList<Player> >)), myObjectDetector, SLOT(showPlayerIdAssigned(QVector<QList<Player> >)));

    QObject::connect(myObjectDetector, SIGNAL(sendObjectData(QVector<QList<Player> >)), myDynamicAssociation, SLOT(getCurrentData(QVector<QList<Player> >)));

    QObject::connect(myFSDialog, SIGNAL(sendTrapeziumCoordinates(QVector<QList<QPoint> >)), this, SLOT(setTrapeziumCoordinates(QVector<QList<QPoint> >)));

    ui->slider_global_frame->setEnabled(false);
    videoLoaded[0] = false;
    videoLoaded[1] = false;
    //click event


    initListPlayer();
    assignedId = 0;
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
                                            tr("Video Files (*.avi *.mpg *.mp4 *.MOV)"));
    myObjectDetector->loadVideo(filename, 1);
    videoLoaded[0] = true;
    if (videoLoaded[0] && videoLoaded[1]) {
        ui->slider_global_frame->setEnabled(true);
        ui->slider_global_frame->setMaximum(myObjectDetector->getNumberOfFrames() / (int)myObjectDetector->getFrameRate());
    }


}

void MainWindow::on_actionVideo_2_triggered()
{
    filename = QFileDialog::getOpenFileName(this,
                                            tr("Open Video Stream 2"), ".",
                                            tr("Video Files (*.avi *.mpg *.mp4 *.MOV)"));
    myObjectDetector->loadVideo(filename, 2);
    videoLoaded[1] = true;
    if (videoLoaded[0] && videoLoaded[1]) {
        ui->slider_global_frame->setEnabled(true);
        ui->slider_global_frame->setMaximum(myObjectDetector->getNumberOfFrames());
        ui->label_max_time->setText(getFormattedTime((int)myObjectDetector->getNumberOfFrames() / (int)myObjectDetector->getFrameRate()));
    }
}

void MainWindow::on_pushButton_play_released()
{
    myObjectDetector->playContinously();
}
void MainWindow::on_pushButton_single_play_released() {
    myObjectDetector->playSingleFrame();
}

void MainWindow::displayModifiedId(QVector<QList<Player> > modifiedId)
{
    QPixmap pixmapField("lapangan.png");   //ukuran pixmap
    QPainter painterField(&pixmapField);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);

    playerDisplayed = modifiedId;

    painterField.setRenderHint(QPainter::Antialiasing, true);
    painterField.setPen(pen);
    for (int cameraId = 0; cameraId < playerDisplayed.size(); cameraId++)
    {
        for (int i = 0; i < playerDisplayed.at(cameraId).size(); i++)
        {
            playerDisplayed[cameraId][i].pos.x = (modifiedId.at(cameraId).at(i).pos.x);
            playerDisplayed[cameraId][i].pos.y = (modifiedId.at(cameraId).at(i).pos.y);

            brush.setColor(Qt::red);
            painterField.setBrush(brush);

            painterField.drawRect( playerDisplayed[cameraId][i].pos.x, playerDisplayed[cameraId][i].pos.y, RECT_PLAYER_SIZE, RECT_PLAYER_SIZE);  //posisi x, y, dan ukuran elips
            painterField.setFont(QFont ("Arial"));

            painterField.drawText(QPoint(playerDisplayed[cameraId][i].pos.x, playerDisplayed[cameraId][i].pos.y), QString::number(playerDisplayed.at(cameraId).at(i).id)); //posisi x, y, dan ukuran elips
        }

    }
    ui->label_game_visual->setPixmap(pixmapField);
}

void MainWindow::displayTransformedPosition(QVector<QList<Player> > transformedPosition)
{
    QPixmap pixmapField("lapangan.png");   //ukuran pixmap
    QPainter painterField(&pixmapField);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);

    playerDisplayed = transformedPosition;
    painterField.setRenderHint(QPainter::Antialiasing, true);
    painterField.setPen(pen);
    for (int cameraId = 0; cameraId < transformedPosition.size(); cameraId++)
    {
        for (int i = 0; i < transformedPosition.at(cameraId).size(); i++)
        {
            playerDisplayed[cameraId][i].pos.x = (transformedPosition.at(cameraId).at(i).pos.x * pixmapField.width() / GLOBAL_FIELD_LENGTH);
            playerDisplayed[camdisplayTransformedPositioneraId][i].pos.y = (transformedPosition.at(cameraId).at(i).pos.y * pixmapField.height() / GLOBAL_FIELD_WIDTH);

            brush.setColor(Qt::red);
            painterField.setBrush(brush);

            painterField.drawRect( playerDisplayed[cameraId][i].pos.x, playerDisplayed[cameraId][i].pos.y, RECT_PLAYER_SIZE, RECT_PLAYER_SIZE);  //posisi x, y, dan ukuran elips
            painterField.setFont(QFont ("Arial"));
            painterField.drawText(QPoint(playerDisplayed.at(cameraId).at(i).pos.x, playerDisplayed.at(cameraId).at(i).pos.y), QString::number(playerDisplayed.at(cameraId).at(i).id)); //posisi x, y, dan ukuran elips

        }

    }
    ui->label_game_visual->setPixmap(pixmapField);
    //qDebug()<< "displayed "<< playerDisplayed.at(0).at(1).pos.y ;
}

void MainWindow::initListPlayer()
{
    ui->listTeamA->clear();
    ui->listTeamB->clear();
    for (int cameraId = 0; cameraId < 2; cameraId++)
    {
        for (int i = 0; i < 11; i++)
        {
            if (cameraId == 0)
                ui->listTeamA->insertItem(i, QString::number(i));
            else
                ui->listTeamB->insertItem(i, QString::number(i));
        }
    }

}

void MainWindow::setCameraViewFirstFrameImage(QVector<QImage> firstFrameImage) {
    ui->label_stream_1->setAlignment(Qt::AlignCenter);
    ui->label_stream_1->setPixmap(QPixmap::fromImage((firstFrameImage[0]).scaled(ui->label_stream_1->size(), Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->label_stream_2->setAlignment(Qt::AlignCenter);
    ui->label_stream_2->setPixmap(QPixmap::fromImage((firstFrameImage[1]).scaled(ui->label_stream_2->size(), Qt::KeepAspectRatio, Qt::FastTransformation)));
}

void MainWindow::on_pushButton_initialize_object_released()
{

}

void MainWindow::on_slider_global_frame_sliderPressed()
{
    myObjectDetector->stop();
}

void MainWindow::on_slider_global_frame_sliderReleased()
{
    myObjectDetector->playContinously();
}

void MainWindow::on_slider_global_frame_valueChanged(int value)
{
    myObjectDetector->setCurrentFrame(value);
    ui->label_current_time->setText(getFormattedTime(value / (int)myObjectDetector->getFrameRate()));
}

QString MainWindow::getFormattedTime(int timeInSeconds) {
    int seconds = (int) (timeInSeconds) % 60 ;
    int minutes = (int) ((timeInSeconds / 60) % 60);
    int hours   = (int) ((timeInSeconds / (60 * 60)) % 24);
    QTime t(hours, minutes, seconds);
    if (hours == 0 )
        return t.toString("mm:ss");
    else
        return t.toString("h:mm:ss");
}

void MainWindow::assignIdFromList(QPoint& pos)
{
    qDebug() << "right click pos " << pos.x() << " " << pos.y();
    int JUMLAH_PLAYER = 22;
    if (idToAssign < JUMLAH_PLAYER)
    {
        for (int cameraId = 0; cameraId < playerDisplayed.size(); cameraId++)
        {
            for (int i = 0; i < playerDisplayed.at(cameraId).size(); i++)
            {
                if ((pos.x() >= playerDisplayed.at(cameraId).at(i).pos.x && pos.x() <= playerDisplayed.at(cameraId).at(i).pos.x + 10)
                        && (pos.y() >= playerDisplayed.at(cameraId).at(i).pos.y && pos.y() <= playerDisplayed.at(cameraId).at(i).pos.y + 10))
                {
                    playerDisplayed[cameraId][i].id = idToAssign;

                    displayModifiedId(playerDisplayed);

                    //idToSigned default
                    idToAssign = 999;
                }
            }
        }
    }
}
void MainWindow::on_listTeamA_itemClicked(QListWidgetItem *item)
{
    idToAssign = item->text().toInt();
    qDebug("idAToAssigned = ");
    qDebug() << idToAssign;
}

void MainWindow::on_listTeamB_itemClicked(QListWidgetItem *item)
{
    idToAssign = item->text().toInt() + 11;
    qDebug("idBToAssigned = ");
    qDebug() << idToAssign;
}

QVector<QList<Player> > MainWindow::setRandomPlayer()
{
//set random value of player
    QVector<QList<Player> > dummyPlayer;
    Player playerSet;
    dummyPlayer.resize(2);
    for (int i = 0; i < dummyPlayer.size(); i++)
    {
        for (int j = 0; j < 11; j++)
        {
            playerSet.id = 100 + (i + 1) * j;
            playerSet.pos.x = qrand() % 100;
            playerSet.pos.y = qrand() % 50;
            dummyPlayer[i].append(playerSet);
        }
    }
    return (dummyPlayer);
}

void MainWindow::on_pushButton_send_id_clicked()
{
    emit sendAllIdAssigned(playerDisplayed);
}

void MainWindow::updateCameraViewFrameImage(QVector< QVector<QImage> > image) {
    ui->label_stream_1->setAlignment(Qt::AlignCenter);
    ui->label_stream_1->setPixmap(QPixmap::fromImage((image.at(0).at(5)).scaled(ui->label_stream_1->size(), Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->label_stream_2->setAlignment(Qt::AlignCenter);
    ui->label_stream_2->setPixmap(QPixmap::fromImage((image.at(1).at(5)).scaled(ui->label_stream_2->size(), Qt::KeepAspectRatio, Qt::FastTransformation)));
}


void MainWindow::setValueParameter(QVector< QVector<int> > valueParameter) {
    myValueParameter = valueParameter;
    isSetThresholds = true;
    if (isSetThresholds && isSetTrapezium) {
        myDynamicAssociation = new DynamicAssociation(myTrapeziumCoordinates, myValueParameter[0][4], myValueParameter[1][4], myValueParameter[0][5], myValueParameter[1][5], myObjectDetector->getFrameRate());
        QObject::connect(myDynamicAssociation, SIGNAL(sendDataAggregate(QList<Player>)), myCoordinateTransform, SLOT(processTransformPosition(QList<Player>)));
    }
}

void MainWindow::setTrapeziumCoordinates(QVector<QList<QPoint> > trapeziumCoordinates) {
    myTrapeziumCoordinates = trapeziumCoordinates;
    isSetTrapezium = true;
    if (isSetThresholds && isSetTrapezium) {
        myDynamicAssociation = new DynamicAssociation(myTrapeziumCoordinates, myValueParameter[0][4], myValueParameter[1][4], myValueParameter[0][5], myValueParameter[1][5], myObjectDetector->getFrameRate());
        QObject::connect(myDynamicAssociation, SIGNAL(sendDataAggregate(QList<Player>)), myCoordinateTransform, SLOT(processTransformPosition(QList<Player>)));

    }
}
