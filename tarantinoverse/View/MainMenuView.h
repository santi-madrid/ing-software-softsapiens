#ifndef MAIN_MENU_VIEW_H
#define MAIN_MENU_VIEW_H

#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <vector>
#include "../Presenter/MainMenuPresenter.h"

namespace godot {

class MainMenuView : public Control {
    GDCLASS(MainMenuView, Control);

private:
    MainMenuPresenter* presenter;
    int current_index;
    std::vector<String> button_paths;

protected:
    static void _bind_methods();

public:
    MainMenuView();
    ~MainMenuView();

    void _ready();
    void _process(double delta) override;
    void grab_focus_at_index(int index);
    void activate_button_at_index(int index);
    void _on_play_pressed();
    void _on_options_pressed();
    void _on_credits_pressed();
    void _on_quit_pressed();
    void set_presenter(MainMenuPresenter* p);
    
};

}

#endif // MAIN_MENU_VIEW_H
