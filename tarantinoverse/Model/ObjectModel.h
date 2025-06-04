// Model/ObjectModel.h
#pragma once

#include <godot_cpp/variant/vector2.hpp>

enum class ObjectType {
    COIN,
    HEALTH,
    POWERUP,
    CUSTOM
};

class ObjectModel {
private:
    godot::Vector2 position;
    ObjectType type;
    int value;
    bool collected;

public:
    ObjectModel(godot::Vector2 start_pos, ObjectType obj_type, int val);

    void collect();
    bool is_collected() const;
    ObjectType get_type() const;
    int get_value() const;
    godot::Vector2 get_position() const;
};
