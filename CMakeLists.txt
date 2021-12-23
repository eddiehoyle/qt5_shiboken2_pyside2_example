cmake_minimum_required(VERSION 3.20)
project(bindings)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 5.12 CONFIG
        HINTS /usr/local/opt/qt@5/lib/cmake
        REQUIRED COMPONENTS Core Gui Widgets)

find_package(PySide2 CONFIG
        HINTS /usr/local/opt/pyside@2/lib/cmake/PySide2-5.15.2
        REQUIRED)

find_package(Shiboken2 CONFIG
        HINTS /usr/local/opt/pyside@2/lib/cmake/Shiboken2-5.15.2
        REQUIRED)

#message(STATUS "PYSIDE_PYTHONPATH  : ${PYSIDE_PYTHONPATH}")
#message(STATUS "PYSIDE_TYPESYSTEMS : ${PYSIDE_TYPESYSTEMS}")
#message(STATUS "PYSIDE_GLUE        : ${PYSIDE_GLUE}")
#message(STATUS "SHIBOKEN_BUILD_TYPE         : ${SHIBOKEN_BUILD_TYPE}")
#message(STATUS "SHIBOKEN_PYTHON_INTERPRETER : ${SHIBOKEN_PYTHON_INTERPRETER}")
#message(STATUS "SHIBOKEN_SHARED_LIBRARY_DIR : ${SHIBOKEN_SHARED_LIBRARY_DIR}")
#message(STATUS "SHIBOKEN_PYTHON_MODULE_DIR  : ${SHIBOKEN_PYTHON_MODULE_DIR}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_subdirectory(cpp)