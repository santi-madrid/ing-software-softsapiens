cmake_minimum_required(VERSION 3.10)
project(CharacterViewTests)

# Agregar Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Agregar Godot C++ bindings
include_directories(${CMAKE_SOURCE_DIR}/tarantinoverse)

# Agregar archivos fuente desde tests/
add_executable(run_tests tests/test_character_view.cpp)  # ✅ Especificar la ruta correcta
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)
