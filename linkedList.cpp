#include <iostream>
#include "Node.h"
#include "Student.h"
#include <string.h>
#include <iomanip>

using namespace std;

void print(Node* node) {
  if (node == NULL) {
    return;
  }
  cout << "hi" << endl;
  node->getStudent()->printInfo();
  cout << endl;
  print(node->getNext());
}
void add(Node* node, Student* student) {
  if (node == NULL) {
    Node* temp = new Node(student);
    node = temp;
    return;
  }
  if (node->getNext() == NULL) {
    Node* temp = new Node(student);
    node->setNext(temp);
    return;
  }
  add(node->getNext(), student);
}
void remove(Node* &head, Node* node, int studentID) {
  if (node->getStudent()->getID() == studentID && node == head) {
    Node* temp = head;
    head = head->getNext();
    delete temp;
    return;
  }
  if (node->getNext()->getStudent()->getID() == studentID) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext();
    return;
  }
  remove(head, node->getNext(), studentID);
}
void average(Node* node, float sum, float count) {
  if (node == NULL) {
    cout << setprecision(2) << fixed;
    cout << (sum / count) << endl;
    return;
  }
  sum += node->getStudent()->getGPA();
    count++;
    average(node->getNext(), sum, count);
}
int main() {
  Node* head = NULL;
  while (true) {
    
    cout << "Type ADD to add student" << endl;
    cout << "Type PRINT to print this list of all students" << endl;
    cout << "Type DELETE to delete a student" << endl;
    cout << "Type AVERAGE to average all the student's GPA" << endl;
    cout << "Type QUIT to quit program" << endl;
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
      Student *temp = new Student(firstName, lastName, studentID, GPA);
      add(head, temp);
    }
    if (strcmp(input, "PRINT") == 0) {
      print(head);
    }
    if (strcmp(input, "DELETE") == 0) {
      int studentID;
      cout << "input student's ID" << endl;
      cin >> studentID;
      remove(head, head, studentID); 
    }
    if (strcmp(input, "AVERAGE") == 0) {
      average(head, 0, 0);
    }
    if (strcmp(input, "QUIT") == 0) {
      return 0;
    }
  }
}
