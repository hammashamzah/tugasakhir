/**
  Fungsi : menghimpun semua variabel atau objeck yang ingin digunakan secara global.
  **/

#include "objectvariable.h"

//playerVisual player_visual[JUMLAH_PLAYER];
int playerIdSelected;

int ObjectVariable::foo(QList<DataInputCam> keyList,int id) {
   DataInputCam nk;
   int i=0;
   foreach(nk,keyList) {
      if (nk.id==id) {
         // a match ...
         break;
      }
      i++;
   }
   return(i);
}


int ObjectVariable::fooT(QList<DataInputTrans> keyList,int id) {
   int i=0;
   DataInputTrans  nk;
   foreach (nk, keyList) {
      if (nk.id==id) {
         // a match ...
         break;
      }
      i++;
   }
   return(i);
}
