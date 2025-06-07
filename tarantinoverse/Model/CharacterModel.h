// Model/CharacterModel.h
#pragma once
class CharacterModel {
private:
    float speed;
    int health;
public:
    CharacterModel(int initial_health, float movement_speed);

    void set_health(int p_health);
    int get_health() const;
    bool take_damage(int amount);
    bool is_dead() const;
    float get_speed() const;
    void set_speed(float s);
};
