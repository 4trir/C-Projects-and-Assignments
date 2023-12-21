/**CSCI 200: A1 Bubble.cpp
 * @file Bubble.cpp
 * @author Gabriel Berta
 * @brief Compilable code for the bubble object
 * @version 0.1
 * @date 2023-06-09
 */

#include<SFML/Graphics.hpp>
#include "Bubble.h"
#include<cstdlib>


using namespace std;


Bubble::Bubble() {
    xDir = rand() / double(RAND_MAX) * (0.1667 - (-0.1667)) + (-0.1667);
    yDir = rand() / double(RAND_MAX) * (0.1667 - (-0.1667)) + (-0.1667);
    xPos = rand() % (400 - 100 + 1) + 100;
    yPos = rand() % (400 - 100 + 1) + 100;
    object.setRadius(rand() % (50 - 10 + 1) + 10);

    object.setPosition(xPos, yPos);
    int color = rand() % (7 - 1 + 1) + 1;
    switch(color) {
        case 1:
            object.setFillColor(Color::Blue);
            break;
        case 2:
            object.setFillColor(Color::Cyan);
            break;
        case 3:
            object.setFillColor(Color::Green);
            break;
        case 4:
            object.setFillColor(Color::Magenta);
            break;
        case 5:
            object.setFillColor(Color::Red);
            break;
        case 6:
            object.setFillColor(Color::White);
            break;
        case 7:
            object.setFillColor(Color::Yellow);
            break;
    }

}

Bubble::Bubble(Vector2i location) {
    xDir = rand() / double(RAND_MAX) * (0.1667 - (-0.1667)) + (-0.1667);
    yDir = rand() / double(RAND_MAX) * (0.1667 - (-0.1667)) + (-0.1667);
    xPos = location.x - object.getRadius() - 20;
    yPos = location.y - object.getRadius() - 20;
    object.setRadius(rand() % (50 - 10 + 1) + 10);

    object.setPosition(xPos, yPos);
    int color = rand() % (7 - 1 + 1) + 1;
    switch(color) {
        case 1:
            object.setFillColor(Color::Blue);
            break;
        case 2:
            object.setFillColor(Color::Cyan);
            break;
        case 3:
            object.setFillColor(Color::Green);
            break;
        case 4:
            object.setFillColor(Color::Magenta);
            break;
        case 5:
            object.setFillColor(Color::Red);
            break;
        case 6:
            object.setFillColor(Color::White);
            break;
        case 7:
            object.setFillColor(Color::Yellow);
            break;
    }
}

double Bubble::getCircleSize() {
    return object.getRadius();
}

Vector2f Bubble::getCircleLocation() {
    return object.getPosition();
}

void Bubble::setCircleSize(double r) {
    object.setRadius(r);
}

void Bubble::setCircleLocation(double x, double y) {
    object.setPosition(x, y);

}

void Bubble::draw(RenderWindow& Window) {
    Window.draw(object);
}

void Bubble::updatePosition(int windowWidth, int windowHeight) {
    if(xPos > (windowWidth - (2 * object.getRadius()))) {
        xDir = (-1 * xDir);
    }
    if(yPos > (windowHeight - (2 * object.getRadius()))) {
        yDir = (-1 * yDir);
    }
    if(xPos < 0) {
        xDir = (-1 * xDir);
    }
    if(yPos < 0) {
        yDir = (-1 * yDir);
    }

    xPos += xDir;
    yPos += yDir;

    object.setPosition(xPos, yPos);
}
