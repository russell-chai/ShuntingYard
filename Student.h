
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
 public:
   Student(char* newFirstName, char* newLastName, int newID, float newGPA);
   ~Student();
   void printInfo();
   char* getFirstName();
   char* getLastName();
   int getID();
   float getGPA();

 private:
   char* firstName;
   char* lastName;
   int ID;
   float GPA;
};

#endif /*OBJECTS_H*/

