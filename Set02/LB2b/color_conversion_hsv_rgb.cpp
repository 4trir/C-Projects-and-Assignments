#include <cmath>
#include "color_conversion_hsv_rgb.h"
#include<iostream>
using namespace std;

void color_conversion_hsv_rgb(double &(H), double &(S), double &(V)) {
    
    double M = 255 * V;
    double m = M * (1-S);
    double t = H/60;
    double z = abs((M-m) * (1 - abs((remainder(t, 2)) - 1)));
    int R, G, B;
    
    if (H < 60){
        R = M;
        G = z + m;
        B = m;
        

    }else if (H >= 60 && H < 120) {
        R = z + m;
        G = M;
        B = m;


    }else if (H >= 120 && H < 180) {
        R = m;
        G = M;
        B = z + m;

    }else if (H >= 180 && H < 240) {
        R = m;
        G = z + m;
        B = M;

    }else if (H >= 240 && H < 300) {
        R = z + m;
        G = m;
        B = M;

    }else if (H >= 300 && H < 360) {
        R = M;
        G = m;
        B = z + m;

    }
    H = R;
    S = G;
    V = B;
}
