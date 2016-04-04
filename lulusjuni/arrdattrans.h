#ifndef ARRDATTRANS_H
#define ARRDATTRANS_H
#include "arrtrans.h"
#include <QObject>

class Arrdattrans:public QObject
{
    Q_OBJECT
    public:
        explicit Arrdattrans(QWidget *parent = 0);
        Arrdattrans();
        ~Arrdattrans();
        Arrtrans data;
        int jumlahCluster;
        int frame;
        bool Isset;
    public slots:
        void setdata(bool state_input,Arrtrans buff,int numCluster, int fr);
    signals:
};

#endif // ARRDATTRANS_H
