/*
 * By Ishan Joshi
 */

#include <iostream>
#include <string>
using namespace std;


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


		if (ptr == NULL) {
			return true;
		}

		delete ptr;
		return false;

	}

	void push(T);
	T pop();
	T stackTop();
	void display();

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
T Stack<T>::pop() {

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

template <class T>
void Stack<T>::display() {

	node *ptr = top;

	if (isEmpty()) {
		cout << "Stack is Empty\n";
	}

	while(ptr != NULL) {

		cout << ptr->data;
		ptr = ptr->next;

	}

}

int precedence(char c) {

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

string reverseString(string expression) {

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
		if(isalnum(c)) {

			postFixExpression += c;

		}
		else {
			if (c == '(') {
				ExpressionStack.push(c);
			}
			else if(c == ')') {
				while ((op = ExpressionStack.pop())!='(') {
					postFixExpression += op;
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
			if(c>47 && c <= 57) {
				digit = c - '0';
			}
			else {
				cout << "Enter value for " + c << endl;
				cin >>digit;
			}
			integers.push(digit);
		}
		else {
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
	string Expression;
	do {
		cout << "1. Convert Expression from Infix to Postfix" << endl
					<< "2. Convert Expression from Infix to Prefix" << endl
					<< "3. Convert Expression from Postfix to Infix" << endl
					<< "4. Exit" << endl;
		cin >> choice;
		switch (choice) {
			cout << "Enter the Expression" << endl;
			cin >> Expression
			case 1: {
				cout << "The Postfix Expression is " << endl  << toPostFix(Expression) << endl;
			}
			case 2: {
				
			}
		}
	} while(true);
}
