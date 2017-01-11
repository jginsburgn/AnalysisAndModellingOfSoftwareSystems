//
//  main.cpp
//  SingletonClock
//
//  Created by Jonathan Ginsburg on 1/11/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include "SingletonClock.hpp"

int main(int argc, const char * argv[]) {
    SingletonClock * first = SingletonClock::Instance();
    SingletonClock * second = SingletonClock::Instance();
    std::cout << "Address of first pointer: " << first << ". Hour given: " << first->getTime() << "." << std::endl;
    sleep(1);
    std::cout << "Address of second pointer: " << second << ". Hour given: " << second->getTime() << "." << std::endl;
    SingletonClock::Destroy();
    return 0;
}
