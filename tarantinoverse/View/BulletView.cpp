// View/bullet_view.cpp
#include "BulletView.h"
#include "View/EnemyView.h"
#include "View/CharacterView.h"
#include <godot_cpp/classes/area2d.hpp>

using namespace godot;

BulletView::BulletView() {
    presenter = nullptr;
    damage_power = 25; // Valor por defecto, puede ser modificado según sea necesario
}

BulletView::~BulletView() {
    if (presenter)
        delete presenter;
}

void BulletView::_ready() {
    //presenter = new BulletPresenter(get_position(), direction);
    Area2D* hitbox = get_node<Area2D>("Hitbox");
    if (hitbox) {
        hitbox->connect("body_entered", Callable(this, "_on_body_entered"));
    }
}

void BulletView::_process(double delta) {
    if (!presenter)
         presenter = new BulletPresenter(get_position(), direction);
    presenter->update(delta);
    set_position(presenter->get_position());

    if (presenter->should_destroy()) {
        queue_free();
    }
}

void BulletView::_on_body_entered(Node* body) {
    // Si el cuerpo golpeado es el mismo que disparó la bala, ignorarlo
    if (body == shooter) {
        return;
    }

    CharacterView* character = Object::cast_to<CharacterView>(body);
    if (character) {
        bool character_died = character->take_damage(damage_power); // Pasamos el daño de la bala
        if (character_died) {
            character->die(); // Solo llamamos a die() si la vida llegó a 0
        }
        queue_free(); // Destruir la bala de todas formas
    }

    EnemyView* enemy = Object::cast_to<EnemyView>(body);
    if (enemy) {
        bool power_up = character && character->is_power_up_active(); // Verificamos si el power_up está activo
        bool enemy_died = enemy->take_damage(power_up ? damage_power * 2 : damage_power); // Pasamos el daño de la bala de acuerdo a si el power_up esta activo o no
        if (enemy_died) {
            enemy->die(); // Solo llamamos a die() si la vida llegó a 0
        }
        queue_free(); // Destruir la bala de todas formas
    }
}

void BulletView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_direction", "dir"), &BulletView::set_direction);
    ClassDB::bind_method(D_METHOD("get_direction"), &BulletView::get_direction);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "direction"), "set_direction", "get_direction");

    ClassDB::bind_method(D_METHOD("_on_body_entered", "body"), &BulletView::_on_body_entered);
}
