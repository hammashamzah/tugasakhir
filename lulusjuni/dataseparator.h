#ifndef DATASEPARATOR_H
#define DATASEPARATOR_H
#include "objectvariable.h"
#include "datainputtrans.h"

class DataSeparator:public QObject
{
    Q_OBJECT
public:
    explicit DataSeparator(QObject *parent = 0);
    DataSeparator(bool);
    ~DataSeparator();
private:
    bool startseparate;
    QList<DataInputTrans>DataCam1;
    QList<DataInputTrans>DataCam2;
public slots:
    void getDataTrans(QList<QList<DataInputTrans> >);
signals:
    void SendCamera1(QList<DataInputTrans>);
    void SendCamera2(QList<DataInputTrans>);
};

#endif // DATASEPARATOR_H
