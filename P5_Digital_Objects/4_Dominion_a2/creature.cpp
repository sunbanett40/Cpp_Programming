/*
Project:    Dominion Terminal RPG
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/
#include <iostream>
#include <cstring>
#include "creature.h"
#include "demon.h"
#include "elf.h"
#include "human.h"
#include "balrog.h"
#include "cyberdemon.h"






// Returns type of species
std::string Creature::getSpecies()
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

int Creature::getStrength()
{
    return strength;
}
void Creature::modifyStrength(int strengthmodify)
{
    strength += strengthmodify;
}

int Creature::getHitPoints()
{
    return hitpoints;
}
void Creature::modifyHitPoints(int hitpointsmodify)
{
    hitpoints += hitpointsmodify;
} 

// Returns amount of damage this creature
// inflicts in one round of combat
int Creature::getDamage()
{
    int damage;
    // All creatures inflict damage, which is a
    // random number up to their strength
    damage = (rand() % strength) + 1;
    std::cout << getSpecies() << " attacks for " << damage << " points!" << std::endl;

    return damage;
}

int Demon::getDamage()
{
    int damage;
    // All creatures inflict damage, which is a
    // random number up to their strength
    damage = (rand() % strength) + 1;
    std::cout << getSpecies() << " attacks for " << damage << " points!" << std::endl;
    // Demons can inflict damage of 50 with a 5% chance
    if ((rand() % 100) < 5)
    {
        damage = damage + 50;
        std::cout << "Demonic attack inflicts 50 "
                  << " additional damage points!" << std::endl;
    }

    return damage;
}
int Elf::getDamage()
{
    int damage;
    // All creatures inflict damage, which is a
    // random number up to their strength
    damage = (rand() % strength) + 1;
    std::cout << getSpecies() << " attacks for " << damage << " points!" << std::endl;
    // Elves inflict double magical damage with a 10% chance

    if ((rand() % 10) == 0)
    {
        std::cout << "Magical attack inflicts " << damage << " additional damage points!" << std::endl;
        damage = damage * 2;
    }

    return damage;
}
int Balrog::getDamage()
{
    int damage;
    // All creatures inflict damage, which is a
    // random number up to their strength
    damage = (rand() % strength) + 1;
    std::cout << getSpecies() << " attacks for " << damage << " points!" << std::endl;
    // Demons can inflict damage of 50 with a 5% chance
    if ((rand() % 100) < 5)
    {
        damage = damage + 50;
        std::cout << "Demonic attack inflicts 50 "
                  << " additional damage points!" << std::endl;
    }
    // Balrogs are so fast they get to attack twice

    int damage2 = (rand() % strength) + 1;
    std::cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << std::endl;
    damage = damage + damage2;

    return damage;
}
