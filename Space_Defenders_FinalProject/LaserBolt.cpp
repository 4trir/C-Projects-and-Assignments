#include "LaserBolt.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>


/**
 * @brief Construct a new Laser Bolt:: Laser Bolt object
 * 
 * @param fileName 
 */
LaserBolt::LaserBolt(std::string fileName) {

    texture.loadFromFile(fileName);
    sf::FloatRect bounds = laser.getGlobalBounds();
    float spriteWidth = bounds.width;
    float spriteHeight = bounds.height;
    laser.setOrigin(spriteWidth / 2, spriteHeight / 2);
    laser.setOrigin(50,50);
    laser.setTexture(texture);
    laser.rotate(180);
    laser.setScale(0.1, 0.1);
    //laser.setTextureRect(sf::IntRect(10, 100, 150, 150));
    isExploded = false;
    lifetime = 10;
}


/**
 * @brief Destroy the Laser Bolt:: Laser Bolt object
 * 
 */
LaserBolt::~LaserBolt() {
    
}


/**
 * @brief draws the laser
 * 
 * @param window 
 */
void LaserBolt::draw(sf::RenderWindow &window) {
    window.draw(laser);
    isOnScreen = true;
}

/**
 * @brief sets the laser pos
 * 
 * @param mainShip 
 */
void LaserBolt::setPos(MainShip &mainShip) {
    posX = mainShip.getPosX() + 20;
    posY = mainShip.getPosY() + 85;
    laser.setPosition(posX, posY);
    isOnScreen = true;
}


/**
 * @brief returns if the laser is on screen
 * 
 * @return true 
 * @return false 
 */
bool LaserBolt::getIsOnScreen() {
    if(posX > 2100) {
        isOnScreen = false;
    }
    return isOnScreen;
}


/**
 * @brief moves the laser
 * 
 */
void LaserBolt::move() {
    posX += 15;
    laser.setPosition(posX, laser.getPosition().y);
}



/**
 * @brief returns the hitbox
 * 
 * @return sf::IntRect 
 */
sf::IntRect LaserBolt::getHitBox() {
    return laser.getTextureRect();
}


/**
 * @brief reutns the bounds
 * 
 * @return sf::FloatRect 
 */
sf::FloatRect LaserBolt::getBounds() {
    sf::FloatRect bounds = laser.getGlobalBounds();
    return bounds;
}


/**
 * @brief changes the laser texture to an explosion and sets is exploded to true
 * 
 */
void LaserBolt::explode() {
    sf::Texture explosion;
    explosion.loadFromFile("explosion.png");
    texture.swap(explosion);
    laser.setTexture(texture);
    laser.rotate(180);
    laser.setScale(0.3 , 0.3);
    laser.setPosition(laser.getPosition().x, laser.getPosition().y - 40);
    laser.setTextureRect(sf::IntRect(0, 0, 290, 300));
    isExploded = true;
    
}


/**
 * @brief sets the life time of the ship while it dies, so it can stay on screen
 * 
 * @param time 
 */
void LaserBolt::setLifetime(int time) {
    lifetime = time;
}


/**
 * @brief returns the remaining lifetime of the laser explosion
 * 
 * @return float 
 */
float LaserBolt::getLifTime() {
    return lifetime;
}