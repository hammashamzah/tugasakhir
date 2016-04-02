#include "playervisual.h"
#include "objectvariable.h"

playerVisual::playerVisual(QObject *parent) : QObject(parent)
{

    if(id==999)
    {
        signedFlag = false;
    }
    else signedFlag = true;

}

