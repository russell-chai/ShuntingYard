#include "Node.h"
//Node constructor
Node::Node(Student* newStudent) {
  student = newStudent;
  nextNode = NULL;
}
//Node destructor
Node::~Node() {
  delete student;
}
//get next node
Node* Node::getNext() {
  return nextNode;
}
//get student of the node
Student* Node::getStudent() {
  return student;
}
//set the next node
void Node::setNext(Node* newNextNode) {
  nextNode = newNextNode;
}
