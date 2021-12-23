set(BINDINGS_LIB bindings)

add_library(${BINDINGS_LIB} SHARED Window.cpp Window.h)
target_link_libraries(${BINDINGS_LIB}
        PUBLIC
        Qt5::Widgets
        )
add_subdirectory(bindings)
