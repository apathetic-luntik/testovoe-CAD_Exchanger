# CMakeLists.txt для библиотеки кривых

# Создание статической библиотеки curves из исходных файлов
add_library(curves
    CurveBase.h
    Circle.h
    Circle.cpp
    Ellipse.h
    Ellipse.cpp
    Spiral.h
    Spiral.cpp
)

# Установка свойств библиотеки (C++11 стандарт)
target_compile_features(curves PUBLIC cxx_std_11)

# Установка директории включения для библиотеки
target_include_directories(curves PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
