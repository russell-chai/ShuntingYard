//Student header file
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
 public:
   Student(char* newFirstName, char* newLastName, int newID, float newGPA);
   ~Student();
   void printInfo();//prints all of the student's information
   char* getFirstName();//gets first name
   char* getLastName();//gets last name
   int getID();//get student ID
   float getGPA();//get GPA

 private:
   char* firstName;
   char* lastName;
   int ID;
   float GPA;
};

#endif /*OBJECTS_H*/
