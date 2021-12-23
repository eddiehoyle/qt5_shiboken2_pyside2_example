set(BINDINGS_LIB bindings)
add_library(${BINDINGS_LIB} SHARED Window.cpp Window.h)
target_link_libraries(${BINDINGS_LIB}
        PUBLIC
        Qt5::Widgets
        )
install(TARGETS ${BINDINGS_LIB} DESTINATION ${CMAKE_PROJECT_NAME}/lib)

add_subdirectory(bindings)
