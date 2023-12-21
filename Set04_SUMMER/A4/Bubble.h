#ifndef BUBBLE_H
#define BUBBLE_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Bubble {
private:
    /**
     * @brief Creates circles
     * 
     */
    CircleShape object;
    /**
     * @brief Stores speed in x direction
     * 
     */
    double xDir;
    /**
     * @brief Stores speed in y direction
     * 
     */
    double yDir;
    /**
     * @brief stores object x location
     * 
     */
    double xPos;
    /**
     * @brief stores object y location
     * 
     */
    double yPos;
    
public:
    /**
     * @brief Construct a new Bubble object
     * 
     */
    Bubble();
    /**
     * @brief Construct a new Bubble object based on click location
     * 
     * @param location of click
     */
    Bubble(Vector2i location);
    /**
     * @brief Get the Circle Size object
     * 
     * @return double 
     */
    double getCircleSize();
    /**
     * @brief Get the Circle Location object
     * 
     * @return Vector2f 
     */
    Vector2f getCircleLocation();
    /**
     * @brief Set the Circle Size object
     * 
     * @param radius 
     */
    void setCircleSize(double r);
    /**
     * @brief Set the Circle Location object
     * 
     * @param x coordinate
     * @param y coordinate
     */
    void setCircleLocation(double x, double y);
    /**
     * @brief renders the frame
     * 
     * @param drawee 
     */
    void draw(RenderWindow& drawee);
    /**
     * @brief updates object position
     * 
     * @param windowWidth 
     * @param windowHeight 
     */
    void updatePosition(int windowWidth, int windowHeight);
    



};













#endif