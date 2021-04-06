/*
Project:    Dominion Terminal RPG
Author:     Joseph Butterworth
License:    This work is licensed under the Creative Commons Attribution-ShareAlike License.
            View this license at https://creativecommons.org/licenses/
*/
#include <iostream>
#include<cstring>
#include "dominion.h"
#include "balrog.h"
#include "elf.h"
#include "human.h"
#include "cyberdemon.h"

int main()
{
    printheader();
    Creature playerCharacter = createCharacter();
}

void printheader()
{
    std::cout << "-------------------------------------------------------------------------" << std::endl; 
    std::cout << " _______                           __            __                      " << std::endl;
    std::cout << "/       \\                         /  |          /  |                     " << std::endl;
    std::cout << "#######  |  ______   _____  ____  ##/  _______  ##/   ______   _______   " << std::endl;
    std::cout << "## |  ## | /      \\ /     \\/    \\ /  |/       \\ /  | /      \\ /       \\  " << std::endl;
    std::cout << "## |  ## |/######  |###### ####  |## |#######  |## |/######  |#######  | " << std::endl;
    std::cout << "## |  ## |## |  ## |## | ## | ## |## |## |  ## |## |## |  ## |## |  ## | " << std::endl;
    std::cout << "## |__## |## \\__## |## | ## | ## |## |## |  ## |## |## \\__## |## |  ## | " << std::endl;        
    std::cout << "##    ##/ ##    ##/ ## | ## | ## |## |## |  ## |## |##    ##/ ## |  ## | " << std::endl;
    std::cout << "#######/   ######/  ##/  ##/  ##/ ##/ ##/   ##/ ##/  ######/  ##/   ##/  " << std::endl;
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "                               Terminal RPG                              " << std::endl;
    std::cout << "-------------------------------------------------------------------------" << std::endl;
}

Creature createCharacter()
{
    int input;

    std::cout << "What class would you like to play as?" << std::endl;
    std::cout << "Press 1-Human 2-Cyberdemon 3-Balrog 4-Elf" << std::endl;
    switch (input)
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

}