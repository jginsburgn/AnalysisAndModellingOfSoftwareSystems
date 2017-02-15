//
//  DidacticGame.cpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/14/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include "DidacticGame.hpp"

std::string DidacticGame::getDescription() const {
    std::string retVal = Game::getDescription() + "\n";
    retVal += "Minimum Age: " + std::to_string(minimumAge) + "%\n";
    retVal += "Target Age: " + std::to_string(targetAge) + "\n";
    retVal += "Maximum Age: " + std::to_string(maximumAge) + "\n";
    retVal += "Difficulty Percentage: " + std::to_string(difficultyPercentage) + "%\n";
    retVal += "Completion Time: " + std::to_string(completionTime) + "s";
    return retVal;
}

void DidacticGame::conception() {
    Helper::print(getName() + " is being conceived.");
    minimumAge = Helper::read<int>("What is the minimum age of the players?");
}

void DidacticGame::design() {
    Helper::print(getName() + " is being designed.");
    targetAge = Helper::read<int>("What is the target age of the players?");
}

void DidacticGame::planning() {
    Helper::print(getName() + " is being planned.");
    maximumAge = Helper::read<int>("What is the maximum age of the players?");
}

void DidacticGame::production() {
    Helper::print(getName() + " is being produced.");
    difficultyPercentage = Helper::read<int>("In percentage, what is the difficulty of the game?");
}

void DidacticGame::testing() {
    Helper::print(getName() + " is being tested.");
    completionTime = Helper::read<int>("In seconds, what is the expected time of completion of the game?");
}
