#ifndef ENEMY_LASER_H
#define ENEMY_LASER_H
#include "Enemies.h"

class enemyLaser
{
private:
    int posX;
    int posY;
    bool hit;
    sf::RectangleShape laser;

public:
    enemyLaser(EnemyShip * enemyShip);

    sf::FloatRect getLaserBounds();
    void move();
    void draw(sf::RenderWindow &window);
    bool didHit();
    bool isOnScreen();

};

#endif 
