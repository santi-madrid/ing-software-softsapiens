// Presenter/CharacterPresenter.h
#pragma once

namespace godot {
class CharacterView;
}

#include "../Core/ObjectType.h"
#include "Model/CharacterModel.h"


/**
 * @class CharacterPresenter
 * @brief Presenter para el personaje principal. Conecta la vista y el modelo
 * del personaje.
 */
class CharacterPresenter {
public:
  CharacterPresenter(godot::CharacterView *view, int hp, int sp, float speed);
  ~CharacterPresenter();

  bool take_damage(int amount);
  int get_health() const;
  int get_score() const;
  void set_speed(double p_speed);
  double get_speed() const;
  int get_max_health() const;
  void collect_object(ObjectType type, int value);
  void activate_power_up(float duration);
  bool is_power_up_active() const;
  void update(float delta);

private:
  CharacterModel model;
  godot::CharacterView *view;

  bool power_up_active = false;
  float power_up_time_left = 0.0f;
  inline static constexpr float POWER_UP_DURATION = 5.0f;
};