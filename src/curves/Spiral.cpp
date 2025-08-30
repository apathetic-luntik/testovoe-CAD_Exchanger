#include "Spiral.h"
#include <stdexcept>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Spiral::Spiral(double radius, double step) : radius(radius), step(step) {
    if (radius <= 0) {
        throw std::invalid_argument("Radius must be a positive number");
    }
    
    if (step <= 0) {
        throw std::invalid_argument("Step must be a positive number");
    }
}

Point3D Spiral::getPoint(double t) const {
    // Параметрическое уравнение спирали в 3D пространстве
    // X(t) = r * cos(t)
    // Y(t) = r * sin(t)
    // Z(t) = (step / (2 * PI)) * t
    double z = (step / (2 * M_PI)) * t;
    return Point3D(radius * cos(t), radius * sin(t), z);
}

Point3D Spiral::getDerivative(double t) const {
    // Первая производная параметрического уравнения спирали
    // X'(t) = -r * sin(t)
    // Y'(t) = r * cos(t)
    // Z'(t) = step / (2 * PI)
    double dz = step / (2 * M_PI);
    return Point3D(-radius * sin(t), radius * cos(t), dz);
}

double Spiral::getRadius() const {
    return radius;
}

double Spiral::getStep() const {
    return step;
}

std::string Spiral::getType() const {
    return "Spiral";
}
