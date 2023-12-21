#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include "Die.h"
#include<cstdlib>
class Player {
public:
    Player(); //Constructor
    
    Player(std::string n, int h, bool b, int D1, int D2 );

    std::string getPlayerName();
    bool isAlive();
    int attack(Player*);
    int rollDice();
private:
    std::string playerName;
    int healthPoints;
    bool isBlessed;
    int numDice;
    int diceSides;
    Die playerDie;
    Die blessedDie;

};

#endif