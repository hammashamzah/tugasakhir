#ifndef ARRDATCAM_H
#define ARRDATCAM_H

#include <QObject>
#include "objectvariable.h"
#include "arrcam.h"

class ArrDatCam: public QObject
{
    Q_OBJECT
    public:
        explicit ArrDatCam(QWidget *parent = 0);
        ArrDatCam();
        ~ArrDatCam();
        Arrcam data;
        int jumlahCluster;
        int frame;
        bool Isset;
    public slots:
        void setdata(bool state_input,Datainputcam dat[JUMLAH_PLAYER],int numCluster, int fr);
    signals:


};

#endif // ARRDATCAM_H
