// Presenter/bullet_presenter.cpp
#include "BulletPresenter.h"

void BulletPresenter::update(float delta) {
    model->move(delta);
}

bool BulletPresenter::should_destroy() const {
    return model->should_destroy();
}

godot::Vector2 BulletPresenter::get_position() const {
    return model->get_position();
}
