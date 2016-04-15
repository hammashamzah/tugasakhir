#include "datainputcam.h"

Player::Player(Point data)
{
	id = 0;
	position = data;
}

Player::Player() {
	id = 0;
	pos = Point2f(0,0);
	speed = Point2f(0,0);
	acceleration = Point2f(0,0);
}


Player::~Player()
{
	delete id;
	delete pos;
	delete speed;
	delete acceleration;
}
