#ifndef CIRCLE_H
#define CIRCLE_H

#include "CurveBase.h"
#include <cmath>

class Circle : public CurveBase {
private:
    double radius;

public:
    Circle(double radius);
    
    Point3D getPoint(double t) const override;
    Point3D getDerivative(double t) const override;
    
    double getRadius() const;
};

#endif // CIRCLE_H
