#include "Node.h"

Node::Node(Student* newStudent) {
  student = newStudent;
  nextNode = NULL;
}
Node::~Node() {
  delete[] student;
}
Node* Node::getNext() {
  return nextNode;
}
Student* Node::getStudent() {
  return student;
}
void Node::setNext(Node* newNextNode) {
  nextNode = newNextNode;
}
