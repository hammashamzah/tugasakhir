#ifndef CLICKDISPLAY_H
#define CLICKDISPLAY_H
#include <iostream>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QString>

class ClickDisplay : public QLabel
{
	Q_OBJECT
public:
    ClickDisplay(QWidget *parent = 0);
protected:
	void mouseMoveEvent(QMouseEvent *mouse_event);
	void mousePressEvent(QMouseEvent *mouse_event);

signals:
	void sendMousePosition(QPoint&);
	void sendClickPosition(QPoint&);

};

#endif // CLICKDISPLAY_H
