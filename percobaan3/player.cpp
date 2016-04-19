#include "player.h"


Player::Player(int identity, int frame,int cam,Point2f position,Point2f kecepatan,Point2f percepatan){
	id = identity;
	framePosition = frame;
	camera = cam;
	pos = position;
	speed = kecepatan;
	acceleration = percepatan;
}


Player::~Player(){

}
