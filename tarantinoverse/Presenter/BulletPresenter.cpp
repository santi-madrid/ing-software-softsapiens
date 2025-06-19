// Presenter/bullet_presenter.cpp
#include "BulletPresenter.h"

/**
 * @brief Actualiza la posición de la bala.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void BulletPresenter::update(float delta) { model->move(delta); }

/**
 * @brief Indica si la bala debe ser destruida.
 * @return true si debe destruirse, false en caso contrario.
 */
bool BulletPresenter::should_destroy() const { return model->should_destroy(); }

/**
 * @brief Obtiene la posición actual de la bala.
 * @return Posición de la bala.
 */
godot::Vector2 BulletPresenter::get_position() const {
  return model->get_position();
}
