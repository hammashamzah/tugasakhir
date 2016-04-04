/**
  Header ini digunakan sebagai jembatan penghubung variabel ataupun objek global

  **/
#ifndef OBJECTVARIABLE
#define OBJECTVARIABLE
#define JUMLAH_PLAYER 24
#define rect_player_size 10


#include "videoprocessor.h"
#include "backgroundmodeltuningdialog.h"
#include "cameraviewdialog.h"
#include "errorcalculationdialog.h"
#include "fieldselectiondialog.h"
#include "systemperformancedialog.h"
#include "trackingviewdialog.h"
#include "playervisual.h"

extern playerVisual player_visual[JUMLAH_PLAYER];
extern int playerIdSelected;


#endif // OBJECTVARIABLE
