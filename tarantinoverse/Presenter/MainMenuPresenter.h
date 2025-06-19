// Presenter/CharacterPresenter.h
#pragma once

namespace godot {
class MainMenuView;
}

#include "Model/MainMenuModel.h"

/**
 * @class MainMenuPresenter
 * @brief Presenter para el menú principal. Conecta la vista y el modelo del
 * menú principal.
 */
class MainMenuPresenter {
private:
  MainMenuModel model;
  godot::MainMenuView *view;

public:
  MainMenuPresenter(godot::MainMenuView *v);
  ~MainMenuPresenter();
};
