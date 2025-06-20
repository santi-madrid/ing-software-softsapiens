#include "CreditsMenuView.h"
#include "Presenter/CreditsMenuPresenter.h"
#include "BaseMenuView.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include "godot_cpp/classes/button.hpp"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

class CreditsMenuPresenter;

using namespace godot;

/**
 * @brief Registra los métodos y señales de CreditsMenuView para Godot.
 */
void CreditsMenuView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_quit_pressed"), &CreditsMenuView::_on_quit_pressed);
}

/**
 * @brief Constructor de CreditsMenuView. Inicializa el presenter en nullptr.
 */
CreditsMenuView::CreditsMenuView()
    : presenter(nullptr) {}

/**
 * @brief Inicializa la vista del menú de créditos y conecta el botón.
 */
void CreditsMenuView::_ready() {
    UtilityFunctions::print("CreditsMenuView::_ready called");

    BaseMenuView::_ready();

    if (!presenter) {
        presenter = new CreditsMenuPresenter(this);
        UtilityFunctions::print("Presenter created");
    }

    button_paths = {
        "VBoxContainer/QuitButton"
    };

    grab_focus_at_index(current_index);

    get_node<Button>("VBoxContainer/QuitButton")->connect("pressed", Callable(this, "_on_quit_pressed"));
}

/**
 * @brief Destructor de CreditsMenuView.
 */
CreditsMenuView::~CreditsMenuView() {
    // Add your cleanup here.
}

/**
 * @brief Proceso de lógica del menú de créditos. Maneja la navegación.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void CreditsMenuView::_process(double delta) {
    handle_navigation(delta);
}

/**
 * @brief Callback del botón Quit. Cambia a la escena de menú principal.
 */
void CreditsMenuView::_on_quit_pressed() {
    UtilityFunctions::print("Quit button pressed");
    get_tree()->change_scene_to_file("res://main_menu.tscn");
}

/**
 * @brief Asigna el presenter asociado a la vista.
 * @param p Puntero al presenter.
 */
void CreditsMenuView::set_presenter(CreditsMenuPresenter* p) {
    presenter = p;
}