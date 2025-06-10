#include "PauseMenuView.h"
#include "Presenter/PauseMenuPresenter.h"
#include "BaseMenuView.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include "godot_cpp/classes/button.hpp"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

class PauseMenuPresenter;

using namespace godot;

void PauseMenuView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_process", "delta"), &PauseMenuView::_process);
    ClassDB::bind_method(D_METHOD("_on_play_pressed"), &PauseMenuView::_on_play_pressed);
    ClassDB::bind_method(D_METHOD("_on_options_pressed"), &PauseMenuView::_on_options_pressed);
    ClassDB::bind_method(D_METHOD("_on_quit_pressed"), &PauseMenuView::_on_quit_pressed);
}

PauseMenuView::PauseMenuView()
    : presenter(nullptr) {}
void PauseMenuView::_ready() {
    UtilityFunctions::print("PauseMenuView::_ready called");

    set_visible(false); // Ocultamos el menú al iniciar
    set_process(true);

    BaseMenuView::_ready();

    if (!presenter) {
        presenter = new PauseMenuPresenter(this);
        UtilityFunctions::print("Presenter created");
    }

    button_paths = {
        "VBoxContainer/PlayButton",
        "VBoxContainer/OptionsButton",
        "VBoxContainer/QuitButton"
    };

    grab_focus_at_index(current_index);

    get_node<Button>("VBoxContainer/PlayButton")->connect("pressed", Callable(this, "_on_play_pressed"));
    get_node<Button>("VBoxContainer/OptionsButton")->connect("pressed", Callable(this, "_on_options_pressed"));
    get_node<Button>("VBoxContainer/QuitButton")->connect("pressed", Callable(this, "_on_quit_pressed"));
}

PauseMenuView::~PauseMenuView() {
    // Add your cleanup here.
}

void PauseMenuView::_process(double delta) {
    Input* input = Input::get_singleton();

    if (input->is_action_just_pressed("ui_cancel")) { // ESC
        toggle_pause();
    }

    if (paused) {
        handle_navigation(delta);
    }
}

void PauseMenuView::toggle_pause() {
    paused = !paused;

    if (paused) {
        UtilityFunctions::print("Game Paused");
        set_visible(true);
        get_tree()->set_pause(true);
        grab_focus_at_index(current_index);
    } else {
        UtilityFunctions::print("Game Resumed");
        set_visible(false);
        get_tree()->set_pause(false);
    }
}

bool PauseMenuView::is_paused() const {
    return paused;
}

void PauseMenuView::_on_play_pressed() {
    toggle_pause(); // Resume
}

void PauseMenuView::_on_options_pressed() {
    UtilityFunctions::print("Options button pressed");
    get_tree()->change_scene_to_file("res://scenes/OptionsMenu.tscn");
}

void PauseMenuView::_on_quit_pressed() {
    UtilityFunctions::print("Quit button pressed");
    get_tree()->change_scene_to_file("res://scenes/Main_Menu.tscn");
}

void PauseMenuView::set_presenter(PauseMenuPresenter* p) {
    presenter = p;
}