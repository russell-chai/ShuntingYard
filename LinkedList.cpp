#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

void print(Node* node) {
  if (node == NULL) {
    return;
  }
  node->getStudent()->printInfo();
  cout << endl;
  print(node->getNext());
}
void add(Node* node, Student* student) {
  if (node->getNext() == NULL) {
    Node* temp = new Node(student);
    node->setNext(temp);
    return;
  }
  add(node->getNext(), student);
  
}
void remove(Node* node, Student* student) {
  if (node->getNext()->getStudent() == student) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext();
    delete student;
    return;
  }
  remove(node->getNext(), student);
}
int main() {
  Student* russell = new Student("Russell", "Chai", 417856, 4.0);
  Student* jason = new Student("Jason", "Shi", 322023, 1.0);
  Student* donglai = new Student("Donglai", "Men", 310231, 4.0);
  Student* connor = new Student("Connor", "Shu", 320721, 2.1);
  Node* head = new Node(russell);
  print(head);
  add(head, jason);
  print(head);
  add(head, donglai);
  print(head);
  add(head, connor);
  print(head);
  remove(head, jason);
  print(head);
}
