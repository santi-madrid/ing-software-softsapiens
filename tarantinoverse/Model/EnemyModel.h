#pragma once
#include <algorithm> // For std::max

/**
 * @class EnemyModel
 * @brief Modelo de datos para enemigos.
 */
class EnemyModel {
private:
  int health = 100; // Default health value
  float speed;

public:
  EnemyModel(int initial_health, float movement_speed)
      : health(initial_health), speed(movement_speed) {}

  bool take_damage(int amount) {
    health = std::max(0, health - amount);
    return is_dead();
  }
  int get_health() const { return health; }
  float get_speed() const { return speed; }
  bool is_dead() const { return health <= 0; }
};
