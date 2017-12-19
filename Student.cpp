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

//print all of Student's infor
void Student::printInfo() {
 cout << setprecision(2) << fixed;
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

