#include "CharacterModel.h"
#include <algorithm>

CharacterModel::CharacterModel(int initial_health, int initial_score, float movement_speed) {
    health = initial_health;
    max_health = 100;
    score = initial_score;
    speed = movement_speed;
}

void CharacterModel::set_health(int p_health){
    health = p_health;
}

int CharacterModel::get_health() const{
    return health;
}

void CharacterModel::set_score(int p_score){
    score = p_score;
}

int CharacterModel::get_score() const{
    return score;
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

void CharacterModel::set_max_health(int p_max_health)
{
    max_health = p_max_health;
}

int CharacterModel::get_max_health() const {
    return max_health;
}