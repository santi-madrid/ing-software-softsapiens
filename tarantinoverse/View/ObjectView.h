// ObjectView.h
#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include "Presenter/ObjectPresenter.h"
#include "../Core/ObjectType.h"

using namespace godot;

class ObjectView : public Node2D {
    GDCLASS(ObjectView, Node2D)

private:
    ObjectPresenter* presenter;
    int object_type; // será casteado a ObjectType

public:
    ObjectView();
    ~ObjectView();

    void set_object_type(int type);
    int get_object_type() const;

    void _ready() override;
    void _process(double delta) override;
    void _on_body_entered(Node* body);

    static void _bind_methods();
};
