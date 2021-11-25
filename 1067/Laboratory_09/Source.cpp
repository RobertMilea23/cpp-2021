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

	string driver = "";
	string *locations = nullptr;		//dynamic array of strings
	int* noBoxes = nullptr;
	int noDeliveries = 0;
	const float volume;

public:
	const static int MAX_NO_BOXES;
	const static int MIN_NO_BOXES;

private:
	static int NO_DELIVERY_VANS;

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

	void changeDriver(string newDriver) {
		this->driver = newDriver;
	}

	DeliveryVan(string driverName, float vanVolume) : volume(vanVolume), driver(driverName) {
		//this->driver = driverName;
		DeliveryVan::NO_DELIVERY_VANS += 1;
	}

	~DeliveryVan() {
		cout << endl << "Calling DESTRUCTOR";
		delete[] this->noBoxes;
		delete[] this->locations;

		DeliveryVan::NO_DELIVERY_VANS -= 1;
	}

	DeliveryVan(const DeliveryVan& van) : volume(van.volume), driver(van.driver) {
		//this->driver = van.driver;

		this->locations = new string[van.noDeliveries];
		this->noBoxes = new int[van.noDeliveries];
		for (int i = 0; i < van.noDeliveries; i++) {
			this->locations[i] = van.locations[i];
			this->noBoxes[i] = van.noBoxes[i];
		}
		this->noDeliveries = van.noDeliveries;
		DeliveryVan::NO_DELIVERY_VANS += 1;

	}
};

const int DeliveryVan::MAX_NO_BOXES = 5;
const int DeliveryVan::MIN_NO_BOXES = 1;
int DeliveryVan::NO_DELIVERY_VANS = 0;

void printVan(DeliveryVan van) {

}

DeliveryVan createVan(string name, float volume) {
	DeliveryVan temp(name, volume);
	return temp;
}

int main() {
	DeliveryVan van1("John", 300);
	DeliveryVan van2("Bob", 500);

	van1.addDelivery("Piata Romana", 2);
	van1.addDelivery("Calea Dorobanti 15-17", 1);

	DeliveryVan* pointerToVan = new DeliveryVan("Vader", 400);
	delete pointerToVan;

	//explicit call to the copy constructor
	DeliveryVan copy = van1;
	printVan(van1);
	createVan("Alice", 600);

	//DON't do it
	//van1.~DeliveryVan();

}
