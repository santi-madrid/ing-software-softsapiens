// Model/bullet_model.cpp
#include "BulletModel.h"

using namespace godot;


void BulletModel::move(float delta) {
    float move_step = speed * delta * direction;
    position.x += move_step;
    distance_traveled += fabs(move_step);
}

bool BulletModel::should_destroy() const {
    return distance_traveled >= max_distance;
}

Vector2 BulletModel::get_position() const {
    return position;
}
