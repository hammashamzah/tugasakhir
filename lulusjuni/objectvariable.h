/**
  Header ini digunakan sebagai jembatan penghubung variabel ataupun objek global

  **/
#ifndef OBJECTVARIABLE
#define OBJECTVARIABLE
#define JUMLAH_PLAYER_TEAM_A 11
#define JUMLAH_PLAYER_TEAM_B 11
#define JUMLAH_PLAYER 22
#define rect_player_size 10
#define marginKiriField 12
#define marginAtasField 20


#include "videoprocessor.h"
#include "backgroundmodeltuningdialog.h"
#include "cameraviewdialog.h"
#include "errorcalculationdialog.h"
#include "fieldselectiondialog.h"
#include "systemperformancedialog.h"
#include "trackingviewdialog.h"
#include "playervisual.h"
#include "allaboutteam.h"

extern playerVisual player_visual[JUMLAH_PLAYER];
extern int playerIdSelected;
extern const int heightOfField;
extern const int widthOfField;
extern QPoint playerFormation[JUMLAH_PLAYER];
//extern AllAboutTeam teamB;



#endif // OBJECTVARIABLE
