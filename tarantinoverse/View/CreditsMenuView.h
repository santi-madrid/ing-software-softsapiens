#ifndef CREDITS_MENU_VIEW_H
#define CREDITS_MENU_VIEW_H

#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <vector>
#include "../Presenter/CreditsMenuPresenter.h"
#include "../View/BaseMenuView.h"

namespace godot {

class CreditsMenuView : public BaseMenuView {
    GDCLASS(CreditsMenuView, BaseMenuView);

private:
    CreditsMenuPresenter* presenter;

protected:
    static void _bind_methods();

public:
    CreditsMenuView();
    ~CreditsMenuView();

    void _process(double delta);
    void _ready();
    void _on_quit_pressed();
    void set_presenter(CreditsMenuPresenter* p);
    
};

}

#endif // MAIN_MENU_VIEW_H