#pragma once

#ifndef PLAYER_H
#define PLAYER_H



class Player{

public:
	Player();
	~Player();

	void Move(int r);
	void SetSpawn(float x, float y);

	float xPos;
	float yPos;

	int spawnX;
	int spawnY;

	int speed;
	int defense;
	int max_hp;
	int hp;
};

#endif