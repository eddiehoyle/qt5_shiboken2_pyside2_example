# Qt5, Shiboken2 and PySide2

A reference project for building OSX homebrew installed Qt5 applications in C++ and generating PySide2 Python bindings using Shiboken2.

## Setup
Start by installing dependencies:
```zsh
% brew install python@3.9 qt@5 pyside@2 cmake@3.20
```

## Building

```zsh
% mkdir build && cd build
% cmake ..
% cmake --build .
% cmake --install . --prefix=<your install directory> --config Release
```

```zsh
% cd <your install directory>
% python3 main.py
```

For OSX only at the moment.

Don't forget to test using `python3` ya dangus.