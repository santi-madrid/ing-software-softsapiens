#ifndef MAIN_MENU_VIEW_H
#define MAIN_MENU_VIEW_H

#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <vector>
#include "../Presenter/MainMenuPresenter.h"
#include "../View/BaseMenuView.h"

namespace godot {

class MainMenuView : public BaseMenuView {
    GDCLASS(MainMenuView, BaseMenuView);

private:
    MainMenuPresenter* presenter;

protected:
    static void _bind_methods();

public:
    MainMenuView();
    ~MainMenuView();

    void _process(double delta);
    void _ready();
    void _on_play_pressed();
    void _on_options_pressed();
    void _on_credits_pressed();
    void _on_quit_pressed();
    void set_presenter(MainMenuPresenter* p);
    
};

}

#endif // MAIN_MENU_VIEW_H
