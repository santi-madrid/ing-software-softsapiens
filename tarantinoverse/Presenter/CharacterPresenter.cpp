#include "CharacterPresenter.h"
#include "CharacterModel.h"

CharacterPresenter::CharacterPresenter() {
    model = new CharacterModel();
}

CharacterPresenter::~CharacterPresenter() {
    delete model;
}

void CharacterPresenter::set_speed(double p_speed) {
    model->set_speed(p_speed);
}

double CharacterPresenter::get_speed() const {
    return model->get_speed();
}
