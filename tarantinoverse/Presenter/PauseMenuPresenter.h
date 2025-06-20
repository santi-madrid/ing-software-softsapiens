#pragma once

namespace godot {
class PauseMenuView;
}

#include "Model/PauseMenuModel.h"

/**
 * @class PauseMenuPresenter
 * @brief Presenter para el menú de pausa. Conecta la vista y el modelo del menú
 * de pausa.
 */
class PauseMenuPresenter {
private:
  PauseMenuModel model;
  godot::PauseMenuView *view;

public:
  PauseMenuPresenter(godot::PauseMenuView *v);
  ~PauseMenuPresenter();
};
