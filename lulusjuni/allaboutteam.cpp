#include "allaboutteam.h"

AllAboutTeam::AllAboutTeam(QObject *parent) : QObject(parent)
{

}

bool AllAboutTeam::setFormation(int formation)
{
    if(formation==442)
    {
                playerFormation[0].setX(20);
                playerFormation[0].setY(50);

                playerFormation[1].setX(60);
                playerFormation[1].setY(12);

                playerFormation[2].setX(60);
                playerFormation[2].setY(37);

                playerFormation[3].setX(60);
                playerFormation[3].setY(59);

                playerFormation[4].setX(60);
                playerFormation[4].setY(86);

                playerFormation[5].setX(100);
                playerFormation[5].setY(9);

                playerFormation[6].setX(100);
                playerFormation[6].setY(34);

                playerFormation[7].setX(100);
                playerFormation[7].setY(59);

                playerFormation[8].setX(100);
                playerFormation[8].setY(84);

                playerFormation[9].setX(130);
                playerFormation[9].setY(35);

                playerFormation[10].setX(130);
                playerFormation[10].setY(70);


    }

    return true;
}

