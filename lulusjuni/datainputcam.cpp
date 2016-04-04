#include "datainputcam.h"

Datainputcam::Datainputcam(int identity, Rect Player_dat, int stats, bool fo)
{
    id = identity;
    playerData = Player_dat;
    status = stats;
    flagOcclusion = fo;
}

Datainputcam::~Datainputcam(){


}


