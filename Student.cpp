#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

//Student contructer
Student::Student(char* newFirstName, char* newLastName, int newID, float newGPA) {
 firstName = newFirstName;
 lastName = newLastName;
 ID = newID;
 GPA = newGPA;
}

//Student deconstructor
Student::~Student() {
 delete firstName;
 delete lastName;
}

//print all of Student's info
void Student::printInfo() {
<<<<<<< HEAD
  cout << setprecision(2) << fixed;
=======
 cout << setprecision(2) << fixed;
>>>>>>> 00460c9126627beb55b82cf95989117dc2ae9c63
 cout << "Name: " << firstName << " " << lastName << endl;
 cout << "Student ID: " << ID << endl;
 cout << "Student GPA: " << GPA << endl;
}

//return Student's first name
char* Student::getFirstName() {
 return firstName;
}

//return Student's last name
char* Student::getLastName() {
 return lastName;
}

//return Student's ID
int Student::getID() {
 return ID;
}

//return Student's GPA
float Student::getGPA() {
 return GPA;
}

