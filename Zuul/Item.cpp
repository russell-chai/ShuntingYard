#include <cstring>
#include <iostream>
#include "Item.h"

Item::Item(int type, char name[], int boost, int strength) {
    this->type = type;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->boost = boost;
    this->strength = strength;
}

Item::~Item() {
    delete [] name;
}

int Item::getType() {
    return type;
}

char* Item::getName() {
    return name;
}

void Item::switchType() {
    if (type == ENEMY) {
        type = DEF;
        strength = 0;
        char name[strlen(this->name) + 1];
        strcpy(name, this->name);
        delete [] this->name;
        this->name = new char[strlen(name) + 8];
        strcpy(this->name, strcat(name, " Trophy"));
    }
}

int Item::getBoost() {
    return boost;
}

int Item::getStrength() {
    return strength;
}
