#include "playerdisplay.h"

PlayerDisplay::PlayerDisplay(){
}

PlayerDisplay& PlayerDisplay::operator=(PlayerDisplay b) {
    swap(*this, b);
    return *this;
}

PlayerDisplay::~PlayerDisplay(){

}



