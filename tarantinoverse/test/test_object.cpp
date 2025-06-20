// test/test_object.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include "Presenter/ObjectPresenter.h"

using namespace godot;

TEST_CASE("ObjectPresenter - General behavior") {
    Vector2 position(10, 20);
    int value = 5;

    SUBCASE("Create COIN object") {
        ObjectPresenter* presenter = ObjectPresenter::create(position, ObjectType::COIN, value);

        CHECK(presenter != nullptr);
        CHECK(presenter->get_type() == ObjectType::COIN);
        CHECK(presenter->get_value() == value);
        CHECK(presenter->get_position() == position);
        CHECK_FALSE(presenter->is_collected());

        presenter->collect();
        CHECK(presenter->is_collected());

        delete presenter;
    }

    SUBCASE("Create HEALTH object") {
        ObjectPresenter* presenter = ObjectPresenter::create(position, ObjectType::HEALTH, value);

        CHECK(presenter->get_type() == ObjectType::HEALTH);
        CHECK(presenter->get_value() == value);

        delete presenter;
    }

    SUBCASE("Create POWERUP object") {
        ObjectPresenter* presenter = ObjectPresenter::create(position, ObjectType::POWERUP, value);

        CHECK(presenter->get_type() == ObjectType::POWERUP);
        CHECK(presenter->get_value() == value);

        delete presenter;
    }

    SUBCASE("Collect object twice") {
        ObjectPresenter* presenter = ObjectPresenter::create(position, ObjectType::COIN, value);

        CHECK_FALSE(presenter->is_collected());
        presenter->collect();
        CHECK(presenter->is_collected());
        presenter->collect(); // Recolectar de nuevo no debe fallar
        CHECK(presenter->is_collected());

        delete presenter;
    }
}