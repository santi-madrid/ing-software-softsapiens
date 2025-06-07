#include "CharacterPresenter.h"
#include "CharacterModel.h"
#include "../View/CharacterView.h"

class CharacterView;

CharacterPresenter::CharacterPresenter(CharacterView *v, int hp, float speed)
    : model(hp, speed), view(v) {
}

CharacterPresenter::~CharacterPresenter() {

}

bool CharacterPresenter::take_damage(int amount){
    return model.take_damage(amount);
}

int CharacterPresenter::get_health() const {
    return model.get_health();
}

void CharacterPresenter::set_speed(double p_speed) {
    model.set_speed(p_speed);
}

double CharacterPresenter::get_speed() const {
    return model.get_speed();
}
