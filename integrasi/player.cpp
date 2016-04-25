#include "player.h"

Player::Player() {

}

Player::Player(int frame, int cameraId, Point2f cameraPosition) {
    isValid = false;
    isOccluded = false;
    isAssociated = false;
    id = 0;
    framePosition = frame;
    camera = cameraId;
    cameraPos = cameraPosition;
    pos = Point2f(0, 0);
    speed = Point2f(0, 0);
    acceleration = Point2f(0, 0);
}

//untuk inisialisasi di datalogger
Player::Player(int identity, int cameraId, int frame, Point2f inputPosition, Point2f inputSpeed, Point2f inputAcceleration, Point2f inputCameraPos)
{
    isValid = true;
    isOccluded = false;
    id = identity;
    camera = cameraId;
    framePosition = frame;
    pos = inputPosition;
    speed = inputSpeed;
    acceleration = inputAcceleration;
    cameraPos = inputCameraPos;
}

/*Player::Player(int identity, int frame,int cameraId,Point2f position,Point2f inputSpeed,Point2f inputAcceleration){
    isValid = true;
    id = identity;
    framePosition = frame;
    cameraPos = cameraId;
    pos = position;
    speed = inputSpeed;
    acceleration = inputAcceleration;
    transformedPos = Point2f(0,0);
    transformedSpeed = Point2f(0,0);
}*/

/*Player::Player(Point2f position){
    isValid = false;
    cameraPos = position;

}*/



/*friend void swapPlayer(Player& first, Player& second) {


}*/

Player& Player::operator=(Player b) {
    swap(*this, b);
    return *this;
}

Player::~Player()
{
}
