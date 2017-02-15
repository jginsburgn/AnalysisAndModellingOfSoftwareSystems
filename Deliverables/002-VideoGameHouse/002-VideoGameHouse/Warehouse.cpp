//
//  Warehouse.cpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/9/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include "Warehouse.hpp"

Warehouse * Warehouse::singleton = NULL;

Warehouse::Warehouse() {
    this->warehouseSize = Helper::read<int>("What is the size of the inventory?");
}

RetailGame * Warehouse::popRetailGame(const int index) {
    RetailGame * gameToPop = inventory[index];
    inventory.erase(inventory.begin() + index);
    return gameToPop;
}

void Warehouse::deleteRetailGame(const int index) {
    flushLastDeleteOperation();
    RetailGame * gameToBeDeleted = popRetailGame(index);
    deletedItems.push_back(gameToBeDeleted);
    deletedItemsPerOperation.push_back(1);
}

void Warehouse::deleteRetailGames(const std::vector<int> indices) {
    flushLastDeleteOperation();
    std::vector<int> tmpIndices = indices;
    std::sort(tmpIndices.rbegin(), tmpIndices.rend());
    for (int i = 0; i < indices.size(); ++i) {
        RetailGame * gameToBeDeleted = popRetailGame(tmpIndices.at(i));
        deletedItems.push_back(gameToBeDeleted);
    }
    deletedItemsPerOperation.push_back((int)indices.size());
}

void Warehouse::flushLastDeleteOperation() {
    if (deletedItemsPerOperation.size() != 3) {
        return;
    }
    int numberOfDeletedItemsInDeleteOperationToFlush = *deletedItemsPerOperation.begin();
    for (int i = 0; i < numberOfDeletedItemsInDeleteOperationToFlush; ++i) {
        RetailGame * gameToFlush = *deletedItems.begin();
        delete gameToFlush;
        deletedItems.erase(deletedItems.begin());
    }
    deletedItemsPerOperation.erase(deletedItemsPerOperation.begin());
}

void Warehouse::setRetailGameDiscount(const int index, const float discount){
    RetailGame * game = inventory.at(index);
    game->setDiscount(discount);
}

std::vector<int> Warehouse::searchRetailGamesByName(const std::string query) const {
    std::vector<int> retVal;
    for (int i = 0; i < inventory.size(); ++i) {
        RetailGame * game = inventory.at(i);
        if (game->getActualGame().getName() == query) {
            retVal.push_back(i);
        }
    }
    return retVal;
}

int Warehouse::searchRetailGameBySerialNumber(const int query) const {
    int retVal = -1;
    for (int i = 0; i < inventory.size(); ++i) {
        RetailGame * game = inventory.at(i);
        if (game->getSerialNumber() == query) {
            return i;
        }
    }
    return retVal;
}

Warehouse & Warehouse::getInstance() {
    if (!singleton) {
        singleton = new Warehouse();
    }
    return *singleton;
}

//Main warehouse logic
//Prototype creation and display
void Warehouse::addPrototype(const std::string prototypeType) {
    RetailGame * retailGame;
    if (prototypeType == "strategy") {
        retailGame = new RetailGame(Game::produce<StrategyGame>());
    }
    else if (prototypeType == "adventure") {
        retailGame = new RetailGame(Game::produce<AdventureGame>());
    }
    else if (prototypeType == "didactic") {
        retailGame = new RetailGame(Game::produce<DidacticGame>());
    }
    else {
        Helper::print("Unrecognized prototype game type " + prototypeType + ", defaulting to strategy.");
        retailGame = new RetailGame(Game::produce<StrategyGame>());
    }
    prototypes.push_back(retailGame);
}

void Warehouse::listPrototypes() {
    if (prototypes.size() == 0) {
        Helper::print("There are no prototypes.");
    }
    for (int i = 0; i < prototypes.size(); ++i) {
        Game * actualGame = prototypes.at(i)->actualGame;
        std::string prefix = "Prototype #";
        prefix += std::to_string(i+1);
        prefix += ":\n";
        Helper::print(prefix + actualGame->getDescription());
    }
}

void Warehouse::sortAscending() {
    std::sort(inventory.begin(), inventory.end(), [](const RetailGame * a, const RetailGame * b){
        return a->getRetailPrice() < b->getRetailPrice();
    });
}

void Warehouse::sortDescending() {
    std::sort(inventory.rbegin(), inventory.rend(), [](const RetailGame * a, const RetailGame * b){
        return a->getRetailPrice() < b->getRetailPrice();
    });
}

//Retail game production, dismissal and modification
void Warehouse::produceGames() {
    if (prototypes.size() == 0) {
        Helper::print("There are no prototypes from which to produce games into the inventory.");
        return;
    }
    listPrototypes();
    int index = Helper::read<int>("Enter the prototype number from which to reproduce copies:") - 1;
    if (index >= prototypes.size()) {
        Helper::print("Unexistent prototype index.");
        return;
    }
    int amount = Helper::read<int>("Enter the number of copies to reproduce:");
    RetailGame * prototype = prototypes.at(index);
    if (warehouseSize < inventory.size() + amount) {
        Helper::print("Increasing capacity of the warehouse: " + std::to_string(warehouseSize) + " -> " + std::to_string(warehouseSize + amount) + ".");
        warehouseSize += amount;
    }
    for (int i = 0; i < amount; ++i) {
        RetailGame * newRetailGame = prototype->clone(++lastSerialNumber);
        inventory.push_back(newRetailGame);
    }
}

void Warehouse::removeGamesByName(const std::string name) {
    std::vector<int> resultIndices = searchRetailGamesByName(name);
    if (resultIndices.size() == 0) {
        Helper::print("No games were found with name " + name + ".");
        return;
    }
    Helper::print("The following games will be erased.");
    listInventory(resultIndices);
    if(Helper::read<std::string>("Proceed? [Y/N]") == "Y") {
        deleteRetailGames(resultIndices);
    }
}

void Warehouse::removeGameBySerialNumber(const int sn) {
    int index = searchRetailGameBySerialNumber(sn);
    if (index == -1) {
        Helper::print("No games were found with serial number " + std::to_string(sn) + ".");
        return;
    }
    Helper::print("The following game will be erased.");
    Helper::print(inventory.at(index)->getDescription());
    if (Helper::read<std::string>("Proceed? [Y/N]") == "Y") {
        deleteRetailGame(index);
    }
}

void Warehouse::alterDiscount() {
    
}

void Warehouse::undoDeletion() {
    if (deletedItemsPerOperation.size() == 0) {
        Helper::print("No delete operation to undo.");
        return;
    }
    int numberOfDeletedItemsInLastDeleteOperation = deletedItemsPerOperation.back();
    for (int i = 0; i < numberOfDeletedItemsInLastDeleteOperation; ++i) {
        RetailGame * gameToRestore = deletedItems.back();
        deletedItems.pop_back();
        inventory.push_back(gameToRestore);
    }
    deletedItemsPerOperation.pop_back();
}

//General inventory information
void Warehouse::listInventory(const std::vector<int> indices) const {
    if (inventory.size() == 0) {
        Helper::print("The inventory is empty.");
    }
    if (indices.size() == 1 && indices.at(0) == -1) { //Check if indices was provided or is the default argument, i.e. {-1}, in which case list all inventory
        for (int i = 0; i < inventory.size(); ++i) {
            Helper::print(inventory.at(i)->getDescription());
        }
    }
    else {
        for (int i = 0; i < indices.size(); ++i) {
            Helper::print(inventory.at(indices.at(i))->getDescription());
        }
    }
}

int Warehouse::getItemsCount() const {
    return (int)inventory.size();
}

int Warehouse::getWarehouseSize() const {
    return warehouseSize;
}

void Warehouse::listItemsWithName(const std::string query) const {
    std::vector<int> indices = searchRetailGamesByName(query);
    if (indices.size() == 0) {
        Helper::print("No games found with name " + query + ".");
        return;
    }
    else {
        listInventory(indices);
    }
}

void Warehouse::listItemsWithSerialNumber(const int query) const {
    int index = searchRetailGameBySerialNumber(query);
    if (index == -1) {
        Helper::print((std::string)"No games found with serial number " + std::to_string(query) + ".");
        return;
    }
    else {
        Helper::print(inventory.at(index)->getDescription());
    }
}

RetailGame::RetailGame(Game * newActualGame, const int newSerialNumber, const float newDiscount) {
    actualGame = newActualGame;
    serialNumber = newSerialNumber;
    discount = newDiscount;
}

RetailGame & RetailGame::operator = (Game * newActualGame) {
    this->actualGame = newActualGame;
    return *this;
}

RetailGame * RetailGame::clone(const int newSerialNumber, const float newDiscount) {
    RetailGame * newRetailGame = new RetailGame(this->actualGame, newSerialNumber, newDiscount);
    return newRetailGame;
}

float RetailGame::getRetailPrice() const {
    float regularPrice = actualGame->getPrice();
    return regularPrice*(1-discount/100);
}

std::string RetailGame::getDescription() const {
    std::string description = this->actualGame->getDescription() + "\n";
    description += "Serial Number: " + std::to_string(getSerialNumber()) + "\n";
    description += "Discount: " + std::to_string(getDiscount()) + "\n";
    description += "Retail Price: " + std::to_string(getRetailPrice()) + "\n";
    return description;
}
