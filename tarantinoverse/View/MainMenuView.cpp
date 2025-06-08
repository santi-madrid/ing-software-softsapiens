#include "MainMenuView.h"
#include "Presenter/MainMenuPresenter.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include "godot_cpp/classes/button.hpp"
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/scene_tree.hpp>

class MainMenuPresenter;

using namespace godot;

void MainMenuView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_process", "delta"), &MainMenuView::_process);
    ClassDB::bind_method(D_METHOD("_on_play_pressed"), &MainMenuView::_on_play_pressed);
    ClassDB::bind_method(D_METHOD("_on_options_pressed"), &MainMenuView::_on_options_pressed);
    ClassDB::bind_method(D_METHOD("_on_credits_pressed"), &MainMenuView::_on_credits_pressed);
    ClassDB::bind_method(D_METHOD("_on_quit_pressed"), &MainMenuView::_on_quit_pressed);
}

MainMenuView::MainMenuView()
    : presenter(nullptr) {}
void MainMenuView::_ready() {
    UtilityFunctions::print("MainMenuView::_ready called");

    if (!presenter) {
        presenter = new MainMenuPresenter(this);
        UtilityFunctions::print("Presenter created");
    }
    
    current_index = 0;

    button_paths = {
        "VBoxContainer/PlayButton",
        "VBoxContainer/OptionsButton",
        "VBoxContainer/CreditsButton",
        "VBoxContainer/QuitButton"
    };

    get_node<Button>("VBoxContainer/PlayButton")->connect("pressed", Callable(this, "_on_play_pressed"));
    get_node<Button>("VBoxContainer/OptionsButton")->connect("pressed", Callable(this, "_on_options_pressed"));
    get_node<Button>("VBoxContainer/CreditsButton")->connect("pressed", Callable(this, "_on_credits_pressed"));
    get_node<Button>("VBoxContainer/QuitButton")->connect("pressed", Callable(this, "_on_quit_pressed"));

    grab_focus_at_index(current_index);
}

MainMenuView::~MainMenuView() {
	// Add your cleanup here.
}

void MainMenuView::_process(double delta) {
    Input* input = Input::get_singleton();

    if (input->is_action_just_pressed("ui_down")) {
        current_index = (current_index + 1) % button_paths.size();
        grab_focus_at_index(current_index);
    }

    if (input->is_action_just_pressed("ui_up")) {
        current_index = (current_index - 1 + button_paths.size()) % button_paths.size();
        grab_focus_at_index(current_index);
    }

    if (input->is_action_just_pressed("ui_accept")) {
        activate_button_at_index(current_index);
    }
}

void MainMenuView::grab_focus_at_index(int index) {
    Node* node = get_node<Button>(button_paths[index]);
    Button* button = Object::cast_to<Button>(node);
    if (button) {
        button->grab_focus();
    }
}

void MainMenuView::activate_button_at_index(int index) {
    Node* node = get_node<Button>(button_paths[index]);
    Button* button = Object::cast_to<Button>(node);
    if (button) {
        button->emit_signal("pressed");
    }
}

void MainMenuView::_on_play_pressed() {
    UtilityFunctions::print("Play button pressed");
    get_tree()->change_scene_to_file("res://Main.tscn");
}

void MainMenuView::_on_options_pressed() {
    UtilityFunctions::print("Options button pressed");
    get_tree()->change_scene_to_file("res://scenes/OptionsMenu.tscn");
}

void MainMenuView::_on_credits_pressed() {
    UtilityFunctions::print("Credits button pressed");
    get_tree()->change_scene_to_file("res://scenes/Credits.tscn");
}

void MainMenuView::_on_quit_pressed() {
    UtilityFunctions::print("Quit button pressed");
    get_tree()->quit();
}

void MainMenuView::set_presenter(MainMenuPresenter* p) {
	presenter = p;
}