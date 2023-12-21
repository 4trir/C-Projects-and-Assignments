/* CSCI 200: Lab 5: L5A - Escape Room
 *
 * Author: Gabe Berta
 * Resources used (Class Slides, Help from Prof. Paone, Ed):
 *
 * Completed functions to work with poly morphism and pass rooms
 */
#include "ExitRoom.h"

#include <iostream>
using namespace std;

ExitRoom::ExitRoom() {
    cout << "ExitRoom() called" << endl;
    mRoomName = "ExitRoom";
}

ExitRoom::~ExitRoom() {
    cout << "~ExitRoom() called" << endl;
}
bool ExitRoom::escapeTheRoom() {
    cout << "You found a way out!" << endl;
    return true;
} 
