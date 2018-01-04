#include "Item.h"
#include <map>
#include <vector>
#ifndef ROOM_H_
#define ROOM_H_

class Room {

public:
    Room(char name[], char description[]);
    ~Room(); // need to dealloc name and description
    char* getName();
    void print(); // what happens to the returned reference?
    std::vector<Item*>* getItems();
    std::vector<Room*> getExits();
    // don't allow changing of name and description
    // "setters" for items and exits
    void addExit(Room* room);
    // will not be removing exits except in destructor, no need for removeExit();
    void addItem(Item* item);
    void removeItem(Item* item);

private:
    char* name;
    char* description; // description of the room should be complete sentence (with space at end)
    std::vector<Item*>* items; // need this to be reference, must be referred to in main
    std::vector<Room*> exits; // does not need to be reference because only need read not write
};

#endif
