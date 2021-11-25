#include <iostream>
#include <string>
using namespace std;

////{"Piata Romana", "Calea Dorobanti 15-17", "Piata Unirii", }
//char* location;			//dyanamic array of chars with any size
//char location[50];		//static array of chars with 50 chars
//
//char* locations[100];	//static array of maximum 100 dynamic arrays of chars
//char locations[100][50];	//static array of 100 static arrays, each having 50 characters
//char** locations;		//dynamic array of dynamic arrays of chars

class DeliveryVan {

	string driver;
	string *locations;		//dynamic array of strings
	int* noBoxes;
	int noDeliveries;
public:
	void addDelivery(string location, int noBoxesForLocation) {
		int* newNoBoxes = new int[this->noDeliveries + 1];
		for (int i = 0; i < this->noDeliveries; i++) {
			newNoBoxes[i] = this->noBoxes[i];
		}
		newNoBoxes[this->noDeliveries] = noBoxesForLocation;

		//avoiding the memory leak
		delete[] this->noBoxes;
		this->noBoxes = newNoBoxes;

		string* newLocations = new string[this->noDeliveries + 1];
		for (int i = 0; i < this->noDeliveries; i++) {
			newLocations[i] = this->locations[i];
		}
		newLocations[this->noDeliveries] = location;

		delete[] this->locations;
		this->locations = newLocations;

		this->noDeliveries += 1;
	}

};
