#include "Student.h"

class Node {
 public:
  Node(Student* newStudent);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newNextNode);;
  
 private:
  Student* student;
  Node* nextNode;
};
