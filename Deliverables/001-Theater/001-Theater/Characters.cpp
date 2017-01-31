//
//  Characters.cpp
//  001-Theater
//
//  Created by Jonathan Ginsburg on 1/31/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include "Characters.hpp"

//Hero implementation

Hero::Hero() {
    std::cout << "Default constructor of hero called..." << std::endl;
}

void Hero::heroicAction() {
    std::cout << "Hero executing heroic action..." << std::endl;
}

void Hero::giveBirth() {
    std::cout << "A new hero is being born and some actions are being done to empower him..." << std::endl;
    originWorld = Earth;
}

void Hero::vitalize() {
    std::cout << "The hero can swing his sword..." << std::endl;
}

//Factory implementation

Factory::Factory() {
    std::cout << "A factory is being created..." << std::endl;
}

Factory::~Factory() {
    std::cout << "A factory is being destroyed..." << std::endl;
}

Factory * Factory::factoryInstance = NULL;

Factory * Factory::getInstance() {
    if (!Factory::factoryInstance) {
        Factory::factoryInstance = new Factory();
    }
    return Factory::factoryInstance;
}
