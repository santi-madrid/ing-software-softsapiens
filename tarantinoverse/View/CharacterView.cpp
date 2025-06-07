#include "CharacterView.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/rectangle_shape2d.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/camera2d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include "Presenter/CharacterPresenter.h"

// Forward declaration
class CharacterPresenter;

using namespace godot;

const float step_size = 32.0f;

void CharacterView::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_amplitude"), &CharacterView::get_amplitude);
	ClassDB::bind_method(D_METHOD("set_amplitude", "p_amplitude"), &CharacterView::set_amplitude);

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "amplitude"), "set_amplitude", "get_amplitude");

	ClassDB::bind_method(D_METHOD("get_speed"), &CharacterView::get_speed);
    ClassDB::bind_method(D_METHOD("set_speed", "p_speed"), &CharacterView::set_speed);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed", PROPERTY_HINT_RANGE, "0,500,0.1"), "set_speed", "get_speed");

	ADD_SIGNAL(MethodInfo("position_changed", PropertyInfo(Variant::OBJECT, "node"), PropertyInfo(Variant::VECTOR2, "new_pos")));
}

CharacterView::CharacterView()
	: presenter(nullptr),
      initial_health(100), 
      initial_speed(100.0f),
      time_passed(0.0),
      time_emit(0.0),
      amplitude(10.0),
      speed(100.0) // Set a default speed instead of using presenter
{
    if (!presenter) {
        presenter = new CharacterPresenter(this, initial_health, initial_speed);
        UtilityFunctions::print("Presenter created");
    }// Constructor body can remain empty or handle other initialization
}

CharacterView::~CharacterView() {
	// Add your cleanup here.
}

void CharacterView::_physics_process(double p_delta) {
    Input* input = Input::get_singleton();
    Vector2 velocity = get_velocity();
    velocity.y += gravity * p_delta;

    if (!camera) {
        if (has_node("Camera2D")) {
            camera = get_node<Camera2D>("Camera2D");
            camera->make_current();
            last_camera_x = get_global_position().x;
        }
    }

    velocity.x = 0;
    float current_speed = speed; // Valor por defecto

    if (presenter) {
        current_speed = presenter->get_speed();
    }

    if (input->is_action_pressed("ui_right")) {
        velocity.x += current_speed;
    }
    if (input->is_action_pressed("ui_left")) {
        velocity.x -= current_speed;
    }

    if (is_on_floor() && input->is_action_just_pressed("ui_up")) {
        velocity.y = jump_speed;
    }

    AnimatedSprite2D* sprite = Object::cast_to<AnimatedSprite2D>(get_node<AnimatedSprite2D>("AnimatedSprite2D"));
    if (velocity.x != 0) {
        if (!sprite->is_playing() || sprite->get_animation() != String("walk")) {
            sprite->play("walk");
        }
        sprite->set_flip_h(velocity.x < 0);
    } else {
        if (!sprite->is_playing() || sprite->get_animation() != StringName("idle")) {
            sprite->play("idle");
        }
    }

    if (input->is_action_just_pressed("ui_select")) {
        Ref<PackedScene> bullet_scene = ResourceLoader::get_singleton()->load("res://Bullet.tscn");
        if (bullet_scene.is_valid()) {
            Node2D *bullet_instance = Object::cast_to<Node2D>(bullet_scene->instantiate());
            if (bullet_instance) {
                AnimatedSprite2D* sprite = Object::cast_to<AnimatedSprite2D>(get_node<AnimatedSprite2D>("AnimatedSprite2D"));
                int dir = sprite->is_flipped_h() ? -1 : 1; // Determinar la dirección del disparo
                bullet_instance->set("direction", dir); // Asignar la dirección al modelo de bala
                bullet_instance->set_position(get_position());
                get_parent()->add_child(bullet_instance);
            }
        }
    }

    set_velocity(velocity);
    move_and_slide();
}	

void CharacterView::set_amplitude(const double p_amplitude) {
	amplitude = p_amplitude;
}

double CharacterView::get_amplitude() const {
	return amplitude;
}

void CharacterView::set_speed(const double p_speed) {
    if (presenter) {
        presenter->set_speed(p_speed);
    } else {
        speed = p_speed;
    }
}

double CharacterView::get_speed() const {
    if (presenter) {
        return presenter->get_speed();
    } else {
        return speed;
    }
}

void CharacterView::set_presenter(CharacterPresenter* p) {
	presenter = p;
	if (presenter) {
		initial_health = presenter->get_health();
		initial_speed = presenter->get_speed();
	}
}

bool CharacterView::take_damage(int amount) {
    UtilityFunctions::print("take_damage called with amount: ", amount);
    if (!presenter) {
        UtilityFunctions::print("ERROR: Presenter is null!");
        return false;
    }
    bool result = presenter->take_damage(amount);
    UtilityFunctions::print("take_damage result: ", result);
    return result;
}

void CharacterView::die() {
	queue_free();
}

