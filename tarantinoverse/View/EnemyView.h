// EnemyView.h
#pragma once

#include <godot_cpp/classes/character_body2d.hpp>
#include "Presenter/EnemyPresenter.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/vector2.hpp>

using namespace godot;

class EnemyView : public CharacterBody2D {
    GDCLASS(EnemyView, CharacterBody2D);

private:
    EnemyPresenter* presenter = nullptr;

public:
    void _ready() override;
    void _physics_process(double delta) override;

    void set_presenter(EnemyPresenter* p) { presenter = p; }
    void update_position(Vector2 new_pos) { set_position(new_pos); }
    void play_damage_animation();
    void die();

protected:
    static void _bind_methods(); 
};
