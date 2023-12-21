/* CSCI 200: Lab 5: L5A - Escape Room
 *
 * Author: Gabe Berta
 * Resources used (Class Slides, Help from Prof. Paone, Ed):
 *
 * Completed functions to work with poly morphism and pass rooms
 */
#include "GuessTheNumberRoom.h"
#include "ExitRoom.h"

#include <cstdlib>
#include <iostream>
#include<ctime>
using namespace std;

ARoom *pARoom;
ARoom *pExitRoom;


ARoom *go_to_next_room() {
    int randRoomChoice = rand() % 10; // a 10% chance to get directly out
    pExitRoom = new ExitRoom();
    pARoom = new GuessTheNumberRoom();
    switch(randRoomChoice) {
    case 7:     return pExitRoom;
    default:    return pARoom;
    }
}

int main() {
    srand( time(0) );
    rand();

    ARoom *currentRoom = new GuessTheNumberRoom();

    do {    
        currentRoom = go_to_next_room();
        cout << "Welcome to the " << currentRoom->getRoomName() << endl;
    } while( !currentRoom->escapeTheRoom() );

    cout << "You made it out!" << endl;

    return 0;
}