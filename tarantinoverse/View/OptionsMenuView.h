#ifndef OPTIONS_MENU_VIEW_H
#define OPTIONS_MENU_VIEW_H

#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <vector>
#include "../Presenter/OptionsMenuPresenter.h"
#include "../View/BaseMenuView.h"

namespace godot {

class OptionsMenuView : public BaseMenuView {
    GDCLASS(OptionsMenuView, BaseMenuView);

private:
    OptionsMenuPresenter* presenter;

protected:
    static void _bind_methods();

public:
    OptionsMenuView();
    ~OptionsMenuView();

    void _process(double delta);
    void _ready();
    void _on_play_pressed();
    void _on_quit_pressed();
    void set_presenter(OptionsMenuPresenter* p);
    
};

}

#endif // MAIN_MENU_VIEW_H