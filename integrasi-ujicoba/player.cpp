#include "player.h"

Player::Player() {

}

Player::Player(int frame, int cameraId, Point2f cameraPosition, double blob) {
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
    blobSize = blob;
}

//untuk inisialisasi di datalogger
Player::Player(int identity, int cameraId, int frame, Point2f inputPosition, Point2f inputSpeed, Point2f inputAcceleration, Point2f inputCameraPos, double blob)
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
    blobSize = blob;
}

Player& Player::operator=(Player b) {
    swap(*this, b);
    return *this;
}

Player::~Player()
{
}
