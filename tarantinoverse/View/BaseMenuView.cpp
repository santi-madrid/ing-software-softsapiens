#include "BaseMenuView.h"
#include "godot_cpp/classes/button.hpp"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


class BaseMenuPresenter;

using namespace godot;

/**
 * @brief Registra los métodos y señales de BaseMenuView para Godot.
 */
void BaseMenuView::_bind_methods() {
  // Add if there is something to show in Godot.
}

/**
 * @brief Constructor de BaseMenuView.
 */
BaseMenuView::BaseMenuView() {}

/**
 * @brief Inicializa la vista base del menú y el índice de selección.
 */
void BaseMenuView::_ready() { current_index = 0; }

/**
 * @brief Destructor de BaseMenuView.
 */
BaseMenuView::~BaseMenuView() {
  // Add your cleanup here.
}

/**
 * @brief Maneja la navegación entre botones del menú según el input del
 * usuario.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void BaseMenuView::handle_navigation(double delta) {
  Input *input = Input::get_singleton();

  if (input->is_action_just_pressed("ui_down")) {
    current_index = (current_index + 1) % button_paths.size();
    grab_focus_at_index(current_index);
  }

  if (input->is_action_just_pressed("ui_up")) {
    current_index =
        (current_index - 1 + button_paths.size()) % button_paths.size();
    grab_focus_at_index(current_index);
  }

  if (input->is_action_just_pressed("ui_accept")) {
    activate_button_at_index(current_index);
  }
}

/**
 * @brief Da foco al botón en la posición indicada.
 * @param index Índice del botón.
 */
void BaseMenuView::grab_focus_at_index(int index) {
  Node *node = get_node<Button>(button_paths[index]);
  Button *button = Object::cast_to<Button>(node);
  if (button) {
    button->grab_focus();
  }
}

/**
 * @brief Activa el botón en la posición indicada (emite la señal 'pressed').
 * @param index Índice del botón.
 */
void BaseMenuView::activate_button_at_index(int index) {
  Node *node = get_node<Button>(button_paths[index]);
  Button *button = Object::cast_to<Button>(node);
  if (button) {
    button->emit_signal("pressed");
  }
}