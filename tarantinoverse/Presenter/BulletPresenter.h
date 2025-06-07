// Presenter/bullet_presenter.h
#pragma once
#include "Model/BulletModel.h"

class BulletPresenter {
private:
    BulletModel* model;

public:
    BulletPresenter(godot::Vector2 start_pos, int dir = 1)
        : model(new BulletModel(start_pos, dir)) {}

    ~BulletPresenter() { delete model; }

    void update(float delta);
    bool should_destroy() const;
    godot::Vector2 get_position() const;
};
