#pragma once
#include <vector>

#ifndef MY_MATRIX_H
#define MY_MATRIX_H


class MyMatrix{

public:
	MyMatrix(void);								//noetig?
	MyMatrix(int l, int h);					//Konstruktor fur die Matrix der Ordnung l,h.
	~MyMatrix(void);							//Destruktor.


	int MyMatrixElem(int i, int j);	//Zugriff auf Matrixelemente uber M(i, j).

	void UpdateMatrixEintrag();				//TODO, nötig, oder schon durch MyMatrixElem x = y?
	
	int lenght() const { return l; }		//Funktion, die die Laenge der Matrix liefert.
	int height() const { return h; }		//Funktion, die die Hoehe n der Matrix liefert.
		
//private:
	int h;						// Hoehe h der Matrix.
	int l;						// Laenge l der Matrix.
	int *M;						// Zeiger auf Matrixelemente.

			
};

#endif

