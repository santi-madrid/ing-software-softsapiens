// Presenter/CharacterPresenter.h
#pragma once
#include "Model/CharacterModel.h"

class CharacterPresenter {
public:
    CharacterPresenter(CharacterView* v, int hp, float speed);
    ~CharacterPresenter();

    bool take_damage(int amount);
    int get_health() const;
    void set_speed(double p_speed);
    double get_speed() const;

private:
    CharacterModel model;
    CharacterView* view;
};