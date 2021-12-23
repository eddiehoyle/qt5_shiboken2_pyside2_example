set(GENERATED_SOURCES
        ${CMAKE_CURRENT_BINARY_DIR}/bindings/bindings_module_wrapper.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/bindings/window_wrapper.cpp)
set(WRAPPED_HEADER ${CMAKE_CURRENT_LIST_DIR}/Wrapped.h)
set(TYPESYSTEM_FILE ${CMAKE_CURRENT_LIST_DIR}/Wrapped.xml)
set(SHIBOKEN_PATH /usr/local/opt/pyside@2/bin/shiboken2)
set(SHIBOKEN_OPTIONS
        --generator-set=shiboken
        --enable-parent-ctor-heuristic
        --enable-pyside-extensions
        --enable-return-value-heuristic
        --use-isnull-as-nb_nonzero
        --avoid-protected-hack
        --output-directory=${CMAKE_CURRENT_BINARY_DIR}
        -T${CMAKE_CURRENT_LIST_DIR}
        -T${PYSIDE_TYPESYSTEMS}
        -I${PROJECT_SOURCE_DIR}/cpp
        -I/usr/local/opt/qt@5/include
        -I/usr/local/opt/qt@5/include/QtWidgets
        -I/usr/local/opt/qt@5/include/QtGui
        -I/usr/local/opt/qt@5/include/QtCore
        )

add_custom_command(
        OUTPUT ${GENERATED_SOURCES}
        COMMAND ${SHIBOKEN_PATH} ${SHIBOKEN_OPTIONS} ${WRAPPED_HEADER} ${TYPESYSTEM_FILE}
        DEPENDS ${WRAPPED_HEADER} ${TYPESYSTEM_FILE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running generator for ${TYPESYSTEM_FILE}."
)

# Generator
set(BINDINGS_GEN bindings_gen)
add_custom_target(${BINDINGS_GEN} DEPENDS ${GENERATED_SOURCES})
add_dependencies(${BINDINGS_GEN} ${BINDINGS_LIB})

# Python
set(BINDINGS_PYLIB bindings_pylib)
add_library(${BINDINGS_PYLIB} SHARED ${GENERATED_SOURCES})
get_target_property(PYSIDE2_INCLUDE_DIR PySide2::pyside2 INTERFACE_INCLUDE_DIRECTORIES)
target_include_directories(${BINDINGS_PYLIB}
        PRIVATE
            ${PROJECT_SOURCE_DIR}/cpp
            ${PYSIDE2_INCLUDE_DIR}/QtCore
            ${PYSIDE2_INCLUDE_DIR}/QtWidgets
            ${PYSIDE2_INCLUDE_DIR}/QtGui
        )
target_link_libraries(${BINDINGS_PYLIB}
        PRIVATE
            Qt5::Widgets
            PySide2::pyside2
            Shiboken2::libshiboken
            ${BINDINGS_LIB}
        )
set_target_properties(${BINDINGS_PYLIB}
        PROPERTIES
            OUTPUT_NAME bindings
            SUFFIX ".so"
            PREFIX ""
        )
add_dependencies(${BINDINGS_PYLIB} ${BINDINGS_GEN})
install(TARGETS ${BINDINGS_PYLIB}
        DESTINATION ${CMAKE_PROJECT_NAME}/python)

# Example runner
get_target_property(BINDINGS_MODULE ${BINDINGS_PYLIB} OUTPUT_NAME)
configure_file(main.py.in main.py @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/main.py
        DESTINATION ${CMAKE_PROJECT_NAME}/python)
