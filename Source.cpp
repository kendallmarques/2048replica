// credit: Yunhan Huang

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "Board.cpp"
#include "InputReader.cpp"

using namespace std;

int main() {
    srand((unsigned int) time(0));

    Board *boardGame = new Board();
    InputReader *reader = new InputReader();
    cout << "Welcome to 2048!" << endl;
    cout << "Use W to move up, S to move down, A to move left, and D to move right." << endl;
    cout << "Have fun!" << endl;
    boardGame->printBoard();
    while (true) {
        /* at the first I wrote the line as boardGame->addRandomNumber();
         *  but the random number will come out unstable that each time add 2 or 4 numbers
         *  i have moved the add random number function to each of the moveUp functions and add break here to break the loop
        */
        switch (reader->read()) {
            case 'w':
                boardGame->moveUp();
                break;
            case 's':
                boardGame->moveDown();
                break;
            case 'a':
                boardGame->moveLeft();
                break;
            case 'd':
                boardGame->moveRight();
                break;
        }

        int logic = boardGame->isFinished();
        if (logic == 1) {
            cout << "You Win! Thank you for playing!" << endl;
            break;
        } else if (logic == 0) {
            cout << "you lost, no tile can move" << endl;
            break;
        } else if (logic == 2){
            boardGame->printBoard();
        }

    }
}