#pragma once

namespace godot {
    class CreditsMenuView;
}

#include "Model/CreditsMenuModel.h"

class CreditsMenuPresenter {
private:
    CreditsMenuModel model;
    godot::CreditsMenuView* view;

public:
    CreditsMenuPresenter(godot::CreditsMenuView *v);
    ~CreditsMenuPresenter();
};