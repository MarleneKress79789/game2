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
    //void drawMapToWindow(int x, int y); TODO geht das mit SDL2 ?

};

#endif

/* correcte Map ausgabe in konsole

		for (int i = 0; i != ThisMap.height; i++) {


			for (int j = 0; j != ThisMap.lenght; j++) {

				if (ThisMap.MapMatrix[i][j] == 0) {
					cout << "0" ;
				}
				else if (ThisMap.MapMatrix[i][j] == 1) {
					cout << "1" ;
				}
				else cout << ThisMap.MapMatrix[i][j]<< ",";
			}
			cout << endl;
		}
*/
