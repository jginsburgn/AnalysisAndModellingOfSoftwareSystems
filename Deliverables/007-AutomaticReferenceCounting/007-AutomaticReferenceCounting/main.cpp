//
//  main.cpp
//  007-AutomaticReferenceCounting
//
//  Created by Jonathan Ginsburg on 5/4/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>

//Wrong ARC (Taken as-is from the instructions PDF)
class Child {
public:
    int * p;
    Child() {
        p = new int;
    }
    ~Child() {
        delete p;
        p = NULL;
    }
};

//Correction
template <class Containable>
class ARCCapsule { //Automatic reference counting capsule
    
private:
    Containable * containable; //Value of which to count references to
    int * referencesCount; //Count of references to containable
    
    //Reference count modifiers
    void decreaseReferenceCount() {
        if (referencesCount) {
            --(*referencesCount);
            if (*referencesCount == 0) {
                std::cout << "Containable memory freed at: " << containable << std::endl;
                delete containable;
                std::cout << "References count memory freed at: " << referencesCount << std::endl;
                delete referencesCount;
                referencesCount = NULL;
            }
        }
    }
    void increaseReferenceCount() {
        if (referencesCount) {
            ++(*referencesCount);
        }
    }
    
public:
    //Default constructor
    ARCCapsule() {
        containable = new Containable;
        std::cout << "Containable allocated at: " << containable << std::endl;
        referencesCount = new int;
        std::cout << "References count allocated at: " << referencesCount << std::endl;
        *referencesCount = 1;
    }
    //Constructor with existing reference to a containable
    ARCCapsule(Containable * existingContainable) {
        containable = existingContainable;
        referencesCount = new int;
        std::cout << "References count allocated at: " << referencesCount << std::endl;
        *referencesCount = 1;
    }
    //Copy construcutor
    ARCCapsule(const ARCCapsule & other) {
        containable = other.containable;
        referencesCount = other.referencesCount;
        increaseReferenceCount();
    }
    //Destructor
    ~ARCCapsule() {
        decreaseReferenceCount();
    }
    //Assignment operator
    void operator=(const ARCCapsule & other) {
        decreaseReferenceCount();
        containable = other.containable;
        referencesCount = other.referencesCount;
        increaseReferenceCount();
    }
    //For accessing vlaue in an analog way as pointers
    Containable & operator*() { //Dereference operator
        return *containable;
    }
};

int main(int argc, const char * argv[]) {
    ARCCapsule<int> a;
    ARCCapsule<int> b = a;
    *a = 5;
    std::cout << *b << std::endl;
    int * dynamicInt = new int;
    std::cout << "Dynamic int allocated at: " << dynamicInt << std::endl;
    *dynamicInt = 10;
    ARCCapsule<int> c(dynamicInt);
    
    /* Erroneous ARC (Taken as-is from the instructions PDF)
    Child a;
    Child b = a;
    *(a.p) = 5;
    std::cout << *(b.p);
     */
    return 0;
}
