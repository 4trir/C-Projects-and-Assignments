#include<cmath>
#include "coordinate_conversion.h"

using namespace std;

void polar_to_cartesian(const double radius, const double angle, double &(x_Out), double &(y_out)) {
    double x, y;
    y = radius * (sin(angle));
    x = radius * (cos(angle));


    x_Out = x;
    y_out = y;

}

void cartesian_to_polar(const double x, const double y, double &(radiusOut), double &(thetaOut)) {
    double r, theta;
    r = sqrt(pow(x, 2) + pow(y, 2));
    theta = atan(y / x);

    radiusOut = r;
    thetaOut = theta;

}
