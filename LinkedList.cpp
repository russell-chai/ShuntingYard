/*
Author: Russell Chai
Date: 12/5/17
This program creates a LinkedList of Student nodes
*/
#include <iostream>
#include "Node.h"
#include "Student.h"
#include <cstring>

using namespace std;

//print out all the nodes
void print(Node* node) {
  //when the node is null, time to stop
  if (node == NULL) {
    return;
  }
  //print node
  node->getStudent()->printInfo();
  cout << endl;
  //print next node
  print(node->getNext());
}
//add node to end of linkedlist
void add(Node* node, Student* student) {
  if (node->getNext() == NULL) {//when next node is null, set next node to new node
    Node* temp = new Node(student);
    node->setNext(temp);
    return;
  }
  //recurse to the next node
  add(node->getNext(), student);
}
//remove a node
void remove(Node* &head, Node* node, Student* student) {
  if (node->getStudent() == student && node == head) {//if removed node is head node
    Node* temp = head;
    head = head->getNext();
    delete temp;
    return;
  }
  //if next node is remove node then set the next node to next next node and delete remove node
  if (node->getNext()->getStudent() == student) {
    node->setNext(node->getNext()->getNext());
    delete node->getNext();
    return;
  }
  //recurse to the next node
  remove(head, node->getNext(), student);
}
int main() {
  //creating nodes
  char* first = new char(8);
  strcpy(first, "Russell");
  char* last = new char(5);
  strcpy(last, "Chai");
  Student* russell = new Student(first, last, 417856, 4.0);
  Student* connor = new Student("Connor", "Shu", 322023, 5.0);
  Student* donglai = new Student("Donglai", "Men", 310231, 4.0);
  Student* bob = new Student("Bob", "Lee", 320721, 2.1);
  //set head node to russell
  Node* head = new Node(russell);
  //printing out head node
  print(head);
  cout << endl << endl;
  //add connor to the linkedlist
  add(head, connor);
  print(head);
  cout << endl << endl;
  //add donglai to the linkedlist
  add(head, donglai);
  print(head);
  cout << endl << endl;
  //add bob to the linkedlist
  add(head, bob);
  print(head);
  cout << endl << endl;
  //remove bob from the linkedlist
  remove(head, head, bob);
  print(head);
  cout << endl << endl;
  //remove head from linkedlist
  remove(head, head, russell);
  print(head);
}
