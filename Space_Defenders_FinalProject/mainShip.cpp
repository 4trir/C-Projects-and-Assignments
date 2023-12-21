#include "mainShip.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>



/**
 * @brief Construct a new Main Ship:: Main Ship object
 * 
 * @param fileName 
 */
MainShip::MainShip(std::string fileName) {
    posX = 400;
    posY = 450;
    mainShip.setPosition(posX, posY);
    mainShip.rotate(90);
    mainShip.setTextureRect(sf::IntRect(mainShip.getTextureRect().left, mainShip.getTextureRect().top, mainShip.getTextureRect().width * 3, mainShip.getTextureRect().height * 3));
    texture.loadFromFile(fileName);
    mainShip.setTexture(texture);
    mainShip.scale(3, 3);
    healthPoints = 4;
    isDead = false;
    lifetime = 60;

}


/**
 * @brief Destroy the Main Ship:: Main Ship object
 * 
 */
MainShip::~MainShip() {

}


/**
 * @brief sets player position
 * 
 * @param x 
 * @param y 
 */
void MainShip::setPos(double x, double y) {
    posX = x;
    posY = y;
}


/**
 * @brief gets x position
 * 
 * @return double 
 */
double MainShip::getPosX() {
    return mainShip.getPosition().x;
}


/**
 * @brief gets y position
 * 
 * @return double 
 */
double MainShip::getPosY() {
    return mainShip.getPosition().y;
}


/**
 * @brief rotates the sprite
 * 
 * @param degrees 
 */
void MainShip::rotateSprite(float degrees) {
    mainShip.rotate(degrees);
    isRotated = true;
}


/**
 * @brief moves the sprite but allows for a speed multiplyer to be used
 * 
 * @param speedMultiplyer 
 */
void MainShip::moveSpriteY(int speedMultiplyer) {
    double temp;
    temp = mainShip.getPosition().y + 5 * speedMultiplyer;
    mainShip.setPosition(mainShip.getPosition().x, temp);
}


/**
 * @brief moves the sprite but allows for a speed multiplyer to be used
 * 
 * @param speedMultiplyer 
 */
void MainShip::moveSpriteX(int speedMultiplyer) {
    int temp;
    temp = mainShip.getPosition().x + 5 * speedMultiplyer;
    mainShip.setPosition(temp, mainShip.getPosition().y);  
}


/**
 * @brief moves the sprite
 * 
 */
void MainShip::moveSpriteY() {
    int temp;
    temp = mainShip.getPosition().y + 5;
    mainShip.setPosition(mainShip.getPosition().x, temp);
}


/**
 * @brief moves the sprite
 * 
 */
void MainShip::moveSpriteX() {
    int temp;
    temp = mainShip.getPosition().x + 5;
    mainShip.setPosition(temp, mainShip.getPosition().y);  
}


/**
 * @brief sets sprite scale
 * 
 * @param scale 
 */
void MainShip::setScale(int scale) {
    mainShip.setScale(scale, scale);
}

/**
 * @brief loads textures to the sprite
 * 
 * @param filename 
 */
void MainShip::loadTexture(std::string filename) {
    texture.loadFromFile(filename);
}


/**
 * @brief returns the sprite
 * 
 * @return sf::Sprite 
 */
sf::Sprite MainShip::getSprite() {
    return mainShip;
}


/**
 * @brief draws the sprite
 * 
 * @param window 
 */
void MainShip::drawSprite(sf::RenderWindow& window) {
    window.draw(mainShip);
    //window.display();
}


/**
 * @brief returns if rotated
 * 
 * @return true 
 * @return false 
 */
bool MainShip::getIsRotated() {
    return isRotated;
}


/**
 * @brief resets the ships rotation to default
 * 
 */
void MainShip::resetRotation() {
    mainShip.setRotation(90);
}


/**
 * @brief sets the players health
 * 
 * @param health 
 */
void MainShip::setHealth(int health) {
    healthPoints = health;
}


/**
 * @brief logic for if the player is hit by a laser and changes the players texture to reflect the health
 * 
 */
void MainShip::hit() {
    healthPoints -= 1;
    sf::Texture damaged;
    switch (healthPoints) {
        case 1:
            damaged.loadFromFile("Main Ship Very Damaged.png");
            texture.swap(damaged);
            mainShip.setTexture(texture);
            break;
        case 2:
            damaged.loadFromFile("Main Ship Damaged.png");
            texture.swap(damaged);
            mainShip.setTexture(texture);
            break;
        case 3:
            damaged.loadFromFile("Main Ship Slight Damage.png");
            texture.swap(damaged);
            mainShip.setTexture(texture);
            break;
    }
    if(healthPoints <= 0){
        isDead = true;
    }
}


/**
 * @brief returns if the player is dead
 * 
 * @return true 
 * @return false 
 */
bool MainShip::getIsDead() {
    return isDead;
}


/**
 * @brief sets the players lifetime to stay on screen after dead
 * 
 * @param frames 
 */
void MainShip::setLifeTime(int frames) {
    lifetime = frames;
}


/**
 * @brief returns the remaining lifetime of the player
 * 
 * @return int 
 */
int MainShip::getLifeTime() {
    return lifetime;
}


/**
 * @brief swaps the players texture with a explosion if the player has been hit
 * 
 */
void MainShip::explode() {
    sf::Texture explosion;
    explosion.loadFromFile("explosion.png");
    texture.swap(explosion);
    mainShip.setTexture(texture);
    mainShip.rotate(-90);
    mainShip.setTextureRect(sf::IntRect(0, 0, 290, 300));
    mainShip.setPosition(mainShip.getPosition().x - 125, mainShip.getPosition().y + 30);
    mainShip.setScale(0.3, 0.3);


}


/**
 * @brief returns the bounds of the player
 * 
 * @return sf::FloatRect 
 */
sf::FloatRect MainShip::getBounds() {
    return mainShip.getGlobalBounds();
}