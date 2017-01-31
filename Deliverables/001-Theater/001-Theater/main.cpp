//
//  main.cpp
//  001-Theater
//
//  Created by Jonathan Ginsburg on 1/31/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

/*
 This project brings together the concepts of prototyping, factories and singletons: the characters are created through cloning a prototype, or through a factory, and the factory is itself a singleton.
 */

#include <iostream>
#include "Characters.hpp"

int main(int argc, const char * argv[]) {
    Factory * firstFactory = Factory::getInstance(); //This factory is a singleton
    Hero * firstHero = firstFactory->produce<Hero>(); //This hero is obtained through a factory and is used as prototype
    std::cout << (firstHero->originWorld == Earth ? "Earth" : "Other") << std::endl; //The factory takes care of setting up the hero and giving him a planet
    Hero * heroWithoutFactory = new Hero(); //This hero does not have a planet
    std::cout << (heroWithoutFactory->originWorld == Earth ? "Earth" : "Other") << std::endl;
    Hero * secondHero = firstHero->clone(); //This hero is created from the first hero as a base, having its same planet
    std::cout << (secondHero->originWorld == Earth ? "Earth" : "Other") << std::endl;
    Factory * secondFactory = Factory::getInstance(); //This is the same factory as the first factory
    std::cout << "If the factory is a real singleton the next addresses should be the same: " << firstFactory << ", " << secondFactory << std::endl;
    Hero * thirdHero = secondFactory->produce<Hero>();
    std::cout << "The addresses of the heroes are as follows: \n\t-First Hero: " << firstHero << "\n\t-Hero Without Factory: " << heroWithoutFactory << "\n\t-Second Hero: " << secondHero << "\n\t-Third Hero: " << thirdHero << std::endl;
    return 0;
}
