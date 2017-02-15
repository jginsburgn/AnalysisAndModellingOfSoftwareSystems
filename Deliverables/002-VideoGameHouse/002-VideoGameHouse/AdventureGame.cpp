//
//  AdventureGame.cpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/14/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include "AdventureGame.hpp"

std::string AdventureGame::getDescription() const {
    std::string retVal = Game::getDescription() + "\n";
    retVal += "Number of Levels: " + std::to_string(numberOfLevels) + "%\n";
    retVal += "Number of Weapons: " + std::to_string(numberOfWeapons) + "\n";
    retVal += "Number of Characters: " + std::to_string(numberOfCharacters) + "\n";
    retVal += "Number of Objectives: " + std::to_string(numberOfObjectives) + "%\n";
    retVal += "Number of Trophies: " + std::to_string(numberOfTrophies) + "s";
    return retVal;
}

void AdventureGame::conception() {
    Helper::print(getName() + " is being conceived.");
    numberOfLevels = Helper::read<int>("What is the number of levels in the game?");
}

void AdventureGame::design() {
    Helper::print(getName() + " is being designed.");
    numberOfWeapons = Helper::read<int>("What is the number of weapons in the game?");
}

void AdventureGame::planning() {
    Helper::print(getName() + " is being planned.");
    numberOfCharacters = Helper::read<int>("What is the number of characters in the game?");
}

void AdventureGame::production() {
    Helper::print(getName() + " is being produced.");
    numberOfObjectives = Helper::read<int>("What is the number of objectives in the game?");
}

void AdventureGame::testing() {
    Helper::print(getName() + " is being tested.");
    numberOfTrophies = Helper::read<int>("What is the number of trophies in the game?");
}
