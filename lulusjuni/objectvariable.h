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
#include "arrdatcam.h"
#include "arrdattrans.h"
#include "arrcam.h"

extern playerVisual player_visual[JUMLAH_PLAYER];
extern int playerIdSelected;

/**Data dari frame paling pertama dan yang ini diaksesnya hanya sekali saja saat frame==1**/
    /*Object sebagai register sementara sebelum diproses*/
    extern ArrDatCam datainit1;
    extern ArrDatCam datainit2;
    extern ArrDatCam datainit3;
    extern Arrdattrans dataTransinit;

    /*Object ini kapanpun bisa diupdate digunakan untuk mengupdate register ArrdatCam dan Arrdattrans jika ada flag dari CU*/
    extern Arrcam arrinit1;
    extern Arrcam arrinit2;
    extern Arrcam arrinit3;
    extern DataInputTrans arrtransinit[JUMLAH_PLAYER];


/**Data Inputan**/
    /*Object sebagai register sementara sebelum diproses*/
    extern ArrDatCam dataCam1;
    extern ArrDatCam dataCam2;
    extern ArrDatCam dataCam3;
    extern Arrdattrans dataTransf;

    /*Object ini kapanpun bisa diupdate digunakan untuk mengupdate register ArrdatCam dan Arrdattrans jika ada flag dari CU*/
    extern Arrcam arrcam1;
    extern Arrcam arrcam2;
    extern Arrcam arrcam3;
    extern DataInputTrans arrtrans[JUMLAH_PLAYER];



/**predictor:Hasil keluaran Kalman**/
    /*Register*/
    extern ArrDatCam datapred1;
    extern ArrDatCam datapred2;
    extern ArrDatCam datapred3;
    extern Arrdattrans dataTranspred;

    /*data predictor*/
    extern Arrcam arrpred1;
    extern Arrcam arrpred2;
    extern Arrcam arrpred3;
    extern DataInputTrans arrpredtrans;



/**Mapping Result: Hasil keluaran**/
    /*Register*/
    extern ArrDatCam datamap1;
    extern ArrDatCam datamap2;
    extern ArrDatCam datamap3;
    extern Arrdattrans dataTransmap;

    /*data mapping*/
    extern Arrcam arrmap1;
    extern Arrcam arrmap2;
    extern Arrcam arrmap3;
    extern DataInputTrans arrmaptrans[JUMLAH_PLAYER];






#endif // OBJECTVARIABLE
