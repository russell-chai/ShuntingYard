#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <climits>
#include <iterator>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;

struct Student {
  char* name;
  int id;
  double gpa;

  Student(char c[], int i, double d) {
    name = new char[strlen(c) + 1]; // make sure to allocate new memory
    std::strcpy(name, c); // copy contents of c[] into new memory
    id = i;
    gpa = d;
  }
  
  ~Student() {
    delete [] name; // delete contents of pointer name
    name = NULL; // delete pointer name
  }

};

void printStudent(Student &s) { // print with GPA to 2 sig figs
  printf("%s, ID %d, GPA %.2f\n", s.name, s.id, s.gpa);
} // why no dereference s.name?

void swap(Student* &s1, Student* &s2) { // passes in two student pointers by reference
  Student* temp = s1; // allows us to swap pointers rather than structs; more efficient
  s1 = s2;
  s2 = temp;
}

int binarySearch(vector<Student*> &v, int idKey) {
  int upper = v.size() - 1, lower = 0;
  while (upper >= lower) {
    int mid = (upper + lower) / 2;
    if (v.at(mid)->id == idKey) return mid;
    else if (v.at(mid)->id < idKey) lower = mid + 1;
    else upper = mid - 1; // if loop breaks and upper < lower then key does not exist in vector
  } return -1;
}

int main() {
  
  vector<Student*>* list = new vector<Student*>();
  char command[SHRT_MAX];
  
  do { // run until quit
    cout << "Enter a command (ADD, DELETE, PRINT, QUIT)> ";
    cin.getline(command, SHRT_MAX);
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
    
    if (strcmp(command, "ADD") == 0) {
      char name[SHRT_MAX], id[SHRT_MAX], gpa[SHRT_MAX];
      cout << "Enter name> "; // get student name
      cin.getline(name, SHRT_MAX);
      cout << "Enter ID> "; // get student id
      cin.getline(id, SHRT_MAX);
      cout << "Enter GPA> "; // get student gpa
      cin.getline(gpa, SHRT_MAX);
      
      // creating new student using constructor
      Student* newStudent = new Student(name, std::atoi(id), std::atod(gpa));
      list->push_back(newStudent);
      cout << "Added ";
      printStudent(*list->back()); // print out last element of list (newly added student)

      // sort vector by id by insertion sort of pointers using student id as sorting reference
      for (std::string::size_type i = list->size() - 1; i > 0 && list->at(i)->id < list->at(i - 1)->id; i--)
	swap(list->at(i), list->at(i - 1)); // swap pointers rather than structs
    }

    else if (strcmp(command, "DELETE") == 0) {
      cout << "Enter ID of student to delete> ";
      char id[SHRT_MAX];
      cin.getline(id, SHRT_MAX);
      int index = binarySearch(*list, std::atoi(id)); // get index by binary search
      if (index >= 0) { // if student with entered id was found then delete
	printf("Deleted %s\n", list->at(index)->name);
	delete list->at(index); // call destructor on contents of student pointer first, before removing pointer
	list->erase(list->begin() + index); // get iterator start and add index to get element
      } else cout << "ID not found.\n";
    }

    else if (strcmp(command, "PRINT") == 0) {
      if (list->size() == 0) cout << "Nothing to print.\n"; // if list is empty print "nothing to print"
      else for (vector<Student*>::iterator i = list->begin(); i != list->end(); std::advance(i, 1)) printStudent(**i);
    } // use iterator to get all students in array
    
  } while (strcmp(command, "QUIT") != 0);
  
  cout << "Program Terminated.\n";
}
