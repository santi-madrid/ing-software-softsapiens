#pragma once

namespace godot {
    class OptionsMenuView;
}

#include "Model/OptionsMenuModel.h"

class OptionsMenuPresenter {
private:
    OptionsMenuModel model;
    godot::OptionsMenuView* view;

public:
    OptionsMenuPresenter(godot::OptionsMenuView *v);
    ~OptionsMenuPresenter();
};