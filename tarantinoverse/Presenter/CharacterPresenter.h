// Presenter/CharacterPresenter.h
#pragma once
#include "Model/CharacterModel.h"

class CharacterPresenter {
public:
    CharacterPresenter();
    ~CharacterPresenter();

    void set_speed(double p_speed);
    double get_speed() const;

private:
    CharacterModel* model;
};