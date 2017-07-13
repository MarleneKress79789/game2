#include "Player.h"
#include <iostream>


Player::Player(){
	this-> xPos = 0;
	this-> yPos = 0;

	this->spawnX = 0;
	this->spawnY = 0;

	this->speed;
	this->defense;
	this->max_hp;
	this->hp;
}


Player::~Player(){

}


void Player::Move(int r) {
	if (r == 119) {//w
		yPos = yPos+1;
	}
	else if (r == 97) {//a
		xPos = xPos + 1;
	}
	else if (r == 115) {//s
		yPos = yPos - 1;
	}
	else if (r == 100) {//d
		xPos = xPos - 1;
	}
	else return;
}

void Player::SetSpawn(float x, float y) {
	spawnX = x;
	spawnY = y;
}