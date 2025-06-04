#pragma once

#include <godot_cpp/classes/node2d.hpp>
#include "Presenter/ObjectPresenter.h"

using namespace godot;

class ObjectView : public Node2D {
    GDCLASS(ObjectView, Node2D)

private:
    ObjectPresenter* presenter;

public:
    ObjectView();
    ~ObjectView();

    void _ready() override;
    void _process(double delta) override;
    void _on_body_entered(Node* body);

    static void _bind_methods();
};
