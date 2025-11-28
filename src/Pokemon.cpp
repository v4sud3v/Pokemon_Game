#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon(const std::string& name, int maxhp, int attack, int defense)
    : name(name),
      maxhp(maxhp),
      attack(attack),
      defense(defense),
      currenthp(maxhp),
      fainted(false)
{
}
Pokemon::~Pokemon() {}

void Pokemon::use_attack(Pokemon& target) {
    std::cout << name << " used" << attack<< std::endl;
    target.receive_damage(attack);

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

void Pokemon::display_status() {
    std::cout << "Pokemon: " << name << std::endl;
    std::cout << "HP: " << currenthp << "/" << maxhp << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Status: " << (fainted ? "Fainted" : "Active") << std::endl;
}