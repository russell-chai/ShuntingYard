#include <iostream>
#include <map>
#include <vector>
#include <string.h>

using namespace std;

struct stackNode {
  char operand;
  stackNode *next;
};
struct treeNode {
  treeNode *parent;
  treeNode *left;
  treeNode *right;
  bool isOperand;
  char operand;
  int number;
};
void removeHead(stackNode* &head) {
  stackNode* temp = head->next;
  delete head;
  head = temp;
}
void addToHead(char newOperand, stackNode* &head) {
  stackNode *temp = new stackNode();
  temp->operand = newOperand;
  temp->next = head;
  head = temp;
}
void printStack(stackNode *head) {
  cout << "hello" << endl;
  if (head->operand == ' ') {
    return;
  }
  cout << head->operand;
  printStack(head->next);
}
int main() {

  cout << "input mathmatecal expression" << endl;
  cout << "use '+' for addition" << endl;
  cout << "use '-' for subtraction" << endl;
  cout << "use '*' for multiplication" << endl;
  cout << "use '/' for division" << endl;
  cout << "use '^' for power" << endl;
  
  stackNode *stackHead = new stackNode();
  stackHead->next = NULL;
  stackHead->operand = ' ';

  treeNode *topNode = new treeNode();
  topNode->parent = NULL;
  
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
  
  char *input = new char(200);
  int runningInt = 0;
  cin.getline(input, 200);
  cout << "Postfix: ";
  for (int a = 0; a < strlen(input); a++) {
    if ('0' <= input[a] && input[a] <= '9') {
      runningInt = runningInt * 10 + (input[a] - '0');
    }
    else {
      if (input[a] == ' ') {
	if (runningInt > 0) {
	  cout << runningInt << " ";
	}
	runningInt = 0;
      }
      else if (input[a] == '(') {
	addToHead(input[a], stackHead);
      }
      else if (input[a] == ')') {
	stackNode *temp = stackHead;
	while (temp->operand != '(') {
	  cout << temp->operand << " ";
	  removeHead(temp);
	}
	stackHead = temp->next;
	delete temp;
      }
      else {
	while (stackHead->operand != ' ' && stackHead->operand != '(' &&
	     ((precedence[input[a]] < precedence[stackHead->operand]) || (precedence[input[a]] == precedence[stackHead->operand] && associativity[input[a]] == 'l'))) {
	  cout << stackHead->operand << " ";
	  removeHead(stackHead);
	}
	addToHead(input[a], stackHead);
      }
    }
  }
  if (runningInt != 0) {
    cout << runningInt << " ";
  }
  while (stackHead->next != NULL) {
    cout << stackHead->operand << " ";
    removeHead(stackHead);
  }
  return 0;
}
