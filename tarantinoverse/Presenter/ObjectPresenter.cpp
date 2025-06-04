// Presenter/ObjectPresenter.cpp

#include "ObjectPresenter.h"

ObjectPresenter::ObjectPresenter(godot::Vector2 start_pos, ObjectType obj_type, int value)
    : model(new ObjectModel(start_pos, obj_type, value)) {}

ObjectPresenter::~ObjectPresenter() {
    delete model;
}

void ObjectPresenter::collect() {
    model->collect();
}

bool ObjectPresenter::is_collected() const {
    return model->is_collected();
}

ObjectType ObjectPresenter::get_type() const {
    return model->get_type();
}

int ObjectPresenter::get_value() const {
    return model->get_value();
}

godot::Vector2 ObjectPresenter::get_position() const {
    return model->get_position();
}
