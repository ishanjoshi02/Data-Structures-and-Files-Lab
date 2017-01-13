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

string toPostFix(string expression) {

	char c, op;
	string postFixExpression = "";
	Stack<char> ExpressionStack;

	int length = expression.length();

	for(int i = 0; i < length; i++) {

		c = expression.at(i);
		if(isalnum(c)) {

			postFixExpression.append(1,c);

		}
		else if (c == '(') {
			ExpressionStack.push(c);
		}
		else if((op = ExpressionStack.pop())!=')') {
			postFixExpression.append(1,op);
		}
	}

	return postFixExpression;

}

int main(int argc, char **argv) {

	Stack<int> IntegerStack;
	Stack<string> StringStack;

	int option;

	do {

		cout << "1. Integer Operations\n2. String Operations\n3. Exit\n";
		cin >> option;
		switch(option) {
		case 1 : {
			cout << "1. Display Stack\n"
					"2. Push Element\n"
					"3. Pop Element\n"
					"4. Get Top Position Value\n6. Exit\n";
			cin >> option ;
			switch(option) {
			case 1 : {
				IntegerStack.display();
				break;
			}
			case 2 : {
				int element;
				cout << "Enter Integer\n";
				cin >> element;

				IntegerStack.push(element);

				break;
			}
			case 3 : {
				string answer;
				do {
					cout << IntegerStack.pop() << endl;
					cout << "Do you want to Pop another\n";
					cin >> answer;
				}while(answer == "yes" || answer == "y");
				break;
			}
			case 4 : {
				cout << IntegerStack.stackTop();
				break;
			}
			}
			break;
		}
		case 2 : {
			cout << "1. Display Stack\n"
					"2. Push Element\n"
					"3. Pop Element\n"
					"4. Get Top Position Value\n6. Exit\n";
			cin >> option ;
			switch(option) {
			case 1 : {


				StringStack.display();
				break;
			}
			case 2 : {
				string data;
				cout << "Enter String\n";
				cin >> data;

				StringStack.push(data);
				break;
			}
			case 3 : {
				string answer;
				do {
					cout << StringStack.pop() << endl;
					cout << "Do you want to Pop another\n";
					cin >> answer;
				}while(answer == "yes" || answer == "y");
				break;
			}
			case 4 : {
				cout << StringStack.stackTop() << endl;
				break;
			}
			}
			break;

			case 3 : {
				return 0;
			}
		}
		}
	} while (true);
}



