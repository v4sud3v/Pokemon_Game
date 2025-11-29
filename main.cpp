#include "Pokemon.h"

#include <iostream>

int main() {
    Pokemon pikachu(
        "Pikachu",
        100,
        30,
        10,
        Moves{{"Thunderbolt", 40, "Electric"}, {"Quick Attack", 35, "Normal"}}
    );

    Pokemon bulbasaur(
        "Bulbasaur",
        120,
        25,
        15,
        Moves{{"Vine Whip", 35, "Grass"}, {"Tackle", 30, "Normal"}}
    );

    pikachu.display_status();
    bulbasaur.display_status();

    pikachu.use_attack(bulbasaur, 0);
    bulbasaur.display_status();

    bulbasaur.use_attack(pikachu, 0);
    pikachu.display_status();

    return 0;
}