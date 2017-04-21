#include <iostream>
using namespace std;
class List { //class for Linked List
	typedef struct node {
		node *next;
		string name;
		string Symptom;
	}node;
	int patientCode;
	node *head, *rear;
public:
	void displayList() {
		node *p = head;
		while(p!=NULL) {
			cout << p->code << "\t" << p->name << "\t" << p->Symptom;
			p = p->next;
		}
	}
	List() {
		head = NULL;
		rear = NULL;
		patientCode = 0;
	}
	bool isFull() {
		node *p = new node;//Refer Assignment 1 for explanation of this Function
		if (p == NULL) {
			return true;
		}
		delete p;
		return false;
	}
	void add(string Name, string Symptom) {
		if(isEmpty()) {
			rear = new node;
			head = rear;
			rear->name = Name;
			rear->Symptom = Symptom;
			rear->code = ++patientCode;
		}
		else if (!isFull()) {
			node *p = new node;
			rear->next = p;
			p->name = Name;
			p->Symptom = Symptom;
			p->code = ++patientCode;
			p->next = NULL;
			rear = p;
		}
	}
	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}
	string remove() {
		node *p = head;
		string name = p->name;
		head = head->next;
		delete p;
		return name;
	}
};
class PriorityQueue {
	List Serious, Medium, General;//Separate Queues according to priorities.
	string checkCategory(string condition) {
		if(condition == "Cancer" || condition == "HeartAttack") //You can add more diseases. Keep in mind not to use space between two words like I had done in the word Heart Attack. This is because cin acccepts the string till it encounters a space or newline
		//You could use a getline Function to get the string with Spaces. Google getline function for more info
			return "Serious";
		if(condition == "Jaundice" || condition == "Dengue")
			return "Medium";
		return "General";
	}

public :
	PriorityQueue() {	} //Default Constructor for Priority Queue
	void display() {
		if(!Serious.isEmpty()) {
			cout << "Serious \n" ;
			Serious.displayList();
		}
		else
			cout << "No Serious Patients left";
		if(!Medium.isEmpty()) {
			cout << "Medium  \n";
			Medium.displayList();
		}
		else
			cout << "No Medium Patients left";
		if(!General.isEmpty()) {
			cout << "General \n";
			General.displayList();
		}
		else
			cout << "No General Patients left";
	}
	void addPatient(string condition) {
		string Name;
		string Condition = checkCategory(condition);
		cout << "Enter Patient Name\n";
		cin >> Name;
		if (Condition == "Serious") {
			Serious.add(Name, condition);
		} else if (Condition == "Medium") {
			Medium.add(Name, condition);
		} else {
			General.add(Name, condition);
		}
	}
	void checkout() {//Function is fairly simple. First all the High Priority Patients are Processed. If no High Priority Patients are present, Medium Priority Patients are Processed and so on.
		cout << "Checked out ";
		if (!Serious.isEmpty())
			cout << Serious.remove();
		else if (!Medium.isEmpty())
			cout << endl << Medium.remove();
		else if (!General.isEmpty())
			cout << endl << General.remove();
		else
			cout << "No one. All Lists are Empty";
		cout << endl;
	}
};

int main(int argc, char **argv) {
	PriorityQueue queue;
	int option;
	do {
		cout << "1. Add a Patient\n2. Process a Patient\n3. Display Patients\n4. Exit\n";
		cin >> option;
		switch(option) {
		case 1 : {
			string condition;
			cout << "Enter Symptom" << endl;
			cin >> condition;
			queue.addPatient(condition);
			break;
		}
		case 2 : {
			queue.checkout();
			break;
		}
		case 3 : {
			queue.display();
			break;
		}
		case 4 : {
			return 0;
		}
		}
	} while (true);
}
