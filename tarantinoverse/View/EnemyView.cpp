#include "EnemyView.h"
#include "EnemyPresenter.h"

EnemyView::EnemyView() 
    : presenter(nullptr), initial_health(100), initial_speed(100.0f) {}

void EnemyView::_ready() {
    UtilityFunctions::print("EnemyView::_ready called");
    if (!presenter) {
        presenter = new EnemyPresenter(this, initial_health, initial_speed);
        UtilityFunctions::print("Presenter created");
    }
}

void EnemyView::_physics_process(double delta) {
    if (presenter) {
        presenter->on_update(delta);
    }
    Vector2 velocity = get_velocity();
	velocity.y += gravity * delta;

    set_velocity(velocity);
	move_and_slide();
}

void EnemyView::play_damage_animation() {
    // ejemplo visual: shake o flash
}

void EnemyView::die() {
    queue_free();  // o alguna animación antes
}

bool EnemyView::take_damage(int amount) {
    UtilityFunctions::print("take_damage called with amount: ", amount);
    if (!presenter) {
        UtilityFunctions::print("ERROR: Presenter is null!");
        return false;
    }
    bool result = presenter->take_damage(amount);
    UtilityFunctions::print("take_damage result: ", result);
    return result;
}

void EnemyView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("update_position", "pos"), &EnemyView::update_position);
    ClassDB::bind_method(D_METHOD("play_damage_animation"), &EnemyView::play_damage_animation);
}

