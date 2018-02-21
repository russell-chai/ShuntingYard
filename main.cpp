#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

struct stackNode {
	char operand;
	stackNode *next;
};
struct treeNode { 
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
void prefix(treeNode *parent) {
	if (parent != NULL) {
		if (parent->isOperand == true) {
			cout << parent->operand << " ";
		}
		else {
			cout << parent->number << " ";
		}
		prefix(parent->left);
		prefix(parent->right);
	}
}
void infix(treeNode *parent) {
	if (parent != NULL) {
		if (parent->isOperand == true) {
			cout << "( ";
		}
		infix(parent->left);
		if (parent->isOperand == true) {
			cout << parent->operand << " ";
		}
		else {
			cout << parent->number << " ";
		}
		infix(parent->right);
		if (parent->isOperand == true) {
			cout << ") ";
		}
	}
}
void postfix(treeNode *parent) {
	if (parent != NULL) {
		postfix(parent->left);
		postfix(parent->right);
		if (parent->isOperand == true) {
			cout << parent->operand << " ";
		}
		else {
			cout << parent->number << " ";
		}
	}
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

	stack<treeNode*> binaryTree;

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
					treeNode *number = new treeNode();
					number->left = NULL;
					number->right = NULL;
					number->isOperand = false;
					number->number = runningInt;
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

					treeNode *second = binaryTree.top();
					binaryTree.pop();
					treeNode *first = binaryTree.top();
					binaryTree.pop();

					treeNode *expression = new treeNode();
					expression->left = first;
					expression->right = second;
					expression->isOperand = true;
					expression->operand = temp->operand;
					
					removeHead(temp);
				}
				stackHead = temp->next;
				delete temp;
			}
			else {
				while (stackHead->operand != ' ' && stackHead->operand != '(' &&
					((precedence[input[a]] < precedence[stackHead->operand]) || (precedence[input[a]] == precedence[stackHead->operand] && associativity[input[a]] == 'l'))) {
					cout << stackHead->operand << " ";

					treeNode *second = binaryTree.top();
					binaryTree.pop();
					treeNode *first = binaryTree.top();
					binaryTree.pop();

					treeNode *expression = new treeNode();
					expression->left = first;
					expression->right = second;
					expression->isOperand = true;
					expression->operand = stackHead->operand;

					removeHead(stackHead);
				}
				addToHead(input[a], stackHead);
			}
		}
	}
	if (runningInt != 0) {
		cout << runningInt << " ";
		treeNode *number = new treeNode();
		number->left = NULL;
		number->right = NULL;
		number->isOperand = false;
		number->number = runningInt;
	}
	while (stackHead->next != NULL) {
		cout << stackHead->operand << " ";

		treeNode *second = binaryTree.top();
		binaryTree.pop();
		treeNode *first = binaryTree.top();
		binaryTree.pop();

		treeNode *expression = new treeNode();
		expression->left = first;
		expression->right = second;
		expression->isOperand = true;
		expression->operand = stackHead->operand;

		removeHead(stackHead);
	}

	cout << "Expression with binary expression tree:" << endl;
	cout << "Prefix: ";
	prefix(binaryTree.top());
	cout << endl << "Infix: ";
	infix(binaryTree.top()); 
	cout << endl << "Posfix: ";
	postfix(binaryTree.top());


	system("pause");
	return 0;
}
