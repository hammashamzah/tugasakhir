#ifndef FUSSIONDATAFORTRANS_H
#define FUSSIONDATAFORTRANS_H
#include "objectvariable.h"



class FussionDataforTrans:public QObject
{
    Q_OBJECT
public:
    explicit FussionDataforTrans(QObject *parent = 0);
    FussionDataforTrans();
    ~FussionDataforTrans();
    void sendDataFussion();
private:
    QList<DataInputCam>ReadyData;
    QList<DataInputCam>ReadyDataCam2;

    bool IsSetdatCam1;
    bool IsSetdatCam2;
public slots:
    void getDataLostFoundCam1(QList<DataInputCam>);
    void getDataLostFoundCam2(QList<DataInputCam>);
signals:
    void sendDatabeTransformed(QList<DataInputCam>);
};

#endif // FUSSIONDATAFORTRANS_H
