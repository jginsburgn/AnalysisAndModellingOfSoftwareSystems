//
//  Characters.hpp
//  001-Theater
//
//  Created by Jonathan Ginsburg on 1/31/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#ifndef Characters_hpp
#define Characters_hpp

#include <stdio.h>
#include <iostream>

//A silly enumeration for exemplification of Prototyping (https://en.wikipedia.org/wiki/Prototype_pattern).
enum World {
    Mars,
    Jupiter,
    Earth
};

template <typename Character>
class AbstractCharacter {
public:
    //An attribute that all characters have.
    World originWorld;
    
    //The cloning of a prototype.
    Character * clone(){
        return new Character(dynamic_cast<Character&>(*this));
    };
    //Prototyping is helpful for creating a second object from an existing one that can be taken as a model.
    
    //Setup action that must be executed for all characters for later usage.
    virtual void giveBirth() = 0;
    //The use of a factory enables the abstraction of this action so that the final user does not need to worry about the setup particularity of this class/library.
    
    //Some derived class specific action, that all children must implement.
    virtual void vitalize() = 0;
    //For testing purposes.
};

class Hero : public AbstractCharacter<Hero> {
public:
    Hero();
    void heroicAction();
    void giveBirth() override;
    void vitalize() override;
};

class Factory {
private:
    static Factory * factoryInstance;
    Factory();
    ~Factory();
public:
    static Factory * getInstance();
    
    template <typename Character>
    Character * produce() {
        Character * retVal = new Character();
        retVal->giveBirth();
        return retVal;
    };
};

#endif /* Characters_hpp */
