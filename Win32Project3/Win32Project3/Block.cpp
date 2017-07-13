#include "Block.h"

Block::Block() {}

Block::Block(int id){
	this->blockID = id;
	this->blockType = "Type" ;		//TODO
}


Block::~Block(){

}


std::string Block::getBlockType(int blockID) {
	if (blockID > 2 && blockID < 0) {
		return "ERROR";
	}

	switch (blockID) {

	case 0:
		return "NULL";
	case 1:
		return "Erd";
	case 2:
		return "Stein";
	}

	return "NONE";
}