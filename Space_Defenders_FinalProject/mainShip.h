#ifndef MAINSHIP_H
#define MAINSHIP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include<string>
class MainShip
{
private:
    double posX;
    double posY;
    sf::Texture texture;
    int rotation;
    sf::Vector2i scale;
    sf::Sprite mainShip;
    bool isRotated;
    int healthPoints;
    bool isDead;
    int lifetime;


public:
    MainShip(std::string fileName);
    ~MainShip();
    double getPosX();
    double getPosY();
    void setPos(double x, double y);

    void rotateSprite(float degrees);
    void moveSpriteY(int speedMultipler);
    void moveSpriteX(int speedMultipler);
    void moveSpriteY();
    void moveSpriteX();
    void setScale(int scale);
    void loadTexture(std::string filename);
    sf::Sprite getSprite();
    void drawSprite(sf::RenderWindow& window);
    bool getIsRotated();
    void resetRotation();
    sf::FloatRect getBounds();
    void setHealth(int health);
    void hit();
    bool getIsDead();
    void setLifeTime(int frames);
    int getLifeTime();
    void explode();





};








#endif