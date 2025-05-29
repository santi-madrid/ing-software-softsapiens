// View/bullet_view.cpp
#include "BulletView.h"
#include "View/EnemyView.h"
#include <godot_cpp/classes/area2d.hpp>

using namespace godot;

BulletView::BulletView() {
    presenter = nullptr;
}

BulletView::~BulletView() {
    if (presenter)
        delete presenter;
}

void BulletView::_ready() {
    presenter = new BulletPresenter(get_position());
    Area2D* hitbox = get_node<Area2D>("Hitbox");
    if (hitbox) {
        hitbox->connect("body_entered", Callable(this, "_on_body_entered"));
    }
}

void BulletView::_process(double delta) {
    if (!presenter)
        return;

    presenter->update(delta);
    set_position(presenter->get_position());

    if (presenter->should_destroy()) {
        queue_free();
    }
}

void BulletView::_on_body_entered(Node* body) {
    EnemyView* enemy = Object::cast_to<EnemyView>(body);
    if (enemy) {
        enemy->die();     // Matar al enemigo
        queue_free();     // Destruir la bala
    }
}

void BulletView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_body_entered", "body"), &BulletView::_on_body_entered);
}
