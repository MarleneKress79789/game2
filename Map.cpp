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
