#include <gtest/gtest.h>
#include <godot_cpp/variant/vector2.hpp>  // Asegurar que Vector2 esté disponible
#include "../tarantinoverse/View/CharacterView.h"  // Ajusta la ruta según tu estructura

using namespace godot;  // Para evitar escribir godot::Vector2 cada vez

class CharacterViewTest : public ::testing::Test {
protected:
    CharacterView character;

    void SetUp() override {
        character.set_position(Vector2(0, 0)); // Posición inicial
        character.set_speed(200.0f); // Velocidad estándar
    }
};

// Test: Movimiento hacia la derecha
TEST_F(CharacterViewTest, MoveRight) {
    character.set_position(Vector2(0, 0));
    character.set_speed(200.0f);
    
    character.set_position(character.get_position() + Vector2(character.get_speed(), 0));

    EXPECT_EQ(character.get_position().x, 200);
}

// Test: Movimiento hacia la izquierda
TEST_F(CharacterViewTest, MoveLeft) {
    character.set_position(Vector2(200, 0));
    character.set_speed(200.0f);
    
    character.set_position(character.get_position() - Vector2(character.get_speed(), 0));

    EXPECT_EQ(character.get_position().x, 0);
}
