/* CSCI 200: Assignment 5: A5 - SFML: Polygon Land
 *
 * Author: Gabriel Berta
 * Resources used (Class slides(A lot...) Zybooks, my other coding aissignments, chatspt for debugging):

 * This program uses classes to define shapes from a data file, then it uses the data it has recieved to draw the image out (somewhat)
 */
#include "EquilateralTriangle.h"
#include <cmath>

bool EquilateralTriangle::validate() const {
    double side1(0), side2(0), side3(0);
    side1 = sqrt( pow( ( vertices[1].x - vertices[0].x ), 2 ) + pow( ( vertices[1].y - vertices[0].y ), 2 ) );
    side2 = sqrt( pow( ( vertices[2].x - vertices[0].x ), 2 ) + pow( ( vertices[2].y - vertices[0].y ), 2 ) );
    side3 = sqrt( pow( ( vertices[2].x - vertices[1].x ), 2 ) + pow( ( vertices[2].y - vertices[1].y ), 2 ) );
    if (side1 > 0 && side2 > 0 && side3 > 0 && side1 == side2 && side1 == side3 && side2 == side3) {
        return true;
    }
    else {
        return false;
    }
}