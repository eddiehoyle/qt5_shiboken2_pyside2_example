cmake_minimum_required(VERSION 3.20)
project(bindings)

# Setup
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Distribution
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH ${CMAKE_CURRENT_BINARY_DIR} /Users/eddiehoyle/Code/cpp/bindings/cmake-build-debug/cpp)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Qt
set(CMAKE_AUTOMOC ON)

find_package(Qt5 5.12 CONFIG
        HINTS /usr/local/opt/qt@5/lib/cmake
        REQUIRED COMPONENTS Core Gui Widgets)

find_package(PySide2 CONFIG
        HINTS /usr/local/opt/pyside@2/lib/cmake/PySide2-5.15.2
        REQUIRED)

find_package(Shiboken2 CONFIG
        HINTS /usr/local/opt/pyside@2/lib/cmake/Shiboken2-5.15.2
        REQUIRED)

# Temp
#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist)

add_subdirectory(cpp)