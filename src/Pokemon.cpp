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
      moveset_(std::move(moveset)),
      defense_buff(0)
{
}

Pokemon::~Pokemon() = default;

void Pokemon::use_move(Pokemon& target, std::size_t move_index) {
    const auto& move = moveset_.at(move_index);
    std::cout << name << " used " << move.name << "!" << std::endl;
    
    switch (move.moveType) {
        case MoveType::ATTACK:
            target.receive_damage(move.power);
            break;
            
        case MoveType::DEFENSE:
            defense_buff = move.power;
            std::cout << name << "'s defense increased by " << defense_buff << " for this turn!" << std::endl;
            break;
            
        case MoveType::HEAL:
            currenthp += move.power;
            if (currenthp > maxhp) {
                currenthp = maxhp;
            }
            std::cout << name << " restored " << move.power << " HP!" << std::endl;
            break;
    }
}

void Pokemon::receive_damage(int damage) {
    int effective_defense = defense + defense_buff;
    int damage_taken = damage - effective_defense;
    if (damage_taken < 0) {
        damage_taken = 0;
    }
    
    currenthp -= damage_taken;
    std::cout << name << " received " << damage_taken << " damage!" << std::endl;
    
    if (currenthp <= 0) {
        fainted = true;
        currenthp = 0;
        std::cout << name << " has fainted!" << std::endl;
    }
}

void Pokemon::clear_defense_buff() {
    if (defense_buff > 0) {
        std::cout << name << "'s defense buff wore off." << std::endl;
        defense_buff = 0;
    }
}

bool Pokemon::is_fainted() const {
    return fainted;
}

void Pokemon::display_status() const {
    std::cout << "Pokemon: " << name << std::endl;
    std::cout << "HP: " << currenthp << "/" << maxhp << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense;
    if (defense_buff > 0) {
        std::cout << " (+" << defense_buff << " buff)";
    }
    std::cout << std::endl;
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

MoveType Pokemon::get_move_type(std::size_t index) const {
    return moveset_.at(index).moveType;
}