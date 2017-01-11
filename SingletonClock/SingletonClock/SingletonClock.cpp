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
        std::cout << "Creating clock..." << std::endl;
    }
}

SingletonClock::~SingletonClock() {
    std::cout << "Destroying clock..." << std::endl;
    singleton = NULL;
}

void SingletonClock::Destroy() {
    if (!singleton) {
        return;
    }
    else {
        delete singleton;
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
    time_t t = time(0);
    struct tm * now = localtime( & t );
    std::string hour = formatTimeMember(std::to_string(now->tm_hour));
    std::string minute = formatTimeMember(std::to_string(now->tm_min));
    std::string second = formatTimeMember(std::to_string(now->tm_sec));
    retVal += hour + ":" + minute + ":" + second;
    return retVal;
}

std::string SingletonClock::formatTimeMember(const std::string & timeMember) {
    if (timeMember.length() != 2) {
        return "0" +  timeMember;
    }
    else {
        return timeMember;
    }
}
