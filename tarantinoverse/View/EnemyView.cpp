#include "EnemyView.h"
#include "EnemyPresenter.h"
#include "BulletView.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>

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
    shoot_timer += delta;
    static float reset_timer = 0.0f;
    reset_timer += delta;

    if (presenter) {
        presenter->on_update(delta);
    }
    Vector2 velocity = get_velocity();
	velocity.y += gravity * delta;

    set_velocity(velocity);
	move_and_slide();

    
        if(shoot_timer >= shoot_interval) {
            shoot_timer = 0.0f;

            //Disparo
            Ref<PackedScene> bullet_scene = ResourceLoader::get_singleton()->load("res://Bullet.tscn");
            if (bullet_scene.is_valid()) {
                Node2D *bullet_instance = Object::cast_to<Node2D>(bullet_scene->instantiate());
                if (bullet_instance) {
                    Sprite2D* sprite = Object::cast_to<Sprite2D>(get_node<Sprite2D>("Sprite2D"));
                    int dir = sprite->is_flipped_h() ? 1 : -1;
                    
                    // Asignar el shooter (this) a la bala
                    BulletView* bullet = Object::cast_to<BulletView>(bullet_instance);
                    if (bullet) {
                        bullet->set_shooter(this);
                    }

                    bullet_instance->set("direction", dir);
                    bullet_instance->set_position(get_position());
                    get_parent()->add_child(bullet_instance);
                }
            }
        }
    bullets_shot++;

    reset_timer += delta;

    if (reset_timer >= 3.0f) {
        bullets_shot = 0;
        reset_timer = 0.0f;
    }

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

