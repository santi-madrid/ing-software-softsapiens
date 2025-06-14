#include "CharacterModel.h"
#include <algorithm>

CharacterModel::CharacterModel(int initial_health, float movement_speed) {
    health = initial_health;
    speed = movement_speed;
}

void CharacterModel::set_health(int p_health){
    health = p_health;
}

int CharacterModel::get_health() const{
    return health;
}

bool CharacterModel::take_damage(int amount) { 
        health = std::max(0, health - amount);
        return is_dead();
}

bool CharacterModel::is_dead() const{
    return health <= 0;
}

void CharacterModel::set_speed(float p_speed) {
    speed = p_speed;
}

float CharacterModel::get_speed() const {
    return speed;
}
