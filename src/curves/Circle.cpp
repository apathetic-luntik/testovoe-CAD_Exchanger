#include "Circle.h"
#include <stdexcept>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double radius) : radius(radius) {
    if (radius <= 0) {
        throw std::invalid_argument("Radius must be a positive number");
    }
}

Point3D Circle::getPoint(double t) const {
    // Параметрическое уравнение окружности в плоскости XoY
    // X(t) = r * cos(t)
    // Y(t) = r * sin(t)
    // Z(t) = 0
    return Point3D(radius * cos(t), radius * sin(t), 0.0);
}

Point3D Circle::getDerivative(double t) const {
    // Первая производная параметрического уравнения окружности
    // X'(t) = -r * sin(t)
    // Y'(t) = r * cos(t)
    // Z'(t) = 0
    return Point3D(-radius * sin(t), radius * cos(t), 0.0);
}

double Circle::getRadius() const {
    return radius;
}

std::string Circle::getType() const {
    return "Circle";
}
