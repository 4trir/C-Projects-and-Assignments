/**CSCI 200: Set 1: A4 - Bubble Bobble
 * 
 * @file: main.cpp
 * @author: Gabriel Berta
 * @Resources Used: Class slides, SMFL documentation, ChatGPT for debugging 
 * @brief This program creates a window that has balls bouncing and allows the user to delete and create balls
 * @version 0.1
 * @date 2023-06-09 
 */

#include <iostream>
#include <ctime>
#include <vector>
#include "Bubble.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

using namespace sf;
using namespace std;

int main() {
    //Asign varibles with their values, before the while loop
    int windowW(1280), windowH(720);
    bool mouseIsClick(false), keyIsPressed(false);
    double refreshrate(144);
    refreshrate = (1 / refreshrate) * 1000;

    //star timer, set resolution, set render mode, create window, load the cursor, and seed random
    sf::Clock chrono;
    VideoMode resolution = VideoMode(windowW, windowH);
    RenderWindow window( resolution, "Bubble Bobble!" );
    Cursor cursor;
    cursor.loadFromSystem(sf::Cursor::Hand);
    srand(time(0));
    
    //Create vector to store the bubbles
    vector<Bubble> bubbleVector;
    //create  the 5 bubbles
    for(int i = 0; i < 5; i++){
        Bubble bubble;
        bubbleVector.push_back(bubble);
    }
    
    Event event;

    while( window.isOpen() ) {
        window.clear();
        //evaluate the state of the mouse and keyboard every loop (to stop infinite balls from spawning and deleting)
        mouseIsClick = (Mouse::isButtonPressed(Mouse::Left));
        keyIsPressed = (Keyboard::isKeyPressed(Keyboard::D));


        //Check if time elasped is greater than the refresh rate
        if(chrono.getElapsedTime() >= sf::microseconds(refreshrate)) {
            //draws all of the bubbles in the vector, updates it's position and resarts the timer.
            for(unsigned int i = 0; i < bubbleVector.size(); i++) {
                bubbleVector.at(i).draw(window);
                bubbleVector.at(i).updatePosition(windowW, windowH);
                chrono.restart();
        }  
        }
        window.display();

        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                window.close();
            }
            //check if the mouse is pressed, create a new object, append to the vector
            if(Mouse::isButtonPressed(Mouse::Left) && mouseIsClick == false) {
                Vector2i mousePosition = Mouse::getPosition(window);
                Bubble x(mousePosition);
                bubbleVector.push_back(x);
                mouseIsClick = true;
            }
            //for(int i = 0; i < bubbleVector.size(); )
            //changes the users cursor to the hand cursor cus its coolllll
            if(Mouse::getPosition(window).x >= 0 && Mouse::getPosition(window).y >= 0 && Mouse::getPosition(window).x <= windowW && Mouse::getPosition(window).y <= windowH ) {
                window.setMouseCursor(cursor);
            }
            //check if the D key is pressed and remove a ball from the vector if it is
            if(Keyboard::isKeyPressed(Keyboard::D) && keyIsPressed == false) {
                bubbleVector.pop_back();
                keyIsPressed = true;
            }
            //gets resolution for full screen mode
            if(event.type == Event::Resized){
                resolution = VideoMode::getDesktopMode();
            }
            //Checks if q is pressed and closes program if it is
            if(Keyboard::isKeyPressed(Keyboard::Q) || Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }
        }
    }

    return 0;
}