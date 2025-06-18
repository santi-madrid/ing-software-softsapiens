// Presenter/CharacterPresenter.h
#pragma once

namespace godot {
class CharacterView;
}

#include "Model/CharacterModel.h"

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
  void collect_object(int type, int value);

private:
  CharacterModel model;
  godot::CharacterView *view;
};