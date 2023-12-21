#ifndef POLYGON_H
#define POLYGON_H
#include <SFML/Graphics.hpp>
#include "Coordinate.h"

class Polygon {
public:
    Polygon();
    ~Polygon();
    void setColor(sf::Color colorin);
    void draw(sf::RenderTarget& window);
    void setCoordinate(int i, Coordinate);
    virtual bool validate() const = 0;
private:
    sf::Color color;
protected:
    short int numVertices;
    Coordinate* vertices;
};
#endif

