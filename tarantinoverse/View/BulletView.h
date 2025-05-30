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

public:
    BulletView();
    ~BulletView();

    void _ready() override;
    void _process(double delta) override;
    void _on_body_entered(Node* body);

    static void _bind_methods();
};
