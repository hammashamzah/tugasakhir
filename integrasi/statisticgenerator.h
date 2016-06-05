#ifndef STATISTICGENERATOR_H
#define STATISTICGENERATOR_H

#include <QObject>
#include <QList>
#include <player.h>

class StatisticGenerator : public QObject
{
    Q_OBJECT
public:
    explicit StatisticGenerator(QObject *parent = 0);
    void generateHeatMap(QList <Player> dataPlayer);

signals:

public slots:
};

#endif // STATISTICGENERATOR_H
