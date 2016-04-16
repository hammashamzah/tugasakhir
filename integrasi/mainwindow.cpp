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

    QObject::connect(myObjectDetector, SIGNAL(sendFirstFrameImage(QVector<QImage>)), myFSDialog, SLOT(setFirstFrameImage(QVector<QImage>)));
    QObject::connect(myObjectDetector, SIGNAL(sendFirstFrameImage(QVector<QImage>)), this, SLOT(setCameraViewFirstFrameImage(QVector<QImage>)));
    QObject::connect(myFSDialog, SIGNAL(sendMaskCoordinates(QVector< QList<QPoint> >)), myObjectDetector, SLOT(setMaskCoordinate(QVector< QList<QPoint> >)));
    QObject::connect(myObjectDetector, SIGNAL(sendCameraViewImage(QVector< QVector<QImage> >)), myCVDialog, SLOT(updateCameraViewImage(QVector< QVector<QImage> >)));
    QObject::connect(myBMTDialog, SIGNAL(sendValueParameter(QVector< QVector<int> >)), myObjectDetector, SLOT(updateValueParameter(QVector< QVector<int> >)));
    QObject::connect(myObjectDetector, SIGNAL(sendObjectData(QVector<QList<Player> >)), myCoordinateTransform, SLOT(processTransformPosition(QVector<QList<Player> >)));
    QObject::connect(myCoordinateTransform, SIGNAL(sendTransformedPosition(QVector<QList<Player> >)), this, SLOT(displayTransformedPosition(QVector<QList<Player> >)));

    QObject::connect(myFSDialog, SIGNAL(sendTransformationCoordinates(QVector<QList<QPoint> >)), myCoordinateTransform, SLOT(setTransformMatrix(QVector<QList<QPoint> >)));
    QObject::connect(myFSDialog, SIGNAL(sendImageSize(QList<QSize>)), myCoordinateTransform, SLOT(setImageSize(QList<QSize>)));
    QPixmap pixmapField("lapangan.png");
    ui->label_game_visual->setPixmap(pixmapField);

    ui->slider_global_frame->setEnabled(false);
    videoLoaded[0] = false;
    videoLoaded[1] = false;
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
    if(videoLoaded[0] && videoLoaded[1]){
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
    if(videoLoaded[0] && videoLoaded[1]){
        ui->slider_global_frame->setEnabled(true);
        ui->slider_global_frame->setMaximum(myObjectDetector->getNumberOfFrames());
        ui->label_max_time->setText(getFormattedTime((int)myObjectDetector->getNumberOfFrames()/(int)myObjectDetector->getFrameRate()));
    }
}

void MainWindow::on_pushButton_play_released()
{
    myObjectDetector->playContinously();
}
void MainWindow::on_pushButton_single_play_released() {
    myObjectDetector->playSingleFrame();
}

void MainWindow::displayTransformedPosition(QVector<QList<Player> > transformedPosition)
{
    QPixmap pixmapField("lapangan.png");   //ukuran pixmap
    QPainter painterField(&pixmapField);
    QPen pen(Qt::black, 1);        //warna dan tebal garis lingkaran
    QBrush brush(Qt::white);

    painterField.setRenderHint(QPainter::Antialiasing, true);
    painterField.setPen(pen);
    for(int cameraId=0;cameraId<2;cameraId++)
    {
        for(int i=0; i<transformedPosition.at(cameraId).size(); i++)
        {
              brush.setColor(Qt::red);
              painterField.setBrush(brush);

              painterField.drawRect(transformedPosition.at(cameraId).at(i).pos.x*pixmapField.width()/GLOBAL_FIELD_LENGTH,
                                    transformedPosition.at(cameraId).at(i).pos.y*pixmapField.height()/GLOBAL_FIELD_WIDTH,
                                    RECT_PLAYER_SIZE, RECT_PLAYER_SIZE);  //posisi x, y, dan ukuran elips
              painterField.setFont(QFont ("Arial"));

              painterField.drawText(QPoint(transformedPosition.at(cameraId).at(i).pos.x*pixmapField.width()/GLOBAL_FIELD_LENGTH, transformedPosition.at(cameraId).at(i).pos.y*pixmapField.height()/GLOBAL_FIELD_WIDTH), QString::number(transformedPosition.at(cameraId).at(i).id)); //posisi x, y, dan ukuran elips
         }
    }
    ui->label_game_visual->setPixmap (pixmapField);

    //update waktu
    ui->label_current_time->setText(getFormattedTime(myObjectDetector->getCurrentFrame() / myObjectDetector->getFrameRate()));
}


void MainWindow::setCameraViewFirstFrameImage(QVector<QImage> firstFrameImage){
    ui->label_stream_1->setAlignment(Qt::AlignCenter);
    ui->label_stream_1->setPixmap(QPixmap::fromImage((firstFrameImage[0]).scaled(ui->label_stream_1->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
    ui->label_stream_2->setAlignment(Qt::AlignCenter);
    ui->label_stream_2->setPixmap(QPixmap::fromImage((firstFrameImage[1]).scaled(ui->label_stream_2->size(),Qt::KeepAspectRatio, Qt::FastTransformation)));
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
    ui->label_current_time->setText(getFormattedTime(value/(int)myObjectDetector->getFrameRate()));
}

QString MainWindow::getFormattedTime(int timeInSeconds){
    int seconds = (int) (timeInSeconds) % 60 ;
    int minutes = (int) ((timeInSeconds / 60) % 60);
    int hours   = (int) ((timeInSeconds / (60*60)) % 24);
    QTime t(hours, minutes, seconds);
    if (hours == 0 )
        return t.toString("mm:ss");
    else
        return t.toString("h:mm:ss");
}