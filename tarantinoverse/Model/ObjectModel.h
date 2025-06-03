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
    float lifetime; // en segundos

public:
    ObjectModel(godot::Vector2 start_pos, ObjectType obj_type, int val, float life);

    void collect();
    bool is_collected() const;
    ObjectType get_type() const;
    int get_value() const;
    godot::Vector2 get_position() const;
    bool expired(float elapsed_time) const;
};
