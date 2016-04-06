/**
  Fungsi : menghimpun semua variabel atau objeck yang ingin digunakan secara global.
  **/

#include "objectvariable.h"

playerVisual player_visual[JUMLAH_PLAYER];
int playerIdSelected;

int Foo(QList<DataInputCam> keyList,int id) {
   DataInputCam nk;
   QRegExp  reg(id); // <-- prepare a regular expression (format)
   int i=0;
   foreach(nk,keyList) {
      if (nk.id(reg)) {
         // a match ...
         break;
      }
      i++;
   }
   return(i);
}


int FooT(QList<DataInputTrans> keyList,int id) {
   int i=0;
   QRegExp  reg(id); // <-- prepare a regular expression (format)
   DataInputTrans  nk;
   foreach (nk, keyList) {
      if (nk.id(reg)) {
         // a match ...
         break;
      }
      i++;
   }
   return(i);
}
