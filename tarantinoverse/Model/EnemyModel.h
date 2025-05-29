#pragma once
class EnemyModel {
private:
    int health;
    float speed;
public:
    EnemyModel(int initial_health, float movement_speed)
        : health(initial_health), speed(movement_speed) {}

    void take_damage(int amount) { health -= amount; }
    int get_health() const { return health; }
    float get_speed() const { return speed; }
    bool is_dead() const { return health <= 0; }
};
