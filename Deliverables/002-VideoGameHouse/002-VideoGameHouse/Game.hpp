//
//  Game.hpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/8/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "../../../Helper/Helper.hpp"
#include <stdio.h>
#include <iostream>

typedef enum {
    Xbox,
    PlayStation,
    PC,
} Platform;

//Platform aid functions
std::string platformToString(const Platform pla);
Platform stringToPlatform(const std::string str);

class Game {
private:
    Game() = delete;
    
protected:
    std::string name;
    float price;
    int launchYear;
    int numberOfPlayers;
    Platform platform;
    Game(const std::string newName, const float newPrice, const int newLaunchYear, const int newNumberOfPlayers, const Platform newPlatform) : name(newName), price(newPrice), launchYear(newLaunchYear), numberOfPlayers(newNumberOfPlayers), platform(newPlatform) {};
    
public:
    //Getters and setters
    void setName(const std::string newName) { name = newName; };
    std::string getName() const { return name; };
    void setPrice(const float newPrice) { price = newPrice; };
    float getPrice() const { return price; };
    void setLaunchYear(const int newLaunchYear) { launchYear = newLaunchYear; };
    int getLaunchYear() const { return launchYear; };
    void setNumberOfPlayers(const int newNumberOfPlayers) { numberOfPlayers = newNumberOfPlayers; };
    int getNumberOfPlayers() const { return numberOfPlayers; };
    void setPlatform(const Platform newPlatform) { platform = newPlatform; };
    Platform getPlatform() const { return platform; };
    std::string getPlatformString() const;
    
    //Partially virtual method
    virtual std::string getDescription() const;
    
    //Required actions for each newly developed game
    virtual void conception() {};
    virtual void design() {};
    virtual void planning() {};
    virtual void production() {};
    virtual void testing() {};
    
    //Factory method
    template <typename G>
    static G * produce() {
        G * retVal = new G(
                 Helper::readLine("What is the name of the new game?"),
                 Helper::read<float>("What is the price?"),
                 Helper::read<int>("What is the launch year?"),
                 Helper::read<int>("What is the number of players?"),
                 stringToPlatform(Helper::read<std::string>("What is the platform? (PC, Xbox, or PlayStation)"))
                 );
        retVal->conception();
        retVal->design();
        retVal->planning();
        retVal->production();
        retVal->testing();
        return retVal;
    };
};


#endif /* Game_hpp */
