/*
Project:    Dominion Terminal RPG
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/
#include"creature.h"

class Demon : public Creature
{
private:
    int type;            // 0 human, 1 cyberdemon, 2 balrog, 3 elf
    int strength;        // How much damage we can inflict
    int hitpoints;       // How much damage we can sustain
    string getSpecies(); // Returns type of species
public:
    Demon();
    // Initialize to human, 10 strength, 10 hit points
    Demon(int newType, int newStrength, int newHit);
    // Initialize creature to new type, strength, hit points
    // Also add appropriate accessor and mutator functions
    // for type, strength, and hit points
    int getDamage();
    // Returns amount of damage this creature
    // inflicts in one round of combat
};