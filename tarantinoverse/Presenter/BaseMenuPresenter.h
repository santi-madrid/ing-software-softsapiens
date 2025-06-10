#pragma once

namespace godot {
    class BaseMenuView;
}

#include "Model/BaseMenuModel.h"

class BaseMenuPresenter {
private:
    BaseMenuModel model;

public:
    BaseMenuPresenter();
    ~BaseMenuPresenter();
};