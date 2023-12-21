
#ifndef COORDINATE_CONVERSION_H
#define COORDINATE_CONVERSION_H

/**
 * @brief Converts a polar coordinate to cartesian
 * 
 * @param radius The value of the radius
 * @param angle The value of the angle in radians 
 */
void polar_to_cartesian(const double radius, const double angle, double &(x_Out), double &(y_out));



/**
 * @brief Converts a cartesian coordinate to polar
 * 
 * @param x The X value
 * @param y The Y value
 */
void cartesian_to_polar(const double x, const double y, double &(radiusOut), double &(thetaOut));



#endif

