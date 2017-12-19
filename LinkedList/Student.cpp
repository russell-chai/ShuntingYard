#include "Student.h"
#include <cstring>

Student::Student(char name[], int id, float gpa) {
    this->name = new char[strlen(name) + 1]; // alloc memory for name
    strcpy(this->name, name); // copy into new memory
    this->id = id;
    this->gpa = gpa;
}

Student::~Student() {
    delete [] name; // only this uses dynamic memory
}

// getters
char* Student::getName() {
    return name;
}

int Student::getID() {
    return id;
}

float Student::getGPA() {
    return gpa;
}
