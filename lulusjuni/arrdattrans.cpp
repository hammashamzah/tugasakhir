#include "arrdattrans.h"

Arrdattrans::Arrdattrans(){
}

Arrdattrans::~Arrdattrans(){

}

void Arrdattrans:: setdata(bool state_input,Arrtrans buff,int numCluster, int fr){
    if(state_input){
        jumlahCluster = numCluster;
        frame = fr;
        data = buff;
        Isset = true;
    }
    else{
        Isset = false;
    }
}
