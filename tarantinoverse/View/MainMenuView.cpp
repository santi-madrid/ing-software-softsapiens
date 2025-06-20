#include "MainMenuView.h"
#include "BaseMenuView.h"
#include "Presenter/MainMenuPresenter.h"
#include "godot_cpp/classes/button.hpp"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


class MainMenuPresenter;

using namespace godot;

/**
 * @brief Registra los métodos y señales de MainMenuView para Godot.
 */
void MainMenuView::_bind_methods() {
  ClassDB::bind_method(D_METHOD("_on_play_pressed"),
                       &MainMenuView::_on_play_pressed);
  ClassDB::bind_method(D_METHOD("_on_options_pressed"),
                       &MainMenuView::_on_options_pressed);
  ClassDB::bind_method(D_METHOD("_on_credits_pressed"),
                       &MainMenuView::_on_credits_pressed);
  ClassDB::bind_method(D_METHOD("_on_quit_pressed"),
                       &MainMenuView::_on_quit_pressed);
}

/**
 * @brief Constructor de MainMenuView. Inicializa el presenter en nullptr.
 */
MainMenuView::MainMenuView() : presenter(nullptr) {}

/**
 * @brief Inicializa la vista del menú principal y conecta los botones.
 */
void MainMenuView::_ready() {
  UtilityFunctions::print("MainMenuView::_ready called");

  BaseMenuView::_ready();

  if (!presenter) {
    presenter = new MainMenuPresenter(this);
    UtilityFunctions::print("Presenter created");
  }

  button_paths = {"VBoxContainer/PlayButton", "VBoxContainer/OptionsButton",
                  "VBoxContainer/CreditsButton", "VBoxContainer/QuitButton"};

  grab_focus_at_index(current_index);

  get_node<Button>("VBoxContainer/PlayButton")
      ->connect("pressed", Callable(this, "_on_play_pressed"));
  get_node<Button>("VBoxContainer/OptionsButton")
      ->connect("pressed", Callable(this, "_on_options_pressed"));
  get_node<Button>("VBoxContainer/CreditsButton")
      ->connect("pressed", Callable(this, "_on_credits_pressed"));
  get_node<Button>("VBoxContainer/QuitButton")
      ->connect("pressed", Callable(this, "_on_quit_pressed"));
}

/**
 * @brief Destructor de MainMenuView.
 */
MainMenuView::~MainMenuView() {
  // Add your cleanup here.
}

/**
 * @brief Proceso de lógica del menú principal. Maneja la navegación.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void MainMenuView::_process(double delta) { handle_navigation(delta); }

/**
 * @brief Callback del botón Play. Cambia a la escena principal.
 */
void MainMenuView::_on_play_pressed() {
  UtilityFunctions::print("Play button pressed");
  get_tree()->change_scene_to_file("res://main.tscn");
}

/**
 * @brief Callback del botón Options. Cambia a la escena de opciones.
 */
void MainMenuView::_on_options_pressed() {
  UtilityFunctions::print("Options button pressed");
  get_tree()->change_scene_to_file("res://options_menu.tscn");
}

/**
 * @brief Callback del botón Credits. Cambia a la escena de créditos.
 */
void MainMenuView::_on_credits_pressed() {
  UtilityFunctions::print("Credits button pressed");
  get_tree()->change_scene_to_file("res://credits_menu.tscn");
}

/**
 * @brief Callback del botón Quit. Sale del juego.
 */
void MainMenuView::_on_quit_pressed() {
  UtilityFunctions::print("Quit button pressed");
  get_tree()->quit();
}

/**
 * @brief Asigna el presenter asociado a la vista.
 * @param p Puntero al presenter.
 */
void MainMenuView::set_presenter(MainMenuPresenter *p) { presenter = p; }