#include "MainMenuPresenter.h"
#include "MainMenuModel.h"
#include "../View/MainMenuView.h"

class MainMenuView;

MainMenuPresenter::MainMenuPresenter(godot::MainMenuView *v)
    : model(), view(v) {
    view->set_presenter(this);
}

MainMenuPresenter::~MainMenuPresenter(){
    
}

