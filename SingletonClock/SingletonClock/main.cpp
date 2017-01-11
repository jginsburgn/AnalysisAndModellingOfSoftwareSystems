//
//  main.cpp
//  SingletonClock
//
//  Created by Jonathan Ginsburg on 1/11/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "SingletonClock.hpp"

int main(int argc, const char * argv[]) {
    SingletonClock * first = SingletonClock::Instance();
    SingletonClock * second = SingletonClock::Instance();
    std::cout << "Address of first pointer: " << first << ". Hour given: " << first->getTime() << "." << std::endl;
    std::cout << "Address of second pointer: " << first << ". Hour given: " << second->getTime() << "." << std::endl;
    return 0;
}
