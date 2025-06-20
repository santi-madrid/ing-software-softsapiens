#include "MainMenuPresenter.h"
#include "MainMenuModel.h"
#include "../View/MainMenuView.h"

class MainMenuView;

/**
 * @brief Constructor de MainMenuPresenter. Asocia el presenter a la vista.
 * @param v Puntero a la vista del menú principal.
 */
MainMenuPresenter::MainMenuPresenter(godot::MainMenuView *v)
    : model(), view(v) {
    view->set_presenter(this);
}

/**
 * @brief Destructor de MainMenuPresenter.
 */
MainMenuPresenter::~MainMenuPresenter(){
    
}

