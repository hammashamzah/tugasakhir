#ifndef CLICKDISPLAY_H
#define CLICKDISPLAY_H
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

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
    void sendRightClickPosition(QPoint&);

};

#endif // CLICKDISPLAY_H
