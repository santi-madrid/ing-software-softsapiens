#include "CharacterView.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/rectangle_shape2d.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include "Presenter/CharacterPresenter.h"


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

CharacterView::CharacterView() {
	// Initialize any variables here.
	time_passed = 0.0;
	time_emit = 0.0;
	amplitude = 10.0;
	speed = presenter.get_speed();

    // Crear y agregar CollisionShape2D
    CollisionShape2D *collision_shape = memnew(CollisionShape2D);
    Ref<RectangleShape2D> shape = memnew(RectangleShape2D);
    shape->set_size(Vector2(32, 32)); // Tamaño del cuerpo del personaje
    collision_shape->set_shape(shape);
    add_child(collision_shape);
}

CharacterView::~CharacterView() {
	// Add your cleanup here.
}

void CharacterView::_physics_process(double p_delta) {
	Input* input = Input::get_singleton();
	Vector2 velocity = get_velocity();
	velocity.y += gravity * p_delta;

	// Movimiento horizontal con teclas (opcional)
	velocity.x = 0;

	float current_speed = presenter.get_speed();

	if (input->is_action_pressed("ui_right")) {
		velocity.x += current_speed;
	}
	if (input->is_action_pressed("ui_left")) {
		velocity.x -= current_speed;
	}

	// Salto
	if (is_on_floor() && input->is_action_just_pressed("ui_up")) {
		velocity.y = jump_speed;
	}

	if (input->is_action_just_pressed("ui_select")) { // Space por defecto en Godot
    Ref<PackedScene> bullet_scene = ResourceLoader::get_singleton()->load("res://Bullet.tscn");

    if (bullet_scene.is_valid()) {
        Node2D *bullet_instance = Object::cast_to<Node2D>(bullet_scene->instantiate());

        if (bullet_instance) {
            // Posicionamos la bala en la posición del personaje
            bullet_instance->set_position(get_position());

            // Agregamos al árbol de nodos
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
    presenter.set_speed(p_speed);  // Le pasa la velocidad al model
}

double CharacterView::get_speed() const {
    return presenter.get_speed();  // Lee la velocidad del model
}

