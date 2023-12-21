#ifndef Scalene_TRIANGLE_H
#define Scalene_TRIANGLE_H

#include "Triangle.h"

class ScaleneTriangle : public Triangle {
public:
    bool validate() const override;
};
#endif