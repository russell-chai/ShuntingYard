#include "Student.h"
#include "Node.h"
#include <cstddef>
#include <cstdio>

void add(Student* value, Node* &head) {
    Node* previous = NULL; // keep track of node before current node
    while (head != NULL) { // if head is already null don't do anything
        previous = head; // this will be one step behind in loop
        head = head->getNext(); // set head equal to frontmost node until null
    } head = new Node(value); // create new node to be head
    if (previous != NULL) {
        head->setPrevious(previous); // set node prior to head
        head->getPrevious()->setNext(head); // set head as node after prior node
    }
}

void print(Node* node) {
    printf("%s, %d, %.2f\n", node->getValue()->getName(), node->getValue()->getID(), node->getValue()->getGPA());
    if (node->getPrevious() != NULL) print(node->getPrevious());
}


int main() {
    Node* head = NULL;
    add(new Student(new char[5]{'E','r','i','c','\0'}, 322328, 4.28), head);
    add(new Student(new char[6]{'J','a','s','o','n','\0'}, 432123, 4.28), head);
    add(new Student(new char[7]{'C','o','n','n','o','r','\0'}, 111111, 4.43), head);
    print(head);
}
