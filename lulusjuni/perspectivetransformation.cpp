#include "perspectivetransformation.h"
#include "ui_perspectivetransformation.h"

perspectiveTransformation::perspectiveTransformation()
{
    ui->setupUi(this);
    connect(ui->labelPersTrans, SIGNAL(sendClickPosition(QPoint&)),this, SLOT(get4Point(QPoint&)));
    QPixmap pixmap("lapangan,png");
    ui->labelPersTrans->setPixmap(pixmap);
}

perspectiveTransformation::~perspectiveTransformation()
{
    delete ui;
}

void perspectiveTransformation::get4Point(QPoint &pos)
{
    Point2f position(pos.x(), pos.y());
    std::cout<< pos.x()<<' '<<pos.y()<<' '<<position.x<<' '<<position.y;

    int camera=0;//dummy, harusnya dari GUI

    if(camera==1)
        cameraId=0;
    else cameraId=1;

    if(ui->radioButton_P1->isChecked())
    {
        clickedPoint[cameraId][0]= position;
        ui->radioButton_P1->setText("P1 ("+QString::number(clickedPoint[cameraId][0].x)+", "+QString::number(clickedPoint[cameraId][0].y)+")");
    }
    else if(ui->radioButton_P2->isChecked())
    {
        clickedPoint[cameraId][1]= position;
        ui->radioButton_P2->setText("P2 ("+QString::number(clickedPoint[cameraId][1].x)+", "+QString::number(clickedPoint[cameraId][1].y)+")");
    }
    if(ui->radioButton_P3->isChecked())
    {
        clickedPoint[cameraId][2]= position;
        ui->radioButton_P3->setText("P3 ("+QString::number(clickedPoint[cameraId][2].x)+", "+QString::number(clickedPoint[cameraId][2].y)+")");
    }
    if(ui->radioButton_P4->isChecked())
    {
        clickedPoint[cameraId][3]= position;
        ui->radioButton_P4->setText("P4 ("+QString::number(clickedPoint[cameraId][3].x)+", "+QString::number(clickedPoint[cameraId][3].y)+")");
    }
}


void perspectiveTransformation::get4PointFromHammas(QList<QList<QPoint> > &pos)
{
    Point2f position;
    for(int cameraId=0;cameraId<2;cameraId++)
    {
        for (int i=0;i<4;i++)
        {
            position.x = pos.at(cameraId).at(i).x();
            position.y = pos.at(cameraId).at(i).y();
            clickedPoint[cameraId][i].= position;
        }
    }
}

/* fungsi ini mentransformasi perspective */
void perspectiveTransformation::getMatrix(Mat MatToBeTransformed)
{
    //asumsi lebar lapangan adalah 0.5 panjang lapangan
    daouble size_ratio = 0.5;

    // Output Quadilateral or World plane coordinates
    Point2f outputQuad[4];
    // Lambda Matrix
    QList<Mat> lambda( 2, 4, CV_32FC1 );

    if(camera==1)
        cameraId=0;
    else cameraId=1;

    size_mat_camera[cameraId].setWidth(clickedPoint[cameraId][3].x-clickedPoint[cameraId][4].x);
    size_mat_camera[cameraId].setHeight(size_ratio*size_mat_camera[cameraId].width(););

    // Set the lambda matrix the same type and size as input
    lambda = Mat::zeros( MatToBeTransformed.cols(), MatToBeTransformed.rows();, MatToBeTransformed.type();));

    // The 4 points where the mapping is to be done , from top-left in clockwise order
    outputQuad[0] = Point2f( 0, 0 );
    outputQuad[1] = Point2f( size_mat_camera[cameraId].width , 0);
    outputQuad[2] = Point2f( size_mat_camera[cameraId].width, size_mat_camera[cameraId].height());
    outputQuad[3] = Point2f( 0,size_mat_camera[cameraId].height());

    // Get the Perspective Transform Matrix i.e. lambda
    lambda[cameraId] = getPerspectiveTransform( clickedPoint[cameraId], outputQuad );
    //qDebug << "lambda = "<< endl << " "  << lambda << endl << endl;
    //size_mat_camera[cameraID].setWidth(clickedPoint[cameraId][3].x-clickedPoint[cameraId][4].x), );
}


void perspectiveTransformation::on_buttonBox_accepted()
{
    emit sendTransformMat (lambda);
    emit sendSizeMatCamera(size_mat_camera);
}
