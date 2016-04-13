#ifndef FUSIONDATAFORTRANS_H
#define FUSSONDATAFORTRANS_H
#include "objectvariable.h"



class FusionDataforTrans:public QObject
{
    Q_OBJECT
public:
    FusionDataforTrans(bool);
    ~FusionDataforTrans();
    void sendDataFussion();
    QList<QList<DataInputCam> > ReadyData;
private:
    bool startfussion;
    QList <DataInputCam> Ready2;
    QList <DataInputCam> Ready1;
    bool IsSetdatCam1;
    bool IsSetdatCam2;
public slots:
    void getDataLostFoundCam1(QList<DataInputCam>);
    void getDataLostFoundCam2(QList<DataInputCam>);
signals:
    void sendDatabeTransformed(QList<QList<DataInputCam> >);
};

#endif // FUSSIONDATAFORTRANS_H
