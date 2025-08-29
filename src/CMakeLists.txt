cmake_minimum_required(VERSION 3.16)

project(testovoe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление поддиректории с библиотекой кривых
add_subdirectory(curves)

add_executable(testovoe main.cpp)

# Связывание исполняемого файла с библиотекой кривых
target_link_libraries(testovoe PRIVATE curves)

include(GNUInstallDirs)
install(TARGETS testovoe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
