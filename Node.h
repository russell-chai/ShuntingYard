#include "Student.h"

class Node {
 public://Node's functions
  Node(Student* newStudent);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newNextNode);;
  
 private://Node's variables
  Student* student;
  Node* nextNode;
};
