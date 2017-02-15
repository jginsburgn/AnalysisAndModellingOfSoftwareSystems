#Video Game House

This REPL was developed as an exercise to implement four Software Design Patters seen during lectures. Detailed explanation, per design pattern, follows.

##Prototype

Each ```RetailGame``` has the ability to clone itself through its ```clone()``` method. This is useful as each instance of this class comes from a model one that has an invalid serial number (i.e. ```0```).

##Factory Method

The ```Game``` class has a ```produce()``` method that hides/abstracts internal production operations, which are implemented by each child class. These operations are:

1. Conception
2. Design
3. Planning
4. Production
5. Testing

##Singleton

The ```Warehouse``` is a singleton. This is handy as all serial numbers are assigned from this class and there should not be duplicates. Also, this allows for a single unified instance that inhibits redundancy of data for the given purpose (See ``PrimerParcial-17.pdf```), and provides coherence among all users.

##Proxy

The ```RetailGame``` class acts as a proxy to ```Game```, extending its capabilities (by providing discount and serial number attributes, and calculating final retail price). In addition, it allows for the concept of prototype to work correctly, as many ```RetailGame``` instances can point to a single ```Game``` instance that is the game from which the copy was made.
