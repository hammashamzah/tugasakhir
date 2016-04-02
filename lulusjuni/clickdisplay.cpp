#include "clickdisplay.h"


using namespace std;

ClickDisplay::ClickDisplay(QWidget* parent): QLabel(parent)
{
    this->setMouseTracking(true);
}

void ClickDisplay::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos_label = mouse_event->pos();
    QPoint mouse_pos;
    if (mouse_pos_label.x() <= this->size().width() && mouse_pos_label.y() <= this->size().height())
    {
        mouse_pos.setX(mouse_pos_label.x() * this->pixmap()->width() / this->size().width());
        mouse_pos.setY(mouse_pos_label.y() * this->pixmap()->height() / this->size().height());

        if (mouse_pos.x() >= 0 && mouse_pos.y() >= 0) {
            cout << mouse_pos.x() << "-" << mouse_pos.y() << "\n";
            emit sendMousePosition(mouse_pos);
        }
    }
}

void ClickDisplay::mousePressEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_click = mouse_event->pos();
    if (mouse_event->button() == Qt::LeftButton)
    {
        mouse_click.setX(mouse_click.x() * this->pixmap()->width() / this->size().width());
        mouse_click.setY(mouse_click.y() * this->pixmap()->height() / this->size().height());
        emit sendClickPosition(mouse_click);
    }
}
