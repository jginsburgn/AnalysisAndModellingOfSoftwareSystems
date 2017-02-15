//
//  AdventureGame.hpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/14/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#ifndef AdventureGame_hpp
#define AdventureGame_hpp

#include "Game.hpp"

class AdventureGame : public Game {
    
private:
    int numberOfLevels;
    int numberOfWeapons;
    int numberOfCharacters;
    int numberOfObjectives;
    int numberOfTrophies;
    
public:
    //Constructors
    AdventureGame(const std::string newName, const float newPrice, const int newLaunchYear, const int newNumberOfPlayers, const Platform newPlatform) : Game(newName, newPrice, newLaunchYear, newNumberOfPlayers, newPlatform) {};
    
    //Getters and setters
    void setNumberOfLevels(const int newNumberOfLevels) { numberOfLevels = newNumberOfLevels; };
    int getNumberOfLevels() const { return numberOfLevels; };
    void setNumberOfWeapons(const int newNumberOfWeapons) { numberOfWeapons = newNumberOfWeapons; };
    int getNumberOfWeapons() const { return numberOfWeapons; };
    void setNumberOfCharacters(const int newNumberOfCharacters) { numberOfCharacters = newNumberOfCharacters; };
    int getNumberOfCharacters() const { return numberOfCharacters; };
    void setNumberOfObjectives(const float newNumberOfObjectives) { numberOfObjectives = newNumberOfObjectives; };
    float getNumberOfObjectives() const { return numberOfObjectives; };
    void setNumberOfTrophies(const float newNumberOfTrophies) { numberOfTrophies = newNumberOfTrophies; };
    float getNumberOfTrophies() const { return numberOfTrophies; };
    
    //Implementation of virtual functions
    std::string getDescription() const final;
    void conception() final;
    void design() final;
    void planning() final;
    void production() final;
    void testing() final;
};

#endif /* AdventureGame_hpp */
