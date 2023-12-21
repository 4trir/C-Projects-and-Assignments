#include<cmath>
#include<iostream>
#include "coordinate_conversion.h"

using namespace std;

int main(){
double *oPnum1, *oPnum2;
double a, b;


polar_to_cartesian(2,5, a, b);

cout <<"( " << a << ", " << b << " )" << endl;

cartesian_to_polar(2, 5, a, b);
cout <<"( " << a << ", " << b << " )" << endl;
return 0;
}