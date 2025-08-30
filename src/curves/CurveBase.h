#ifndef CURVEBASE_H
#define CURVEBASE_H

#include <string>

struct Point3D {
    double x, y, z;
    
    Point3D(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}
};

class CurveBase {
public:
    virtual ~CurveBase() = default;
    
    virtual Point3D getPoint(double t) const = 0;
    virtual Point3D getDerivative(double t) const = 0;
    virtual std::string getType() const = 0;
};

#endif // CURVEBASE_H
