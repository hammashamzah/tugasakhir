/**
  Header ini digunakan sebagai jembatan penghubung variabel ataupun objek global

  **/
#ifndef OBJECTVARIABLE
#define OBJECTVARIABLE
#define JUMLAH_PLAYER 23
#define rect_player_size 10

/**#include "videoprocessor.h"
#include "backgroundmodeltuningdialog.h"
#include "cameraviewdialog.h"
#include "errorcalculationdialog.h"
#include "fieldselectiondialog.h"
#include "systemperformancedialog.h"
#include "trackingviewdialog.h"
#include "playervisual.h"**/
#include "datainputcam.h"
#include "datainputtrans.h"
#include <QList>
#include <QRegExp>
#include <QObject>
#include <QMutex>
#define Pict_sizex 1280
#define Pict_sizey 1024
#define stateNum_mot 6
#define measureNum_mot 6
#define vx_init 0
#define vy_init 0
#define ax_init 0
#define ay_init 0
//Modeoperasi

enum mode{singel,dual,triple};




//extern playerVisual player_visual[JUMLAH_PLAYER];
extern int playerIdSelected;
const double BOBOT_PREDICTIONS = 0.30;

class ObjectVariable{
public:
     int foo(QList<DataInputCam>,int idx);
     int fooT(QList<DataInputTrans>,int idx);
};


#endif // OBJECTVARIABLE
