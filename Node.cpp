#include "Node.h"

Node::Node(Student* newStudent) {
  student = newStudent;
}
Node::~Node() {
  delete[] student;
  delete[] nextNode;
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
