#include "Player.h"
#include "Die.h"
#include<cstdlib>
#include<iostream>
Player::Player() {
    playerName = "Madrigal";
    healthPoints = 100;
    isBlessed = false;
    numDice = 3;
    Die playerDie(6);
    Die blessedDie(2);

}

Player::Player(std::string n, int h, bool b, int D1, int D2) {
    
    if(n != "") {
        playerName = n;    
    }else{
        playerName = "Madrigal";
    }
    
    if(h > 0) {
        healthPoints = h;
    }else {
        healthPoints = 100;
    }

    isBlessed = b;
    numDice = D1;
    if(D1 > 0){
        numDice = D1;
    }else {
        numDice = 3;
    }

    playerDie = Die(D2);
    blessedDie = Die(2);
    diceSides = D2;

}

int Player::rollDice() {
    int sum = 0;
    for(int i = 0; i < numDice; i++) {
        Die instance(playerDie);
        sum += instance.roll();  
    }
    return sum;
}

std::string Player::getPlayerName() {
    return playerName;
}

bool Player::isAlive() {
    if(healthPoints <= 0) {
        return false;
    }else {
        return true;
    }
}

int Player::attack(Player* pEnemy) {
    int damage = 0;
    for(int i = 0; i < numDice; i++) {
    damage += playerDie.roll();  
    }
    

    
    if(blessedDie.roll() == 2 && isBlessed == true) {
        blessedDie.getNumSides();
        damage = damage * 2 ;
    }

    pEnemy->healthPoints -= damage;

    
    
    return damage;
}

