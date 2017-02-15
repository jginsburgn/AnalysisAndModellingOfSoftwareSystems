//
//  Game.cpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/8/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include "Game.hpp"

std::string platformToString(const Platform pla) {
    switch (pla) {
        case Xbox:
            return "Xbox";
            break;
        case PC:
            return "PC";
            break;
        case PlayStation:
            return "PlayStation";
            break;
        default:
            return "Unknown Platform";
            break;
    }
}

Platform stringToPlatform(const std::string str) {
    if (str == "Xbox") {
        return Xbox;
    }
    else if (str == "PC") {
        return PC;
    }
    else if (str == "PlayStation") {
        return PlayStation;
    }
    else {
        Helper::print("Unrecognized platform " + str + ", defaulting to Xbox.");
        return Xbox;
    }
}

std::string Game::getPlatformString() const {
    return platformToString(platform);
}

std::string Game::getDescription() const {
    std::string retVal;
    retVal += "Name: " + getName() + "\n";
    retVal += "Price: $" + std::to_string(getPrice()) + "\n";
    retVal += "Launch Year: " + std::to_string(getLaunchYear()) + "\n";
    retVal += "Number of Players: " + std::to_string(getNumberOfPlayers()) + "\n";
    retVal += "Platform: " + getPlatformString();
    return retVal;
}
