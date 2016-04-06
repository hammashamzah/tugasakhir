#include "playervisual.h"
#include "objectvariable.h"

playerVisual::playerVisual(QObject *parent) : QObject(parent)
{
    if(id==999)
    {
        signedFlag = false;
    }
    else signedFlag = true;
    //PosHeatMap = konversi.pixelToHeatMap(this->Position);
    //heatMapCounter[(konversi.pixelToHeatMap(this->Position)).x()][(konversi.pixelToHeatMap(this->Position)).y()]++;
}

