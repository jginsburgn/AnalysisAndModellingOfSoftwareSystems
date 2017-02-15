//
//  DidacticGame.hpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/14/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#ifndef DidacticGame_hpp
#define DidacticGame_hpp

#include "Game.hpp"

class DidacticGame : public Game {
    
private:
    int minimumAge;
    int maximumAge;
    int targetAge;
    float difficultyPercentage;
    float completionTime; //In seconds
    
public:
    //Constructors
    DidacticGame(const std::string newName, const float newPrice, const int newLaunchYear, const int newNumberOfPlayers, const Platform newPlatform) : Game(newName, newPrice, newLaunchYear, newNumberOfPlayers, newPlatform) {};
    
    //Getters and setters
    void setMinimumAge(const int newMinimumAge) { minimumAge = newMinimumAge; };
    int getMinimumAge() const { return minimumAge; };
    void setMaximumAge(const int newMaximumAge) { maximumAge = newMaximumAge; };
    int getMaximumAge() const { return maximumAge; };
    void setTargetAge(const int newTargetAge) { targetAge = newTargetAge; };
    int getTargetAge() const { return targetAge; };
    void setDifficultyPercentage(const float newDifficultyPercentage) { difficultyPercentage = newDifficultyPercentage; };
    float getDifficultyPercentage() const { return difficultyPercentage; };
    void setCompletionTime(const float newCompletionTime) { completionTime = newCompletionTime; };
    float getCompletionTime() const { return completionTime; };
    
    //Implementation of virtual functions
    std::string getDescription() const final;
    void conception() final;
    void design() final;
    void planning() final;
    void production() final;
    void testing() final;
};

#endif /* DidacticGame_hpp */
