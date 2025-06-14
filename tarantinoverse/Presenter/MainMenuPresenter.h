// Presenter/CharacterPresenter.h
#pragma once

namespace godot {
    class MainMenuView;
}

#include "Model/MainMenuModel.h"

class MainMenuPresenter {
private:
    MainMenuModel model;
    godot::MainMenuView* view;

public:
    MainMenuPresenter(godot::MainMenuView *v);
    ~MainMenuPresenter();
};
