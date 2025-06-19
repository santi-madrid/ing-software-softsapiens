// ObjectView.h
#pragma once

#include "../Core/ObjectType.h"
#include "Presenter/ObjectPresenter.h"
#include <godot_cpp/classes/node2d.hpp>


using namespace godot;

/**
 * @class ObjectView
 * @brief Vista de objetos recolectables o interactuables en el juego.
 *
 * Gestiona la presentación y detección de colisiones de los objetos.
 */
class ObjectView : public Node2D {
  GDCLASS(ObjectView, Node2D)

private:
  ObjectPresenter *presenter;
  int object_type; // será casteado a ObjectType

public:
  ObjectView();
  ~ObjectView();

  void set_object_type(int type);
  int get_object_type() const;

  void _ready() override;
  void _process(double delta) override;
  void _on_body_entered(Node *body);

  static void _bind_methods();
};
