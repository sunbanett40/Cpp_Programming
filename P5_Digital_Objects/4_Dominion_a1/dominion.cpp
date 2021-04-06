/*
Project:    Dominion Terminal RPG
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/
#include <iostream>
#include "creature.h"

// Returns type of species
string Creature::getSpecies()
{
    switch (type)
    {
    case 0:
        return "Human";
    case 1:
        return "Cyberdemon";
    case 2:
        return "Balrog";
    case 3:
        return "Elf";
    }
    return "Unknown";
}

public:
Creature();
// Initialize to human, 10 strength, 10 hit points
Creature(int newType, int newStrength, int newHit);
// Initialize creature to new type, strength, hit points
// Also add appropriate accessor and mutator functions
// for type, strength, and hit points


// Returns amount of damage this creature
// inflicts in one round of combat
int Creature::getDamage()
{
    int damage;
    // All creatures inflict damage, which is a
    // random number up to their strength
    damage = (rand() % strength) + 1;
    std::cout << getSpecies() << " attacks for " << damage << " points!" << atd::endl;
    // Demons can inflict damage of 50 with a 5% chance
    if ((type = 2) || (type == 1))
        if ((rand() % 100) < 5)
        {
            damage = damage + 50;
            atd::cout << "Demonic attack inflicts 50 "
                 << " additional damage points!" << std::endl;
        }
    // Elves inflict double magical damage with a 10% chance
    if (type == 3)
    {
        if ((rand() % 10) == 0)
        {
            std::cout << "Magical attack inflicts " << damage << " additional damage points!" << std::endl;
            damage = damage * 2;
        }
    }
    // Balrogs are so fast they get to attack twice
    if (type == 2)
    {
        int damage2 = (rand() % strength) + 1;
        std::cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << std::endl;
        damage = damage + damage2;
    }
    return damage;
}