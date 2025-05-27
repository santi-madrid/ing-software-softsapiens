// View/bullet_view.cpp
#include "BulletView.h"

using namespace godot;

BulletView::BulletView() {
    presenter = nullptr;
}

BulletView::~BulletView() {
    if (presenter)
        delete presenter;
}

void BulletView::_ready() {
    presenter = new BulletPresenter(get_position());
}

void BulletView::_process(double delta) {
    if (!presenter)
        return;

    presenter->update(delta);
    set_position(presenter->get_position());

    if (presenter->should_destroy()) {
        queue_free();
    }
}

void BulletView::_bind_methods() {}
