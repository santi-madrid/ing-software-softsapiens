#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/camera2d.hpp>
#include "../Presenter/CharacterPresenter.h"

namespace godot {

class CharacterView: public CharacterBody2D {
	GDCLASS(CharacterView, CharacterBody2D);

private:
	CharacterPresenter* presenter;
	int initial_health;
	float initial_speed;
	double time_passed;
	double time_emit;
	double amplitude;
	double speed;
	float velocity_y;
	float gravity = 600.0f;
	float jump_speed = -450.0f;
	double last_camera_x = 0.0f;
	godot::Camera2D* camera = nullptr;


protected:
	static void _bind_methods();

public:
	CharacterView();
	~CharacterView();

	void _physics_process(double delta) override;

	void set_amplitude(const double amplitude);
	double get_amplitude() const;

	void set_speed(const double speed);
	double get_speed() const;

	bool take_damage(int amount);

	void set_presenter(CharacterPresenter* p);

	void die();
};

}

#endif
