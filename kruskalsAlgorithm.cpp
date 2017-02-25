#include <iostream>
using namespace std;

class GraphNode;
class GraphArc;

class GraphArc {
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

private:
	int weight;
	GraphArc *nextGraphArc;
	GraphNode *graphNode;
	GraphNode *source;


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
		parentNode->setNextGraphNode(p);
		cout << "Enter the Name of the City";
		cin >> cityName;
		p->setCityName(cityName);

		do {
			int weight;
			cout << "Enter Name of Adjacent Cities\n";
			cin >> cityName;
			someNode = this->first;
			while (someNode != NULL || someNode->getCityName() != cityName)
				someNode = someNode->getNextGraphNode();
			if (someNode == NULL) {
				cout << "No such Node exists \n";
			}
			else {
				cout << "Enter Weight\n";
				cin >> weight;
				GraphArc *i = NULL;
				GraphArc *graphArc = new GraphArc;
				p->setFirstGraphArc(graphArc);
				graphArc->setGraphNode(someNode);
				graphArc->setSource(p);
				graphArc->setNextGraphArc(i);
				graphArc->setWeight(weight);
				GraphArc *reverse = new GraphArc;
				reverse->setSource(someNode);
				reverse->setGraphNode(p);
				reverse->setWeight(weight);
				reverse->setNextGraphArc(i);
				GraphArc *traverse;
				traverse = someNode->getFirstGraphArc();
				while (traverse!=NULL) {
					traverse = traverse->getNextGraphArc();
				}
				traverse->setNextGraphArc(reverse);
				cout << "Arc from " << p->getCityName() << " to "
						<< someNode->getCityName() << " created\n";
				cout << "Do you want to add another\n";
				cin >> answer;
			}
		}while (answer == "Y" || answer == "y");
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
