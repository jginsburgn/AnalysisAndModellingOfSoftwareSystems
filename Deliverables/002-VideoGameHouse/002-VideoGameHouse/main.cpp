//
//  main.cpp
//  002-VideoGameHouse
//
//  Created by Jonathan Ginsburg on 2/8/17.
//  Copyright © 2017 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Warehouse.hpp"

void printHelp() {
    Helper::print("The available options are:");
    Helper::print("\thelp\t\t\tShow this menu.");
    Helper::print("\tlist\t\t\tList all games in the inventory.");
    Helper::print("\tlistprot\t\tList all prototype games.");
    Helper::print("\tsort <order>\t\tSort inventory items in <order> order, in regards to their retail price; <order> can be ascending or descending.");
    Helper::print("\tsearchn <name>\t\tList all the games in the inventory that have as name <name>.");
    Helper::print("\tsearchs <sn>\t\tList all the games in the inventory that have serial number <sn>.");
    Helper::print("\tinfo\t\t\tShow the number of items in the inventory and the inventory capacity.");
    Helper::print("\tcreate <type>\t\tCreate a new prototype of type <type>, where <type> is strategy, adventure or didactic.");
    Helper::print("\treproduce\t\tMake copies of a game prototype and adds them to the inventory.");
    Helper::print("\tremoven <name>\t\tRemove copies of a game prototype that have as name <name>.");
    Helper::print("\tremoves <sn>\t\tRemove copies of a game prototype that have as serial number <sn>.");
    Helper::print("\tundorem\t\t\tUndo last remove operation, if any.");
    Helper::print("\tclear\t\t\tClear the terminal screen.");
    Helper::print("\texit\t\t\tLeave the REPL (Read-Evaluate-Print Loop).");
    Helper::printSpace();
}

void repl() {
    Helper::print("Welcome to the Inventory manager for the Video Game House Chell A.S. Created by Jonathan Ginsburg on the 13th of February of 2017 for the Analysis and Modelling of Software Systems Class, lectured by Prof. Ariel Gamboa.");
    Warehouse::getInstance();
    printHelp();
    std::string input = "";
    while (input != "exit") {
        input = Helper::readLine("> ");
        if (input == "help") {
            printHelp();
        }
        else if (input == "list") {
            Warehouse::getInstance().listInventory();
        }
        else if (input == "listprot") {
            Warehouse::getInstance().listPrototypes();
        }
        else if (input.substr(0, 4) == "sort") {
            if (input.size() == 4) {
                Helper::print("Argument for sort is missing.");
                continue;
            }
            std::string argument = input.substr(5);
            if (argument == "ascending") {
                Warehouse::getInstance().sortAscending();
            }
            else if (argument == "descending") {
                Warehouse::getInstance().sortDescending();
            }
            else {
                Helper::print("Argument for sort not recognized.");
                continue;
            }
        }
        else if (input.substr(0, 7) == "searchn") {
            if (input.size() == 7) {
                Helper::print("Argument for searchn is missing.");
                continue;
            }
            Warehouse::getInstance().listItemsWithName(input.substr(8));
        }
        else if (input.substr(0, 7) == "searchs") {
            if (input.size() == 7) {
                Helper::print("Argument for searchs is missing.");
                continue;
            }
            Warehouse::getInstance().listItemsWithSerialNumber(std::stoi(input.substr(8)));
        }
        else if (input == "info") {
            Helper::print((std::string)"The number of items in the inventory is: " + std::to_string(Warehouse::getInstance().getItemsCount()) + ".");
            Helper::print((std::string)"The capacity of the warehouse is: " + std::to_string(Warehouse::getInstance().getWarehouseSize()) + ".");
        }
        else if (input.substr(0, 6) == "create") {
            if (input.size() == 6) {
                Helper::print("Argument for create is missing.");
                continue;
            }
            Warehouse::getInstance().addPrototype(input.substr(7));
        }
        else if (input == "reproduce") {
            Warehouse::getInstance().produceGames();
        }
        else if (input.substr(0, 7) == "removen") {
            if (input.size() == 7) {
                Helper::print("Argument for removen is missing.");
                continue;
            }
            Warehouse::getInstance().removeGamesByName(input.substr(8));
        }
        else if (input.substr(0, 7) == "removes") {
            if (input.size() == 7) {
                Helper::print("Argument for removes is missing.");
                continue;
            }
            Warehouse::getInstance().removeGameBySerialNumber(std::stoi(input.substr(8)));
        }
        else if (input == "undorem") {
            Warehouse::getInstance().undoDeletion();
        }
        else if (input == "clear") {
            system("clear");
        }
        else if (input == "exit") {
            Helper::print("Bye!");
        }
        else {
            Helper::print("Unknown command, type help to see all available commands and descriptions.");
        }
    }
}

int main(int argc, const char * argv[]) {
    repl();
    return 0;
}
