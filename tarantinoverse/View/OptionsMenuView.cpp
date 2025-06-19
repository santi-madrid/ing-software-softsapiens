#include "OptionsMenuView.h"
#include "Presenter/OptionsMenuPresenter.h"
#include "BaseMenuView.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include "godot_cpp/classes/button.hpp"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

class OptionsMenuPresenter;

using namespace godot;

void OptionsMenuView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_on_play_pressed"), &OptionsMenuView::_on_play_pressed);
    ClassDB::bind_method(D_METHOD("_on_quit_pressed"), &OptionsMenuView::_on_quit_pressed);
}

OptionsMenuView::OptionsMenuView()
    : presenter(nullptr) {}
void OptionsMenuView::_ready() {
    UtilityFunctions::print("OptionsMenuView::_ready called");

    BaseMenuView::_ready();

    if (!presenter) {
        presenter = new OptionsMenuPresenter(this);
        UtilityFunctions::print("Presenter created");
    }

    button_paths = {
        "VBoxContainer/PlayButton",
        "VBoxContainer/QuitButton"
    };

    grab_focus_at_index(current_index);

    get_node<Button>("VBoxContainer/PlayButton")->connect("pressed", Callable(this, "_on_play_pressed"));
    get_node<Button>("VBoxContainer/QuitButton")->connect("pressed", Callable(this, "_on_quit_pressed"));
}

OptionsMenuView::~OptionsMenuView() {
    // Add your cleanup here.
}

void OptionsMenuView::_process(double delta) {
    handle_navigation(delta);
}

void OptionsMenuView::_on_play_pressed() {
    UtilityFunctions::print("Play button pressed");
    get_tree()->change_scene_to_file("res://main.tscn"); //Cambiar lógica para mutear sonido.
}

void OptionsMenuView::_on_quit_pressed() {
    UtilityFunctions::print("Quit button pressed");
    get_tree()->change_scene_to_file("res://main_menu.tscn");
}

void OptionsMenuView::set_presenter(OptionsMenuPresenter* p) {
    presenter = p;
}