#include <iostream>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

struct node {
  char operand;
  node *next;
};

void removeHead(node* head) {
  node* temp = head->next;
  delete head;
  head = temp;
}
void addToHead(char newOperand, node *head) {
  node *temp = new node();
  temp->operand = newOperand;
  temp->next = head;
  head = temp;
}
int main() {

  cout << "input mathmatecal expression" << endl;
  cout << "use '+' for addition" << endl;
  cout << "use '-' for subtraction" << endl;
  cout << "use '*' for multiplication" << endl;
  cout << "use '/' for division" << endl;
  cout << "use '^' for power" << endl;
  
  node *stackHead = new node();
  stackHead->next = NULL;
  stackHead->operand = ' ';

  map<char, int> precedence;
  precedence['^'] = 3;
  precedence['*'] = 2;
  precedence['/'] = 2;
  precedence['+'] = 1;
  precedence['-'] = 1;

  map<char, char> associativity;
  associativity['^'] = 'r';
  associativity['*'] = 'l';
  associativity['/'] = 'l';
  associativity['+'] = 'l';
  associativity['-'] = 'l';

  vector<char*> postfix;
  
  char *input = new char(5);
  cin.get(input, 5, ' ');
  while (input[0] != '\n') {
    if ('0' <= input[0] && input[0] <= '9') {
      cout << input << endl;
    }
    else {
      else if (input == '(') {
	addToHead(input, head);
      }
      else if (input == ')') {
	node *temp = stackHead;
	while (temp->operand != '(') {
	  cout << " " << temp->operand << " ";
	  removeHead(temp);
	}
	stackHead = temp->next;
	delete temp;
      }
      else {
	cout << " ";
	while (stackHead->operand != ' ' && stackHead->operand != '(' &&
	     ((precedence[input] < precedence[stackHead->operand]) || (precedence[input] == precedence[stackHead->operand] && associativity[input] == 'l'))) {
	  cout << stackHead->operand << " ";
	  removeHead(stackHead);
	}
	addToHead(input, stackHead);
      }
    }
    cin >> input;
  }
  while (stackHead->next != NULL) {
    cout << " " << stackHead->operand << " ";
    removeHead(stackHead);
  }
  return 0;
}
