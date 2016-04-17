#include "searchplayerdata.h"


SearchPlayerData::SearchPlayerData()
{

}

int SearchPlayerData::searchPlayer(QList<Player> player,int id){
    int buff;
    for(int i=0;i<player.size();i++){
        if(player.at(i).id == id){
            buff = i;
            break;
        }
    }
    return(buff);
}

