#include "PauseMenuView.h"
#include "BaseMenuView.h"
#include "Presenter/PauseMenuPresenter.h"
#include "godot_cpp/classes/button.hpp"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


class PauseMenuPresenter;

using namespace godot;

/**
 * @brief Registra los métodos y señales de PauseMenuView para Godot.
 */
void PauseMenuView::_bind_methods() {
  ClassDB::bind_method(D_METHOD("_on_play_pressed"),
                       &PauseMenuView::_on_play_pressed);
  ClassDB::bind_method(D_METHOD("_on_options_pressed"),
                       &PauseMenuView::_on_options_pressed);
  ClassDB::bind_method(D_METHOD("_on_quit_pressed"),
                       &PauseMenuView::_on_quit_pressed);
}

/**
 * @brief Constructor de PauseMenuView. Inicializa el presenter en nullptr.
 */
PauseMenuView::PauseMenuView() : presenter(nullptr) {}

/**
 * @brief Inicializa la vista del menú de pausa y conecta los botones.
 */
void PauseMenuView::_ready() {
  UtilityFunctions::print("PauseMenuView::_ready called");

  set_process_mode(Node::PROCESS_MODE_WHEN_PAUSED);

  BaseMenuView::_ready();

  if (!presenter) {
    presenter = new PauseMenuPresenter(this);
    UtilityFunctions::print("Presenter created");
  }

  button_paths = {"VBoxContainer/PlayButton", "VBoxContainer/OptionsButton",
                  "VBoxContainer/QuitButton"};

  grab_focus_at_index(current_index);

  get_node<Button>("VBoxContainer/PlayButton")
      ->connect("pressed", Callable(this, "_on_play_pressed"));
  get_node<Button>("VBoxContainer/OptionsButton")
      ->connect("pressed", Callable(this, "_on_options_pressed"));
  get_node<Button>("VBoxContainer/QuitButton")
      ->connect("pressed", Callable(this, "_on_quit_pressed"));
}

/**
 * @brief Destructor de PauseMenuView. Libera el presenter si es necesario.
 */
PauseMenuView::~PauseMenuView() {
  if (presenter)
    delete presenter;
}

/**
 * @brief Proceso de lógica del menú de pausa. Maneja la navegación si está
 * pausado.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void PauseMenuView::_process(double delta) {
  if (paused) {
    handle_navigation(delta);
  }
}

/**
 * @brief Alterna el estado de pausa del juego.
 */
void PauseMenuView::toggle_pause() {
  paused = !paused;

  if (paused) {
    UtilityFunctions::print("Game Paused");
    get_tree()->set_pause(true);
    grab_focus_at_index(current_index);
  }
}

/**
 * @brief Reanuda el juego y elimina el menú de pausa.
 */
void PauseMenuView::resume_game() {
  get_tree()->set_pause(false);
  set_visible(false);
  queue_free();
}

/**
 * @brief Indica si el juego está pausado.
 * @return true si está pausado, false en caso contrario.
 */
bool PauseMenuView::is_paused() const { return paused; }

/**
 * @brief Callback del botón Play. Reanuda el juego.
 */
void PauseMenuView::_on_play_pressed() {
  resume_game(); // Resume
}

/**
 * @brief Callback del botón Options. Cambia a la escena de opciones.
 */
void PauseMenuView::_on_options_pressed() { // aca da la opcion de mutear solo,
                                            // ahora termina el juego
  UtilityFunctions::print("Options button pressed");
  get_tree()->set_pause(false);
  get_tree()->change_scene_to_file("res://options_menu.tscn");
}

/**
 * @brief Callback del botón Quit. Cambia a la escena de menú principal.
 */
void PauseMenuView::_on_quit_pressed() {
  UtilityFunctions::print("Quit button pressed");
  get_tree()->set_pause(false);
  get_tree()->change_scene_to_file("res://main_menu.tscn");
}

/**
 * @brief Asigna el presenter asociado a la vista.
 * @param p Puntero al presenter.
 */
void PauseMenuView::set_presenter(PauseMenuPresenter *p) { presenter = p; }
