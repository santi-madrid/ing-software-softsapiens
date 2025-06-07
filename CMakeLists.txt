cmake_minimum_required(VERSION 3.10)

project(CharacterViewTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agregar Google Test y Google Mock
set(GMock_DIR "/usr/lib/cmake/GTest")  # 🔹 Agrega la ruta de GMock
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

# Agregar directorios de código fuente
include_directories(${CMAKE_SOURCE_DIR}/tarantinoverse/View)

# Agregar los archivos de prueba
add_executable(test_character_view tests/test_character_view.cpp)

# Vincular Google Test y Google Mock con el ejecutable
target_link_libraries(test_character_view GTest::GTest GTest::Main GMock::GMock GMock::Main)
