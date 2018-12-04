// Chapter 10. Object Oriented Programming (II)
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

class Warrior
{
    private:
        int attackMax;
        int blockMax;
    
    public:
        std::string name;
        int health;
        // Constructor
        Warrior(std::string name, int health, int attackMax, int blockMax)
        {
            this->name = name;
            this->health = health;
            this->attackMax = attackMax;
            this->blockMax = blockMax;
        }
        int Attack()
        {
            return std::rand() % this->attackMax;
        }
        int Block()
        {
            return std::rand() % this->blockMax;
        }
        
};

class Battle
{
    // Pass the warriors by reference, to change their values while they remain the same
    public:
        static void StartFight(Warrior& warrior1, Warrior& warrior2)
        {
            // Loop forever until the health of one of the warriors goes down to 0
            while(true)
            {
                // If the result is equal to "Game Over", kill the loop and end the fight
                if(Battle::GetAttackResult(warrior1, warrior2).compare("Game Over") == 0)
                {
                    std::cout << "Game Over \n";
                    break;
                }
                // If the result is equal to "Game Over", kill the loop and end the fight
                if(Battle::GetAttackResult(warrior2, warrior1).compare("Game Over") == 0)
                {
                    std::cout << "Game Over \n";
                    break;
                }
            }
        }
        static std::string GetAttackResult(Warrior& warriorA, Warrior& warriorB)
        {
            // Get the attack amount of warrior A
            int warriorAAttackAmt = warriorA.Attack();
            // Get the block amount of warrior B
            int warriorBBlockAmt = warriorB.Block();
            // Get the actual damage
            int damageToWarriorB = ceil(warriorAAttackAmt - warriorBBlockAmt);
            // Protect against negative values coming out. urnary operator
            // In situation in which I got smaller than 0, set it to 0
            damageToWarriorB = (damageToWarriorB <= 0) ? 0 : damageToWarriorB;
            // Subtract the damage from the health
            warriorB.health = warriorB.health - damageToWarriorB;
            // Print out the information
            printf("%s attacks %s and deals %d damage, ", warriorA.name.c_str(), warriorB.name.c_str(), damageToWarriorB);
            printf("%s is down to %d health\n", warriorB.name.c_str(), warriorB.health);
            if(warriorB.health <= 0)
            {
                printf("%s has died and %s is victorious\n", warriorB.name.c_str(), warriorA.name.c_str());
                return "Game Over";
            }
            else
            {
                return "Fight Again";
            }
        }
};

// Main method
int main()
{
    std::cout << "Chapter 10. Part II\n";
    std::cout << "\n";

    srand(time(NULL));

    std::cout << "Let's fight! \n";
    // Objectr of the class Warrior
    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 25, 10);

    // Method StartFight from the class Battle
    Battle::StartFight(thor, hulk);

    return 0;
}