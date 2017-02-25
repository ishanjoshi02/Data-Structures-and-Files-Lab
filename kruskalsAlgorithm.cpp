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
	GraphNode*& getGraphNode() {
		return graphNode;
	}

	void setGraphNode(GraphNode*& graphNode) {
		this->graphNode = graphNode;
	}

	GraphArc*& getNextGraphArc() {
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
		this->nextGraphArc = NULL;
	}



};

class GraphNode {
public:
	const string& getCityName() const {
		return cityName;
	}

	void setCityName(const string& cityName) {
		this->cityName = cityName;
	}

	 GraphArc*& getFirstGraphArc()  {
		return firstGraphArc;
	}

	void setFirstGraphArc( GraphArc*& firstGraphArc) {
		this->firstGraphArc = firstGraphArc;
	}

	 GraphNode*& getNextGraphNode()  {
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

	 GraphNode*& getSourceGraphNode()  {
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
		cout << "Enter the Name of the City";
		cin >> cityName;
		p->setCityName(cityName);

		int option;
		cout << "1. Create Singular Node\n2. Add Adjacent Cities\n";
		if (p == first) {
			option = 1;
		}
		else {
			cin >> option;
		}
		switch(option) {
		case 2 :
			string cityyy;
			cout << "Enter Adjacent City Name";
			cin >> cityyy;
			GraphNode *someNode;
			someNode = this->first;
			while (someNode!=NULL || someNode->getCityName()!=cityyy)
				someNode = someNode->getNextGraphNode();
			if (someNode == NULL)
				cout << "No such City Exists";
			else {
				int distance;
				cout << "Enter distance between Cities\n";
				cin >> distance;
				GraphArc *graphArc = new GraphArc;
				graphArc->insert(p,someNode,distance);
				p->setFirstGraphArc(graphArc);
				GraphArc *reverse = new GraphArc;
				reverse->insert(someNode,p,distance);
				GraphArc *traversal;
				traversal = someNode->getFirstGraphArc();
				while (traversal!=NULL)
					traversal = traversal->getNegrapxtGraphArc();
				traversal->setNextGraphArc(reverse);
			}
			break;
		}
	}
	void display() {
		GraphNode *p = first;
		while (p!=NULL) {
			GraphArc *firstArc;
			firstArc = p->getFirstGraphArc();
			if (firstArc != NULL) {
				cout << p->getCityName() << " -> ";
				while (firstArc!=NULL) {grap
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
		cout << "1. Create Graph\n2. Insert Node\n3. Display Graph\n4. Exit\n";
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
			graph.addNode();
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
