#include <iostream>
using namespace std;

class GraphNode;
class GraphArc;

class GraphArc {
private:
	int weight;
	GraphArc *nextGraphArc;
	GraphNode *graphNode;
	GraphNode *source;
public:
	GraphArc() {
		nextGraphArc = NULL;
	}
	GraphNode*& getGraphNode() {
		return graphNode;
	}

	void setGraphNode(GraphNode*& graphNode) {
		this->graphNode = graphNode;
	}

	GraphArc* getNextGraphArc() {
		return nextGraphArc;
	}

	void setNextGraphArc(GraphArc*& nextGraphArc) {
		this->nextGraphArc = nextGraphArc;
	}

	int getWeight()  {
		return weight;
	}

	void setWeight(int weight) {
		this->weight = weight;
	}

	 GraphNode*& getSource()  {
		return source;
	}

	void setSource(GraphNode*& source) {
		this->source = source;
	}

	void insert(GraphNode *source, GraphNode *destination, int weight) {
		this->source = source;
		this->graphNode = destination;
		this->weight = weight;
	}



};

class GraphNode {
public:
	GraphNode() {
		this->firstGraphArc = NULL;

	}
	 string getCityName()  {
		return cityName;
	}

	void setCityName( string cityName) {
		this->cityName = cityName;
	}

	 GraphArc* getFirstGraphArc()  {
		return firstGraphArc;
	}

	void setFirstGraphArc( GraphArc* firstGraphArc) {
		this->firstGraphArc = firstGraphArc;
	}

	 GraphNode* getNextGraphNode()  {
		return nextGraphNode;
	}

	void setNextGraphNode( GraphNode*& nextGraphNode) {
		this->nextGraphNode = nextGraphNode;
	}

	bool isProcessed()  {
		return processed;
	}

	void setProcessed(bool processed) {
		this->processed = processed;
	}

	 GraphNode* getSourceGraphNode()  {
		return sourceGraphNode;
	}

	void setSourceGraphNode( GraphNode*& sourceGraphNode) {
		this->sourceGraphNode = sourceGraphNode;
	}

private:
	string cityName;
	GraphArc *firstGraphArc;
	GraphNode *nextGraphNode, *sourceGraphNode;
	bool processed;

};

class Graph {
	GraphNode *first;
	GraphNode *getNode(string Name) {
		GraphNode *p = first;
		while (p!=NULL && p->getCityName()!=Name)
			p = p->getNextGraphNode();
		if (p == NULL)
			cout << "No such City Exists";
		else
			return p;
		return NULL;
	}
	void insertArc(GraphNode *graphNode,GraphArc *graphArc) {
		GraphArc *traversal;
		traversal = graphNode->getFirstGraphArc();
		while (traversal!=NULL)
			traversal = traversal->getNextGraphArc();
		traversal->setNextGraphArc(graphArc);
	}
public :
	Graph() {
		first = NULL;
	}
	void addNode() {
		GraphNode *p = first;
		GraphNode *parentNode, *someNode = NULL;
		while (p!=NULL) {
			parentNode = p;
			p = p->getNextGraphNode();
		}
		string cityName, answer;
		p = new GraphNode;
		if (first == NULL)
			first = p;
		else
			parentNode->setNextGraphNode(p);
		cout << "Enter Name of City\n";
		cin >> cityName;
		p->setCityName(cityName);
		GraphNode *i = NULL;
		p->setNextGraphNode(i);
	}
	void insertArc() {
		int weight;
		string source, destination;
		cout << "Enter Source City followed by destination city\n";
		cin >> source >> destination;
		GraphNode *sourceNode, *destinationNode;
		sourceNode = this->getNode(source);
		destinationNode = this->getNode(destination);
		GraphArc *arc1 = new GraphArc;
		GraphArc *arc2 = new GraphArc;
		cout << "Enter Weight \n";
		cin >> weight;
		arc1->insert(sourceNode,destinationNode,weight);
		arc2->insert(destinationNode,sourceNode,weight);
		this->insertArc(sourceNode,arc1);
		this->insertArc(destinationNode,arc2);
	}
	void display() {
		GraphNode *p = first;
		while (p!=NULL) {
			GraphArc *firstArc;
			firstArc = p->getFirstGraphArc();
			if (firstArc != NULL) {
				cout << p->getCityName() << " -> ";
				while (firstArc!=NULL) {
					if (firstArc->getNextGraphArc()!=NULL)
						cout << firstArc->getGraphNode()->getCityName() << " -> ";
					else {
						cout << firstArc->getGraphNode()->getCityName();
					}
				}
			}
			else {
				cout << p->getCityName();
			}
			cout << endl;
		}
	}
};

int main(int argc, char **argv) {
	Graph graph;
	int option;
	do {
		cout << "1. Create Graph\n2. Insert Arc\n3. Display Graph\n4. Exit\n";
		cin >> option;
		switch (option) {
		case 1 : {
			int number;
			cout << "Enter the Number of nodes\n";
			cin >> number;
			int i;
			for (i=0;i<number;i++)
				graph.addNode();

			break;
		}
		case 2 : {
			graph.insertArc();
			break;
		}
		case 3 :{
			graph.display();
			break;
		}
		case 4 : {
			return 0;
		}
		}
	} while (true);
}
