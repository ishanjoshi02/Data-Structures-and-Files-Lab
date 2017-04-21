/*
 * By Ishan Joshi
 */
#include <iostream>
using namespace std;
//Simple Tip use string objects instead of using char arrays. Google why it's better
template <class T>
class Stack {
	typedef struct node {
		T data;
		node *next;
	}node;
	node *top;
public :
	Stack() {
		top = NULL;
	}
	bool isEmpty() {
		if (top == NULL)
			return true;
		return false;
	}
	bool isFull() {
		node *ptr;
		ptr = new node;
		 //If the RAM is full ptr will be initialised to NULL meaning the Stack is full
		if (ptr == NULL)
			return true;
		delete ptr;
		return false;
	}
	void push(T);
	T pop();
	T stackTop();
};

template <class T>
void Stack<T>::push(T element) {
	if (this->isFull()) {
		cout << "Stack is Full\nDelete some nodes to continue\n";
		return;
	}
	node *ptr;
	ptr = new node;
	ptr->data = element;
	ptr->next = top;
	top = ptr;
}
template <class T>
T Stack<T>::pop() { //Simple Pop Operation on Stack Object
	if (this->isEmpty()) {
		cout << "Stack is Empty\n";
	}
	else {
		T data;
		node *p;
		p = top;
		data = top->data;
		top = top->next;
		delete p;
		return data;
	}
}
template <class T>
T Stack<T>::stackTop() {
	if (!isEmpty()) {
		return top->data;
	}
	else {
		cout << "Stack is Empty";
	}
}
int precedence(char c) {//This Function used as BODMAS simulator
	if (c == '(') {
		return 0;
	}
	if(c == '+' || c == '-') {
		return 1;
	}
	if(c == '*' || c == '/' || c == '%') {
		return 2;
	}
	return 3;
}
string reverseString(string expression) { //Function to reverse a string. Only thing to remember is to replace ( with ) and vice versa
	int length = expression.length();
	string reverse = "";
	char c;
	Stack<char> stack;

	for(int i = 0; i<length;i++) {
		c = expression.at(i);
		stack.push(c);
	}
	while(!stack.isEmpty()) {
		c = stack.pop();
		if (c == ')') {
			c = '(';
		}
		else if (c == '(') {
			c = ')';
		}
		reverse += c;
	}
	return reverse;
}
string toPostFix(string expression) {
	char c, op;
	string postFixExpression = "";
	Stack<char> ExpressionStack;
	int length = expression.length();
	for(int i = 0; i < length; i++) {
		c = expression.at(i);
		if(isalnum(c)) { //isalnum is a function that returns true if the character i.e. c is a alphabet or a number
			postFixExpression += c; //If c is alnum, just add it to the expression
		}
		else {
			if (c == '(') {
				ExpressionStack.push(c);
			}
			else if(c == ')') {
				while ((op = ExpressionStack.pop())!='(') {
					postFixExpression += op;//Use this statement to remove the () brackets and have only alphabets, numbers and operators in the final expression
				}
			}
			else if(!ExpressionStack.isEmpty() && precedence(ExpressionStack.stackTop())>= precedence(c)) {
				postFixExpression += ExpressionStack.pop();
			}
			if(c!='(' && c!=')') {
				ExpressionStack.push(c);
			}
		}
	}
	while (!ExpressionStack.isEmpty()) {
		postFixExpression += ExpressionStack.pop();
	}
	return postFixExpression;
}
float postFixEvaluation(string expression) {
	int length = expression.length();
	float answer, digit;
	char c;
	Stack<float> integers;
	for(int i =0; i<length;i++) {
		c = expression.at(i);
		if(isalnum(c)) {
			if(c>47 && c <= 57)
				digit = c - '0'; // get value of integer from its ASCII representation
			else {
				cout << "Enter value for " + c << endl;
				cin >>digit;
			}
			integers.push(digit);
		}
		else {//If the Character c is an operator, perform the respective operations  on the last two integers/floats that are on the stack(i.e. use pop operation to get the two values)
			if (c == '+') {
				answer = integers.pop() + integers.pop();
			}
			else if (c == '-') {
				answer = integers.pop() - integers.pop();
			}
			else if(c == '*') {
				answer = integers.pop() * integers.pop();
			}
			else if(c == '/') {
				float some = integers.pop();
				answer =  integers.pop()/some;
			}
			integers.push(answer);
		}
	}
	return integers.pop();
}
int main(int argc, char **argv) {
	int choice;
	string Expression;//This is a string object. String class is defined in iostream. Google string in c++ for better understanding
	do {
		cout << "1. Convert Expression from Infix to Postfix" << endl
					<< "2. Convert Expression from Infix to Prefix" << endl
					<< "#. Evaluate Expression (Input is a Postfix Expression)" << endl
					<< "4. Exit" << endl;
		cin >> choice;
		switch (choice) {
			cout << "Enter the Expression" << endl;
			cin >> Expression
			case 1: {
				cout << "The Postfix Expression is " << endl  << toPostFix(Expression) << endl;
				break;
			}
			case 2: {
				cout << "The Prefix Expression is " << endl << reverseString(toPostFix(Expression)) << endl;
				break;
			}
			case 3 : {
				cout << "The Answer is : " << endl <<
				postFixEvaluation(Expression) << endl;
			}
			case 4:
				return 0;
		}
	} while(true);
}
