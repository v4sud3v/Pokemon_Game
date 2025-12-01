#pragma once
#include "Moves.h"
#include <cstddef>
#include <string>

class Pokemon {
public:
    Pokemon(const std::string& name, int maxhp, int attack, int defense, Moves moveset);
    ~Pokemon();

    void use_attack(Pokemon& target, std::size_t move_index);
    void receive_damage(int damage);
    bool is_fainted() const;
    void display_status() const;
    
    const std::string& get_name() const;
    std::size_t get_moveset_size() const;
    const std::string& get_move_name(std::size_t index) const;
    int get_move_power(std::size_t index) const;

private:
    std::string name;
    int maxhp;
    int attack;
    int defense;
    int currenthp;
    bool fainted;
    Moves moveset_;
};
