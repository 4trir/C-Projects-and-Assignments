/* CSCI 200: Final Project: Space Defenders
 *
 * Author: Gabriel Berta
 * Resources used Class slides, Zybooks, my other coding aissignments, SFML documentation,  chatgpt for debugging):

 * This is Space Defenders, an infinite side scrolling space game, where you pilot a ship and destroy other craft while trying to stay alive. Any features that are not implemented 
 * are for future development of the game.
 * 
 * Disclaimer: All assets used for this game are creative commons and not my own work. As they are under creative commons domains I am free to use them in this sense.
 * Credit: All ship sprites are works of Foozle, Music by Tad, Explosion sound by Prof. Mudkip, Background by unknown, "JoyStick Font" by Raymond Larabie, Laser by unknown.
 */

#include "Enemies.h"
#include "LaserBolt.h"
#include "Ships.h"
#include "enemyLaser.h"
#include "mainShip.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace sf;

int main() {
    //set up the render window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space Defenders");
    window.setFramerateLimit(60);

    //event for handling window events
    sf::Event event;

    //open a file stream
    std::fstream fin;

    //load sprite for main ship
    MainShip mainship("Main Ship.png");

    //seed random number generator
    srand(time(0));

    //create vectors that will store game elements
    std::vector<LaserBolt*> lasers;
    std::vector<EnemyShip*> enemies;
    std::vector<enemyLaser*> enemyLasers;
    std::vector<sf::Clock*> clocks;

    //variables for game state
    bool spacePressed = false;
    bool dead = false;
    bool failed = false;

    //clock for tracking time
    sf::Clock chrono;

    //load background texture
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background.png");

    //set up background sprites
    sf::Sprite bckgrnd1(backgroundTexture);
    bckgrnd1.setScale(1.5, 1.5);
    sf::Sprite bckgrnd2(backgroundTexture);
    bckgrnd2.setScale(1.5, 1.5);
    bckgrnd1.setTextureRect(sf::IntRect(0, 0, backgroundTexture.getSize().x * 1.5, backgroundTexture.getSize().y * 1.5));
    bckgrnd2.setTextureRect(sf::IntRect(0, 0, backgroundTexture.getSize().x * 1.5, backgroundTexture.getSize().y * 1.5));
    bckgrnd1.setPosition(0, 0);
    bckgrnd2.setPosition(bckgrnd1.getLocalBounds().width, 0);

    //scroll speed for background
    const int scrollSpeed(1);

    //load music and sound effects
    sf::Music music;
    music.openFromFile("music.ogg");
    sf::Music explodeSound;
    explodeSound.openFromFile("explosion.ogg");

    //clock for limiting shooting frequency
    sf::Clock shootLimiter;

    //clock for hit timer
    sf::Clock hitTimer;

    //load font for text display
    sf::Font font;
    font.loadFromFile("joystix monospace.otf");

    //text for game over message
    sf::Text text("GAME OVER", font);
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Red);
    text.setPosition(550, 500);
    text.setOutlineColor(sf::Color::Black);

    //menu screen elements
    sf::Text gameName("SPACE DEFENDERS", font);
    sf::RectangleShape menu(sf::Vector2f(1300, 500));
    menu.setPosition(sf::Vector2f(960 - 650, 300));
    menu.setFillColor(sf::Color(32, 42, 49));
    gameName.setFillColor(sf::Color::Red);
    gameName.setPosition(sf::Vector2f(330, 300));
    gameName.setCharacterSize(100);
    gameName.setStyle(sf::Text::Bold);
    sf::Text easy("Easy", font);
    sf::Text medium("Medium", font);
    sf::Text hard("Hard", font);
    easy.setFillColor(sf::Color::Red);
    medium.setFillColor(sf::Color::Red);
    hard.setFillColor(sf::Color::Red);
    easy.setPosition(sf::Vector2f(330, 450));
    medium.setPosition(sf::Vector2f(330, 500));
    hard.setPosition(sf::Vector2f(330, 550));
    easy.setCharacterSize(50);
    medium.setCharacterSize(50);
    hard.setCharacterSize(50);

    //game configuration variables
    float enemySpawnRate;
    float enemyFireRate;
    float mainShipFireRate;
    int mainShipSpeed;
    bool gameStarted = false;


        while (window.isOpen()) {
        window.clear();
        //start menu logic and drawings
        if(!gameStarted) {
            window.draw(bckgrnd1);
            window.draw(menu);
            window.draw(easy);
            window.draw(medium);
            window.draw(hard);
            window.draw(gameName);
            //check for clicks and open the file
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && easy.getGlobalBounds().contains(sf::Vector2f( sf::Mouse::getPosition(window))) ) {
                fin.open("Easy.dat");
                fin >> enemySpawnRate >> enemyFireRate >> mainShipFireRate >> mainShipSpeed;
                if(!fin) {
                    std::cout << "ERROR: Cannot Open File" << std::endl;
                }
                gameStarted = true;
                music.play();
            }
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && medium.getGlobalBounds().contains(sf::Vector2f( sf::Mouse::getPosition(window))) ) {
                fin.open("Medium.dat");
                fin >> enemySpawnRate >> enemyFireRate >> mainShipFireRate >> mainShipSpeed;
                if(!fin) {
                    std::cout << "ERROR: Cannot Open File" << std::endl;
                }
                gameStarted = true;
                music.play();
            }
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && hard.getGlobalBounds().contains(sf::Vector2f( sf::Mouse::getPosition(window))) ) {
                fin.open("Hard.dat");
                fin >> enemySpawnRate >> enemyFireRate >> mainShipFireRate >> mainShipSpeed;
                if(!fin) {
                    std::cout << "ERROR: Cannot Open File" << std::endl;
                }
                gameStarted = true;
                music.play();
            }
            //close file as it is no longer needed
            fin.close();
        }
        
        
        
        
        //game logic for when game is running
        if(!dead && gameStarted){
            //check time and spawn enimes in
            if (chrono.getElapsedTime().asSeconds() >= 1 / enemySpawnRate) {
                //create a new enemy ship and clock for that enemey.
                EnemyShip* PenemyShip = new EnemyShip("Enemy1.png");
                sf::Clock* shotTimer = new sf::Clock(); 
                clocks.push_back(shotTimer);
                enemies.push_back(PenemyShip);
                chrono.restart();
            }
            //logic for player control
            if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
                if (mainship.getPosY() + 30 > 0) {
                    mainship.moveSpriteY(-mainShipSpeed);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(sf::Keyboard::S)) {
                if (mainship.getPosY() + 20 < 1080 - 95) {
                    mainship.moveSpriteY(mainShipSpeed);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
                if (mainship.getPosX() + 20 < 800) {
                    mainship.moveSpriteX(mainShipSpeed);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
                if (mainship.getPosX() - 50 > 50) {
                    mainship.moveSpriteX(-mainShipSpeed);
                }
            }
            //logic for shooting and creating new lasers
            if (Keyboard::isKeyPressed(Keyboard::Space) && shootLimiter.getElapsedTime().asSeconds() > 1 / mainShipFireRate) {
                if (!spacePressed) {
                    LaserBolt* laserPt = new LaserBolt("lazers.png");
                    laserPt->setPos(mainship);
                    lasers.push_back(laserPt);
                    spacePressed = true;
                    shootLimiter.restart();
                }
            }
            else {
                spacePressed = false; 
            }



            //scroll the backgrounds and check their logic then draw them
            bckgrnd1.move(-scrollSpeed, 0);
            bckgrnd2.move(-scrollSpeed, 0);
            if (bckgrnd1.getPosition().x + bckgrnd1.getLocalBounds().width <= 0) {
                float newX = bckgrnd2.getPosition().x + bckgrnd2.getLocalBounds().width;
                bckgrnd1.setPosition(newX, 0);
            }
            if (bckgrnd2.getPosition().x + bckgrnd2.getLocalBounds().width <= 0) {
                float newX = bckgrnd1.getPosition().x + bckgrnd1.getLocalBounds().width;
                bckgrnd2.setPosition(newX, 0);
            }
            window.draw(bckgrnd1);
            window.draw(bckgrnd2);



            //draw enemies and handle collisions
            for (unsigned int i = 0; i < enemies.size(); i++) {
                EnemyShip* enemy = enemies.at(i);
                if (enemy->getIsOnScreen()) {
                    enemy->move();
                    enemy->drawSprite(window);
                    if(clocks.at(i)->getElapsedTime().asSeconds() > 1 / enemyFireRate) {
                        enemyLaser *PeLaser = new enemyLaser(enemy);
                        enemyLasers.push_back(PeLaser);
                        clocks.at(i)->restart();
                    }

                    //check collision with lasers
                    for (unsigned int j = 0; j < lasers.size(); j++) {
                        LaserBolt* laser = lasers.at(j);
                        if (laser->getIsOnScreen()) {
                            sf::FloatRect enemyBounds = enemy->getBounds();
                            sf::FloatRect laserBounds = laser->getBounds();
                            //logic if an enemy is hit
                            if (enemyBounds.intersects(laserBounds)) {
                                delete enemies.at(i);
                                enemies.erase(enemies.begin() + i);
                                laser->explode();
                                laser->draw(window);
                                explodeSound.play();
                                i--;
                                break;                            }
                        }
                    }
                }
                //delete the enemies if they are off screen for data mangement or something
                else {
                    delete enemies.at(i);
                    enemies.erase(enemies.begin() + i);
                    lasers.shrink_to_fit();
                    i--;
                }
            //check if the player is hit by a laser and delete the laser and damage the player. If player is dead explode and set dead to true
            for(unsigned int i = 0; i < enemyLasers.size(); i++) {
                if(enemyLasers.at(i)->isOnScreen()) {
                    delete enemyLasers.at(i);
                    enemyLasers.erase(enemyLasers.begin() + i);
                }
                
                sf::FloatRect laserBounds = enemyLasers.at(i)->getLaserBounds();
                sf::FloatRect mainShipBounds = mainship.getBounds();
                if(laserBounds.intersects(mainShipBounds)) {
                    delete enemyLasers.at(i);
                    enemyLasers.erase(enemyLasers.begin() + i);
                    mainship.hit();
                    hitTimer.restart();
                    if(mainship.getIsDead()) {
                        dead = true;
                        mainship.explode();
                        explodeSound.play();
                    }
                }
            }
            }
            //move and draw the lasers
            for(unsigned int i = 0; i < enemyLasers.size(); i++) {
                enemyLasers.at(i)->move();
                enemyLasers.at(i)->draw(window);
            }

            //draw and update the main ship
            mainship.drawSprite(window);

            //draw and update laser bolts, also cause them to explode and change their texture using a countdown
            for (unsigned int i = 0; i < lasers.size(); i++) {
                LaserBolt* laser = lasers.at(i);
                if (laser->getIsOnScreen() && !laser->isExploded) {
                    laser->move();
                    laser->draw(window);
                }
                else {
                    if(laser->getLifTime() <= 30) {
                        laser->draw(window);
                        laser->setLifetime(laser->getLifTime() + 1);
                    }
                    else {
                    delete laser;
                    lasers.erase(lasers.begin() + i);
                    lasers.shrink_to_fit();
                    explodeSound.stop();
                    i--;

                    }
                }
            }
        }
        //endgame logic
        else if(dead && gameStarted) {
            if(mainship.getLifeTime() >= 0) {
                mainship.setLifeTime(mainship.getLifeTime() - 1);
                //std::cout << mainship.getLifeTime() << std::endl;
                window.draw(bckgrnd1);
                window.draw(bckgrnd2); 
                mainship.drawSprite(window);
            }else {
                explodeSound.stop();
                window.draw(bckgrnd1);
                window.draw(bckgrnd2);
                window.draw(text); 
            }


        }
        //check for events
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        //display everything that has been drawn
        window.display();
    }

    //delete remaining elements if any
    for (unsigned int i = 0; i < lasers.size(); i++) {
        delete lasers.at(i);
    }
    for(unsigned int i = 0; i < enemies.size(); i++) {
        delete enemies.at(i);
    }
    for(unsigned int i = 0; i < enemyLasers.size(); i ++) {
        delete enemyLasers.at(i);
    }
    for(unsigned int i = 0; i < clocks.size(); i++) {
        delete clocks.at(i);
    }


    return 0;
}
