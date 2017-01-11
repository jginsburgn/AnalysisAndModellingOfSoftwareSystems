//
//  main.cpp
//  Playground
//
//  Created by Jonathan Ginsburg on 1/11/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    std::cout
    << now->tm_hour << ':'
    <<  now->tm_min
    << std::endl;
    return 0;
}
