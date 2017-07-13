#pragma once
#include "MyMatrix.h"

#include <string>
using namespace std;



#ifndef MAP_H
#define MAP_H

class Map{

public:
	/*static*/ int height;		//eig unnötig, is ja schon durch MyMatrix
	/*static*/ int lenght;
	vector<vector<int> > MapMatrix;
	string MapName;			//TODO set, search mapdirectory for name, error if found.
	int MapID;//TODO
	// chestliste

	Map(int l,int h);
	~Map();

	void GenerateMapContend(); //TODO

	//int getBlockID(int l, int h);//TODO
	void updateBlock(int l, int h);//TODO
//	void drawMapToWindow(int x, int y);

};

#endif
