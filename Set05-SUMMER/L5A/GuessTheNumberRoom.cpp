/* CSCI 200: Lab 5: L5A - Escape Room
 *
 * Author: Gabe Berta
 * Resources used (Class Slides, Help from Prof. Paone, Ed):
 *
 * Completed functions to work with poly morphism and pass rooms
 */
#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;
    mRoomName = "Guesses the Number Room";
    _secretNumber = rand() % 20 + 1;
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}
bool GuessTheNumberRoom::escapeTheRoom() {
    int numGuesses(0);
    int userGuesse;
    while (numGuesses < 5){
        cout << "Please Guess a number" << endl;
        cin >> userGuesse;
        numGuesses++;
        if(userGuesse > _secretNumber) {
            cout << "Number is too high" << endl;
        }else if(userGuesse < _secretNumber) {
            cout << "Number is too low" <<  endl;
        }else if(userGuesse == _secretNumber) {
            cout << "Correct!" << endl;
            return true;
        }
    }
    return false;
    
}