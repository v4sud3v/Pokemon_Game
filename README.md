# Pokémon Battle Simulator (C++)

A command-line Pokémon-style battle game built in C++.  
Choose your Pokémon, face a random opponent, and battle using different move types until one faints.

---

## 🧩 How the Game Works
- **Pokémon Selection**: Choose from 4 starter Pokémon (Pikachu, Bulbasaur, Charmander, Squirtle)
- **Random Opponent**: The game randomly selects an opponent from the remaining Pokémon
- **Turn-Based Combat**: Player and opponent alternate turns until one Pokémon faints

### Pokémon Stats
Each Pokémon has:
- **Name**
- **Max HP** (Health Points)
- **Current HP**
- **Attack Power**
- **Defense Value**
- **Moveset** (4 unique moves)

### Move Types
Each Pokémon has access to 4 moves with different types:

1. **Attack Moves** 🗡️
   - Deals damage to the opponent
   - Damage calculation: `damage_taken = move_power - target_defense`
   - Minimum damage is 0 (high defense can negate weak attacks)

2. **Defense Moves 🛡️**
   - Temporarily boosts the user's defense for one turn
   - Defense buff = move power
   - Increases effective defense during damage calculation
   - Buff clears at the start of the next turn

3. **Heal Moves 💚**
   - Restores HP based on move power
   - Cannot exceed max HP
   - Strategic for prolonging battles

---

## 🎮 Gameplay Flow

1. **Select Your Pokémon** from the roster
2. **Battle Start** - Face your randomly chosen opponent
3. **Each Turn**:
   - View both Pokémon's current status (HP, Attack, Defense, buffs)
   - Choose one of your 4 moves
   - Opponent randomly selects a move
   - Defense buffs clear at the start of each new turn
4. **Victory Condition** - First Pokémon to reach 0 HP faints and loses

---

## 🏗️ Project Structure
