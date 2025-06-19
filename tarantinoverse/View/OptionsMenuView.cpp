#include "OptionsMenuView.h"
#include "BaseMenuView.h"
#include "Presenter/OptionsMenuPresenter.h"
#include "godot_cpp/classes/button.hpp"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


class OptionsMenuPresenter;

using namespace godot;

/**
 * @brief Registra los métodos y señales de OptionsMenuView para Godot.
 */
void OptionsMenuView::_bind_methods() {
  ClassDB::bind_method(D_METHOD("_on_play_pressed"),
                       &OptionsMenuView::_on_play_pressed);
  ClassDB::bind_method(D_METHOD("_on_quit_pressed"),
                       &OptionsMenuView::_on_quit_pressed);
}

/**
 * @brief Constructor de OptionsMenuView. Inicializa el presenter en nullptr.
 */
OptionsMenuView::OptionsMenuView() : presenter(nullptr) {}

/**
 * @brief Inicializa la vista del menú de opciones y conecta los botones.
 */
void OptionsMenuView::_ready() {
  UtilityFunctions::print("OptionsMenuView::_ready called");

  BaseMenuView::_ready();

  if (!presenter) {
    presenter = new OptionsMenuPresenter(this);
    UtilityFunctions::print("Presenter created");
  }

  button_paths = {"VBoxContainer/PlayButton", "VBoxContainer/QuitButton"};

  grab_focus_at_index(current_index);

  get_node<Button>("VBoxContainer/PlayButton")
      ->connect("pressed", Callable(this, "_on_play_pressed"));
  get_node<Button>("VBoxContainer/QuitButton")
      ->connect("pressed", Callable(this, "_on_quit_pressed"));
}

/**
 * @brief Destructor de OptionsMenuView.
 */
OptionsMenuView::~OptionsMenuView() {
  // Add your cleanup here.
}

/**
 * @brief Proceso de lógica del menú de opciones. Maneja la navegación.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void OptionsMenuView::_process(double delta) { handle_navigation(delta); }

/**
 * @brief Callback del botón Play. Cambia a la escena principal.
 */
void OptionsMenuView::_on_play_pressed() {
  UtilityFunctions::print("Play button pressed");
  get_tree()->change_scene_to_file(
      "res://main.tscn"); // Cambiar lógica para mutear sonido.
}

/**
 * @brief Callback del botón Quit. Cambia a la escena de menú principal.
 */
void OptionsMenuView::_on_quit_pressed() {
  UtilityFunctions::print("Quit button pressed");
  get_tree()->change_scene_to_file("res://main_menu.tscn");
}

/**
 * @brief Asigna el presenter asociado a la vista.
 * @param p Puntero al presenter.
 */
void OptionsMenuView::set_presenter(OptionsMenuPresenter *p) { presenter = p; }