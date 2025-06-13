// Presenter/ObjectPresenter.cpp

#include "ObjectPresenter.h"

using namespace godot;

ObjectPresenter::ObjectPresenter(godot::Vector2 start_pos, ObjectType obj_type, int value)
    : model(new ObjectModel(start_pos, obj_type, value)) {}

ObjectPresenter::~ObjectPresenter() {
    delete model;
}

// Método Factory
ObjectPresenter* ObjectPresenter::create(godot::Vector2 start_pos, ObjectType obj_type, int value) {
    // Aquí podría haber lógica condicional más compleja según el tipo
    // Pensado para escalar el proyecto. Facilita la testeabilidad
    return new ObjectPresenter(start_pos, obj_type, value);
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
