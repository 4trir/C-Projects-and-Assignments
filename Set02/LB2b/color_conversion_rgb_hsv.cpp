#include<cmath>
#include "color_conversion_rgb_hsv.h"
#include<iostream>
using namespace std;

void color_conversion_rgb_hsv(double &(r), double &(g), double &(b)) {
    double red = double (r);
    double green = double (g);
    double blue = double (b);

    double inputOne = double (r);
    double inputTwo = double (g);
    double InputThree = double (b);

    double M = 0.0;
    double m = 0.0;
    double S = 0.0;
    double V = 0.0;
    double H = 0.0;

    if (inputOne > inputTwo && inputOne > InputThree) {
        M = inputOne; 
    }else if (inputTwo > inputOne && inputTwo > InputThree) {
        M = inputTwo;
    }else if (InputThree > inputOne && InputThree > inputTwo){
        M = InputThree;
    }else {
        M = inputOne;
    }
    

    if (inputOne < inputTwo && inputOne < InputThree) {
        m = inputOne; 
    }else if (inputTwo < inputOne && inputTwo < InputThree) {
        m = inputTwo;
    }else if (InputThree < inputOne && InputThree < inputTwo){
        m = InputThree;
    }


    V = M/255;
    if (green >= blue){
        H = acos((red - (0.5 * green) - (0.5 * blue))/(sqrt(pow(red, 2.0) + pow(green, 2) +  pow(blue, 2) - (red * green) - (red * blue) - (green * blue))));
        H = (H * (180/3.1415));      
    }else if (blue > green) {
        H = acos((red - (0.5 * green) - (0.5 * blue))/(sqrt(pow(red, 2.0) + pow(green, 2) +  pow(blue, 2) - (red * green) - (red * blue) - (green * blue))));

        H = (H * (180/3.1415926535));
        H = 360 - H; 
 
    }

    if (M > 0) {
        S = (1 - (m/M));
    }else if (M == 0) {
        S = 0;
    }

}