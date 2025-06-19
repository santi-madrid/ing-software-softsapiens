// Presenter/ObjectPresenter.cpp

#include "ObjectPresenter.h"

using namespace godot;

/**
 * @brief Constructor de ObjectPresenter. Inicializa el modelo del objeto.
 * @param start_pos Posición inicial.
 * @param obj_type Tipo de objeto.
 * @param value Valor asociado al objeto.
 */
ObjectPresenter::ObjectPresenter(godot::Vector2 start_pos, ObjectType obj_type, int value)
    : model(new ObjectModel(start_pos, obj_type, value)) {}

/**
 * @brief Destructor de ObjectPresenter. Libera el modelo.
 */
ObjectPresenter::~ObjectPresenter() {
    delete model;
}

/**
 * @brief Método factory para crear un ObjectPresenter.
 * @param start_pos Posición inicial.
 * @param obj_type Tipo de objeto.
 * @param value Valor asociado al objeto.
 * @return Nuevo ObjectPresenter.
 */
ObjectPresenter* ObjectPresenter::create(godot::Vector2 start_pos, ObjectType obj_type, int value) {
    // Aquí podría haber lógica condicional más compleja según el tipo
    // Pensado para escalar el proyecto. Facilita la testeabilidad
    return new ObjectPresenter(start_pos, obj_type, value);
}

/**
 * @brief Marca el objeto como recogido.
 */
void ObjectPresenter::collect() {
    model->collect();
}

/**
 * @brief Indica si el objeto fue recogido.
 * @return true si fue recogido, false en caso contrario.
 */
bool ObjectPresenter::is_collected() const {
    return model->is_collected();
}

/**
 * @brief Obtiene el tipo de objeto.
 * @return Tipo de objeto.
 */
ObjectType ObjectPresenter::get_type() const {
    return model->get_type();
}

/**
 * @brief Obtiene el valor asociado al objeto.
 * @return Valor del objeto.
 */
int ObjectPresenter::get_value() const {
    return model->get_value();
}

/**
 * @brief Obtiene la posición del objeto.
 * @return Posición.
 */
godot::Vector2 ObjectPresenter::get_position() const {
    return model->get_position();
}
