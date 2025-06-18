#include "CharacterPresenter.h"
#include "../View/CharacterView.h"
#include "CharacterModel.h"


class CharacterView;

CharacterPresenter::CharacterPresenter(godot::CharacterView *v, int hp,
                                       float speed)
    : model(hp, speed), view(v) {
  view->set_presenter(this);
}

CharacterPresenter::~CharacterPresenter() {}

bool CharacterPresenter::take_damage(int amount) {
  return model.take_damage(amount);
}

int CharacterPresenter::get_health() const { return model.get_health(); }

void CharacterPresenter::set_speed(double p_speed) { model.set_speed(p_speed); }

double CharacterPresenter::get_speed() const { return model.get_speed(); }

int CharacterPresenter::get_max_health() const {
  return model.get_max_health();
}

void CharacterPresenter::collect_object(int type, int value) {
  // Aquí puedes manejar los distintos tipos de objetos
  // Por ejemplo: 0 = moneda, 1 = vida, 2 = powerup
  switch (type) {
  case 0: // Moneda
    // sumar puntaje, etc.
    break;
  case 1: // Vida
    model.set_health(model.get_health() + value);
    break;
  case 2: // PowerUp
    // aplicar powerup
    break;
  default:
    break;
  }
}
