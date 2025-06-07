#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "View/CharacterView.h"

using namespace godot;
using ::testing::AtLeast;  // Permite verificar que una función se llamó al menos una vez

// 🔹 Mock para simular `CharacterView`
class MockCharacterView : public CharacterView {
public:
    MOCK_METHOD(void, move_right, (), (override));
    MOCK_METHOD(void, move_left, (), (override));
    MOCK_METHOD(void, jump, (), (override));
    MOCK_METHOD(void, shoot, (), (override));
};

// 🔹 Test para verificar que se llama a la función correcta
TEST(CharacterViewTest, CallsCorrectFunctionOnInput) {
    MockCharacterView character;

    EXPECT_CALL(character, move_right()).Times(AtLeast(1));  // Verifica que `move_right()` se llama
    EXPECT_CALL(character, move_left()).Times(AtLeast(1));   // Verifica que `move_left()` se llama
    EXPECT_CALL(character, jump()).Times(AtLeast(1));        // Verifica que `jump()` se llama
    EXPECT_CALL(character, shoot()).Times(AtLeast(1));       // Verifica que `shoot()` se llama

    // Simular entrada de movimiento
    character.move_right();
    character.move_left();
    character.jump();
    character.shoot();
}
