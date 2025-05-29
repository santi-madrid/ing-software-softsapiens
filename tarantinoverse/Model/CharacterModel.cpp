#include "CharacterModel.h"

CharacterModel::CharacterModel() {
    speed = 250.0;
}

void CharacterModel::set_speed(float p_speed) {
    speed = p_speed;
}

float CharacterModel::get_speed() const {
    return speed;
}
