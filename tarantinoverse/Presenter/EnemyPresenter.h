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
    bool take_damage(int amount);
    int get_health() const;
};

#endif // ENEMY_PRESENTER_H
