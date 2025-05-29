#ifndef ENEMY_PRESENTER_H
#define ENEMY_PRESENTER_H

#include "Model/EnemyModel.h" // Este sí lo necesitás completo

// 👇 Forward declaration
class EnemyView;

class EnemyPresenter {
private:
    EnemyModel model;
    EnemyView* view;

public:
    EnemyPresenter(EnemyView* v, int hp, float speed);

    void on_update(double delta);
    void take_damage(int dmg);
};

#endif // ENEMY_PRESENTER_H
