#include "Ellipse.h"
#include <stdexcept>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Ellipse::Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) {
    if (radiusX <= 0 || radiusY <= 0) {
        throw std::invalid_argument("Радиусы должны быть положительными числами");
    }
}

Point3D Ellipse::getPoint(double t) const {
    // Параметрическое уравнение эллипса в плоскости XoY
    // X(t) = rx * cos(t)
    // Y(t) = ry * sin(t)
    // Z(t) = 0
    return Point3D(radiusX * cos(t), radiusY * sin(t), 0.0);
}

Point3D Ellipse::getDerivative(double t) const {
    // Первая производная параметрического уравнения эллипса
    // X'(t) = -rx * sin(t)
    // Y'(t) = ry * cos(t)
    // Z'(t) = 0
    return Point3D(-radiusX * sin(t), radiusY * cos(t), 0.0);
}

double Ellipse::getRadiusX() const {
    return radiusX;
}

double Ellipse::getRadiusY() const {
    return radiusY;
}
