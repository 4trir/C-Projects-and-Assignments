/**
 * @file main.cpp
 * @author Gabriel Berta
 * @brief This program creates a animation of driving down a road while the sun sets
 * @version 0.1
 * @date 2023-06-09
 * Resources used: class slides, SMFL documentation 
 * Note, computer variances in proccessing speed may break the display of graphics.
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include<cmath>
using namespace std;

int main() {
    RenderWindow window( VideoMode(1920, 1080), "Just vibin'" );

    Event event;
    //Initalize varibles with their values.
    double i(0), pos0X(965), pos0Y(541), pos1X(955), pos1Y(541), pos2X(956), pos2Y(550), pos3X(964), pos3Y(550);
    double skyColorRed(0), skyColorGreen(0), skyColorBlue(256);
    //Bools for time of day
    bool dayTime = true;
    bool dawn = false;
    bool night = false;
    
    double sunposY(0);
    

    while( window.isOpen() ) {
        window.clear();

        CircleShape sun;
        sun.setPosition(300, sunposY);
        sun.setRadius(100);
        sun.setFillColor(Color::Yellow);

        

        RectangleShape ground;
        ground.setSize(Vector2f(1920, 540));
        ground.setPosition(0,540);
        ground.setFillColor(Color(52, 140, 49));
    
        RectangleShape sky;
        sky.setSize(Vector2f(1920,540));
        sky.setPosition(0,0);
        sky.setFillColor(Color(skyColorRed, skyColorGreen, skyColorBlue));
        
        ConvexShape road;
        road.setPointCount(4); 
        road.setPoint(0, Vector2f(480,1080));
        road.setPoint(1, Vector2f(1440, 1080));
        road.setPoint(2, Vector2f(980, 540));
        road.setPoint(3, Vector2f(940, 540));
        road.setFillColor(Color(128, 126, 120));
        
        ConvexShape sunHider;
        sunHider.setPointCount(4);
        sunHider.setPoint(0, Vector2f(0, 1080));
        sunHider.setPoint(1, Vector2f(480, 1080));
        sunHider.setPoint(2, Vector2f(940, 540));
        sunHider.setPoint(3, Vector2f(0, 540));
        sunHider.setFillColor(Color(52, 140, 49));
       
        ConvexShape line;
        line.setPointCount(4);
        line.setPoint(0, Vector2f(pos0X, pos0Y));
        line.setPoint(1, Vector2f(pos1X,pos1Y));
        line.setPoint(2, Vector2f(pos2X, pos2Y));
        line.setPoint(3, Vector2f(pos3X, pos3Y));
        line.setFillColor(Color(255, 216, 0));
        
        //Draw everything
        window.draw(ground);
        window.draw(road);
        window.draw(line); 
        window.draw(sky);
        window.draw(sun);
        window.draw(sunHider);
        
        //increment values as needed
        pos0X += 0.075;
        pos0Y += i * 0.55;
        pos1X -= 0.075;
        pos1Y += i * 0.55;
        pos2X -= 0.05;
        pos2Y += i * 0.375;
        pos3X += 0.05;
        pos3Y += i * 0.375;
        //Conditions for sun setting
        if(dayTime == true) {
        skyColorBlue -= 0.01;
        skyColorRed += 0.01;
        sunposY += 0.01;
        }
        if(skyColorRed >= 255.9) {
            dawn = true;
            dayTime = false;
        }
        if(dawn == true) {
            skyColorRed -= 0.01;
            sunposY += 0.015;
            skyColorBlue = 0;
            skyColorGreen = 0;

        }
        if(skyColorBlue <= 0.1 && skyColorRed <= 0.1) {
            night = true;
            dawn = false;
        }
        if(night == true){
            skyColorBlue = 0;
            skyColorGreen = 0;
            skyColorRed = 0;
            sunposY = -500;
        }

        //Condition to reset the line to default.
        if(pos3Y >= 1080 ) {
            pos0X = (965);
            pos0Y = (540);
            pos1X = (955);
            pos1Y = (540);
            pos2X = (956);
            pos2Y = (530);
            pos3X = (964);
            pos3Y = (530);
            i = 1; //reset i so that the line does not gain infinte speed...   
        }

        i += 0.0005;



        window.display();

        while( window.pollEvent(event) ) {
            if(event.type == Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}