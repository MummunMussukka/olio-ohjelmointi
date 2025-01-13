#include <iostream>
#include "game.h"

using namespace std;

Game::Game(int maxNum) {
    maxNumber = maxNum;
    numberOfGuesses = 0;
    cout << "OBJECT CONSTRUCTOR: game initialized with " << maxNumber << " as the maximum number" << endl;
}

Game::~Game(){
    cout << "OBJECT DESTRUCTOR: cleared game from stack memory" << endl;
}

void Game::play(){
    int input;
    randomNumber = std::rand() % maxNumber + 1;
    while(1){
        cout << "give a number: ";
        cin >> input;
        numberOfGuesses++;
        if (input < randomNumber){
            cout << "the number is bigger" << endl;
        }
        else if (input > randomNumber){
            cout << "the number is smaller" << endl;
        }
        else{
            cout << "your guess is correct" << endl;
            break;
        }
    }
    printGameResult();
}

void Game::printGameResult(){
    cout << "you guessed the correct number in " << numberOfGuesses << " guesses" << endl;
}
