#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include "Ships.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include<string>

class EnemyShip : public Ship {
public:
    EnemyShip(std::string fileName);
    virtual ~EnemyShip();

    double getPosX() const override;
    double getPosY() const override;
    void setPos(double x, double y)  override;
    void move();
    sf::Sprite getSprite() const override;
    void drawSprite(sf::RenderWindow& window) override;
    sf::IntRect getHitBox() const override;
    bool getIsOnScreen();
    sf::FloatRect getBounds();
    void destroy(int phase);
    bool getIsDestroyed();
    void setIsDestroyed();
private:
    bool isOnScreen;
    bool isDestroyed;


    };

#endif