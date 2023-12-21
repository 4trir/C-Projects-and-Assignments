#include "Enemies.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include<cmath>
#include <cstdlib>
/**
 * @brief Construct a new Enemy Ship:: Enemy Ship object
 * 
 * @param fileName 
 */
EnemyShip::EnemyShip(std::string fileName) {
    posX = 2000;
    posY = rand() % (1000 - 100 + 1) + 100;
    sf::FloatRect bounds = Ship.getGlobalBounds();
    float spriteWidth = bounds.width;
    float spriteHeight = bounds.height;
    Ship.setOrigin(spriteWidth / 2, spriteHeight / 2);
    Ship.rotate(-90);
    Ship.setPosition(posX, posY);
    texture.loadFromFile(fileName);
    Ship.setTexture(texture);
    Ship.scale(3, 3);
    isOnScreen = true;
}

/**
 * @brief Destroy the Enemy Ship:: Enemy Ship object
 * 
 */
EnemyShip::~EnemyShip() {
}


/**
 * @brief set sprite positions
 * 
 * @param x 
 * @param y 
 */
void EnemyShip::setPos(double x, double y) {
    posX = x;
    posY = y;
    Ship.setPosition(posX, posY);
}


/**
 * @brief getter of position x
 * 
 * @return double 
 */
double EnemyShip::getPosX() const {
    return Ship.getPosition().x;
}


/**
 * @brief getter of position y
 * 
 * @return double 
 */
double EnemyShip::getPosY() const {
    return Ship.getPosition().y;
}


/**
 * @brief returns the sprite object
 * 
 * @return sf::Sprite 
 */
sf::Sprite EnemyShip::getSprite() const {
    return Ship;
}


/**
 * @brief draws the ship
 * 
 * @param window 
 */
void EnemyShip::drawSprite(sf::RenderWindow& window) {
    window.draw(Ship);
}


/**
 * @brief returns the hitbox of the sprite
 * 
 * @return sf::IntRect 
 */
sf::IntRect EnemyShip::getHitBox() const {
    return Ship.getTextureRect();
}


/**
 * @brief moves the enemy ship
 * 
 */
void EnemyShip::move() {
    posX -= 1;
    posY -= sin(posX * 0.01);
    Ship.setPosition(posX, posY);

}


/**
 * @brief returns if the ship is still on the screen
 * 
 * @return true 
 * @return false 
 */
bool EnemyShip::getIsOnScreen() {
    if(posX < -100) {
        isOnScreen = false;
    }
    return isOnScreen;
}


/**
 * @brief returns the hitbox as bounds
 * 
 * @return sf::FloatRect 
 */
sf::FloatRect EnemyShip::getBounds() {
    sf::FloatRect bounds = Ship.getGlobalBounds();
    // Adjust the hitbox in the y-direction
    bounds.top += 50;  // Increase the top position
    bounds.height -= 90;  // Decrease the height
    bounds.left += 100;
    bounds.width -= 150;
    return bounds;
}


/**
 * @brief returns if the ship has been destroyed
 * 
 * @return true 
 * @return false 
 */
bool EnemyShip::getIsDestroyed() {
    return isDestroyed;
}


/**
 * @brief sets destroyed to true
 * 
 */
void EnemyShip::setIsDestroyed() {
    isDestroyed = true;
}

