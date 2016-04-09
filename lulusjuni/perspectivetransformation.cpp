#include "perspectivetransformation.h"
#include "ui_perspectivetransformation.h"

perspectiveTransformation::perspectiveTransformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::perspectiveTransformation)
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
    if(ui->radioButton_P1->isChecked())
    {
        clickedPoint[0]= position;
        ui->radioButton_P1->setText("P1 ("+QString::number(clickedPoint[0].x)+", "+QString::number(clickedPoint[0].y)+")");
    }
    else if(ui->radioButton_P2->isChecked())
    {
        clickedPoint[1]= position;
        ui->radioButton_P2->setText("P2 ("+QString::number(clickedPoint[1].x)+", "+QString::number(clickedPoint[1].y)+")");
    }
    if(ui->radioButton_P3->isChecked())
    {
        clickedPoint[2]= position;
        ui->radioButton_P3->setText("P3 ("+QString::number(clickedPoint[2].x)+", "+QString::number(clickedPoint[2].y)+")");
    }
    if(ui->radioButton_P4->isChecked())
    {
        clickedPoint[3]= position;
        ui->radioButton_P4->setText("P4 ("+QString::number(clickedPoint[3].x)+", "+QString::number(clickedPoint[3].y)+")");
    }

}

/* fungsi ini mentransformasi perspective */
void perspectiveTransformation::getMatrix(String imageFileName)
{

    // Output Quadilateral or World plane coordinates
    Point2f outputQuad[4];
    // Lambda Matrix
    Mat lambda( 2, 4, CV_32FC1 );

    //Load the image
    Mat input=imread(imageFileName);

    // Set the lambda matrix the same type and size as input
    lambda = Mat::zeros( input.rows, input.cols, input.type() );

    // The 4 points where the mapping is to be done , from top-left in clockwise order
    outputQuad[0] = Point2f( 0, 0 );
    outputQuad[1] = Point2f( input.cols, 0);
    outputQuad[2] = Point2f( input.cols, input.rows);
    outputQuad[3] = Point2f( 0, input.rows );

    // Get the Perspective Transform Matrix i.e. lambda
    lambda = getPerspectiveTransform( clickedPoint, outputQuad );
    //qDebug << "lambda = "<< endl << " "  << lambda << endl << endl;

    //imshow("lambda", lambda);
    // Apply the Perspective Transform just found to the src image
    //warpPerspective(input,output,lambda,input.size());
    //imwrite("output.jpg", output);
    emit sendTransformMat (lambda);

}


void perspectiveTransformation::on_buttonBox_accepted()
{
    this->getMatrix("lapangan.png");
}
