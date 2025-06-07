cmake_minimum_required(VERSION 3.10)
project(CharacterViewTests)

# Agregar Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Agregar Godot C++ bindings
set(GODOT_CPP_PATH "${CMAKE_SOURCE_DIR}/godot-cpp")  # ✅ Ruta de los bindings
include_directories(${GODOT_CPP_PATH}/include)

# Agregar archivos fuente desde tests/
add_executable(run_tests tests/test_character_view.cpp)
target_link_libraries(run_tests ${GTEST_LIBRARIES} pthread)
