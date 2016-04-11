#ifndef ALLABOUTTEAM_H
#define ALLABOUTTEAM_H

#include <QObject>
#include <QPoint>
#include <QColor>
#include "objectvariable.h"


class AllAboutTeam : public QObject
{
    Q_OBJECT
public:
    explicit AllAboutTeam(QObject *parent = 0);
    QPoint playerPosition;
    QColor teamColor;
    QString TeamName;
    int TeamPlayerNumber;

    bool setFormation(int formation);

private:


signals:


public slots:
};

#endif // ALLABOUTTEAM_H
