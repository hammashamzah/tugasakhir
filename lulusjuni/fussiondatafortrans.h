#ifndef FUSSIONDATAFORTRANS_H
#define FUSSIONDATAFORTRANS_H
#include "objectvariable.h"



class FussionDataforTrans:public QObject
{
    Q_OBJECT
public:
    explicit FussionDataforTrans(QObject *parent = 0);
    FussionDataforTrans(bool);
    ~FussionDataforTrans();
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
