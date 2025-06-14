#include "CreditsMenuPresenter.h"
#include "CreditsMenuModel.h"
#include "../View/CreditsMenuView.h"

class CreditsMenuView;

CreditsMenuPresenter::CreditsMenuPresenter(godot::CreditsMenuView *v)
    : model(), view(v) {
    view->set_presenter(this);
}

CreditsMenuPresenter::~CreditsMenuPresenter(){
    
}