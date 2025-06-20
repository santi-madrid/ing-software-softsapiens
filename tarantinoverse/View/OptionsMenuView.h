#ifndef OPTIONS_MENU_VIEW_H
#define OPTIONS_MENU_VIEW_H

#include "../Presenter/OptionsMenuPresenter.h"
#include "../View/BaseMenuView.h"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <vector>


namespace godot {

/**
 * @class OptionsMenuView
 * @brief Vista del menú de opciones, permite modificar configuraciones del
 * juego.
 *
 * Gestiona la UI y la interacción del usuario en el menú de opciones.
 */

class OptionsMenuView : public BaseMenuView {
  GDCLASS(OptionsMenuView, BaseMenuView);

private:
  OptionsMenuPresenter *presenter;

protected:
  static void _bind_methods();

public:
  OptionsMenuView();
  ~OptionsMenuView();

  void _process(double delta);
  void _ready();
  void _on_play_pressed();
  void _on_quit_pressed();
  void set_presenter(OptionsMenuPresenter *p);
};

} // namespace godot

#endif // MAIN_MENU_VIEW_H