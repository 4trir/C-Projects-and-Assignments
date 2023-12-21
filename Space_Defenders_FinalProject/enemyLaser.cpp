#include "enemyLaser.h"
#include "Enemies.h"

/**
 * @brief Construct a new enemy Laser::enemy Laser object
 * 
 * @param enemyShip 
 */
enemyLaser::enemyLaser(EnemyShip * enemyShip) {
    posX = enemyShip->getPosX();
    posY = enemyShip->getPosY() - 100;
    laser.setPosition(posX, posY);
    laser.setSize(sf::Vector2f(50, 10));
    laser.setFillColor(sf::Color::Red);

    hit = false;

}


/**
 * @brief returns the bounds of the enemy lasers
 * 
 * @return sf::FloatRect 
 */
sf::FloatRect enemyLaser::getLaserBounds() {
    return laser.getGlobalBounds();
}


/**
 * @brief moves the enemy lasers
 * 
 */
void enemyLaser::move() {
    posX -= 10;
    laser.setPosition(posX, posY);
}


/**
 * @brief draws the lasers on the screen
 * 
 * @param window 
 */
void enemyLaser::draw(sf::RenderWindow &window) {
    window.draw(laser);
}


/**
 * @brief returns if the laser hit the player
 * 
 * @return true 
 * @return false 
 */
bool enemyLaser::didHit() {
    return hit;
}


/**
 * @brief returns if the laser is still on screen
 * 
 * @return true 
 * @return false 
 */
bool enemyLaser::isOnScreen() {
    if(posX + 60 < 0) {
        return true;
    }
    else {
        return false;
    }
}