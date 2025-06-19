#include "EnemyView.h"
#include "BulletView.h"
#include "EnemyPresenter.h"
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/sprite2d.hpp>

/**
 * @brief Constructor de EnemyView. Inicializa el presenter y variables por
 * defecto.
 */
EnemyView::EnemyView()
    : presenter(nullptr), initial_health(100), initial_speed(-50.0f) {}

/**
 * @brief Inicializa la vista del enemigo y crea el presenter si es necesario.
 */
void EnemyView::_ready() {
  UtilityFunctions::print("EnemyView::_ready called");
  if (!presenter) {
    presenter = new EnemyPresenter(this, initial_health, initial_speed);
    UtilityFunctions::print("Presenter created");
  }

  // Ajustar flip inicial según la dirección
  AnimatedSprite2D *sprite = Object::cast_to<AnimatedSprite2D>(
      get_node<AnimatedSprite2D>("AnimatedSprite2D"));
  if (sprite) {
    sprite->set_flip_h(false); // Siempre inicia sin flip
    if (initial_speed > 0) {
      sprite->set_flip_h(true);
    }
    sprite->play("walk"); // Iniciar animación walk
  }
}

/**
 * @brief Proceso de física y disparo del enemigo. Maneja movimiento, disparos y
 * reseteo de balas.
 * @param delta Tiempo transcurrido desde el último frame.
 */
void EnemyView::_physics_process(double delta) {
  shoot_timer += delta;
  static float reset_timer = 0.0f;
  reset_timer += delta;

  if (presenter) {
    presenter->on_update(delta);
  }
  Vector2 velocity = get_velocity();
  velocity.y += gravity * delta;

  // Lógica de movimiento automático en X
  velocity.x = initial_speed;

  set_velocity(velocity);
  move_and_slide();

  // Si el enemigo cae por debajo del piso (por ejemplo, y > 2000), muere
  if (get_global_position().y > 2000) {
    die();
    return;
  }

  // Si el enemigo choca con una pared, se da la vuelta
  if (is_on_wall()) {
    for (int i = 0; i < get_slide_collision_count(); i++) {
      Ref<KinematicCollision2D> collision = get_slide_collision(i);
      if (collision.is_valid()) {
        Node *collider = Object::cast_to<Node>(collision->get_collider());
        if (collider && collider->is_in_group("walls")) {
          AnimatedSprite2D *sprite = Object::cast_to<AnimatedSprite2D>(
              get_node<AnimatedSprite2D>("AnimatedSprite2D"));
          if (sprite) {
            sprite->set_flip_h(!sprite->is_flipped_h());
            sprite->play("walk"); // Asegura que siga animando walk
          }
          initial_speed = -initial_speed;
          break;
        }
      }
    }
  }

  if (shoot_timer >= shoot_interval) {
    shoot_timer = 0.0f;

    // Disparo
    Ref<PackedScene> bullet_scene =
        ResourceLoader::get_singleton()->load("res://Bullet.tscn");
    if (bullet_scene.is_valid()) {
      Node2D *bullet_instance =
          Object::cast_to<Node2D>(bullet_scene->instantiate());
      if (bullet_instance) {
        AnimatedSprite2D *sprite = Object::cast_to<AnimatedSprite2D>(
            get_node<AnimatedSprite2D>("AnimatedSprite2D"));
        int dir = sprite->is_flipped_h() ? 1 : -1;

        // Asignar el shooter (this) a la bala
        BulletView *bullet = Object::cast_to<BulletView>(bullet_instance);
        if (bullet) {
          bullet->set_shooter(this);
        }

        bullet_instance->set("direction", dir);
        bullet_instance->set_position(get_position());
        get_parent()->add_child(bullet_instance);
      }
    }
  }
  bullets_shot++;

  reset_timer += delta;

  if (reset_timer >= 3.0f) {
    bullets_shot = 0;
    reset_timer = 0.0f;
  }

  move_and_slide();
}

/**
 * @brief Ejecuta una animación visual de daño (placeholder).
 */
void EnemyView::play_damage_animation() {
  // ejemplo visual: shake o flash
}

/**
 * @brief Maneja la muerte del enemigo y su destrucción.
 */
void EnemyView::die() {
  queue_free(); // o alguna animación antes
}

/**
 * @brief Aplica daño al enemigo y lo delega al presenter.
 * @param amount Cantidad de daño recibido.
 * @return true si el enemigo muere, false en caso contrario.
 */
bool EnemyView::take_damage(int amount) {
  UtilityFunctions::print("take_damage called with amount: ", amount);
  if (!presenter) {
    UtilityFunctions::print("ERROR: Presenter is null!");
    return false;
  }
  bool result = presenter->take_damage(amount);
  UtilityFunctions::print("take_damage result: ", result);
  return result;
}

/**
 * @brief Registra los métodos y señales de EnemyView para Godot.
 */
void EnemyView::_bind_methods() {
  ClassDB::bind_method(D_METHOD("update_position", "pos"),
                       &EnemyView::update_position);
  ClassDB::bind_method(D_METHOD("play_damage_animation"),
                       &EnemyView::play_damage_animation);
}
