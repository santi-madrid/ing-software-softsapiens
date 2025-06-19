#pragma once

namespace godot {
class OptionsMenuView;
}

#include "Model/OptionsMenuModel.h"

/**
 * @class OptionsMenuPresenter
 * @brief Presenter para el menú de opciones. Conecta la vista y el modelo del
 * menú de opciones.
 */
class OptionsMenuPresenter {
private:
  OptionsMenuModel model;
  godot::OptionsMenuView *view;

public:
  OptionsMenuPresenter(godot::OptionsMenuView *v);
  ~OptionsMenuPresenter();
};