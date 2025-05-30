#include "EnemyPresenter.h"
#include "EnemyView.h"

EnemyPresenter::EnemyPresenter(EnemyView* v, int hp, float speed)
    : model(hp, speed), view(v) {
    view->set_presenter(this);
}

void EnemyPresenter::on_update(double delta) {
    Vector2 pos = view->get_position();
    pos.x -= model.get_speed() * delta;
    view->update_position(pos);
}

bool EnemyPresenter::take_damage(int amount) {
    return model.take_damage(amount); // Devuelve true si el enemigo murió
}

int EnemyPresenter::get_health() const {
    return model.get_health();
}
