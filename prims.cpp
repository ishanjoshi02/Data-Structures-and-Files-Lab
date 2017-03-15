#include <iostream>
#define MAX 4
using namespace std;

class AdjacencyMatrix {
	int array[MAX][MAX];
	string country[MAX];
	int getCountryIndex(string Country) {
		int i;
		for (i=0;i<MAX;i++)
			if (country[i] == Country)
				return i;
		return -1;
	}
	int* getLowestNode(string country) {
		int pair[2];
		int i;
		int bestDistance;
		int countryIndex = getCountryIndex(country);
		bestDistance = array[countryIndex][0];
		for (i=1;i<MAX;i++)
			if (bestDistance > array[countryIndex][i])
				bestDistance = array[countryIndex][i];
		pair[0] = countryIndex;
		pair[1] = bestDistance;
		return pair;
	}
public:
	AdjacencyMatrix() {
		int i,j;
		for (i=0;i<MAX;i++)
			for (j=0;j<MAX;j++)
				array[i][j] = 0;
	}
	void acceptCountries() {
		cout << "Enter the Names of Countries\n";
		int i;
		for (i=0;i<MAX;i++) {
			cin >> country[i];
		}
	}
	void accept() {
		string country1, country2;
		int countryIndex1, countryIndex2;
		do {
			if ((countryIndex1 == -1 || countryIndex2 == -1)) {
				cout << "Check spelling of Countries\n";
			}
			cout << "Enter Name of First Country followed by Second Country\n";
			cin >> country1 >> country2;
			countryIndex1 = getCountryIndex(country1);
			countryIndex2 = getCountryIndex(country2);
		}while(countryIndex1 == -1 || countryIndex2 == -1);
		int costOfLine;
		cout << "Now enter cost of Telephone Line between " << country1 << " and "
				<< country2 << endl;
		cin >> costOfLine;
		array[countryIndex1][countryIndex2] = costOfLine;
		array[countryIndex2][countryIndex1] = costOfLine;
	}
	void display() {
		int i,j;
		cout << "Countries ";
		for (i=0;i<MAX;i++)
			cout << country[i] << "\t";
		cout << endl;
		for (i=0;i<MAX;i++) {
			cout << country[i] << "\t";
			for (j=0;j<MAX;j++)
				cout << array[i][j] <<"\t";
			cout << endl;
		}
	}
	void calculateMinimumCost() {
		string country1, country2;
		int countryIndex1, countryIndex2;
		do {
			if ((countryIndex1 == -1 || countryIndex2 == -1)) {
				cout << "Check spelling of Countries\n";
			}
			cout << "Enter Name of First Country followed by Second Country\n";
			cin >> country1 >> country2;
			countryIndex1 = getCountryIndex(country1);
			countryIndex2 = getCountryIndex(country2);
		}while(countryIndex1 == -1 || countryIndex2 == -1);
		int costOfLine;
		int *pair;
		do {
			pair = getLowestNode(country1);
			costOfLine += pair[1];
		}while (pair[0] != countryIndex2) ;
		cout << "Minimum Telephone Line Cost between " << country1 << " and "
				<< country2 << " is " << costOfLine << endl;
	}
};
int main(int argc, char **argv) {
	AdjacencyMatrix mAdjacencyMatrix;
	int option;
	do {
		cout << "1. Accept Countries\n" << "2. Insert Values\n" <<
				"3. Display Matrix\n" << "4. Calculate Minimum Cost\n" <<
				"5. Exit\n";
		cin >> option;
		switch (option) {
		case 1 : {
			mAdjacencyMatrix.acceptCountries();
			break;
		}
		case 2 : {
			mAdjacencyMatrix.accept();
			break;
		}
		case 3 : {
			mAdjacencyMatrix.display();
			break;
		}
		case 4 : {
			mAdjacencyMatrix.calculateMinimumCost();
			break;
		}
		case 5 : {
			return 0;
		}
		}
	}while(true);
}
