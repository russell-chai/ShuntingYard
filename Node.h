#include "Student.h"
#ifndef NODE_H_
#define NODE_H_

class Node {

public:
    Node(Student* value); // enables setting value when created
    ~Node();
    // setters
    void setValue(Student* value);
    void setNext(Node* next);
    void setPrevious(Node* previous); // doubly linked list
    // getters
    Student* getValue();
    Node* getNext();
    Node* getPrevious(); // doubly linked list

private:
    Student* value;
    Node* next;
    Node* previous;

};

#endif
