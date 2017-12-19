#include <iostream>
#include "Node.h"
#include "Student.h"
#include <cstring>

using namespace std;

void print(Node* node) {
  if (node == NULL) {
    return;
  }
  node->getStudent()->printInfo();
  cout << endl;
  print(node->getNext());
}
void add(Node* node, Student* student) {
  if (node->getNext() == NULL) {
    Node* temp = new Node(student);
    node->setNext(temp);
    return;
  }
  add(node->getNext(), student);
}
void remove(Node* &head, Node* node, int studentID) {
  if (node->getStudent()->getID() == student && node == head) {
    Node* temp = head;
    head = head->getNext();
    delete temp;
    return;
  }
  if (node->getNext()->getStudent()->getID() == student) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext();
    return;
  }
  remove(head, node->getNext(), student);
}
int main() {
  cout << "Type ADD to add student" << endl;
  cout << "Type PRINT to print this list of all students" << endl;
  cout << "Type DELETE to delete a student" << endl;
  cout << "Type AVERAGE to average all the student's GPA" << endl;
  cout << "Type QUIT to quit program" << endl;
  Node* head = NULL;
  while (true) {
    char *input = new char(7);
    cin.getline(input, 7);
    if (strcmp(input, "ADD") == 0) {
      char* firstName = new char(50);
      char* lastName = new char(50);
      int studentID;
      float GPA;
      cout << "input student's first name" << endl;
      cin.getline(firstName, 50);
      cout << "input student's last name" << endl;
      cin.getline(lastName, 50);
      cout << "input student's ID" << endl;
      cin >> studentID;
      cin.ignore();
      cout << "input student's GPA" << endl;
      cin >> GPA;
      cin.ignore();
      Student temp = new Student(firstName, lastName, studentID, GPA);
      add(head, temp);
    }
    if (strcmp(input, "PRINT") == 0) {
      print(head);
    }
    if (strcmp("DELETE") == 0) {
      int studentID;
      cout << "input student's ID" << endl;
      cin >> studentID;
      remove(head, head, studentID); 
    }
    
  }
}
