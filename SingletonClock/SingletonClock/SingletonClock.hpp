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
    static SingletonClock * singleton;
    SingletonClock();
public:
    static SingletonClock * Instance();
    std::string getTime();
};

#endif /* SingletonClock_hpp */
