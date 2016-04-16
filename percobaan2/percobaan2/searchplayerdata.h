#ifndef SEARCHPLAYERDATA_H
#define SEARCHPLAYERDATA_H
#include <QObject>
#include <QList>
#include "player.h"

using namespace std;

class SearchPlayerData:public QObject
{
    Q_OBJECT
    public:
        SearchPlayerData();
        int searchPlayer(QList<Player> player,int id);
};

#endif // SEARCHPLAYERDATA_H
