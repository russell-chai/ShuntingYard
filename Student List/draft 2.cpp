#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <iterator>
#include <algorithm>
using std::cout;
using std::cin;
using std::vector;
using std::string;

struct Student {
  char* name;
  int id;
  double gpa;

  Student(string s, int i, double d) {
    name = new char[s.length() + 1];
    std::strcpy(name, s.c_str());
    id = i;
    gpa = d;
  }
  
  ~Student() {
    delete [] name;
    name = NULL;
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
  string command;
  
  do { // run until quit
    cout << "Enter a command (ADD, DELETE, PRINT, QUIT)> ";
    getline(cin, command);
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);
    
    if (command.compare("ADD") == 0) {
      string name, id, gpa;
      cout << "Enter name> "; // get student name
      getline(cin, name);
      cout << "Enter ID> "; // get student id
      getline(cin, id);
      cout << "Enter GPA> "; // get student gpa
      getline(cin, gpa);

      Student* newStudent = new Student(name, std::stoi(id), std::stod(gpa));
      list->push_back(newStudent);
      cout << "Added ";
      printStudent(*list->back());

      // sort vector by id by insertion sort of pointers using student id as sorting reference
      for (std::string::size_type i = list->size() - 1; i > 0 && list->at(i)->id < list->at(i - 1)->id; i--)
	swap(list->at(i), list->at(i - 1)); // swap pointers rather than structs
    }

    else if (command.compare("DELETE") == 0) {
      cout << "Enter ID of student to delete> ";
      string id;
      getline(cin, id);
      int index = binarySearch(*list, std::stoi(id)); // get index by binary search
      if (index >= 0) { // if student with entered id was found then delete
	printf("Deleted %s\n", list->at(index)->name);
	delete list->at(index); // call destructor
	list->erase(list->begin() + index); // get iterator start and add index to get element
      } else cout << "ID not found.\n";
    }

    else if (command.compare("PRINT") == 0) // i.advance()?
      if (list->size() == 0) cout << "Nothing to print.\n";
      else for (vector<Student*>::iterator i = list->begin(); i != list->end(); i++) printStudent(**i);
    
  } while (command.compare("QUIT") != 0);
  
  cout << "Program Terminated.\n";
}
