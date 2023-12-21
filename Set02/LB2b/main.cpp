#include <iostream>
#include "color_conversion_hsv_rgb.h"
#include "color_conversion_rgb_hsv.h"
using namespace std;

int main() {
    char choice = ' ';

    cout << "Would you like to convert RGB -> HSV or HSV -> RGB (1 or 2)" << endl;
    cin >> choice;


    if (choice == '1'){

        double x;
        double y;
        double z;

        cout << "What is the value of the Red channel?" << endl;
        cin >> x;
        cout << "What is the value of the Green channel?" << endl;
        cin >> y;
        cout << "What is the value of the Blue channel?" << endl;
        cin >> z;

        
        color_conversion_rgb_hsv(x, y, z);
        cout << "The HSV value is " << "(" << x << ", " << y << ", " << z << ")" << endl;

    }else if (choice == '2') {
        
        double a;
        double b;
        double c;
        
        cout << "What is the value of the Hue?" << endl;
        cin >> a;
        cout << "What is the saturation?" << endl;
        cin >> b;
        cout << "What is the value" << endl;
        cin >> c;
        
        
        color_conversion_hsv_rgb(a, b, c);
        
        cout << "The RGB value is " << "(" << a << ", " << b << ", " << c << ")" << endl;

    }else {
        cout << "Please enter a valid response" << endl;



    




    }
    return 0;
}