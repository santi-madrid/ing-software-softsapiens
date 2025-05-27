// Model/CharacterModel.h
#pragma once
class CharacterModel {
private:
    float speed;
public:
    CharacterModel();

    float get_speed() const;
    void set_speed(float s);
};
