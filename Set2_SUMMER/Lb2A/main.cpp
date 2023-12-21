#include<cmath>
#include<iostream>
#include "coordinate_conversion.h"
using namespace std;

int main() {
double return1, return2, input1, input2;
int choice;

cout << "Would you like to convert from polar to cartesian(1) or cartesian to polar?(2)" << endl;
cin >> choice;

if (choice == 1) {
   cout << "Please enter the Radius and the Angle, seperately: " << endl;
   cin >> input1 >> input2;
    const double input1const = input1;
    const double input2const = input2;
   
    polar_to_cartesian(input1const, input2const, return1, return2);
    
    cout << "The cartesian eqivalent is: " << "( " << return1 << ", " << return2 << " )" << endl; 

}else if (choice == 2) {
    cout << "Please enter the X and the Y coordinate, seperately: " << endl;
    cin >> input1 >> input2;
    
    const double input1const = input1;
    const double input2const = input2;
    
    cartesian_to_polar(input1const, input2const, return1, return2);
    cout << "The polar eqivalent is: " << "( " << return1 << ", " << return2 << " )" << endl;    



}else {
    cout << "Error, please enter a valid response." << endl;
    return -1;
}



    
    



    return 0;
}