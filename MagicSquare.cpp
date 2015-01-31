#include<iostream>
using namespace std;
#include "MagicSquare.h"


int main() {
	
	//continuing to make squares
	while (true) {
	
		MagicSquare* magicSquare = new MagicSquare();

		cout << "Enter an odd number betwixt 3 and 15" << endl;
		cin >> size;
		//Check to make sure we aren't using even numbers as the size
		if (size % 2 == 0) {
			cout << "Re-enter an odd number, please" << endl;
			cin >> size;	
		}


        int** magicArray = (magicSquare->makeSquare(size));

		cout << "One possible magic square is:" << "\n";
		
        magicSquare->printSquare(magicArray);
        magicSquare->calculateRows(magicArray);
        magicSquare->calculateCols(magicArray);
        magicSquare->calculateDiags(magicArray);
		delete magicSquare;
        delete [] magicArray;
		
		cout << "Want to make another? Y/N" << endl;
        cin >> option;
		if (option == 'N') {
			break;
		}
	}

    return 0;
}

int** MagicSquare::makeSquare(int size) {
	//declaring the dynamic double array for the square
    int** magicArray = new int*[size]; 
    for (int i = 0; i < size; i++) {
        
        magicArray[i] = new int[size];

    }

    //initialize the double array
    for(int i = 0; i < size; i++) {
    	for(int j = 0; j < size; j++) {
      		magicArray[i][j] = 0;
    	}
  	}
  	//This is for the starting position. xPos is defined in the class constructor, but since yPos depends on size, I update it here.
	yPos = size/2;

    //Magic Square algorithm
    for (int num = 1; num <= (size*size); num++) {
    	
    	magicArray[xPos][yPos] = num;
    	xPos--;
    	yPos++;
		//if the algorithm moves outside the square, reset it to the right and down a row
		if (num % size == 0) {
			xPos += 2;
			yPos--;
		} else {
			//moves it back down a row/column after reaching an edge
			if (yPos == size) {
				yPos -= size;
			} else if (xPos < 0) {
				xPos += size;
			}
		}	
    }
    //returns a pointer to the array for use in the other functions
    return magicArray;
}
//prints out the array
void MagicSquare::printSquare(int **magicArray) {
    for (int i = 0; i < size; i++) {
    	for (int j = 0; j < size; j++) {
    		cout << magicArray[i][j] << "\t";
    	}
    	cout<< "\n";
    }
}

//MATH
//adds rows
void MagicSquare::calculateRows(int **magicArray) {
    cout << "Checking the rows for equivalence:" << "\n";
    for (int c = 0; c < size; c++) {
        for (int r = 0; r < size; r++) {
            rowSum += magicArray[c][r];
        }
        cout << rowSum << "\t";
        rowSum = 0;
    }
    cout << "\n";
}
//adds columns
void MagicSquare::calculateCols(int **magicArray) {
    cout << "Checking the columns for equivalence:" << "\n";
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
           colSum += magicArray[r][c]; 
        }
        cout << colSum << "\t";
        colSum = 0;
    }
    cout << "\n";
}
//adds diagonals
void MagicSquare::calculateDiags(int **magicArray) {
cout << "Checking the diagonals for equivalence:" << "\n";

    //from top left to bottom right
    for (int k = 0; k < size; k++) {
        diagSum += magicArray[k][k];
    } 
    cout << diagSum << "\t";
    //resetting diagSum for the next diagonal
    diagSum = 0;


    //from bottom right to top left
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= 0; j--) {
            diagSum += magicArray[i][j];
            break;
        }   
    }
    cout << diagSum << endl;
    diagSum = 0;
}
