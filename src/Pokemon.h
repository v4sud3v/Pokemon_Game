#pragma once

#include <string>

class Pokemon {
public:

    Pokemon(const std::string& name, int maxhp, int attack, int defense);
    ~Pokemon();
    void use_attack(Pokemon& target);
    void receive_damage(int damage);
    bool is_fainted() const;
    void display_status();

private:
    bool fainted;
    std::string name;
    int maxhp;
    int attack;
    int defense;
    int currenthp;
};
