//
//  StrategyGame.cpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/14/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include "StrategyGame.hpp"

std::string StrategyGame::objectiveToString(const Objective obj) {
    switch (obj) {
        case Domination:
            return "Domination";
            break;
        case Conquer:
            return "Conquer";
            break;
        case Kill:
            return "Kill";
            break;
        default:
            return "Unknown objective";
            break;
    }
}

StrategyGame::Objective StrategyGame::stringToObjective(const std::string str) {
    if (str == "Domination") {
        return Domination;
    }
    else if (str == "Conquer") {
        return Conquer;
    }
    else if (str == "Kill") {
        return Kill;
    }
    else {
        Helper::print("Unrecongnized objective " + str + ", defaulting to Kill.");
        return Kill;
    }
}

std::string StrategyGame::strategyElementToString(const StrategyElement str) {
    switch (str) {
        case Cards:
            return "Cards";
            break;
        case Board:
            return "Board";
            break;
        case World:
            return "World";
            break;
        default:
            return "Unknown strategy element";
            break;
    }
}

StrategyGame::StrategyElement StrategyGame::stringToStrategyElement(const std::string str) {
    if (str == "Cards") {
        return Cards;
    }
    else if (str == "Board") {
        return Board;
    }
    else if (str == "World") {
        return World;
    }
    else {
        Helper::print("Unrecognized strategy element " + str + ", defaulting to World.");
        return World;
    }
}

std::string StrategyGame::getObjectiveString() const {
    return objectiveToString(objective);
}

std::string StrategyGame::getStrategyElementString() const {
    return strategyElementToString(strategyElement);
}

std::string StrategyGame::getDescription() const {
    std::string retVal = Game::getDescription() + "\n";
    retVal += "Luck percentage: " + std::to_string(luckPercentage) + "%\n";
    retVal += "Objective: " + getObjectiveString() + "\n";
    retVal += "Allows teams: " + (std::string)(getAllowsTeams() ? "Yes" : "No") + "\n";
    retVal += "Allows trading: " + (std::string)(getAllowsTrading() ? "Yes" : "No") + "\n";
    retVal += "Strategy element: " + getStrategyElementString();
    return retVal;
}

void StrategyGame::conception() {
    Helper::print(getName() + " is being conceived.");
    luckPercentage = Helper::read<float>("What is its luck percentage?");
}

void StrategyGame::design() {
    Helper::print(getName() + " is being designed.");
    objective = stringToObjective(Helper::read<std::string>("What is its objective? (Domination, Conquer or Kill)"));
}

void StrategyGame::planning() {
    Helper::print(getName() + " is being planned.");
    allowsTeams = Helper::read<std::string>("Will it allow teaming? (Y or N)") == "Y" ? true : false;
}

void StrategyGame::production() {
    Helper::print(getName() + " is being produced.");
    allowsTrading = Helper::read<std::string>("Will it allow trading? (Y or N)") == "Y" ? true : false;
}

void StrategyGame::testing() {
    Helper::print(getName() + " is being tested.");
    strategyElement = stringToStrategyElement(Helper::read<std::string>("What is its strategy element? (Cards, Board or World)"));
}
