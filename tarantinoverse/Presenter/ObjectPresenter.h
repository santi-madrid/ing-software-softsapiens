// Presenter/ObjectPresenter.h
#pragma once

#include "../Core/ObjectType.h"
#include "Model/ObjectModel.h"


/**
 * @class ObjectPresenter
 * @brief Presenter para objetos recolectables o interactuables. Conecta la
 * vista y el modelo del objeto.
 */
class ObjectPresenter {
private:
  ObjectModel *model;
  float time_alive;

public:
  ObjectPresenter(godot::Vector2 start_pos, ObjectType obj_type, int value);
  ~ObjectPresenter();

  // Método Factory
  static ObjectPresenter *create(godot::Vector2 start_pos, ObjectType obj_type,
                                 int value);

  void collect();
  bool is_collected() const;
  ObjectType get_type() const;
  int get_value() const;
  godot::Vector2 get_position() const;
};
