// Model/CharacterModel.h
#pragma once

#include "../Core/ObjectType.h"

class CharacterModel {
private:
    float speed;
    int health;
    int max_health;
    int score;
public:
    CharacterModel(int initial_health, int initial_score, float movement_speed);

    void set_health(int p_health);
    int get_health() const;
    void set_score(int p_score);
    int get_score() const;
    bool take_damage(int amount);
    bool is_dead() const;
    float get_speed() const;
    void set_speed(float s);
    void set_max_health(int p_max_health);
    int get_max_health() const;
};
