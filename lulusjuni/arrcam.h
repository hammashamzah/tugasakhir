#ifndef ARRCAM_H
#define ARRCAM_H
#include "objectvariable.h"

struct Datainputcam{
    int id;
    Rect playerData;
    bool flagOcclusion;
    int status;
};

class Arrcam{
    public:
        Datainputcam data[JUMLAH_PLAYER];
        Arrcam();
        ~Arrcam();
};

#endif // ARRCAM_H
