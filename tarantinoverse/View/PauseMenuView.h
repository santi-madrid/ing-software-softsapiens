#ifndef PAUSE_MENU_VIEW_H
#define PAUSE_MENU_VIEW_H

#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <vector>
#include "../Presenter/PauseMenuPresenter.h"
#include "../View/BaseMenuView.h"

namespace godot {

class PauseMenuView : public BaseMenuView {
    GDCLASS(PauseMenuView, BaseMenuView);

private:
    PauseMenuPresenter* presenter;
    bool paused = false;

protected:
    static void _bind_methods();

public:
    PauseMenuView();
    ~PauseMenuView();

    void _process(double delta);
    void _ready();
    
    void resume_game();
    void toggle_pause();
    bool is_paused() const;
    void _on_play_pressed();
    void _on_options_pressed();
    void _on_quit_pressed();
    void set_presenter(PauseMenuPresenter* p);
    
};

}

#endif // MAIN_MENU_VIEW_H