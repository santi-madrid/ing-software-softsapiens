#ifndef CREDITS_MENU_VIEW_H
#define CREDITS_MENU_VIEW_H

#include "../Presenter/CreditsMenuPresenter.h"
#include "../View/BaseMenuView.h"
#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <vector>


namespace godot {

/**
 * @class CreditsMenuView
 * @brief Vista del menú de créditos, muestra información sobre los creadores
 * del juego.
 *
 * Gestiona la UI y la interacción del usuario en la pantalla de créditos.
 */

class CreditsMenuView : public BaseMenuView {
  GDCLASS(CreditsMenuView, BaseMenuView);

private:
  CreditsMenuPresenter *presenter;

protected:
  static void _bind_methods();

public:
  CreditsMenuView();
  ~CreditsMenuView();

  void _process(double delta);
  void _ready();
  void _on_quit_pressed();
  void set_presenter(CreditsMenuPresenter *p);
};

} // namespace godot

#endif // MAIN_MENU_VIEW_H