// EnemyView.h
#pragma once

#include "Presenter/EnemyPresenter.h"
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/vector2.hpp>


using namespace godot;

/**
 * @class EnemyView
 * @brief Vista de los enemigos, maneja su presentación y lógica visual.
 *
 * Gestiona la física, animaciones y colisiones de los enemigos en el juego.
 */
class EnemyView : public CharacterBody2D {
  GDCLASS(EnemyView, CharacterBody2D);

private:
  EnemyPresenter *presenter;
  int initial_health;
  float initial_speed;
  double gravity = 600.0f; // Gravedad para el enemigo
  float shoot_timer = 0.0f;
  float shoot_interval = 1.0f; // tiempo entre disparos en segundos
  int bullets_to_shoot = 3;
  int bullets_shot = 0;

public:
  EnemyView();
  void _ready() override;
  void _physics_process(double delta) override;
  void play_damage_animation();
  bool take_damage(int amount);
  void die();
  void set_presenter(EnemyPresenter *p) { presenter = p; }
  void update_position(Vector2 new_pos) { set_position(new_pos); }

protected:
  static void _bind_methods();
};
