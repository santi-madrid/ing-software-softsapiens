#include "PauseMenuPresenter.h"
#include "../View/PauseMenuView.h"
#include "PauseMenuModel.h"

class PauseMenuView;

/**
 * @brief Constructor de PauseMenuPresenter. Asocia el presenter a la vista.
 * @param v Puntero a la vista del menú de pausa.
 */
PauseMenuPresenter::PauseMenuPresenter(godot::PauseMenuView *v)
    : model(), view(v) {
  view->set_presenter(this);
}

/**
 * @brief Destructor de PauseMenuPresenter.
 */
PauseMenuPresenter::~PauseMenuPresenter() {}