// Presenter/CharacterPresenter.cpp
#include "CharacterPresenter.h"
#include "../View/CharacterView.h"
#include "CharacterModel.h"

// Interfaz
class ObjectEffectStrategy {
public:
  virtual ~ObjectEffectStrategy() {}
  virtual void apply(CharacterModel *model, int value) = 0;
};

// Implementaciones de la interfaz
class CoinEffect : public ObjectEffectStrategy {
public:
  void apply(CharacterModel *model, int value) override {
    model->set_score(model->get_score() + value);
  }
};

class HealthEffect : public ObjectEffectStrategy {
public:
  void apply(CharacterModel *model, int value) override {
    model->set_health(model->get_health() + value);
  }
};

class PowerUpEffect : public ObjectEffectStrategy {
public:
  void apply(CharacterModel *model, int value) override {
    model->set_speed(model->get_speed() + value * 10);
    model->set_max_health(model->get_max_health() + value);
  }
};

class CharacterView;

CharacterPresenter::CharacterPresenter(godot::CharacterView *v, int hp, int sp,
                                       float speed)
    : model(hp, sp, speed), view(v) {
  view->set_presenter(this);
}

/**
 * @brief Destructor de CharacterPresenter.
 */
CharacterPresenter::~CharacterPresenter() {}

/**
 * @brief Aplica daño al personaje y actualiza el modelo.
 * @param amount Cantidad de daño recibido.
 * @return true si el personaje murió, false en caso contrario.
 */
bool CharacterPresenter::take_damage(int amount) {
  return model.take_damage(amount);
}

/**
 * @brief Obtiene la vida actual del personaje.
 * @return Vida actual.
 */
int CharacterPresenter::get_health() const { return model.get_health(); }

/**
 * @brief Obtiene la puntuación actual del personaje.
 * @return Puntuación.
 */
int CharacterPresenter::get_score() const { return model.get_score(); }

/**
 * @brief Establece la velocidad del personaje.
 * @param p_speed Nueva velocidad.
 */
void CharacterPresenter::set_speed(double p_speed) { model.set_speed(p_speed); }

/**
 * @brief Obtiene la velocidad actual del personaje.
 * @return Velocidad.
 */
double CharacterPresenter::get_speed() const { return model.get_speed(); }

/**
 * @brief Obtiene la vida máxima del personaje.
 * @return Vida máxima.
 */
int CharacterPresenter::get_max_health() const {
  return model.get_max_health();
}

/**
 * @brief Permite al personaje recoger un objeto y aplica su efecto.
 * @param type Tipo de objeto.
 * @param value Valor asociado al objeto.
 */
void CharacterPresenter::collect_object(ObjectType type, int value) {
  ObjectEffectStrategy *strategy = nullptr;
  switch (type) {
  case ObjectType::COIN:
    strategy = new CoinEffect();
    break;
  case ObjectType::HEALTH:
    strategy = new HealthEffect();
    break;
  case ObjectType::POWERUP:
    strategy = new PowerUpEffect();
    activate_power_up(POWER_UP_DURATION);
    break;
  default:
    return;
  }

  if (strategy) {
    strategy->apply(&model, value);
    delete strategy;
  }
}

/**
 * @brief Activa el power-up del personaje por un tiempo determinado.
 * @param duration Duración del power-up en segundos.
 */
void CharacterPresenter::activate_power_up(float duration) {
  power_up_active = true;
  power_up_time_left = duration;
}

/**
 * @brief Indica si el power-up está activo.
 * @return true si está activo, false en caso contrario.
 */
bool CharacterPresenter::is_power_up_active() const { return power_up_active; }

/**
 * @brief Actualiza el estado del power-up y otros temporizadores.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void CharacterPresenter::update(float delta) {
  if (power_up_active) {
    power_up_time_left -= delta;
    if (power_up_time_left <= 0.0f) {
      power_up_active = false;
      power_up_time_left = 0.0f;
      model.set_speed(250.0);
      model.set_max_health(100);
    }
  }
}