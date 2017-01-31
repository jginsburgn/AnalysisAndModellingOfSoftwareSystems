//
//  FactoryMethod.hpp
//  FactoryMethod
//
//  Created by Jonathan Ginsburg on 1/18/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#ifndef FactoryMethod_hpp
#define FactoryMethod_hpp

#include <stdio.h>
#include <iostream>

class Product {
protected:
    virtual void setup() = 0;
};

class ProductA : public Product {
private:
    int attributeOfA;
public:
    ProductA();
    void setup();
};

ProductA::ProductA() {
    std::cout << "Default constructor of product A called..." << std::endl;
}

void ProductA::setup() {
    std::cout << "Setup of product A called..." << std::endl;
}

template <typename T>
class FactoryMethod {
public:
    static T & produce();
};



#endif /* FactoryMethod_hpp */
