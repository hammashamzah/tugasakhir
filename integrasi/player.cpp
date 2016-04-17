#include "player.h"

Player::Player(){

}

Player::Player(int identity, int frame, int cameraId, Point2f position){
	id = identity;
    framePosition = frame;
    camera = cameraId;
    pos = position;
    speed = Point2f(0,0);
    transformedPos = Point2f(0,0);
    transformedSpeed = Point2f(0,0);
}

Player::Player(int identity, int frame, int cameraId, Point2f position, Point2f inputSpeed, Point2f inputTransformedPos, Point2f inputTransformedSpeed)
{
	id = identity;
    framePosition = frame;
    camera = cameraId;
    pos = position;
    speed = inputSpeed;
    transformedPos = inputTransformedPos;
    transformedSpeed = inputTransformedSpeed;

}

Player::Player(Point2f position){
    pos = position;
}

Player::~Player()
{
}
