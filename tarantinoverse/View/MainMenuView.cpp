#include "MainMenuView.h"
#include "Presenter/MainMenuPresenter.h"
#include "BaseMenuView.h"
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

    BaseMenuView::_ready();

    if (!presenter) {
        presenter = new MainMenuPresenter(this);
        UtilityFunctions::print("Presenter created");
    }

    button_paths = {
        "VBoxContainer/PlayButton",
        "VBoxContainer/OptionsButton",
        "VBoxContainer/CreditsButton",
        "VBoxContainer/QuitButton"
    };

    grab_focus_at_index(current_index);

    get_node<Button>("VBoxContainer/PlayButton")->connect("pressed", Callable(this, "_on_play_pressed"));
    get_node<Button>("VBoxContainer/OptionsButton")->connect("pressed", Callable(this, "_on_options_pressed"));
    get_node<Button>("VBoxContainer/CreditsButton")->connect("pressed", Callable(this, "_on_credits_pressed"));
    get_node<Button>("VBoxContainer/QuitButton")->connect("pressed", Callable(this, "_on_quit_pressed"));
}

MainMenuView::~MainMenuView() {
	// Add your cleanup here.
}

void MainMenuView::_process(double delta) {
    handle_navigation(delta);
}

void MainMenuView::_on_play_pressed() {
    UtilityFunctions::print("Play button pressed");
    get_tree()->change_scene_to_file("res://main.tscn");
}

void MainMenuView::_on_options_pressed() {
    UtilityFunctions::print("Options button pressed");
    get_tree()->change_scene_to_file("res://options_menu.tscn");
}

void MainMenuView::_on_credits_pressed() {
    UtilityFunctions::print("Credits button pressed");
    get_tree()->change_scene_to_file("res://credits_menu.tscn");
}

void MainMenuView::_on_quit_pressed() {
    UtilityFunctions::print("Quit button pressed");
    get_tree()->quit();
}

void MainMenuView::set_presenter(MainMenuPresenter* p) {
	presenter = p;
} 