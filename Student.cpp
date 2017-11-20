#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(char* newFirstName, char* newLastName, int newID, float newGPA) {
  firstName = newFirstName;
  lastName = newLastName;
  ID = newID;
  GPA = newGPA;
}
Student::~Student() {
  delete[] firstName;
  delete[] lastName;
}
void Student::printInfo() {
  cout << "Name: " << firstName << " " << lastName << endl;
  cout << "Student ID: " << ID << endl;
  cout << "Student GPA: " << GPA << endl;
}
char* Student::getFirstName() {
  return firstName;
}
char* Student::getLastName() {
  return lastName;
}
int Student::getID() {
  return ID;
}
float Student::getGPA() {
  return GPA;
}
