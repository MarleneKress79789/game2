#pragma once

#include <string>
using namespace std;

#ifndef BLOCK_H
#define BLOCK_H

class Block{

public:
	Block();
	Block(int id);
	~Block();

	int blockID;
	string blockType;
	int passThrough;
	//sprite entweder pfad oder ganze textur?

	string getBlockType(int blockID);
};

#endif
