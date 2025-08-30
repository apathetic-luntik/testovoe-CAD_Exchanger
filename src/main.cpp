#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <ctime>
#include <cmath>

#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Spiral.h"


double randomDouble(double min, double max) {
    static std::mt19937 generator(time(nullptr));
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

std::unique_ptr<CurveBase> createRandomCurve() {
    // (0 - Circle, 1 - Ellipse, 2 - Spiral)
    int curveType = static_cast<int>(randomDouble(0, 3));
    
    switch (curveType) {
        case 0:
            return std::unique_ptr<CurveBase>(new Circle(randomDouble(1.0, 10.0)));
        
        case 1:
            return std::unique_ptr<CurveBase>(new class Ellipse(randomDouble(1.0, 10.0), randomDouble(1.0, 10.0)));
        
        case 2:
            return std::unique_ptr<CurveBase>(new class Spiral(randomDouble(1.0, 10.0), randomDouble(0.1, 5.0)));
        
        default:
            return std::unique_ptr<CurveBase>(new Circle(1.0)); // fallback
    }
}

int main()
{

    std::cout << "Creating container with random curves..." << std::endl;
      
    std::vector<std::unique_ptr<CurveBase>> curves;
    
    const int numCurves = 10;
    for (int i = 0; i < numCurves; ++i) {
        curves.push_back(createRandomCurve());
    }
    
    std::cout << "Container successfully filled with " << curves.size() << " random curves." << std::endl;
    
    for (size_t i = 0; i < curves.size(); ++i) {
        std::cout << "Curve " << i + 1 << " (" << curves[i]->getType() << "): ";
        
        double t = M_PI / 4.0;
        Point3D point = curves[i]->getPoint(t);
        Point3D derivative = curves[i]->getDerivative(t);
        
        std::cout << "point(" << point.x << ", " << point.y << ", " << point.z << "), ";
        std::cout << "derivative(" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")" << std::endl;
    }
    
    return 0;
}
