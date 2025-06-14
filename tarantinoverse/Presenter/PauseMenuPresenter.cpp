#include "PauseMenuPresenter.h"
#include "PauseMenuModel.h"
#include "../View/PauseMenuView.h"

class PauseMenuView;

PauseMenuPresenter::PauseMenuPresenter(godot::PauseMenuView *v)
    : model(), view(v) {
    view->set_presenter(this);
}

PauseMenuPresenter::~PauseMenuPresenter(){
    
}

