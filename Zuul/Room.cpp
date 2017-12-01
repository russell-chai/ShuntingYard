#include "Item.h"
#include "Room.h"
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
using std::vector;
using std::map;

Room::Room(char name[], char description[]) {
    // copy parameters to new allocated memory
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    items = new vector<Item*>();
}

Room::~Room() {
    // dealloc dynamic memory
    delete [] name;
    delete [] description;
    // need to dealloc memory for items
    // but do not need to delete Item pointers because that's automatically deleted in delete items
    for (vector<Item*>::iterator i = items->begin(); i != items->end(); i++) delete *i;
    delete items;
    // no need to dealloc room pointers in exits
    // those will be deallocated in main
}

char* Room::getName() {
    return name;
}

void Room::print() {
    printf("\nYou are in %s. \n%s", name, description);
    if (items->size() > 0) { // only print out stuff if not empty
        printf("\nThere are items in the room: ");
        for (int i = 0; i < items->size(); i++) { 
            if (items->at(i)->getType() == Item::ENEMY) printf("(%dhp ENEMY) ", items->at(i)->getStrength());
            else if (items->at(i)->getType() == Item::BOSS) printf("(%dhp BOSS) ", items->at(i)->getStrength());
            printf("%s%s", items->at(i)->getName(), i == items->size() - 1 ? ". " : ", ");
        }
    } else printf("\nThe room is empty. ");
    // don't check for exits.size() > 0, there is always exit
    printf("\nThere are %d exits to: ", exits.size());
    for (int i = 0; i < exits.size(); i++)
        printf("%s%s", exits.at(i)->getName(), i == exits.size() - 1 ? ".\n\n" : ", "); 
}

vector<Item*>* Room::getItems() {
    return items;
}

vector<Room*> Room::getExits() {
    return exits;
}

void Room::addExit(Room* room) {
    exits.push_back(room); 
    //room->getExits().push_back(this);
}

void Room::addItem(Item* item) {
    items->push_back(item);
}

void Room::removeItem(Item* item) {
    // iterate through all items
    for (vector<Item*>::iterator i = items->begin(); i != items->end(); i++) {
        if ((*i) == item) { // if found item
            delete *i; // dealloc spot in memory
            items->erase(i--); // i-- only matters if deleting multiple
            break; // only pick up one item
        }
    }
}
