#pragma once

namespace godot {
    class PauseMenuView;
}

#include "Model/PauseMenuModel.h"

class PauseMenuPresenter {
private:
    PauseMenuModel model;
    godot::PauseMenuView* view;

public:
    PauseMenuPresenter(godot::PauseMenuView *v);
    ~PauseMenuPresenter();
};
