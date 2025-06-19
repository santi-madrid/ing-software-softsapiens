#pragma once

namespace godot {
class CreditsMenuView;
}

/**
 * @class CreditsMenuPresenter
 * @brief Presenter para el menú de créditos. Conecta la vista y el modelo del
 * menú de créditos.
 */

#include "Model/CreditsMenuModel.h"

class CreditsMenuPresenter {
private:
  CreditsMenuModel model;
  godot::CreditsMenuView *view;

public:
  CreditsMenuPresenter(godot::CreditsMenuView *v);
  ~CreditsMenuPresenter();
};