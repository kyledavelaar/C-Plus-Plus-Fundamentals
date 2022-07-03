#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <array>
#include <random>
#include <cstdlib> // rand() and srand()
#include <ctime>

// assumes std::srand has already been called
int getRandomNumber(int min, int max) {
    // static so only gets calculated once
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int getRandomNumber2(int min, int max) {
    std::random_device randomDevice;
    std::mt19937 randomGenerator(randomDevice());
    std::uniform_int_distribution<int> minMax(min, max);
    return minMax(randomGenerator);
}

class Creature {
protected:
    std::string m_name{};
    char m_symbol{};
    int m_health{};
    int m_damage{};
    int m_gold{};

public:
    Creature(std::string_view name, char symbol, int health, int damage, int gold) : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold } {}

    const std::string& getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    void reduceHealth(int amount) { m_health -= amount; }
    bool isDead() { return m_health <= 0; }
    void addGold(int amount) { m_gold += amount; }
};

class Player : public Creature {
private:
    int m_level{1};

public:
    Player(std::string_view name) : Creature{name, '@', 10, 1, 0} {}

    int getLevel() const { return m_level; }

    void levelUp() {
        m_level += 1;
        m_damage += 1;
    }
    bool hasWon() const { return m_level >= 10; }

    void attackMonster(Player player) {

    }
};

class Monster : public Creature {
public:
    enum class Type {
        DRAGON,
        ORC,
        SLIME,
        max_types
    };

    Monster(Type type): Creature { getDefaultCreature(type) } {}

    static Monster getRandomMonster() {
        std::cout << "Generating Random Monster" << '\n';
        int max { static_cast<int>(Type::max_types) - 1 };
        int num{ getRandomNumber(0, max)};
        return Monster{ static_cast<Type>(num) };
    }

    // another way to get random
    Monster static getRandomMonster2() {
        int max{ static_cast<int>(Type::max_types) - 1};
        int randomNumber{ getRandomNumber2(0, max) };
        Type type{ static_cast<Type>(randomNumber) };
        return Monster{ type };
    }

    void attackPlayer(Player player) {
        // reduce player health by monster attack
        // need to make friend function to have access to reduce player health?
        // or return amount to reduce player health by?
    }

private:
    static const Creature& getDefaultCreature(Type type) {
        static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData {
            {
                { "dragon", 'D', 20, 4, 100},
                { "orc", 'O', 4, 2, 25 },
                { "slime", 'S', 1, 1, 10 }
            }
        };
        return monsterData.at(static_cast<std::size_t>(type));
    }
};

std::ostream& operator<<(std::ostream& out, Player& player) {
    std::cout << "-----------------" << '\n';
    std::cout << "PLAYER NAME: " << player.getName() << '\n';
    std::cout << "PLAYER HEALTH: " << player.getHealth() << '\n';
    std::cout << "PLAYER DAMAGE: " << player.getDamage() << '\n';
    std::cout << "PLAYER GOLD: " << player.getGold() << '\n';
    std::cout << "PLAYER LEVEL: " << player.getLevel() << '\n';
    std::cout << "-----------------" << '\n';
    return out;
}
std::ostream& operator<<(std::ostream& out, Monster& monster) {
    std::cout << "-----------------" << '\n';
    std::cout << "MONSTER NAME: " << monster.getName() << '\n';
    std::cout << "MONSTER HEALTH: " << monster.getHealth() << '\n';
    std::cout << "MONSTER DAMAGE: " << monster.getDamage() << '\n';
    std::cout << "MONSTER GOLD: " << monster.getGold() << '\n';
    std::cout << "-----------------" << '\n';
    return out;
}

void attack(Creature& attacker, Creature& wounded) {
    std::cout << attacker.getName() << " wounds " << wounded.getName() << " with damage: " << attacker.getDamage() << '\n';
    wounded.reduceHealth(attacker.getDamage());
}

std::string runOrFlee() {
    std::string option{};
    std::cout << "Run (r) or Fight (f) ?: ";
    std::cin >> option;
    // std::cout << "You chose: " << option << '\n';
    while (!(option == "r" || option == "f")) {
        std::cout << "You must choose either r or f." << " Please choose again:" << '\n';
        std::cin.clear();
        std::cin >> option;
    }
    if (option == "f") {
        std::cout << "You chose to Fight" << '\n';
    }
    if (option == "r") {
        std::cout << "You chose to Run" << '\n';
    }

    return option;
}

bool calculateIfCaught() {
    int random{ getRandomNumber(0, 1) };
    return random % 2 == 0;
}

void startGame(Player& player) {
    bool generateNewMonster{ true };
    Monster monster{ Monster::getRandomMonster() };
    // bool run{};

    while(!player.isDead() && !player.hasWon()) {
        if (generateNewMonster) {
            // make monster static so don't need to instantiate above too?
            monster = Monster::getRandomMonster();
        }
        std::cout << player << " approaches " << '\n' << monster;
        std::string option{ runOrFlee() };

        if (option == "r") {
            bool caught{ calculateIfCaught() };
            if (caught) {
                std::cout << player.getName() << " ran but was caught!" << '\n';
                attack(monster, player); // monster attacks
                if (player.isDead()) {
                    break; // which will end main while loop b/c game is over
                } else {
                    std::cout << player.getName() << " survived the attack from " << monster.getName() << '\n';
                    generateNewMonster = false;
                    continue;  // so go back to asking player to r/f the same monster
                }
            } else {
                std::cout << player.getName() << " ran and was not caught by " << monster.getName() << '\n';
                generateNewMonster = true;
                player.levelUp();
                continue; // start main while loop again
            }
        } else {
            // do we keep fighting until one is dead if choose to fight? or just go one round?
            while (!monster.isDead() && !player.isDead() && !player.hasWon()) {
                attack(player, monster); // player attacks
                if (monster.isDead()) {
                    std::cout << player.getName() << " killed " << monster.getName() << '\n';
                    player.addGold(monster.getGold()); // player takes monster's gold
                    player.levelUp(); // player moves up 1 level
                    generateNewMonster = true;
                    break; // exit from this fighting while loop
                } else {
                    attack(monster, player); // monster attacks
                }
            }
        }
    }

    if (!player.isDead()) {
        std::cout << "You Won! Gold total: " << player.getGold() << '\n';
    } else {
        std::cout << "You lost. You died at level " << player.getLevel() << " with " << player.getGold() << " coins." << '\n';
    }
}



int main() {
    // // set initial seed to system clock
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand(); // omit first result

	// Creature o{ "orc", 'o', 4, 2, 10 };
	// o.addGold(5);
	// o.reduceHealth(1);
	// std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";
    // //-------------------------------------------------------------------------
    std::string name{};
    std::cout << "Enter your name: " << '\n';
    std::cin >> name;
    std::cout << "Welcome: " << name << '\n';
    Player player1{name};
    // std::cout << "You have " << player1.getHealth() << " health and are carrying " << player1.getGold() << " gold." << '\n';
    // //-------------------------------------------------------------------------
    // Monster m{ Monster::Type::ORC };
	// std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
    // //-------------------------------------------------------------------------
    // for (int i{ 0 }; i < 5; i++) {
    //     Monster m{ Monster::getRandomMonster() };
    //     std::cout << "getRandomMonster: " << m.getName() << '\n';
    //     Monster m2{ Monster::getRandomMonster2() };
    //     std::cout << "getRandomMonster2: " << m2.getName() << '\n';
    // }
    // //-------------------------------------------------------------------------

    startGame(player1);
    /*
    The player encounters one randomly generated monster at a time.
    For each monster, the player has two choices: (R)un or (F)ight.
    If the player decides to Run, they have a 50% chance of escaping.
    If the player escapes, they move to the next encounter with no ill effects.
    If the player does not escape, the monster gets a free attack, and the player chooses their next action.
    If the player chooses to fight, the player attacks first. The monster’s health is reduced by the player’s damage.
    If the monster dies, the player takes any gold the monster is carrying. The player also levels up, increasing their level and damage by 1.
    If the monster does not die, the monster attacks the player back. The player’s health is reduced by the monster’s damage.
    The game ends when the player has died (loss) or reached level 20 (win)
    If the player dies, the game should tell the player what level they were and how much gold they had.
    If the player wins, the game should tell the player they won, and how much gold they had
    */

    /*

    generateNewMonster = true;

    while(playerAlive && playerLevel < 20) {
        - if (generateNewMonster) {
            generate random monster
        }
        - ask player to r or f
        - if (run) {
            caught = calculate if caught (odd/even random, odd escape, even caught)
            if (caught) {
                monsterAttacks()
                if (player not dead) {
                    generateNewMonster = false;
                    continue;  so go back to asking player to r/f
                } else {
                    break; which will end main while loop b/c !playerAlive
                }
            } else {
                - increase level
                - start main while loop again -> continue;
            }
        } else {
            // do we keep fighting until one is dead if choose to fight? or just go one round?
            while (monsterAlive && playerAlive && playerLevel < 20) {
                playerAttacks()
                if (monster not dead) {
                    monsterAttacks();
                } else {
                    player takes monster's gold
                    player moves up 1 level
                    continue;
                }
            }
        }
    }
    if (playerAlive) {
        tell player they won and how much gold they have
    } else {
        tell player what level they died on and how much gold they have
    }

    */
    return 0;
}