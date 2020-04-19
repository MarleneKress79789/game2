#include "MyMatrix.h"

using namespace std;

MyMatrix::MyMatrix(void){}					//void Konstruktor

MyMatrix::MyMatrix(int l, int h){			//Konstruktor fur die Matrix der Ordnung l,h.
	this->l = l;
	this->h = h;

	// new vector<vector<int> > Ma(l, vector<int>(h));

	//this->M = Ma;
}

MyMatrix::~MyMatrix(){						//Destruktor.
	delete M;
}

int MyMatrix::MyMatrixElem(int i, int j){	//Zugriff auf Matrixelemente uber M(i, j).
	return M[((i)*l + (j))];
}

void MyMatrix::UpdateMatrixEintrag(void) {

};



