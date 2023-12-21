/* CSCI 200: Assignment 5: A5 - SFML: Polygon Land
 *
 * Author: Gabriel Berta
 * Resources used (Class slides(A lot...) Zybooks, my other coding aissignments, chatspt for debugging):

 * This program uses classes to define shapes from a data file, then it uses the data it has recieved to draw the image out (somewhat)
 */
#include "Polygon.h"
#include<SFML\Graphics.hpp>

Polygon::Polygon() {
    numVertices = 0;
    color = sf::Color::White;
    vertices = nullptr;
}
Polygon::~Polygon() {
    delete[] vertices;
}
void Polygon::setColor(sf::Color colorin) {
    color = colorin;
}
void Polygon::draw(sf::RenderTarget& window) {
    sf::ConvexShape shape;
    shape.setPointCount(numVertices);

    for (int i = 0; i < numVertices; i++) {
        sf::Vector2f vect(vertices[i].x, vertices[i].y);
        shape.setPoint(i, vect);
    }

    shape.setFillColor(color);
    window.draw(shape);
}
void Polygon::setCoordinate(int idx, Coordinate coord) {
    vertices[idx] = coord;
}