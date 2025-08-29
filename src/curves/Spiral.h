#ifndef SPIRAL_H
#define SPIRAL_H

#include "CurveBase.h"
#include <cmath>

class Spiral : public CurveBase {
private:
    double radius;  // Радиус спирали
    double step;    // Шаг спирали (расстояние между витками по оси Z)

public:
    Spiral(double radius, double step);
    
    Point3D getPoint(double t) const override;
    Point3D getDerivative(double t) const override;
    
    double getRadius() const;
    double getStep() const;
};

#endif // SPIRAL_H
