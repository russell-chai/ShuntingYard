/*
Author: Russell Chai
This program creates a list of students that can be modified and can pull information from list
*/
#include <iostream>
#include "Node.h"
#include "Student.h"
#include <string.h>
#include <iomanip>

using namespace std;
//print all of students
void print(Node* node) {
  if (node == NULL) {
    return;
  }
  node->getValue()->printInfo();
  cout << endl;
  print(node->getNext());
}
//add student to the next avaliable space
void add(Node* &head, Node* node, Student* student) {
  if (node == NULL) {
    Node* temp = new Node(student);
    head = temp;
    return;
  }
  if (node->getNext() == NULL) {
    Node* temp = new Node(student);
    node->setNext(temp);
    return;
  }
  add(head, node->getNext(), student);
}
//search for student ID and delete
void remove(Node* &head, Node* node, int studentID) {
  if (node->getValue()->getID() == studentID && node == head) {
    Node* temp = head;
    head = head->getNext();
    delete temp;
    return;
  }
  if (node->getNext()->getValue()->getID() == studentID) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext();
    return;
  }
  remove(head, node->getNext(), studentID);
}
//get average
void average(Node* node, float sum, float count) {
  if (node == NULL) {
    cout << setprecision(2) << fixed;
    cout << (sum / count) << endl;
    return;
  }
  sum += node->getValue()->getGPA();
    count++;
    average(node->getNext(), sum, count);
}
int main() {
  //head node
  Node* head = NULL;
  while (true) {
    //print user's options
    cout << "Type ADD to add student" << endl;
    cout << "Type PRINT to print this list of all students" << endl;
    cout << "Type DELETE to delete a student" << endl;
    cout << "Type AVERAGE to calculate the average GPA" << endl;
    cout << "Type QUIT to quit program" << endl;
    char *input = new char(8);
    cin.getline(input, 8);
    //to ADD user
    if (strcmp(input, "ADD") == 0) {
      //get student's information
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
      add(head, head, temp);
    }
    //print students
    if (strcmp(input, "PRINT") == 0) {
      print(head);
    }
    //delete a student
    if (strcmp(input, "DELETE") == 0) {
      //get deleted student's ID
      int studentID;
      cout << "input student's ID" << endl;
      cin >> studentID;
      cin.ignore();
      remove(head, head, studentID); 
    }
    //get average of all student's GPA
    if (strcmp(input, "AVERAGE") == 0) {
       average(head, 0, 0);
    }
    //quit
    if (strcmp(input, "QUIT") == 0) {
      return 0;
    }
  }
}
