#ifndef MATDISPLAY_H
#define MATDISPLAY_H

#include <QObject>
#include <QWidget>
#include <QLabel>

#include <QMouseEvent>

class matDisplay : public QLabel
{
    Q_OBJECT
public:
    matDisplay(QWidget *parent = 0);


protected:
    void mouseMoveEvent(QMouseEvent *mouse_event);
    void mousePressEvent(QMouseEvent *mouse_event);

signals:
    void sendMousePosition(QPoint&);
    void sendClickPosition(QPoint&);
    void sendRightClickPosition(QPoint&);

};

#endif // MATDISPLAY_H
