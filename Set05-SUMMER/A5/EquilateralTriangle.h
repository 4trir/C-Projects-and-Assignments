#ifndef EQUILATERAl_TRIANGLE_H
#define EQUILATERAL_TRIANGLE_H

#include "Triangle.h"

class EquilateralTriangle : public Triangle {
public:
    bool validate() const override;
};
#endif