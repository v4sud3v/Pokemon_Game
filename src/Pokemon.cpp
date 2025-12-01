#include "Pokemon.h"

#include <iostream>
#include <utility>

#include "Moves.h"

Pokemon::Pokemon(const std::string& name, int maxhp, int attack, int defense, Moves moveset)
    : name(name),
      maxhp(maxhp),
      attack(attack),
      defense(defense),
      currenthp(maxhp),
      fainted(false),
      moveset_(std::move(moveset))
{
}

Pokemon::~Pokemon() = default;

void Pokemon::use_attack(Pokemon& target, std::size_t move_index) {
    const auto& move = moveset_.at(move_index);
    std::cout << name << " used " << move.name << std::endl;
    target.receive_damage(move.power);
}

void Pokemon::receive_damage(int damage) {
    int damage_taken = damage - defense;
    if (damage_taken < 0) {
        damage_taken = 0;
    }
    if (!fainted || currenthp - damage_taken < 0) {
        currenthp -= damage_taken;
    }
    std::cout << name << " received " << damage_taken << " damage!" << std::endl;
    if (currenthp <= 0) {
        fainted = true;
        currenthp = 0;
        std::cout << name << " has fainted!" << std::endl;
    }
}

bool Pokemon::is_fainted() const {
    return fainted;
}

void Pokemon::display_status() const {
    std::cout << "Pokemon: " << name << std::endl;
    std::cout << "HP: " << currenthp << "/" << maxhp << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Status: " << (fainted ? "Fainted" : "Active") << std::endl;
}

const std::string& Pokemon::get_name() const {
    return name;
}

std::size_t Pokemon::get_moveset_size() const {
    return moveset_.size();
}

const std::string& Pokemon::get_move_name(std::size_t index) const {
    return moveset_.at(index).name;
}

int Pokemon::get_move_power(std::size_t index) const {
    return moveset_.at(index).power;
}