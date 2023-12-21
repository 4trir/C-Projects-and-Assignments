#ifndef LASER_BOLT_H
#define LASER_BOLT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include<string>
#include "mainShip.h"

class LaserBolt
{
private:
    int posX;
    int posY;
    sf::Texture texture;
    sf::Sprite laser;
    bool isOnScreen;
    float lifetime;

public:
    LaserBolt(const std::string filename);
    ~LaserBolt();
    void draw(sf::RenderWindow &window);
    void setPos(MainShip &MainShip);
    void move();
    bool getIsOnScreen();
    sf::IntRect getHitBox();
    sf::FloatRect getBounds();
    void explode();
    bool isExploded;
    void setLifetime(int time);
    float getLifTime();
    

};







#endif