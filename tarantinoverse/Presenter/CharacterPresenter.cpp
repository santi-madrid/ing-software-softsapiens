#include "CharacterPresenter.h"
#include "../View/CharacterView.h"
#include "CharacterModel.h"

// Interfaz
class ObjectEffectStrategy {
public:
    virtual ~ObjectEffectStrategy() {}
    virtual void apply(CharacterModel* model, int value) = 0;
};

// Implementaciones de la interfaz
class CoinEffect : public ObjectEffectStrategy {
public:
    void apply(CharacterModel* model, int value) override {
        model->set_score(model->get_score() + value);
    }
};

class HealthEffect : public ObjectEffectStrategy {
public:
    void apply(CharacterModel* model, int value) override {
        model->set_health(model->get_health() + value);
    }
};

class PowerUpEffect : public ObjectEffectStrategy {
public:
    void apply(CharacterModel* model, int value) override {
        model->set_speed(model->get_speed() + value);
    }
};

class CharacterView;

CharacterPresenter::CharacterPresenter(godot::CharacterView *v, int hp, int sp,
                                       float speed)
    : model(hp, sp, speed), view(v) {
  view->set_presenter(this);
}

CharacterPresenter::~CharacterPresenter() {}

bool CharacterPresenter::take_damage(int amount) {
  return model.take_damage(amount);
}

int CharacterPresenter::get_health() const { return model.get_health(); }

int CharacterPresenter::get_score() const { return model.get_score(); }

void CharacterPresenter::set_speed(double p_speed) { model.set_speed(p_speed); }

double CharacterPresenter::get_speed() const { return model.get_speed(); }

int CharacterPresenter::get_max_health() const {
  return model.get_max_health();
}

void CharacterPresenter::collect_object(ObjectType type, int value) {
  ObjectEffectStrategy* strategy = nullptr;
  switch (type) {
        case ObjectType::COIN:
            strategy = new CoinEffect();
            break;
        case ObjectType::HEALTH:
            strategy = new HealthEffect();
            break;
        case ObjectType::POWERUP:
            strategy = new PowerUpEffect();
            break;
        default:
            return;
  }
  if (strategy) {
      strategy->apply(model, value);
      delete strategy;
  }
}
