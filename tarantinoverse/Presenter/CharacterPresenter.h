// Presenter/CharacterPresenter.h
#pragma once

namespace godot {
    class CharacterView;
}

#include "Model/CharacterModel.h"

class CharacterPresenter {
public:
    CharacterPresenter(godot::CharacterView* view, int hp, float speed);
    ~CharacterPresenter();

    bool take_damage(int amount);
    int get_health() const;
    void set_speed(double p_speed);
    double get_speed() const;
    int get_max_health() const;

private:
    CharacterModel model;
    godot::CharacterView* view;
};