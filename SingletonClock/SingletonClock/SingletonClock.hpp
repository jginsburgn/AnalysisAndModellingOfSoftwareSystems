//
//  SingletonClock.hpp
//  SingletonClock
//
//  Created by Jonathan Ginsburg on 1/11/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#ifndef SingletonClock_hpp
#define SingletonClock_hpp

#include <stdio.h>
#include <iostream>

class SingletonClock {
private:
    //Constructors and destructor
    SingletonClock();
    ~SingletonClock();
    
    //Private properties
    static SingletonClock * singleton;
    
    //Private instance methods
    std::string formatTimeMember(const std::string & timeMember);
    
public:
    //Public destructor
    static void Destroy();
    
    //Public singleton getter
    static SingletonClock * Instance();
    
    //Public instance methods
    std::string getTime();
};

#endif /* SingletonClock_hpp */
