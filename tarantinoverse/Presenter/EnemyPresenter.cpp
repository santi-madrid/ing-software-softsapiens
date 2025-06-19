#include "EnemyPresenter.h"
#include "EnemyView.h"

/**
 * @brief Constructor de EnemyPresenter. Asocia el presenter a la vista y configura el modelo.
 * @param v Puntero a la vista del enemigo.
 * @param hp Vida inicial.
 * @param speed Velocidad inicial.
 */
EnemyPresenter::EnemyPresenter(EnemyView* v, int hp, float speed)
    : model(hp, speed), view(v) {
    view->set_presenter(this);
}

/**
 * @brief Actualiza la posición del enemigo cada frame.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void EnemyPresenter::on_update(double delta) {
    Vector2 pos = view->get_position();
    pos.x -= model.get_speed() * delta;
    view->update_position(pos);
}

/**
 * @brief Aplica daño al enemigo y actualiza el modelo.
 * @param amount Cantidad de daño recibido.
 * @return true si el enemigo murió, false en caso contrario.
 */
bool EnemyPresenter::take_damage(int amount) {
    return model.take_damage(amount); // Devuelve true si el enemigo murió
}

/**
 * @brief Obtiene la vida actual del enemigo.
 * @return Vida actual.
 */
int EnemyPresenter::get_health() const {
    return model.get_health();
}
