#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "CurveBase.h"
#include <cmath>

class Ellipse : public CurveBase {
private:
    double radiusX;
    double radiusY;

public:
    Ellipse(double radiusX, double radiusY);
    
    Point3D getPoint(double t) const override;
    Point3D getDerivative(double t) const override;
    
    double getRadiusX() const;
    double getRadiusY() const;
};

#endif // ELLIPSE_H
