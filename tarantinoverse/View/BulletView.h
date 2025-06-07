// View/bullet_view.h
#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include "Presenter/BulletPresenter.h"

using namespace godot;

class BulletView : public Node2D {
    GDCLASS(BulletView, Node2D)

private:
    BulletPresenter* presenter;
    int damage_power = 25; // Default damage power, can be modified as needed
    int direction = 1; // 1 for right, -1 for left
    Node* shooter = nullptr;  // El nodo que disparó esta bala

public:
    BulletView();
    ~BulletView();

    void _ready() override;
    void _process(double delta) override;
    void _on_body_entered(Node* body);
    void set_direction(int dir) { direction = dir; } // Setter for direction
    int get_direction() const { return direction; }
    void set_shooter(Node* node) { shooter = node; }
    Node* get_shooter() const { return shooter; }
    static void _bind_methods();
};
