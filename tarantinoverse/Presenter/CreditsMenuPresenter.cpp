#include "CreditsMenuPresenter.h"
#include "../View/CreditsMenuView.h"
#include "CreditsMenuModel.h"


class CreditsMenuView;

/**
 * @brief Constructor de CreditsMenuPresenter. Asocia el presenter a la vista.
 * @param v Puntero a la vista del menú de créditos.
 */
CreditsMenuPresenter::CreditsMenuPresenter(godot::CreditsMenuView *v)
    : model(), view(v) {
  view->set_presenter(this);
}

/**
 * @brief Destructor de CreditsMenuPresenter.
 */
CreditsMenuPresenter::~CreditsMenuPresenter() {}