//
//  StrategyGame.hpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/14/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#ifndef StrategyGame_hpp
#define StrategyGame_hpp

#include "Game.hpp"

class StrategyGame : public Game {
public:
    //Enumerations
    typedef enum {Domination, Conquer, Kill} Objective;
    typedef enum {Cards, Board, World} StrategyElement;
    //Enumeration aid functions
    static std::string objectiveToString(const Objective obj);
    static Objective stringToObjective(const std::string str);
    static std::string strategyElementToString(const StrategyElement str);
    static StrategyElement stringToStrategyElement(const std::string str);
private:
    double luckPercentage;
    Objective objective;
    bool allowsTeams;
    bool allowsTrading;
    StrategyElement strategyElement;
    
public:
    //Constructors
    StrategyGame(const std::string newName, const float newPrice, const int newLaunchYear, const int newNumberOfPlayers, const Platform newPlatform) : Game(newName, newPrice, newLaunchYear, newNumberOfPlayers, newPlatform) {};
    
    //Getters and setters
    void setLuckPercentage(const double newLuckPercentage) { luckPercentage = newLuckPercentage; };
    double getLuckPercentage() const { return luckPercentage; };
    void setObjective(const Objective newObjective) { objective = newObjective; };
    Objective getObjective() const { return objective; };
    std::string getObjectiveString() const;
    void setAllowsTeams(const bool newAllowsTeams) { allowsTeams = newAllowsTeams; };
    bool getAllowsTeams() const { return allowsTeams; };
    void setAllowsTrading(const bool newAllowsTrading) { allowsTrading = newAllowsTrading; };
    bool getAllowsTrading() const { return allowsTrading; };
    void setStrategyElement(const StrategyElement newStrategyElement) { strategyElement = newStrategyElement; };
    StrategyElement getStrategyElement() const { return strategyElement; };
    std::string getStrategyElementString() const;
    
    //Implementation of virtual functions
    std::string getDescription() const final;
    void conception() final;
    void design() final;
    void planning() final;
    void production() final;
    void testing() final;
};

#endif /* StrategyGame_hpp */
