#ifndef SHIPS_HPP
#define SHIPS_HPP


#include <SFML/Graphics.hpp>
#include <vector>
#include<string>
class Ship {
protected:
    double posX;
    double posY;
    sf::Texture texture;
    int rotation;
    sf::Vector2i scale;
    sf::Sprite Ship;
    bool isRotated;
    int iteration;
    sf::IntRect hitBox;


public:
    virtual double getPosX() const = 0;
    virtual double getPosY() const = 0;
    virtual void setPos(double x, double y) = 0;
    virtual sf::Sprite getSprite() const = 0;
    virtual void drawSprite(sf::RenderWindow& window) = 0;
    virtual sf::IntRect getHitBox() const = 0;




};
#endif