/* CSCI 200: Lab 5: L5A - Escape Room
 *
 * Author: Gabe Berta
 * Resources used (Class Slides, Help from Prof. Paone, Ed):
 *
 * Completed functions to work with poly morphism and pass rooms
 */
#include "Room.h"

#include <iostream>
using namespace std;

ARoom::ARoom() {
    cout << "ARoom() called" << endl;

    mRoomName = "Vacant Room";
}

ARoom::~ARoom() {
    cout << "~ARoom() called" << endl;
}

string ARoom::getRoomName() const {
    return mRoomName;
}

bool ARoom::escapeTheRoom() {
    cout << "There's no escape" << endl;
    return false;
}