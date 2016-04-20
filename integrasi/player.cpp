#include "player.h"

Player::Player(){

}

Player::Player(int frame, int cameraId, Point2f position){
	isValid = false;
    id = 0;
    framePosition = frame;
    camera = cameraId;
    pos = position;
    speed = Point2f(0,0);
    acceleration = Point2f(0,0);
    transformedPos = Point2f(0,0);
    transformedSpeed = Point2f(0,0);
}

Player::Player(int identity, int frame, int cameraId, Point2f position, Point2f inputSpeed, Point2f inputTransformedPos, Point2f inputTransformedSpeed)
{
    isValid = true;
	id = identity;
    framePosition = frame;
    camera = cameraId;
    pos = position;
    speed = inputSpeed;
    acceleration = Point2f(0,0);
    transformedPos = inputTransformedPos;
    transformedSpeed = inputTransformedSpeed;

}

Player::Player(int identity, int frame,int cameraId,Point2f position,Point2f inputSpeed,Point2f inputAcceleration){
    isValid = true;
    id = identity;
    framePosition = frame;
    camera = cameraId;
    pos = position;
    speed = inputSpeed;
    acceleration = inputAcceleration;
    transformedPos = Point2f(0,0);
    transformedSpeed = Point2f(0,0);
}

Player::Player(Point2f position){
    isValid = false;
    pos = position;
    
}

Player::~Player()
{
}
