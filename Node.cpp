#include "Student.h"
#include "Node.h"
#include <cstddef>

Node::Node(Student* value) {
    next = NULL;
    previous = NULL; 
    this->value = value;
}

Node::~Node() {
    delete value;
    // why delete &value for int example?
}

// setters
void Node::setValue(Student* value) {
    this->value = value;
}

void Node::setNext(Node* next) {
    this->next = next;
}

void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

// getters
Student* Node::getValue() {
    return value;
}

Node* Node::getNext() {
    return next;
}

Node* Node::getPrevious() {
    return previous;
}
