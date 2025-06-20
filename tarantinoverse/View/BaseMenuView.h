#ifndef BASE_MENU_VIEW_H
#define BASE_MENU_VIEW_H

#include "godot_cpp/classes/button.hpp"
#include "godot_cpp/classes/control.hpp"
#include "godot_cpp/core/class_db.hpp"
#include <vector>


namespace godot {

/**
 * @class BaseMenuView
 * @brief Vista base para los menús, provee funcionalidad común de navegación y
 * selección.
 *
 * Clase abstracta para heredar en los distintos menús del juego.
 */

class BaseMenuView : public Control {
  GDCLASS(BaseMenuView, Control);

protected:
  static void _bind_methods();
  int current_index;
  std::vector<String> button_paths;

public:
  BaseMenuView();
  ~BaseMenuView();

  void _ready();

  void handle_navigation(double delta);
  void grab_focus_at_index(int index);
  void activate_button_at_index(int index);
};

} // namespace godot

#endif