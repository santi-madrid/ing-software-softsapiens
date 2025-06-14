// Model/ObjectModel.cpp
#include "ObjectModel.h"

using namespace godot;

ObjectModel::ObjectModel(Vector2 start_pos, ObjectType obj_type, int val)
    : position(start_pos), type(obj_type), value(val), collected(false) {}

void ObjectModel::collect() {
    collected = true;
}

bool ObjectModel::is_collected() const {
    return collected;
}

ObjectType ObjectModel::get_type() const {
    return type;
}

int ObjectModel::get_value() const {
    return value;
}

Vector2 ObjectModel::get_position() const {
    return position;
}
