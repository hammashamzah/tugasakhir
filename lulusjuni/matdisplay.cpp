#include "matdisplay.h"
#include "QMessageBox"
#include <iostream>

using namespace std;

matDisplay::matDisplay(QWidget* parent):QLabel(parent)
{
    this->setMouseTracking(true);
    QPixmap pixmap("field.jpg");
   // cout<<pixmap.width()<<' '<<pixmap.height();
    pixmap = pixmap.scaled(QSize(800, 600), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->setPixmap(pixmap);
}

void matDisplay::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos_label = mouse_event->pos();
    QPoint mouse_pos;
    if(mouse_pos_label.x() <= this->size().width() && mouse_pos_label.y()<=this->size().height())
    {
        mouse_pos.setX(mouse_pos_label.x() * this->pixmap()->width() / this->size().width());
        mouse_pos.setY(mouse_pos_label.y() * this->pixmap()->height() / this->size().height());

        if(mouse_pos.x()>=0 && mouse_pos.y()>=0)
           emit sendMousePosition(mouse_pos);
    }
}

void matDisplay::mousePressEvent(QMouseEvent *mouse_event)
{
    QMessageBox msg;
    QPoint mouse_click = mouse_event->pos();
    if(mouse_event->button()==Qt::LeftButton)
    {
        //msg.setText("Left Mouse Button Pressed!");
        //msg.setWindowTitle("aznan");
        //msg.exec();
        mouse_click.setX(mouse_click.x() * this->pixmap()->width() / this->size().width());
        mouse_click.setY(mouse_click.y() * this->pixmap()->height() / this->size().height());
        emit sendClickPosition(mouse_click);
    }
    else if(mouse_event->buttons()==Qt::RightButton)
    {

        //msg.setText("Right Mouse Pressed!");
        //msg.exec();
    }
}

