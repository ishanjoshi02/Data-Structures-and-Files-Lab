/*
Name-Rishabh Gandhewar
Roll No-3154028
Class- SE-IT-A
TITLE- Binary Tree
*/
#include<iostream>		//Header Files
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef struct node{		//Structure of a node of tree
	int info;
	struct node * left;
	struct node *right;
	struct node *next;
}node;
class stack{			//Class for STACK
	node *top;

	public:
	stack(){
		top=NULL;
	}
	int empty(){
		if(top==NULL)
		    return 1;
		else
		    return 0;
	}
	void push(node * temp){
		temp->next=top;
		top=temp;
	}
	node * pop(){
		node *temp;
		temp=top;
		top=top->next;

		return temp;
	}
};
class tree{			//Class For Tree
	node *root;
public:				//Default Constructor
	tree(){root=NULL;}
int max(int val,int val1)
{
	if(val>val1)
	{
		return val;
	}
	else
	{
		return val1;
	}
}

node* insert();			//Member Functions
void display_infix(node *);
int depth(node *);
void displayleaf(node *);
node *copytree(node **,int);
node *display_prefix(node *);
void display_postfix(node *);
};
node* tree::insert()
{
	node *temp;
	int x;
	cout<<endl<<"Enter info to be inserted(-1 for NULL node);"<<endl;
	cin>>x;
	if(x==-1)
	{
		return NULL;
	}
	temp=new node();
	temp->info=x;
	cout<<endl<<"Enter the left child of "<<x;
	temp->left=insert();
	cout<<endl<<"Enter the right child of"<<x;
	temp->right=insert();
	return temp;
}
node *tree::display_prefix(node *root)
{
	node *temp=root;
	if(temp==NULL)
	{
		cout<<"Tree is Empty"<<endl;
		return NULL;
	}
	cout<<temp->info<<" ";
	if(temp->left!=NULL)
	{
		cout<<"(";
		display_prefix(temp->left);
	}
	if(temp->right!=NULL)
	{
		cout<<",";
		display_prefix(temp->right);
		cout<<")";
	}
	return temp;
}
int tree::depth(node *root)
{
	node *temp=root,*temp1;
	node **Q1=new node*[20];
	node **Q2=new node*[20];
	int n=0,f1=0,f2=0;
	int R1=-1,F1=-1,R2=-1,F2=-1;
	if(temp==NULL)
	{
		cout<<"Tree is empty ,Depth=0"<<endl;
		return 0;
	}
	Q1[++R1]=temp;
	do
	{
		while(R1!=F1)
		{
			temp1=Q1[++F1];
			if(temp1->left!=NULL)
			{
				Q2[++R2]=temp1->left;
			}
			if(temp1->right!=NULL)
			{
				Q2[++R2]=temp1->right;
			}
			f1=1;
		}
		if(f1==1)
		{
			n++;
			f1=0;
		}
		while(R2!=F2)
		{
			temp1=Q2[++F2];
			if(temp1->left!=NULL)
			{
				Q1[++R1]=temp1->left;
			}
			if(temp1->right!=NULL)
			{
				Q1[++R1]=temp1->right;
			}
			f2=1;
		}
		if(f2==1)
		{
			n++;
			f2=0;
		}
	}
		while(R1!=F1 || R2!=F2);
	return (n-1);
}
void tree::displayleaf(node *root)
{
	node *temp=root;
	node **Stack=new node*[20];
	int top=-1;
	if(temp==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	do
	{
		while(temp!=NULL)
		{
			Stack[++top]=temp;
			temp=temp->left;
		}
		temp=Stack[top--];
		if(temp->right==NULL && temp->left==NULL)
		{
			cout<<temp->info<<endl;;
		}
		temp=temp->right;
	}
	while(top!=-1 || temp!=NULL);

}
node * tree::copytree(node **q, int rear){
	node * temp, *root, *newnode, *cur, *flag1, *flag2;
	int i = 0;
	stack s;

	root = q[i++];
	newnode = new node();
	newnode->info = root->info;
	s.push(newnode);

	cur = root;

	while(i <= rear){
		temp = q[i++];
		while(temp != NULL){
			newnode = new node();
			newnode->info = temp->info;
			s.push(newnode);
			cur->left = newnode;
			cur = newnode;
			temp = q[i++];
		}
		cur -> left = temp;	//temp is null here
		flag1 = temp;

		temp = q[i++];
		if(temp != NULL){
			newnode = new node();
			newnode->info = temp->info;
			s.pop();
			s.push(newnode);
		}
		else{
			newnode = NULL;
		}
		cur->right = newnode;
		flag2 = newnode;

		while(flag1 == NULL and flag2 == NULL){	//leaf node
			if(s.empty())
				return root;
			s.pop();

			if(s.empty())	//if tree has only 1 node
				return root;
			cur = s.pop();
			temp = q[i++];
			if(temp != NULL){
				newnode = new node();
				newnode->info = temp->info;
				s.push(newnode);
			}
			else
				newnode = NULL;
			cur->right = newnode;
			cur = newnode;

			flag1 = flag2;
			flag2 = newnode;
		}
		cur = newnode;
	}

	return root;
}

int savepreorder(node *root, node **q){
	node *temp=root;
	static int rear = -1;
	if(temp==NULL){
		cout<<"Tree is Empty"<<endl;
		q[++rear]=temp;
		return rear;
	}

	q[++rear]=temp;

	if(temp->left!=NULL)
		savepreorder(temp->left, q);
	else
		q[++rear]=NULL;

	if(temp->right!=NULL)
		savepreorder(temp->right, q);
	else
		q[++rear]=NULL;

	return rear;
}
void tree::display_infix(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		display_infix(temp->left);
		cout<<temp->info;
		display_infix(temp->right);
	}

}
void tree::display_postfix(node *root)
{
	node *temp=root;
	if(temp!=NULL)
	{
		display_postfix(temp->left);
		display_postfix(temp->right);
		cout<<temp->info;
	}
}
int main()				//Main Function
{
	int i=0,d,ch;
	int rear;
	node *root,*copyroot;
	node **q1;
	tree t;
	do
	{
		cout<<endl<<"Enter your choice "<<endl
		  <<"1.Create a tree"<<endl
		    <<"2.Display Created tree in prefix"<<endl
		      <<"3.Depth of a tree"<<endl
		        <<"4.Display leaf nodes of a tree"<<endl
		          <<"5.Copy a tree"<<endl
		            <<"6.Display created tree in infix"<<endl
		              <<"7.Display created tree in postfix"<<endl
		                <<"8.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:root=t.insert();
		break;
		case 2: t.display_prefix(root);
		break;
		case 3:	d=t.depth(root);
				cout<<"Depth of tree is "<<d<<endl;
		break;
		case 4: cout<<"Leaf nodes are:"<<endl;
				t.displayleaf(root);
		break;
		case 5: q1 = new node*[20];
			rear = savepreorder(root, q1);
			cout<<"Copied binary tree is "<<endl;
			copyroot=t.copytree(q1, rear);
			t.display_infix(copyroot);
				cout<<endl;
		break;
		case 6:t.display_infix(root);
		break;
		case 7:t.display_postfix(root);
		break;
		case 8: exit(0);
		break;
		default:cout<<"Invalid choice";
		}
	}
	while(true);
	return 0;

}
