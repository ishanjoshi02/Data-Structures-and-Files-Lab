#include <iostream>
using namespace std;

class Node {
  int value;
public:
  Node *left, *right;
  Node() {
    value = 209;
    left = right = NULL;
  }
  Node(int value) {
    this->value = value;
    left = right = NULL;
  }
  int getValue() { return this->value; }
};
class BinaryTree {
  Node *root;
  void display(Node *p) {
    display(p->left);
    cout << p->value << endl;
    display(p->right);
  }
  void displayLeafNodes(Node *p) {
    if (p == NULL) {
      if (p->left == NULL && p->right == NULL)
        cout << p->value << endl;
      else {
          displayLeafNodes(p->left);
          displayLeafNodes(p->right);
      }
    }
  }
public:
  BinaryTree() { root = NULL; }
  void insert(int value) {
    int dir;//The Direction the User is choosing is saved here
    Node *temp = this->root;
    while(temp != NULL) {
      cout << "1. Left\n2. Right" << endl;
      cin >> dir
      if (dir == 1)
        temp = temp->left;
      else
        temp = temp->right;
    }
    Node *newNode = Node(value);
    if (dir == 1)
      temp->left = newNode;
    else if (dir == 2)
      temp->right = newNode;
    else
      root = newNode;
  }
  void display() { display(root); }
  void displayLeafNodes() { displayLeafNodes(root) }
  
};
