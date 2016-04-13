#ifndef DATASEPARATOR_H
#define DATASEPARATOR_H
#include "objectvariable.h"
#include "datainputtrans.h"

class DataSeparator:public QObject
{
    Q_OBJECT
public:
    DataSeparator();
    ~DataSeparator();
private:
    bool isUpdatedDataTrans[2];
    QList<DataInputTrans>DataCam1;
    QList<DataInputTrans>DataCam2;
public slots:
    void updateDataTrans_1(QList<QList<DataInputTrans> >);
    void updateDataTrans_2(QList<QList<DataInputTrans> >);
signals:
    void sendCamera1(QList<DataInputTrans>);
    void sendCamera2(QList<DataInputTrans>);
};

#endif // DATASEPARATOR_H
