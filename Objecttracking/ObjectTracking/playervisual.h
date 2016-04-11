#ifndef PLAYERVISUAL_H
#define PLAYERVISUAL_H

#include <QObject>
#include <QPoint>

class playerVisual : public QObject
{
    Q_OBJECT
public:
    explicit playerVisual(QObject *parent = 0);
    int id;
    char Name[20];
    char TeamSide;
    QPoint Position;
    int backNumber;
    double speed;
    bool signedFlag;

signals:

public slots:
};

#endif // PLAYERVISUAL_H
