#ifndef DATASEPARATORCAM_H
#define DATASEPARATORCAM_H
#include "objectvariable.h"
#include "datainputcam.h"


class DataSeparatorCam:public QObject
{
    Q_OBJECT
public:
    explicit DataSeparatorCam(QObject *parent = 0);
    DataSeparatorCam(bool);
    ~DataSeparatorCam();
private:
    bool startseparate;
    QList<DataInputCam>DataCam1;
    QList<DataInputCam>DataCam2;
public slots:
    void getDataTrans(QList<QList<DataInputCam> >);
signals:
    void SendCamera1(QList<DataInputCam>);
    void SendCamera2(QList<DataInputCam>);
};

#endif // DATASEPARATORCAM_H
