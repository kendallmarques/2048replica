// credit: Yunhan Huang

#ifndef PrintBoard_H
#define PrintBoard_H
#include <iostream> 
#include <vector>

using namespace std;
const int SIZE = 4;

class Board {
private:


public:
	Board();

	static void printBoard();

	static void moveLeft();

	static void moveRight();

	static void moveUp();

	static void moveDown();

	static int isFinished();

	static int getScore();

	static void addRandomNumber();

	static bool isTheSame(int newBoard[SIZE][SIZE], int originalBoard[SIZE][SIZE]);

};

#endif