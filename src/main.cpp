#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif

#include "curves/Circle.h"
#include "curves/Ellipse.h"
#include "curves/Spiral.h"

using namespace std;

double randomDouble(double min, double max) {
    static mt19937 generator(time(nullptr));
    uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}

unique_ptr<CurveBase> createRandomCurve() {
    // (0 - Circle, 1 - Ellipse, 2 - Spiral)
    int curveType = static_cast<int>(randomDouble(0, 3));
    
    switch (curveType) {
        case 0:
            return unique_ptr<CurveBase>(new Circle(randomDouble(1.0, 10.0)));
        
        case 1:
            return unique_ptr<CurveBase>(new class Ellipse(randomDouble(1.0, 10.0), randomDouble(1.0, 10.0)));
        
        case 2:
            return unique_ptr<CurveBase>(new class Spiral(randomDouble(1.0, 10.0), randomDouble(0.1, 5.0)));
        
        default:
            return unique_ptr<CurveBase>(new Circle(1.0)); // fallback
    }
}

int main()
{

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #else
        setlocale(LC_ALL, "ru_RU.UTF-8");
    #endif


    std::cout << u8"Создание контейнера со случайными кривыми..." << std::endl;
      
    vector<unique_ptr<CurveBase>> curves;
    
    const int numCurves = 10;
    for (int i = 0; i < numCurves; ++i) {
        curves.push_back(createRandomCurve());
    }
    
    cout << "Контейнер успешно заполнен " << curves.size() << " случайными кривыми." << endl;
    
    for (size_t i = 0; i < curves.size(); ++i) {
        cout << "Кривая " << i + 1 << ": ";
        
        Point3D point = curves[i]->getPoint(0);
        Point3D derivative = curves[i]->getDerivative(0);
        
        cout << "точка(" << point.x << ", " << point.y << ", " << point.z << "), ";
        cout << "производная(" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")" << endl;
    }
    
    return 0;
}
