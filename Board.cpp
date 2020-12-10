// credit: Yunhan Huang

#include <iostream>
#include <iomanip>
#include "Board.h"
#define SIZE 4
using namespace std;

int board[SIZE][SIZE];
int sum = 0;

Board::Board() {
    // create two random number on the board as the beginning of the game
	addRandomNumber();
	addRandomNumber();
}

void Board::printBoard() {
    // print instructions and set the board to 4*4 matrix, set the width for each number to 4

    cout << "Score: " << getScore() << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << setw(4) << board[i][j];
		}
		cout << endl;
	}


}

void Board::moveLeft(){

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=0) // first to make sure the number that add up are not zero
                continue;
            for(int k=j+1;k<4;k++) // int k represents the number on the left of the int j in the same row
                if(board[i][k]!=0){ // if the sum of the two numbers is not zero, the function continues
                    swap(board[i][j],board[i][k]); // swap the value of [i][j] to [i][k] for further more use
                    break; // to make sure the function ends
                }
        }
    }
    for(int j=0;j<3;j++) // make two number tiles into one (no calculation here)
        for(int i=0;i<4;i++)
            if(board[i][j]==board[i][j+1])
                board[i][j]<<=1,board[i][j+1]=0;

    for(int i=0;i<4;i++){ // make sure the numbers all the way left, if it is not then keep moving
        for(int j=0;j<3;j++){
            if(board[i][j]!=0)
                continue;
            for(int k=j+1;k<4;k++)
                if(board[i][k]!=0){
                    swap(board[i][j],board[i][k]);
                    break;
                }
        }
    }

    addRandomNumber(); //everytime the movement function is execute, it will create a random number on the board
}

void Board::moveRight() {

    for(int i=0;i<4;i++){
        for(int j=3;j>0;j--){
            if(board[i][j]!=0) // if the
                continue;
            for(int k=j-1;k>=0;k--)
                if(board[i][k]!=0){
                    swap(board[i][j],board[i][k]);
                    break;
                }
        }
    }
    for(int j=3;j>=1;j--)
        for(int i=0;i<4;i++)
            if(board[i][j]==board[i][j-1])
                board[i][j]<<=1,board[i][j-1]=0;
    for(int i=0;i<4;i++){
        for(int j=3;j>0;j--){
            if(board[i][j]!=0)
                continue;
            for(int k=j-1;k>=0;k--)
                if(board[i][k]!=0){
                    swap(board[i][j],board[i][k]);
                    break;
                }
        }
    }

    addRandomNumber();

}

void Board::moveUp() {

    for(int j=0;j<4;j++){
        for(int i=0;i<3;i++){
            if(board[i][j]!=0)
                continue;
            for(int k=i+1;k<4;k++)
                if(board[k][j]!=0){
                    swap(board[i][j],board[k][j]);
                    break;
                }
        }
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            if(board[i][j]==board[i+1][j])
                board[i][j]<<=1,board[i+1][j]=0;
    for(int j=0;j<4;j++){
        for(int i=0;i<3;i++){
            if(board[i][j]!=0)
                continue;
            for(int k=i+1;k<4;k++)
                if(board[k][j]!=0){
                    swap(board[i][j],board[k][j]);
                    break;
                }
        }
    }

    addRandomNumber();
}

void Board::moveDown() {

    for(int j=0;j<4;j++){
        for(int i=3;i>0;i--){
            if(board[i][j]!=0)
                continue;
            for(int k=i-1;k>=0;k--)
                if(board[k][j]!=0){
                    swap(board[i][j],board[k][j]);
                    break;
                }
        }
    }
    for(int i=3;i>0;i--)
        for(int j=0;j<4;j++)
            if(board[i][j]==board[i-1][j])
                board[i][j]<<=1,board[i-1][j]=0;

    for(int j=0;j<4;j++){
        for(int i=3;i>0;i--){
            if(board[i][j]!=0)
                continue;
            for(int k=i-1;k>=0;k--)
                if(board[k][j]!=0){
                    swap(board[i][j],board[k][j]);
                    break;
                }
        }
    }

    addRandomNumber();
}

int Board::isFinished() {
    int localBoard[SIZE][SIZE];
    // made a copy of the original board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            localBoard[i][j] = board[i][j];
            if (board[i][j] == 2048) {
                return 1;
            }
        }
    }

    moveUp();
    if (!isTheSame(board, localBoard)) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = localBoard[i][j];
            }
        }
        return 2;
    }
    moveDown();
    if (!isTheSame(board, localBoard)) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = localBoard[i][j];
            }
        }
        return 2;
    }
    moveLeft();
    if (!isTheSame(board, localBoard)) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = localBoard[i][j];
            }
        }
        return 2;
    }
    moveRight();
    if (!isTheSame(board, localBoard)) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = localBoard[i][j];
            }
        }
        return 2;
    }
    return 0;


}

int Board::getScore()
{
    int localSum = 0;
	for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j < SIZE; j++) {
            localSum += board[i][j];
	    }
	}
	sum = localSum;
    return sum;
}

void Board::addRandomNumber() {

    int rol;
    int col;
    int twoOrFour = rand() % 2;
    do {
        rol = rand() % 4;
        col = rand() % 4;
    } while (board[rol][col] != 0);
    if (twoOrFour) {
        board[rol][col] = 2;
    } else {
        board[rol][col] = 4;
    }
//    cout << "test: here" << endl;
}

bool Board::isTheSame(int newBoard[SIZE][SIZE], int originalBoard[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (newBoard[i][j] != originalBoard[i][j]) {
                return false;
            }
        }
    }
    return true;
}



