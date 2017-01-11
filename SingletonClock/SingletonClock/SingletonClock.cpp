//
//  SingletonClock.cpp
//  SingletonClock
//
//  Created by Jonathan Ginsburg on 1/11/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include "SingletonClock.hpp"

SingletonClock * SingletonClock::singleton = NULL;

SingletonClock::SingletonClock() {
    if (!singleton) {
        std::cout << "Creating clock" << std::endl;
    }
}

SingletonClock * SingletonClock::Instance() {
    if (!singleton) {
        singleton = new SingletonClock();
    }
    return singleton;
}

std::string SingletonClock::getTime() {
    std::string retVal = "";
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    retVal += std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min);
    return retVal;
}
