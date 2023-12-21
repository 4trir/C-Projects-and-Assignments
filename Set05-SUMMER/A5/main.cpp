/* CSCI 200: Assignment 5: A5 - SFML: Polygon Land
 *
 * Author: Gabriel Berta
 * Resources used (Class slides(A lot...) Zybooks, my other coding aissignments, chatspt for debugging):

 * This program uses classes to define shapes from a data file, then it uses the data it has recieved to draw the image out (somewhat)
 */


#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Rhombus.h"
#include "ScaleneTriangle.h"
#include "Triangle.h"


int main() {
    //open the file
    std::ifstream file("polygons.dat");
    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    //create a vector of pointers that point to polygon objects
    std::vector<Polygon*> polygons;
    std::string type;
    //run when there are still new types of polygons
    while (file >> type) {
        if (type == "R") {
            double x1, y1, x2, y2, x3, y3, x4, y4, r, g, b;

            //enter the data from the file into the varibles
            file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> r >> g >> b;
            //create new pointers to the shape
            Rhombus* rhombus = new Rhombus;
            //dereferences the pointer and set the data members to their respective values
            rhombus->setCoordinate(0, { x1, y1 });
            rhombus->setCoordinate(1, { x2, y2 });
            rhombus->setCoordinate(2, { x3, y3 });
            rhombus->setCoordinate(3, { x4, y4 });
            rhombus->setColor(sf::Color(r, g, b));
            if (rhombus->validate() == false) {
                std::cout << "Error, invalid shape data" << std::endl;
                continue;
            }else {
            //add the pointer to vector
                polygons.push_back(rhombus);
            }
        }
        //Repeats for the case of all other types
        else if (type == "E") {
            double x1, y1, x2, y2, x3, y3, r, g, b;
            file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b;
            EquilateralTriangle* triangle = new EquilateralTriangle;
            triangle->setCoordinate(0, { x1, y1 });
            triangle->setCoordinate(1, { x2, y2 });
            triangle->setCoordinate(2, { x3, y3 });
            triangle->setColor(sf::Color(r, g, b));
            if (triangle->validate() == false) {
                std::cout << "Error, invalid shape data" << std::endl;
                continue;
            }else {
                polygons.push_back(triangle);
            }
        }
        else if (type == "I") {
            double x1, y1, x2, y2, x3, y3, r, g, b;
            file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b;
            IsoscelesTriangle* triangle = new IsoscelesTriangle;
            triangle->setCoordinate(0, { x1, y1 });
            triangle->setCoordinate(1, { x2, y2 });
            triangle->setCoordinate(2, { x3, y3 });
            triangle->setColor(sf::Color(r, g, b));
            if (triangle->validate() == false) {
                std::cout << "Error, invalid shape data" << std::endl;
                continue;
            }else {
                polygons.push_back(triangle);
            }
        }
        else if (type == "S") {
            double x1, y1, x2, y2, x3, y3, r, g, b;
            file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b;
            ScaleneTriangle* triangle = new ScaleneTriangle;
            triangle->setCoordinate(0, { x1, y1 });
            triangle->setCoordinate(1, { x2, y2 });
            triangle->setCoordinate(2, { x3, y3 });
            triangle->setColor(sf::Color(r, g, b));
            if (triangle->validate() == false) {
                std::cout << "Error, invalid shape data" << std::endl;
                continue;
            }else{
                polygons.push_back(triangle);
            }
        }else {
            //print error if type is incorrect
            std::cout << "Error, incorrect shape type" << std::endl;
        }
    }
    //close file
    file.close();

    // open a window to draw
    sf::RenderWindow window(sf::VideoMode(800, 600), "Polygon Shapes");
    Polygon* temp;
    while (window.isOpen()) {
        sf::Event event;
        //close if close button is pressed
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //clear the window
        window.clear();

        //iterate through the vector, dereference the pointers and draw the contents
        for(unsigned int i = 0; i < polygons.size(); i++) {
            temp = polygons.at(i);
            temp->draw(window);
        }
        
        //display the drawings
        window.display();
    }

    return 0;
}