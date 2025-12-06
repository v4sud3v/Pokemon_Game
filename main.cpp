#include "Pokemon.h"

#include <iostream>
#include <vector>
#include <random>
#include <memory>

std::vector<std::unique_ptr<Pokemon>> create_pokemon_roster() {
    std::vector<std::unique_ptr<Pokemon>> roster;
    
    roster.push_back(std::make_unique<Pokemon>(
        "Pikachu", 100, 30, 10,
        Moves{
            {"Thunderbolt", 40, "Electric", MoveType::ATTACK},
            {"Quick Attack", 35, "Normal", MoveType::ATTACK},
            {"Iron Tail", 15, "Steel", MoveType::DEFENSE},
            {"Rest", 25, "Normal", MoveType::HEAL}
        }
    ));
    
    roster.push_back(std::make_unique<Pokemon>(
        "Bulbasaur", 120, 25, 15,
        Moves{
            {"Vine Whip", 35, "Grass", MoveType::ATTACK},
            {"Tackle", 30, "Normal", MoveType::ATTACK},
            {"Withdraw", 20, "Water", MoveType::DEFENSE},
            {"Synthesis", 30, "Grass", MoveType::HEAL}
        }
    ));
    
    roster.push_back(std::make_unique<Pokemon>(
        "Charmander", 95, 35, 8,
        Moves{
            {"Ember", 40, "Fire", MoveType::ATTACK},
            {"Scratch", 30, "Normal", MoveType::ATTACK},
            {"Defense Curl", 18, "Normal", MoveType::DEFENSE},
            {"Recover", 20, "Normal", MoveType::HEAL}
        }
    ));
    
    roster.push_back(std::make_unique<Pokemon>(
        "Squirtle", 110, 28, 12,
        Moves{
            {"Water Gun", 38, "Water", MoveType::ATTACK},
            {"Tackle", 30, "Normal", MoveType::ATTACK},
            {"Withdraw", 22, "Water", MoveType::DEFENSE},
            {"Aqua Ring", 28, "Water", MoveType::HEAL}
        }
    ));
    
    return roster;
}

void display_pokemon_menu(const std::vector<std::unique_ptr<Pokemon>>& roster) {
    std::cout << "\n=== Choose Your Pokemon ===\n";
    for (size_t i = 0; i < roster.size(); ++i) {
        std::cout << i + 1 << ". " << roster[i]->get_name() << "\n";
    }
    std::cout << "===========================\n";
}

int get_player_choice(int max_options) {
    int choice;
    while (true) {
        std::cout << "Enter your choice (1-" << max_options << "): ";
        std::cin >> choice;
        
        if (std::cin.fail() || choice < 1 || choice > max_options) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid choice. Try again.\n";
        } else {
            std::cin.ignore(10000, '\n');
            return choice - 1;
        }
    }
}

int get_random_opponent(int player_choice, int roster_size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, roster_size - 2);
    
    int opponent = dis(gen);
    if (opponent >= player_choice) {
        opponent++;
    }
    
    return opponent;
}

void display_move_menu(const Pokemon& pokemon) {
    std::cout << "\n=== Choose Your Move ===\n";
    for (size_t i = 0; i < pokemon.get_moveset_size(); ++i) {
        std::string type_str;
        switch (pokemon.get_move_type(i)) {
            case MoveType::ATTACK: type_str = "Attack"; break;
            case MoveType::DEFENSE: type_str = "Defense"; break;
            case MoveType::HEAL: type_str = "Heal"; break;
        }
        std::cout << i + 1 << ". " << pokemon.get_move_name(i) 
                  << " (Power: " << pokemon.get_move_power(i) 
                  << ", Type: " << type_str << ")\n";
    }
    std::cout << "========================\n";
}

void battle(Pokemon& player, Pokemon& opponent) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::cout << "\n*** Battle Start! ***\n";
    std::cout << player.get_name() << " vs " << opponent.get_name() << "\n\n";
    
    while (!player.is_fainted() && !opponent.is_fainted()) {
        // Clear defense buffs at start of turn
        player.clear_defense_buff();
        opponent.clear_defense_buff();
        
        // Player's turn
        std::cout << "\n--- Your Turn ---\n";
        player.display_status();
        display_move_menu(player);
        
        int move_choice = get_player_choice(player.get_moveset_size());
        player.use_move(opponent, move_choice);
        
        if (opponent.is_fainted()) {
            std::cout << "\n*** You Win! ***\n";
            break;
        }
        
        // Opponent's turn
        std::cout << "\n--- Opponent's Turn ---\n";
        std::uniform_int_distribution<> dis(0, opponent.get_moveset_size() - 1);
        int opponent_move = dis(gen);
        
        opponent.use_move(player, opponent_move);
        
        if (player.is_fainted()) {
            std::cout << "\n*** You Lost! ***\n";
            break;
        }
    }
}

int main() {
    std::cout << "=== Welcome to Pokemon Battle! ===\n\n";
    
    auto roster = create_pokemon_roster();
    
    display_pokemon_menu(roster);
    int player_choice = get_player_choice(roster.size());
    
    int opponent_choice = get_random_opponent(player_choice, roster.size());
    
    std::cout << "\nYou chose: " << roster[player_choice]->get_name() << "\n";
    std::cout << "Your opponent: " << roster[opponent_choice]->get_name() << "\n";
    
    battle(*roster[player_choice], *roster[opponent_choice]);
    
    std::cout << "\n=== Game Over ===\n";
    
    return 0;
}