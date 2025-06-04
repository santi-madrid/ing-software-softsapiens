#include "ObjectView.h"
#include "View/CharacterView.h"

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

ObjectView::ObjectView() {
    presenter = nullptr;
}

ObjectView::~ObjectView() {
    if (presenter)
        delete presenter;
}

void ObjectView::_ready() {
    // Suponemos que estos datos pueden ser definidos por export variables o setters en GDScript
    Vector2 start_pos = get_position();
    ObjectType type = ObjectType::COIN; // Cambiar esto si usás export o parsing
    int value = 1;

    presenter = new ObjectPresenter(start_pos, type, value);

    Area2D* hitbox = get_node<Area2D>("Hitbox");
    if (hitbox) {
        hitbox->connect("body_entered", Callable(this, "_on_body_entered"));
    }
}

void ObjectView::_process(double delta) {
    if (!presenter)
        return;

    if (presenter->is_collected()) {
        queue_free();
    }
}

void ObjectView::_on_body_entered(Node* body) {
    // Acá podés verificar si el body es un jugador, por ejemplo
    CharacterView* player = Object::cast_to<CharacterView>(body);
    if (player) {
        presenter->collect();
        // player->add_score(presenter->get_value()); // Ejemplo de interacción
    }
}
#include <godot_cpp/classes/node.hpp>
void ObjectView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_body_entered", "body"), &ObjectView::_on_body_entered);
}
