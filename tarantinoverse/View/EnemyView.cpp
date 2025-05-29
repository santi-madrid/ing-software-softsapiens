#include "EnemyView.h"
#include "EnemyPresenter.h"
// EnemyView.cpp
void EnemyView::_ready() {
    // Ready callback, quizás no haga nada por ahora
}

void EnemyView::_physics_process(double delta) {
    if (presenter) {
        presenter->on_update(delta);
    }
}

void EnemyView::play_damage_animation() {
    // ejemplo visual: shake o flash
}

void EnemyView::die() {
    queue_free();  // o alguna animación antes
}

void EnemyView::_bind_methods() {
    // Registrás métodos para GDScript si fuera necesario, por ejemplo:
    ClassDB::bind_method(D_METHOD("update_position", "pos"), &EnemyView::update_position);
    ClassDB::bind_method(D_METHOD("play_damage_animation"), &EnemyView::play_damage_animation);
}

