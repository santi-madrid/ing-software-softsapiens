// Model/bullet_model.h
#pragma once
#include <godot_cpp/variant/vector2.hpp>

/**
 * @class BulletModel
 * @brief Modelo de datos para balas.
 */
class BulletModel {
private:
  godot::Vector2 position;
  float speed = 500.0f; // Default speed
  float distance_traveled;
  float max_distance;
  int direction = 1; // 1 for right, -1 for left

public:
  BulletModel(godot::Vector2 start_pos, int dir = 1, float speed = 500.0f,
              float max_dist = 1000.0f)
      : position(start_pos), speed(speed), distance_traveled(0.0f),
        max_distance(max_dist), direction(dir) {}

  void move(float delta);
  bool should_destroy() const;

  godot::Vector2 get_position() const;
};
