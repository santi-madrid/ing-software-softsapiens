cmake_minimum_required(VERSION 3.10)

project(tarantinoverse)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agregar Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Agregar directorios de código fuente
include_directories(${CMAKE_SOURCE_DIR}/tarantinoverse)  # 🔹 Agrega la carpeta tarantinoverse/
include_directories(${CMAKE_SOURCE_DIR}/tarantinoverse/Model)
include_directories(${CMAKE_SOURCE_DIR}/tarantinoverse/Presenter)
include_directories(${CMAKE_SOURCE_DIR}/tarantinoverse/View)

# Agregar los archivos de prueba
add_executable(test_character_view tests/test_character_view.cpp)

# Vincular Google Test con el ejecutable
target_link_libraries(test_character_view GTest::GTest GTest::Main)
