#include <gtest/gtest.h>
#include "View/CharacterView.h"
#include <godot_cpp/classes/input.hpp>

using namespace godot;

TEST(CharacterViewTest, MovementAndActions) {
    CharacterView character;
    character.set_position(Vector2(0, 0)); // Posición inicial
    character.set_speed(200); // Velocidad positiva

    float delta_time = 1.0f; // Simula 1 segundo de movimiento

    // 🔹 Simular movimiento a la derecha
    Input::get_singleton()->action_press("ui_right");
    character._physics_process(delta_time);
    EXPECT_GT(character.get_position().x, 0); // Debe moverse a la derecha

    // 🔹 Simular movimiento a la izquierda
    Input::get_singleton()->action_press("ui_left");
    character._physics_process(delta_time);
    EXPECT_LT(character.get_position().x, 0); // Debe moverse a la izquierda

    // 🔹 Simular salto
    Input::get_singleton()->action_press("ui_up");
    character._physics_process(delta_time);
    EXPECT_LT(character.get_position().y, 0); // Debe moverse hacia arriba

    // 🔹 Simular disparo
    Input::get_singleton()->action_press("ui_select");
    EXPECT_TRUE(character.has_node("Bullet")); // Verifica que se creó una bala
}
