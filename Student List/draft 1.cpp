/*
 * Student List
 * created by Eric Fan on 10/19/17
 * A tracking interface; operator
 * can add, list, and delete students
 * from this list, while keeping track
 * of student ID and GPA.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <iterator>
using namespace std;

struct Student {
  char name[100];
  int id;
  float gpa;
};

void prtStd(Student s) { // print student with correct formatting (2 decimal places)
  printf("%s, %d, %.2f\n", s.name, s.id, s.gpa);
}

int main() {
  vector<Student*>* list = new vector<Student*>();
  while (true) { // run until quit
    char command[7];
    cout << "Enter a command: ";
    cin.getline(command, 100);
    if (strcmp(command, "ADD") == 0) {
      /*
       * Creates new student pointer,
       * reads in required fields,
       * then adds pointer to vector
       */
      Student* newStudent = new Student();
      cout << "Enter name: ";
      cin.getline(newStudent->name, 100);
      cout << "Enter ID: ";
      char tempID[7];
      cin.getline(tempID, 100);
      newStudent->id = atoi(tempID);
      cout << "Enter GPA: ";
      char tempGPA[10];
      cin.getline(tempGPA, 100);
      newStudent->gpa = atof(tempGPA);
      list->push_back(newStudent);
    } else if (strcmp(command, "DELETE") == 0) {
      /*
       * Get the ID of the student to delete. Use
       * iterator to find and then use list->erase
       */
      cout << "Enter the ID of the student you wish to delete: ";
      char tempID[7];
      cin.getline(tempID, 100);
      for (vector<Student*>::iterator i = list->begin(); i != list->end(); i++) {
	if ((*i)->id == atoi(tempID)) {
	  list->erase(i);
	  break;
	}
      }
    } else if (strcmp(command, "PRINT") == 0) for (vector<Student*>::iterator i = list->begin(); i != list->end(); i++) prtStd(**i);
    else if (strcmp(command, "QUIT") == 0) {
      cout << "Program terminated.";
      break;
    } else printf("Invalid command: %s. ", command);
  }
}
