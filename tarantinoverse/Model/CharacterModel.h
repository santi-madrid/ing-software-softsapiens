// Model/CharacterModel.h
#pragma once
class CharacterModel {
private:
    float speed;
    int health;
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

    int get_max_health() const;
};
