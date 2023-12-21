/* CSCI 200: Assignment 5: A5 - SFML: Polygon Land
 *
 * Author: Gabriel Berta
 * Resources used (Class slides(A lot...) Zybooks, my other coding aissignments, chatspt for debugging):

 * This program uses classes to define shapes from a data file, then it uses the data it has recieved to draw the image out (somewhat)
 */
#include "Triangle.h"
#include<SFML\Graphics.hpp>

 Triangle::Triangle() {
    numVertices = 3;
    vertices = new Coordinate[numVertices];
 }