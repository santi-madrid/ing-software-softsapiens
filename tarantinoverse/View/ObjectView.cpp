// ObjectView.cpp
#include "ObjectView.h"
#include "View/CharacterView.h"

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

ObjectView::ObjectView() {
    presenter = nullptr;
    object_type = static_cast<int>(ObjectType::COIN); // por defecto
}

ObjectView::~ObjectView() {
    if (presenter)
        delete presenter;
}

void ObjectView::set_object_type(int type) {
    object_type = type;
}

int ObjectView::get_object_type() const {
    return object_type;
}

void ObjectView::_ready() {
    Vector2 start_pos = get_position();
    ObjectType type = static_cast<ObjectType>(object_type);
    int value = 1;

    //Crea un Object con Factory Method
    presenter = ObjectPresenter::create(start_pos, type, value);

    Sprite2D* sprite = get_node<Sprite2D>("Sprite");
    if (sprite) {
        Ref<Texture2D> texture;

        switch (type) {
            case ObjectType::COIN:
                texture = ResourceLoader::get_singleton()->load("res://Objects Sprites/coin-gold.png");
                break;
            case ObjectType::HEALTH:
                texture = ResourceLoader::get_singleton()->load("res://Objects Sprites/heart.png");
                break;
            case ObjectType::POWERUP:
                texture = ResourceLoader::get_singleton()->load("res://Objects Sprites/jewel.png");
                break;
            default:
                break;
        }

        if (texture.is_valid()) {
            sprite->set_texture(texture);
        } else {
            UtilityFunctions::printerr("No se pudo cargar textura para tipo de objeto");
        }
    }

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
    CharacterView* character_view = Object::cast_to<CharacterView>(body);
    if (character_view && presenter) {
        // Se delega al Presenter del personaje qué hacer con el objeto recolectado
        CharacterPresenter* character_presenter = character_view->get_presenter();
        if (character_presenter) {
            character_presenter->collect_object(
                presenter->get_type(),
                presenter->get_value()
            );
        }
        presenter->collect();
    }
}

void ObjectView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_body_entered", "body"), &ObjectView::_on_body_entered);

    ClassDB::bind_method(D_METHOD("set_object_type", "type"), &ObjectView::set_object_type);
    ClassDB::bind_method(D_METHOD("get_object_type"), &ObjectView::get_object_type);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "object_type", PROPERTY_HINT_ENUM, "Coin,Health,PowerUp"),
                 "set_object_type", "get_object_type");
}
