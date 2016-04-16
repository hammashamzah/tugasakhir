#include "searchplayerdata.h"


SearchPlayerData::SearchPlayerData()
{

}

int SearchPlayerData::searchPlayer(QList<Player> player,int id){
    Player buffer;
    int buff;
    for(int i=0;i<player.length();i++){
        buffer = player.at(i);
        if(buffer.id == id){
            buff = i;
            break;
        }
    }
    return(buff);
}

