/*
Russell Chai
This program takes a mathmatical expression and converts it to prefix, infix and postfix, using 
shunting yard algorithm and binary expression tree
*/
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <stack>

using namespace std;

//node for stack for shunting yard
struct stackNode {
	char operand;
	stackNode *next;
};
//tree node used for binary expression tree
struct treeNode { 
	treeNode *left;
	treeNode *right;
	bool isOperand;
	char operand;
	int number;
};
//removes the top node in a stack
void removeHead(stackNode* &head) {
	stackNode* temp = head->next;
	delete head;
	head = temp;
}
//adds a node to the head of the stack
void addToHead(char newOperand, stackNode* &head) {
	stackNode *temp = new stackNode();
	temp->operand = newOperand;
	temp->next = head;
	head = temp;
}
//print out prefix notation from binary expression tree
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
//print out infix notation from binary expression tree
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
//print out postfix notation from binary expression tree
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

	//first node in stack
	stackNode *stackHead = new stackNode();
	stackHead->next = NULL;
	stackHead->operand = ' ';

	//stack used to create binary tree
	stack<treeNode*> binaryTree;

	//order of precedence for operators
	map<char, int> precedence;
	precedence['^'] = 3;
	precedence['*'] = 2;
	precedence['/'] = 2;
	precedence['+'] = 1;
	precedence['-'] = 1;

	//operator associativity
	map<char, char> associativity;
	associativity['^'] = 'r';
	associativity['*'] = 'l';
	associativity['/'] = 'l';
	associativity['+'] = 'l';
	associativity['-'] = 'l';

	char *input = new char(200);
	int runningInt = 0; //use running int for multiple digit numbers
	cin.getline(input, 200);

	cout << "Postfix: ";
	for (int a = 0; a < strlen(input); a++) {
		//if character is a number, add the number to the running int
		if ('0' <= input[a] && input[a] <= '9') {
			runningInt = runningInt * 10 + (input[a] - '0');
		}
		else {
			if (input[a] == ' ') {
				//print out number and create a tree node for number
				if (runningInt > 0) {
					cout << runningInt << " ";
					
					treeNode *number = new treeNode();
					number->left = NULL;
					number->right = NULL;
					number->isOperand = false;
					number->number = runningInt;
					
					binaryTree.push(number);
				}
				runningInt = 0;
			}
			//if character is a opening paranthesis
			else if (input[a] == '(') {
				addToHead(input[a], stackHead);
			}
			//if character is a ending paranthesis
			else if (input[a] == ')') {
				stackNode *temp = stackHead;
				while (temp->operand != '(') { //keep returning what is on top of the stack until the operand is a opening paranthesis
					cout << temp->operand << " ";
					
					//create a new tree node by taking the top two nodes on the binary tree stack
					treeNode *second = binaryTree.top();
					binaryTree.pop();
					treeNode *first = binaryTree.top();
					binaryTree.pop();

					treeNode *expression = new treeNode();
					expression->left = first;
					expression->right = second;
					expression->isOperand = true;
					expression->operand = temp->operand;
					
					binaryTree.push(expression);
					removeHead(temp);
				}
				stackHead = temp->next;
				delete temp;
			}
			else {
				//keep returning operands until the stack matches certain conditions
				while (stackHead->operand != ' ' && stackHead->operand != '(' &&
					((precedence[input[a]] < precedence[stackHead->operand]) || (precedence[input[a]] == precedence[stackHead->operand] && associativity[input[a]] == 'l'))) {
					cout << stackHead->operand << " ";
					
					//merge the top two nodes on binary tree stack into one
					treeNode *second = binaryTree.top();
					binaryTree.pop();
					treeNode *first = binaryTree.top();
					binaryTree.pop();

					treeNode *expression = new treeNode();
					expression->left = first;
					expression->right = second;
					expression->isOperand = true;
					expression->operand = stackHead->operand;
					
					binaryTree.push(expression);
			
					removeHead(stackHead);
				}
				addToHead(input[a], stackHead);
			}
		}
	}
	//if there still is a running int, return it
	if (runningInt != 0) {
		cout << runningInt << " ";

		treeNode *number = new treeNode();
		number->left = NULL;
		number->right = NULL;
		number->isOperand = false;
		number->number = runningInt;

		binaryTree.push(number);
	}

	//returning all the operands still in the stack
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

		binaryTree.push(expression);
	
		removeHead(stackHead);
	}
	
	//print out prefix, infix and postfix with binary expression tree
	cout << endl << "Expression with binary expression tree:" << endl;
	cout << "Prefix: ";
	prefix(binaryTree.top());
	cout << endl << "Infix: ";
	infix(binaryTree.top()); 
	cout << endl << "Posfix: ";
	postfix(binaryTree.top());
	
	return 0;
}
