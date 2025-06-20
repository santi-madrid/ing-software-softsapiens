#ifndef PAUSE_MENU_VIEW_H
#define PAUSE_MENU_VIEW_H

#include "../Presenter/PauseMenuPresenter.h"
#include "../View/BaseMenuView.h"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <vector>


namespace godot {

/**
 * @class PauseMenuView
 * @brief Vista del menú de pausa, gestiona la UI y la interacción del usuario
 * durante la pausa.
 *
 * Permite pausar, reanudar y navegar entre opciones del menú de pausa.
 */

class PauseMenuView : public BaseMenuView {
  GDCLASS(PauseMenuView, BaseMenuView);

private:
  PauseMenuPresenter *presenter;
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
  void set_presenter(PauseMenuPresenter *p);
};

} // namespace godot

#endif // MAIN_MENU_VIEW_H