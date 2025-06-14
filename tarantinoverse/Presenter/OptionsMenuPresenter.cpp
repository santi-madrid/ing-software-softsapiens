#include "OptionsMenuPresenter.h"
#include "OptionsMenuModel.h"
#include "../View/OptionsMenuView.h"

class MainMenuView;

OptionsMenuPresenter::OptionsMenuPresenter(godot::OptionsMenuView *v)
    : model(), view(v) {
    view->set_presenter(this);
}

OptionsMenuPresenter::~OptionsMenuPresenter(){
    
}