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

void CreditsMenuView::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_process", "delta"), &CreditsMenuView::_process);
    ClassDB::bind_method(D_METHOD("_on_quit_pressed"), &CreditsMenuView::_on_quit_pressed);
}

CreditsMenuView::CreditsMenuView()
    : presenter(nullptr) {}
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

CreditsMenuView::~CreditsMenuView() {
    // Add your cleanup here.
}

void CreditsMenuView::_process(double delta) {
    handle_navigation(delta);
}

void CreditsMenuView::_on_quit_pressed() {
    UtilityFunctions::print("Quit button pressed");
    get_tree()->change_scene_to_file("res://main_menu.tscn");
}

void CreditsMenuView::set_presenter(CreditsMenuPresenter* p) {
    presenter = p;
}