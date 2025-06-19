#include "OptionsMenuPresenter.h"
#include "OptionsMenuModel.h"
#include "../View/OptionsMenuView.h"

class MainMenuView;

/**
 * @brief Constructor de OptionsMenuPresenter. Asocia el presenter a la vista.
 * @param v Puntero a la vista del menú de opciones.
 */
OptionsMenuPresenter::OptionsMenuPresenter(godot::OptionsMenuView *v)
    : model(), view(v) {
    view->set_presenter(this);
}

/**
 * @brief Destructor de OptionsMenuPresenter.
 */
OptionsMenuPresenter::~OptionsMenuPresenter(){
    
}