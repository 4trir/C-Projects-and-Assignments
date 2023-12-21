#include <drawer.h>
#include "SFML\Graphics.hpp"
#include <fstream>
#include <iostream>


void Drawer::draw(std::string filename) {
    int r, c;
    std::fstream maze;
    maze.open(filename);
    maze >> r >> c;
    sf::RectangleShape square;
    sf::RenderWindow window(sf::VideoMode(r * 10, c * 10), "Maze");
    window.setFramerateLimit(60);

    std::string ** blocks = new std::string*[r];
    for(unsigned int i = 0; i < r; i++) {
        blocks[i] = new std::string[c];
    }
    for(unsigned int i = 0; i < r; i++) {
        for(unsigned int j = 0; j < c; j++) {
            
        }
    }

}