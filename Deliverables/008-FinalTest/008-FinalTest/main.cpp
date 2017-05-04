#include <iostream>
#include <vector>
#define GENERAL_LOG_SIGNATURE "[General Log] "

//Required forward declarations for visitor pattern
//Spacecraft
class ExplorationShip;
class ColonizationShip;
class ObservationShip;
//Asteroids
class StonyAsteroid;
class IronAsteroid;
//Planets
class DesertPlanet;
class EarthAnalogPlanet;

//Visitor's pattern element and visitor
class Collidable {
public:
    //Accept other collidable
    virtual void collide(Collidable * otherCollidable) = 0;
    
    //Visit other collidables
    //Spacecraft
    virtual void visitCollide(ExplorationShip * explorationShip) = 0;
    virtual void visitCollide(ColonizationShip * colonizationShip) = 0;
    virtual void visitCollide(ObservationShip * observationShip) = 0;
    //Asteroids
    virtual void visitCollide(StonyAsteroid * stonyAsteroid) = 0;
    virtual void visitCollide(IronAsteroid * ironAsteroid) = 0;
    //Planets
    virtual void visitCollide(DesertPlanet * desertPlanet) = 0;
    virtual void visitCollide(EarthAnalogPlanet * earthAnalogPlanet) = 0;
    
    //Polymorphic method
    virtual std::string getIdentifier() = 0;
};

class Spacecraft : public Collidable {
protected:
    //Spacecraft identifier name
    const std::string name;
    
    //Remove default initializer
    Spacecraft() = delete;
    
public:
    //Spacecraft initializer
    Spacecraft(std::string newName) : name(newName) {};
    
    //Property accessor
    std::string getName() const {
        return name;
    }
    
    //Polymorphic method implementation
    std::string getIdentifier() {
        std::string retVal = "Spacecraft " + name;
        return retVal;
    }
    
};

class ExplorationShip : public Spacecraft {
private:
    //Polymorphic method implementation
    std::string getIdentifier() override {
        std::string retVal = "Exploration Ship " + name;
        return retVal;
    }

    //Print collision alarm
    void printCollisionAlarm(Collidable * otherCollidable) {
        std::cout << "[" << name << "] Alarm: collision with " << otherCollidable->getIdentifier() << std::endl;
    }
    
    //Remove default constructor
    ExplorationShip() = delete;
    
public:
    //Constructor
    ExplorationShip(std::string newName) : Spacecraft(newName) {};
    
    //Visitor pattern implementations
    //Accept
    void collide(Collidable * otherCollidable) override {
        if (otherCollidable == this) return;
        printCollisionAlarm((Collidable *)otherCollidable);
        otherCollidable->visitCollide(this);
    }
    
    //Visits
    //Spacecraft
    void visitCollide(ExplorationShip * explorationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Two exploration ships collided" << std::endl;
        printCollisionAlarm((Collidable *)explorationShip);
    }
    void visitCollide(ObservationShip * observationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Exploration ship collided with observation ship" << std::endl;
        printCollisionAlarm((Collidable *)observationShip);
    }
    void visitCollide(ColonizationShip * colonizationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Exploration ship collided with colonization ship" << std::endl;
        printCollisionAlarm((Collidable *)colonizationShip);
    }
    //Asteroids
    void visitCollide(StonyAsteroid * stonyAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Exploration ship collided with stony asteroid" << std::endl;
        printCollisionAlarm((Collidable *)stonyAsteroid);
    }
    void visitCollide(IronAsteroid * ironAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Exploration ship collided with iron asteroid" << std::endl;
        printCollisionAlarm((Collidable *)ironAsteroid);
    }
    //Planets
    void visitCollide(DesertPlanet * desertPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Exploration ship collided with desert planet" << std::endl;
        printCollisionAlarm((Collidable *)desertPlanet);
    }
    void visitCollide(EarthAnalogPlanet * earthAnalogPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Exploration ship collided with earth analog planet" << std::endl;
        printCollisionAlarm((Collidable *)earthAnalogPlanet);
    }
};

class ObservationShip : public Spacecraft {
private:
    //Polymorphic method implementation
    std::string getIdentifier() override {
        std::string retVal = "Observation Ship " + name;
        return retVal;
    }

    //Print collision alarm
    void printCollisionAlarm(Collidable * otherCollidable) {
        std::cout << "[" << name << "] Alarm: collision with " << otherCollidable->getIdentifier() << std::endl;
    }
    
    //Remove default constructor
    ObservationShip() = delete;
    
public:
    //Constructor
    ObservationShip(std::string newName) : Spacecraft(newName) {};
    
    //Visitor pattern implementations
    //Accept
    void collide(Collidable * otherCollidable) override {
        if (otherCollidable == this) return;
        printCollisionAlarm((Collidable *)otherCollidable);
        otherCollidable->visitCollide(this);
    }
    
    //Visits
    //Spacecraft
    void visitCollide(ExplorationShip * explorationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Observation ship collided with exploration ship" << std::endl;
        printCollisionAlarm((Collidable *)explorationShip);
    }
    void visitCollide(ObservationShip * observationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Two exploration ships collided" << std::endl;
        printCollisionAlarm((Collidable *)observationShip);
    }
    void visitCollide(ColonizationShip * colonizationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Observation ship collided with colonization ship" << std::endl;
        printCollisionAlarm((Collidable *)colonizationShip);
    }
    //Asteroids
    void visitCollide(StonyAsteroid * stonyAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Observation ship collided with stony asteroid" << std::endl;
        printCollisionAlarm((Collidable *)stonyAsteroid);
    }
    void visitCollide(IronAsteroid * ironAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Observation ship collided with iron asteroid" << std::endl;
        printCollisionAlarm((Collidable *)ironAsteroid);
    }
    //Planets
    void visitCollide(DesertPlanet * desertPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Observation ship collided with desert planet" << std::endl;
        printCollisionAlarm((Collidable *)desertPlanet);
    }
    void visitCollide(EarthAnalogPlanet * earthAnalogPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Observation ship collided with earth analog planet" << std::endl;
        printCollisionAlarm((Collidable *)earthAnalogPlanet);
    }
};

class ColonizationShip : public Spacecraft {
private:
    //Polymorphic method implementation
    std::string getIdentifier() override {
        std::string retVal = "Colonization Ship " + name;
        return retVal;
    }

    //Print collision alarm
    void printCollisionAlarm(Collidable * otherCollidable) {
        std::cout << "[" << name << "] Alarm: collision with " << otherCollidable->getIdentifier() << std::endl;
    }
    
    //Remove default constructor
    ColonizationShip() = delete;
    
public:
    //Constructor
    ColonizationShip(std::string newName) : Spacecraft(newName) {};
    
    //Visitor pattern implementations
    //Accept
    void collide(Collidable * otherCollidable) override {
        if (otherCollidable == this) return;
        printCollisionAlarm((Collidable *)otherCollidable);
        otherCollidable->visitCollide(this);
    }
    
    //Visits
    //Spacecraft
    void visitCollide(ExplorationShip * explorationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Colonization ship collided with exploration ship" << std::endl;
        printCollisionAlarm((Collidable *)explorationShip);
    }
    void visitCollide(ObservationShip * observationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Colonization ship collided with observation ship" << std::endl;
        printCollisionAlarm((Collidable *)observationShip);
    }
    void visitCollide(ColonizationShip * colonizationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Two colonization ships collided" << std::endl;
        printCollisionAlarm((Collidable *)colonizationShip);
    }
    //Asteroids
    void visitCollide(StonyAsteroid * stonyAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Colonization ship collided with stony asteroid" << std::endl;
        printCollisionAlarm((Collidable *)stonyAsteroid);
    }
    void visitCollide(IronAsteroid * ironAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Colonization ship collided with iron asteroid" << std::endl;
        printCollisionAlarm((Collidable *)ironAsteroid);
    }
    //Planets
    void visitCollide(DesertPlanet * desertPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Colonization ship collided with desert planet" << std::endl;
        printCollisionAlarm((Collidable *)desertPlanet);
    }
    void visitCollide(EarthAnalogPlanet * earthAnalogPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Colonization ship collided with earth analog planet" << std::endl;
        printCollisionAlarm((Collidable *)earthAnalogPlanet);
    }
};

class Asteroid : public Collidable {
protected:
    //Asteroid identifier name
    const std::string name;
    
    //Remove default initializer
    Asteroid() = delete;
    
public:
    //Asteroid initializer
    Asteroid(std::string newName) : name(newName) {};
    
    //Property accessor
    std::string getName() const {
        return name;
    }
    
    //Polymorphic method implementation
    std::string getIdentifier() {
        std::string retVal = "Asteroid " + name;
        return retVal;
    }
    
};

class StonyAsteroid : public Asteroid {
private:
    //Polymorphic method implementation
    std::string getIdentifier() override {
        std::string retVal = "Stony Asteroid " + name;
        return retVal;
    }

    //Print collision alarm
    void printCollisionAlarm(Collidable * otherCollidable) {
        std::cout << "[" << name << "] Mother nature alarm: collision with " << otherCollidable->getIdentifier() << std::endl;
    }
    
    //Remove default constructor
    StonyAsteroid() = delete;
    
public:
    //Constructor
    StonyAsteroid(std::string newName) : Asteroid(newName) {};
    
    //Visitor pattern implementations
    //Accept
    void collide(Collidable * otherCollidable) override {
        if (otherCollidable == this) return;
        printCollisionAlarm((Collidable *)otherCollidable);
        otherCollidable->visitCollide(this);
    }
    
    //Visits
    //Spacecraft
    void visitCollide(ExplorationShip * explorationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Stony asteroid collided with exploration ship" << std::endl;
        printCollisionAlarm((Collidable *)explorationShip);
    }
    void visitCollide(ObservationShip * observationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Stony asteroid collided with observation ship" << std::endl;
        printCollisionAlarm((Collidable *)observationShip);
    }
    void visitCollide(ColonizationShip * colonizationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Stony asteroid collided with colonization ship" << std::endl;
        printCollisionAlarm((Collidable *)colonizationShip);
    }
    //Asteroids
    void visitCollide(StonyAsteroid * stonyAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Two stony asteroids collided" << std::endl;
        printCollisionAlarm((Collidable *)stonyAsteroid);
    }
    void visitCollide(IronAsteroid * ironAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Stony asteroid collided with iron asteroid" << std::endl;
        printCollisionAlarm((Collidable *)ironAsteroid);
    }
    //Planets
    void visitCollide(DesertPlanet * desertPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Stony asteroid collided with desert planet" << std::endl;
        printCollisionAlarm((Collidable *)desertPlanet);
    }
    void visitCollide(EarthAnalogPlanet * earthAnalogPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Stony asteroid collided with earth analog planet" << std::endl;
        printCollisionAlarm((Collidable *)earthAnalogPlanet);
    }
};

class IronAsteroid : public Asteroid {
private:
    //Polymorphic method implementation
    std::string getIdentifier() override {
        std::string retVal = "Iron Asteroid " + name;
        return retVal;
    }

    //Print collision alarm
    void printCollisionAlarm(Collidable * otherCollidable) {
        std::cout << "[" << name << "] Mother nature alarm: collision with " << otherCollidable->getIdentifier() << std::endl;
    }
    
    //Remove default constructor
    IronAsteroid() = delete;
    
public:
    //Constructor
    IronAsteroid(std::string newName) : Asteroid(newName) {};
    
    //Visitor pattern implementations
    //Accept
    void collide(Collidable * otherCollidable) override {
        if (otherCollidable == this) return;
        printCollisionAlarm((Collidable *)otherCollidable);
        otherCollidable->visitCollide(this);
    }
    
    //Visits
    //Spacecraft
    void visitCollide(ExplorationShip * explorationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Iron asteroid collided with exploration ship" << std::endl;
        printCollisionAlarm((Collidable *)explorationShip);
    }
    void visitCollide(ObservationShip * observationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Iron asteroid collided with observation ship" << std::endl;
        printCollisionAlarm((Collidable *)observationShip);
    }
    void visitCollide(ColonizationShip * colonizationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Iron asteroid collided with colonization ship" << std::endl;
        printCollisionAlarm((Collidable *)colonizationShip);
    }
    //Asteroids
    void visitCollide(StonyAsteroid * stonyAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Iron asteroid collided with stony asteroid" << std::endl;
        printCollisionAlarm((Collidable *)stonyAsteroid);
    }
    void visitCollide(IronAsteroid * ironAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Two iron asteroids collided" << std::endl;
        printCollisionAlarm((Collidable *)ironAsteroid);
    }
    //Planets
    void visitCollide(DesertPlanet * desertPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Iron asteroid collided with desert planet" << std::endl;
        printCollisionAlarm((Collidable *)desertPlanet);
    }
    void visitCollide(EarthAnalogPlanet * earthAnalogPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Iron asteroid collided with earth analog planet" << std::endl;
        printCollisionAlarm((Collidable *)earthAnalogPlanet);
    }
};

class Planet : public Collidable {
protected:
    //Asteroid identifier name
    const std::string name;
    
    //Remove default initializer
    Planet() = delete;
    
public:
    //Asteroid initializer
    Planet(std::string newName) : name(newName) {};
    
    //Property accessor
    std::string getName() const {
        return name;
    }
    
    //Polymorphic method implementation
    std::string getIdentifier() override {
        std::string retVal = "Planet " + name;
        return retVal;
    }
    
};

class DesertPlanet : public Planet {
private:
    //Polymorphic method implementation
    std::string getIdentifier() override {
        std::string retVal = "Desert Planet " + name;
        return retVal;
    }

    //Print collision alarm
    void printCollisionAlarm(Collidable * otherCollidable) {
        std::cout << "[" << name << "] Mother nature alarm for planets: collision with " << otherCollidable->getIdentifier() << std::endl;
    }
    
    //Remove default constructor
    DesertPlanet() = delete;
    
public:
    //Constructor
    DesertPlanet(std::string newName) : Planet(newName) {};
    
    //Visitor pattern implementations
    //Accept
    void collide(Collidable * otherCollidable) override {
        if (otherCollidable == this) return;
        printCollisionAlarm((Collidable *)otherCollidable);
        otherCollidable->visitCollide(this);
    }
    
    //Visits
    //Spacecraft
    void visitCollide(ExplorationShip * explorationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Desert planet collided with exploration ship" << std::endl;
        printCollisionAlarm((Collidable *)explorationShip);
    }
    void visitCollide(ObservationShip * observationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Desert planet collided with observation ship" << std::endl;
        printCollisionAlarm((Collidable *)observationShip);
    }
    void visitCollide(ColonizationShip * colonizationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Desert planet collided with colonization ship" << std::endl;
        printCollisionAlarm((Collidable *)colonizationShip);
    }
    //Asteroids
    void visitCollide(StonyAsteroid * stonyAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Desert planet collided with stony asteroid" << std::endl;
        printCollisionAlarm((Collidable *)stonyAsteroid);
    }
    void visitCollide(IronAsteroid * ironAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Desert planet collided with iron asteroid" << std::endl;
        printCollisionAlarm((Collidable *)ironAsteroid);
    }
    //Planets
    void visitCollide(DesertPlanet * desertPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Two desert planets collided" << std::endl;
        printCollisionAlarm((Collidable *)desertPlanet);
    }
    void visitCollide(EarthAnalogPlanet * earthAnalogPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Desert planet collided with earth analog planet" << std::endl;
        printCollisionAlarm((Collidable *)earthAnalogPlanet);
    }
};

class EarthAnalogPlanet : public Planet {
private:
    //Polymorphic method implementation
    std::string getIdentifier() override {
        std::string retVal = "Earth Analog Planet " + name;
        return retVal;
    }

    //Print collision alarm
    void printCollisionAlarm(Collidable * otherCollidable) {
        std::cout << "[" << name << "] Mother nature alarm for planets: collision with " << otherCollidable->getIdentifier() << std::endl;
    }
    
    //Remove default constructor
    EarthAnalogPlanet() = delete;
    
public:
    //Constructor
    EarthAnalogPlanet(std::string newName) : Planet(newName) {};
    
    //Visitor pattern implementations
    //Accept
    void collide(Collidable * otherCollidable) override {
        if (otherCollidable == this) return;
        printCollisionAlarm((Collidable *)otherCollidable);
        otherCollidable->visitCollide(this);
    }
    
    //Visits
    //Spacecraft
    void visitCollide(ExplorationShip * explorationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Earth analog planet collided with exploration ship" << std::endl;
        printCollisionAlarm((Collidable *)explorationShip);
    }
    void visitCollide(ObservationShip * observationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Earth analog planet collided with observation ship" << std::endl;
        printCollisionAlarm((Collidable *)observationShip);
    }
    void visitCollide(ColonizationShip * colonizationShip) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Earth analog planet collided with colonization ship" << std::endl;
        printCollisionAlarm((Collidable *)colonizationShip);
    }
    //Asteroids
    void visitCollide(StonyAsteroid * stonyAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Earth analog planet collided with stony asteroid" << std::endl;
        printCollisionAlarm((Collidable *)stonyAsteroid);
    }
    void visitCollide(IronAsteroid * ironAsteroid) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Earth analog planet collided with iron asteroid" << std::endl;
        printCollisionAlarm((Collidable *)ironAsteroid);
    }
    //Planets
    void visitCollide(DesertPlanet * desertPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Earth analog planet collided with desert planet" << std::endl;
        printCollisionAlarm((Collidable *)desertPlanet);
    }
    void visitCollide(EarthAnalogPlanet * earthAnalogPlanet) override {
        std::cout << GENERAL_LOG_SIGNATURE << "Two earth analog planets collided" << std::endl;
        printCollisionAlarm((Collidable *)earthAnalogPlanet);
    }
};

class Factory {
private:
    //Singleton instance
    static Factory * instance;
    
    //Disable constructor for only private implementation
    Factory() {}
    
public:
    //Singleton accessor
    static Factory * getInstance() {
        if (instance) return instance;
        else {
            Factory::instance = new Factory();
            return instance;
        }
    }
    
    //Template factory method
    template <class Product>
    Product * produce(std::string genericName) const {
        return new Product(genericName);
    }
};

//Set singleton factory instance initially to null
Factory * Factory::instance = NULL;

//Main function to test APIs
int main() {
    
    //Get factory instance
    Factory * factory = Factory::getInstance();
    
    //Spacecraft
    ExplorationShip * enterprise = factory->produce<ExplorationShip>("USS Enterprise");
    ObservationShip * montana = factory->produce<ObservationShip>("USS Montana");
    ColonizationShip * michigan = factory->produce<ColonizationShip>("USS Michigan");
    //Asteroids
    StonyAsteroid * sa = factory->produce<StonyAsteroid>("SA-908");
    IronAsteroid * ia = factory->produce<IronAsteroid>("IA-1010");
    //Planets
    DesertPlanet * dp = factory->produce<DesertPlanet>("Kepler B");
    EarthAnalogPlanet * ea = factory->produce<EarthAnalogPlanet>("Newton A");
    
    //Fill vector
    std::vector<Collidable *> all;
    all.push_back(enterprise);
    all.push_back(montana);
    all.push_back(michigan);
    all.push_back(sa);
    all.push_back(ia);
    all.push_back(dp);
    all.push_back(ea);
    
    //Collide everything
    for (int i = 0; i < all.size(); ++i) {
        Collidable * current = all[i];
        for (int j = 0; j < all.size(); ++j) current->collide(all[j]);
    }
    
    return 0;
}
