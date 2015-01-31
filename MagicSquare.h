char option;
int size;

class MagicSquare {

int** magicArray;
int rowSum;
int colSum;
int diagSum;
int xPos;
int yPos;

public:
	MagicSquare() {
		rowSum = 0;
		colSum = 0;
		diagSum = 0;
		xPos= 0; 
	};
 
	int** makeSquare(int size);
	void printSquare(int **magicSquare);
	void calculateRows(int **magicSquare);
	void calculateCols(int **magicSquare);
	void calculateDiags(int **magicSquare);
};
