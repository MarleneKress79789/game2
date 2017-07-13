#include "Map.h"



Map::Map(int l, int h) {
	this->height = h;
	this->lenght = l;
	this->MapMatrix =  vector<vector<int> > (h, vector<int>(l));;// MapMatrix(l, vector<int>(h));

	this->MapName;
	this->MapID;
}


Map::~Map(){

}


void Map::GenerateMapContend() {
	for (int i = (height / 2); i != height; i++) {
		for (int j = (0); j != lenght; j++) {
			MapMatrix[i][j] = 1;
		}
	}
}

//int getBlockID(int l, int h) {}

void updateBlock(int l, int h) {}

/*
void drawMapToWindow(int x, int y) {

	int pixeli = ((int)(y * 10)) - (windowH / 2);
	int pixelj = ((int)(x * 10)) - (windowL / 2);

	int i;
	int j;

	if (((int)(y)-windowH / 2) - ((y)-windowH / 2) < 0) {
		i = (int)(y)-windowH / 2 + 1;
	}
	else i = (int)(y)-windowH / 2;

	if (((int)(x)-windowL / 2) - ((x)-windowL / 2) < 0) {
		j = (int)(x)-windowL / 2 + 1;
	}
	else j = (int)(x)-windowL / 2;

	for (i = 0; i != ThisMap.height; i++) { // TODO vo anderen seiten beschränken
		pixeli = pixeli + 10;
		pixelj = (int)(x * 10) - windowL / 2;
		for (int j = 0; j != ThisMap.lenght; j++) {
			pixelj = pixelj + 10;

			if (ThisMap.MapMatrix[i][j] == 0) {
				continue;
			}
			else if (ThisMap.MapMatrix[i][j] == 1) {
				sprite.move(sf::Vector2f(pixelj, pixeli)); // offset relative to the current position
				window.draw(sprite);
				sprite.setPosition(sf::Vector2f(0, 0)); // absolute position
			}

			//else cout << ThisMap.MapMatrix[i][j] << ",";
		}

	}
}*/