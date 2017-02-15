//
//  Warehouse.hpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/9/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#ifndef Warehouse_hpp
#define Warehouse_hpp

#include <stdio.h>
#include "Game.hpp"
#include "StrategyGame.hpp"
#include "DidacticGame.hpp"
#include "AdventureGame.hpp"
#include <vector>
#include <queue>

class RetailGame;

class Warehouse {
private:
    //Static singleton
    static Warehouse * singleton;
    
    //Attributes
    int lastSerialNumber = 0;
    int warehouseSize = 0;
    std::vector<RetailGame *> prototypes;
    std::vector<RetailGame *> inventory;
    
    std::vector<int> deletedItemsPerOperation;
    std::vector<RetailGame *> deletedItems;
    
    //Private constructor
    Warehouse();
    
    //Internal logic
    
    //Get inventory element at index and remove from inventory vector
    RetailGame * popRetailGame(const int index);
    
    //Deleting
    void deleteRetailGame(const int index); //Removes a retail game from the inventory and marks it for future deletion in the deletedItems queue
    void deleteRetailGames(const std::vector<int> indices); //Removes retail games from the inventory and marks them for future deletion in the deletedItems queue
    void flushLastDeleteOperation(); //Flushes third-to-last delete operation removing elements and freeing them from the deletedItems queue
    
    //Modifying
    void setRetailGameDiscount(const int index, const float discount); //Sets a new discount to a retail game
    
    //Searching
    std::vector<int> searchRetailGamesByName(const std::string query) const; //Returns the indices with respect to inventory of the Retail Games that match the query
    int searchRetailGameBySerialNumber(const int query) const; //Returns the index with respect to inventory of the game that matches the query
public:
    //Return singleton
    static Warehouse & getInstance();
    
    //Main warehouse logic
    //Prototype creation and display
    void addPrototype(const std::string prototypeType);
    void listPrototypes();
    
    //Inventory sorting
    void sortAscending();
    void sortDescending();
    
    //Retail game production, dismissal and modification
    void produceGames();
    void removeGamesByName(const std::string name);
    void removeGameBySerialNumber(const int sn);
    void alterDiscount();
    void undoDeletion(); //Recovers the retail games from the last deletion operation and puts them back in the inventory
    
    //General inventory information
    void listInventory(const std::vector<int> indices = {-1}) const;
    int getItemsCount() const;
    int getWarehouseSize() const;
    void listItemsWithName(const std::string query) const;
    void listItemsWithSerialNumber(const int query) const;
};

//Proxy class to Game, used by Warehouse for extended functionality
class RetailGame {
private:
    //Friends
    friend Warehouse; //Warehouse needs to be a friend because it needs access to the constructor
    
    //Remove implicit constructor
    RetailGame() = delete;
    
    Game * actualGame;
    float discount;
    int serialNumber;
    
    //Constructor
    RetailGame(Game * newActualGame, const int newSerialNumber = 0, const float newDiscount = 0);
    //Assignment operator overload
    RetailGame & operator = (Game * newActualGame);
    
public:
    //Cloning method for replicating prototypes
    RetailGame * clone(const int newSerialNumber, const float newDiscount = 0);
    
    //Getters and setters
    Game & getActualGame() const { return *actualGame; };
    void setDiscount(const float newDiscount) { discount = newDiscount; };
    float getDiscount() const { return discount; };
    int getSerialNumber() const { return serialNumber; };
    
    //Get final retail price, considering discount
    float getRetailPrice() const;
    
    //Get game description plus serial number, discount and retail price
    std::string getDescription() const;
};

#endif /* Warehouse_hpp */
