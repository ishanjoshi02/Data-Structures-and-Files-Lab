#include <iostream>
#include <string>

using namespace std;

typedef struct node {
    string data;
    node *left, *right;
}node;
template <class T>
class Stack {
    int top;
    T data[50];
public :
    Stack() {
        top = -1;
    }
    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        return false;
    }
    bool isFull() {
        if(top == 49) {
            return true;
        }
        return false;
    }
    void push(T operand) {
        data[++top] = operand;
    }
    T pop() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
        }
        else {
            return data[top--];
        }
    }
};
class Tree {
    node *leftChild, *rightChild;
    node *root;
    Stack<node*> nodes;
    void postFix(node *p) {
        if(p!=NULL) {
            postFix(p->left);
            postFix(p->right);
            cout << p->data;
        }
    }
    void inFix(node *p) {
        if (p!=NULL) {
            inFix(p->left);
            cout << p->data;
            inFix(p->right);
        }
    }
    void preFix(node *p) {
        if(p!=NULL) {
            cout << p->data;
            preFix(p->left);
            preFix(p->right);
        }
    }
public :
    Tree() {
        root = NULL;
    }
    Tree(string expression) {
        int i;
        for (i =0; i<expression.length(); i++) {
            char data = expression.at(i);
            node *newNode = new node;
            newNode->data = data;
            if(isalnum(data))
                newNode->left = newNode->right = NULL;
            else {
                newNode->right = nodes.pop();
                newNode->left = nodes.pop();
            }
            nodes.push(newNode);
        }
        root = nodes.pop();
    }
    void toInFix() {
        inFix(root);
    }
    void toPreFix() {
        preFix(root);
    }
    void toPostFix() {
        postFix(root);
    }
};
int main(int argc, char **argv) {
    string expression;
    Tree tree;
    cout << "Enter Expression : \n";
    cin >> expression;
    tree = Tree(expression);
    cout << "Infix Expression :\n";
    tree.toInFix();
    cout << "\nPrefix Expression :\n";
    tree.toPreFix();
    cout << "\nPostfix Expression : \n";
    tree.toPostFix();
}
