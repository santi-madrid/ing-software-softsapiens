#pragma once

namespace godot {
class BaseMenuView;
}

#include "Model/BaseMenuModel.h"

/**
 * @class BaseMenuPresenter
 * @brief Presenter base para menús. Provee funcionalidad común para los
 * presenters de menús.
 */
class BaseMenuPresenter {
private:
  BaseMenuModel model;

public:
  BaseMenuPresenter();
  ~BaseMenuPresenter();
};