// Presenter/ObjectPresenter.h
#pragma once

#include "Model/ObjectModel.h"

class ObjectPresenter {
private:
    ObjectModel* model;
    float time_alive;

public:
    ObjectPresenter(godot::Vector2 start_pos, ObjectType obj_type, int value);
    ~ObjectPresenter();

    void collect();
    bool is_collected() const;
    ObjectType get_type() const;
    int get_value() const;
    godot::Vector2 get_position() const;
};
