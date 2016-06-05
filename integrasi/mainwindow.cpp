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
    myDynamicAssociation = new DynamicAssociation();
    myDVDialog = new DataWindow();
    myDistortionCorrection = new DistortionCorrectionDialog();


    QObject::connect(myObjectDetector, SIGNAL(sendFirstFrameImage(QVector<QImage>)), myFSDialog, SLOT(setFirstFrameImage(QVector<QImage>)));
    QObject::connect(myObjectDetector, SIGNAL(sendFirstFrameImage(QVector<QImage>)), myDistortionCorrection, SLOT(setFirstFrameImage(QVector<QImage>)));
    QObject::connect(myObjectDetector, SIGNAL(sendFirstFrameImage(QVector<QImage>)), this, SLOT(setCameraViewFirstFrameImage(QVector<QImage>)));
    QObject::connect(myFSDialog, SIGNAL(sendMaskCoordinates(QVector< QList<QPoint> >)), myObjectDetector, SLOT(setMaskCoordinate(QVector< QList<QPoint> >)));
    QObject::connect(myObjectDetector, SIGNAL(sendCameraViewImage(QVector< QVector<QImage> >)), myCVDialog, SLOT(updateCameraViewImage(QVector< QVector<QImage> >)));
    QObject::connect(myObjectDetector, SIGNAL(sendCameraViewImage(QVector<QVector<QImage> >)), this, SLOT(updateCameraViewFrameImage(QVector< QVector<QImage> >)));

    QObject::connect(myBMTDialog, SIGNAL(sendValueParameter(QVector< QVector<int> >)), myObjectDetector, SLOT(updateValueParameter(QVector< QVector<int> >)));
    QObject::connect(myBMTDialog, SIGNAL(sendValueParameter(QVector< QVector<int> >)), this, SLOT(setValueParameter(QVector< QVector<int> >)));

    QObject::connect(myFSDialog, SIGNAL(sendTransformationCoordinates(QVector<QList<QPoint> >)), myCoordinateTransform, SLOT(setTransformMatrix(QVector<QList<QPoint> >)));
    QObject::connect(myFSDialog, SIGNAL(sendImageSize(QList<QSize>)), myCoordinateTransform, SLOT(setImageSize(QList<QSize>)));
    QObject::connect(ui->label_game_visual, SIGNAL(sendRightClickPosition(QPoint&)), this, SLOT(assignIdFromList(QPoint&)));
    QObject::connect(this, SIGNAL(sendAllIdAssigned(QList<Player>)), myCoordinateTransform, SLOT(returnAssignedPlayer(QList<Player>)));
    //do transformation to object data
    QObject::connect(myObjectDetector, SIGNAL(sendObjectData(QVector<QList<Player> >)), myCoordinateTransform, SLOT(processTransformPosition(QVector<QList<Player> >)));
    //send transformed position to dynamic association to be processed
    QObject::connect(myCoordinateTransform, SIGNAL(sendTransformedPosition(QList<Player>)), myDynamicAssociation, SLOT(processTransformedData(QList<Player>)));

    QObject::connect(myDynamicAssociation, SIGNAL(sendProcessedData(QList<Player>)), this, SLOT(displayProcessedData(QList<Player>)));
    QObject::connect(myCoordinateTransform, SIGNAL(sendPlayerIdAssigned(QList<Player>)), this, SLOT(displayAssignedTransformedPosition(QList<Player>)));
    QObject::connect(myCoordinateTransform, SIGNAL(sendPlayerIdAssigned(QList<Player>)), myDynamicAssociation, SLOT(processAssignedData(QList<Player>)));

    QObject::connect(myDynamicAssociation, SIGNAL(sendToDataWindow(QList<Player>)), myDVDialog, SLOT(processData(QList<Player>)));
    QObject::connect(myDynamicAssociation, SIGNAL(sendToDataWindowAssociated(QList<Player>)), myDVDialog, SLOT(processDataAssociated(QList<Player>)));

    QObject::connect(myDistortionCorrection, SIGNAL(sendDistortionCoeffisient(double)), myCoordinateTransform, SLOT(setDistotionCoefficient(double)));


    ui->slider_global_frame->setEnabled(false);
    videoLoaded[0] = false;
    videoLoaded[1] = false;

    soccerField = QImage("lapanganFix.png");
    logoLV = QImage("LiberoVision.png");
    playerIconTeamA = QImage("playerA.png");
    playerIconTeamA.scaled(QSize(20, 20), Qt::KeepAspectRatio, Qt::FastTransformation);
    playerIconTeamB = QImage("playerB.png");
    ui->label_game_visual->setPixmap(QPixmap::fromImage(soccerField).scaled(ui->label_game_visual->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    ui->logo->setPixmap(QPixmap::fromImage(logoLV));

    initListPlayer();
    assignedId = 0;
    this->setWindowTitle("Libero Vision");
}

MainWindow::~MainWindow() {
    delete ui;
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

void MainWindow::on_actionData_View_triggered() {
    myDVDialog->show();
}

void MainWindow::on_actionTuning_Background_Model_triggered() {
    myBMTDialog->show();
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
        ui->stautusSetVideoFile->text().append(" done");
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

void MainWindow::on_actionFirst_Image_1_triggered() {
    filename = QFileDialog::getOpenFileName(this,
                                            tr("Open Background Model Image 1"), ".",
                                            tr("Image Files (*.jpeg *.jpg *.png)"));
    myObjectDetector->updateBackgroundModelUsingImage(filename, 1);
}

void MainWindow::on_actionFirst_Image_2_triggered() {
    filename = QFileDialog::getOpenFileName(this,
                                            tr("Open Background Model Image 1"), ".",
                                            tr("Image Files (*.jpeg *.jpg *.png)"));
    myObjectDetector->updateBackgroundModelUsingImage(filename, 2);

}

void MainWindow::on_pushButton_load_default_video_released()
{
    QString filename1 = QString("sebelah-kiri.mp4");
    QString filename2 = QString("sebelah-kanan.mp4");

    myObjectDetector->loadVideo(filename1, 1);
    myObjectDetector->loadVideo(filename2, 2);

    ui->slider_global_frame->setEnabled(true);
    ui->slider_global_frame->setMaximum(myObjectDetector->getNumberOfFrames() / (int)myObjectDetector->getFrameRate());
    ui->label_max_time->setText(getFormattedTime((int)myObjectDetector->getNumberOfFrames() / (int)myObjectDetector->getFrameRate()));
}


void MainWindow::on_pushButton_initialize_background_model_released()
{
    QString filename1 = QString("sebelah-kiri.jpg");
    QString filename2 = QString("sebelah-kanan.jpg");
    myObjectDetector->updateBackgroundModelUsingImage(filename1, 1);
    myObjectDetector->updateBackgroundModelUsingImage(filename2, 2);
}

void MainWindow::on_pushButton_send_id_clicked()
{
    emit sendAllIdAssigned(playerDisplayed);
    ui->logActivity->append("sending id . . .");
}

void MainWindow::on_pushButton_play_released()
{
    myObjectDetector->playContinously();
}
void MainWindow::on_pushButton_single_play_released() {
    myObjectDetector->playSingleFrame();
}


void MainWindow::on_listTeamA_itemClicked(QListWidgetItem * item)
{
    idToAssign = item->text().toInt();
    //////qDebug()() << "idAToAssigned = " << idToAssign;
}

void MainWindow::on_listTeamB_itemClicked(QListWidgetItem * item)
{
    idToAssign = item->text().toInt() + 11;
    //////qDebug()() << "idBToAssigned = " << idToAssign;
}


void MainWindow::on_slider_global_frame_sliderPressed()
{
    myObjectDetector->stop();
}

void MainWindow::on_slider_global_frame_sliderReleased()
{
    myObjectDetector->playContinously();
}

void MainWindow::on_actionDistortion_Correction_triggered()
{
    myDistortionCorrection->show();
}


void MainWindow::on_slider_global_frame_valueChanged(int value)
{
    myObjectDetector->setCurrentFrame(value);
    ui->label_current_time->setText(getFormattedTime(value / (int)myObjectDetector->getFrameRate()));
}


void MainWindow::displayModifiedId()
{
    QPixmap pixmapField(QPixmap::fromImage(soccerField).scaled(ui->label_game_visual->size(), Qt::KeepAspectRatio, Qt::FastTransformation));   //ukuran pixmap
    QPainter painterField(&pixmapField);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);

    painterField.setRenderHint(QPainter::Antialiasing, true);
    painterField.setPen(pen);
    for (int i = 0; i < playerDisplayed_scaling.size(); i++)
    {
        brush.setColor(Qt::red);
        painterField.setBrush(brush);

        painterField.drawEllipse(playerDisplayed_scaling.at(i).pos.x, playerDisplayed_scaling.at(i).pos.y, 10, 10);  //posisi x, y, dan ukuran elips
        painterField.setFont(QFont ("Arial"));

        painterField.drawText(QPoint(playerDisplayed_scaling.at(i).pos.x, playerDisplayed_scaling.at(i).pos.y), QString::number(playerDisplayed_scaling.at(i).id)); //posisi x, y, dan ukuran elips
    }
    ui->label_game_visual->setPixmap(pixmapField.scaled(ui->label_game_visual->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
}

void MainWindow::displayProcessedData(QList<Player> transformedPosition)
{
    //myDataLogger->add(transformedPosition);
    QPixmap pixmapField(QPixmap::fromImage(soccerField).scaled(ui->label_game_visual->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    QPainter painterField(&pixmapField);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);
    playerDisplayed.clear();
    playerDisplayed_scaling.clear();
    playerDisplayed = transformedPosition;
    playerDisplayed_scaling = transformedPosition;
    painterField.setRenderHint(QPainter::Antialiasing, true);
    painterField.setPen(pen);
    for (int i = 0; i < transformedPosition.size(); i++)
    {
        playerDisplayed_scaling[i].pos.x = (transformedPosition.at(i).pos.x * pixmapField.width() / GLOBAL_FIELD_LENGTH);
        playerDisplayed_scaling[i].pos.y = (transformedPosition.at(i).pos.y * pixmapField.height() / GLOBAL_FIELD_WIDTH);
        brush.setColor(Qt::red);
        painterField.setBrush(brush);
//        painterField.drawImage(playerDisplayed_scaling[i].pos.x, playerDisplayed_scaling[i].pos.y, playerIconTeamB.scaled(QSize(15, 15), Qt::KeepAspectRatio, Qt::FastTransformation));
        painterField.drawEllipse(playerDisplayed_scaling[i].pos.x, playerDisplayed_scaling[i].pos.y, RECT_PLAYER_SIZE, RECT_PLAYER_SIZE);  //posisi x, y, dan ukuran elips
        painterField.setFont(QFont ("Arial",10));
        painterField.drawText(QPoint(playerDisplayed_scaling.at(i).pos.x, playerDisplayed_scaling.at(i).pos.y), QString::number(playerDisplayed_scaling.at(i).id)); //posisi x, y, dan ukuran elips
    }

    ui->label_game_visual->setPixmap(pixmapField.scaled(ui->label_game_visual->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
}

void MainWindow::assignIdFromList(QPoint & pos)
{
    //int JUMLAH_PLAYER = 22;
    for (int i = 0; i < playerDisplayed_scaling.size(); i++)
    {
        if ((pos.x() >= (playerDisplayed_scaling.at(i).pos.x -10) && pos.x() <= (playerDisplayed_scaling.at(i).pos.x + 10))
                && (pos.y() >= (playerDisplayed_scaling.at(i).pos.y-10) && pos.y() <= (playerDisplayed_scaling.at(i).pos.y + 10))) {
            playerDisplayed[i].id = idToAssign;
            playerDisplayed_scaling[i].id = idToAssign;
            playerDisplayed[i].isValid = true;

        }
    }
    displayModifiedId();
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

void MainWindow::updateCameraViewFrameImage(QVector< QVector<QImage> > image) {
    ui->label_stream_1->setAlignment(Qt::AlignCenter);
    ui->label_stream_1->setPixmap(QPixmap::fromImage((image.at(0).at(5)).scaled(ui->label_stream_1->size(), Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->label_stream_2->setAlignment(Qt::AlignCenter);
    ui->label_stream_2->setPixmap(QPixmap::fromImage((image.at(1).at(5)).scaled(ui->label_stream_2->size(), Qt::KeepAspectRatio, Qt::FastTransformation)));
}

void MainWindow::setValueParameter(QVector< QVector<int> > valueParameter) {
    myDynamicAssociation->setParameters(valueParameter.at(2).at(0), valueParameter.at(2).at(1), myObjectDetector->getFrameRate());
}

void MainWindow::displayAssignedTransformedPosition(QList<Player> assignedTransformedPosition) {
    playerDisplayed = assignedTransformedPosition;
    displayModifiedId();
}



