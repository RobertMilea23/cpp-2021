#include <iostream>
#include <string>
using namespace std;

class DeliveryCompany {
	static int NO_AVAILABLE_DRIVERS;
};

int DeliveryCompany::NO_AVAILABLE_DRIVERS = 10;

class DeliveryVan {

	std::string driverName = "";
	string* locations = nullptr;

	//alternative with classic arrays of chars
	//char** locations;
	int* noBoxes = nullptr;
	int noLocations = 0;
	const float volume;

	const static int MAX_NO_BOXES;
	const static int MIN_NAME_LENGTH;
	static int NO_VANS;

public:
	void setDriverName(string name) {
		if (name.length() < DeliveryVan::MIN_NAME_LENGTH) {
			throw exception("Name too short");
		}
		else {
			this->driverName = name;
		}
	}
	void addDelivery(string location, int noBoxesForLocation) {
		if (noBoxesForLocation > DeliveryVan::MAX_NO_BOXES) {
			throw exception("Max no of boxes exceeded");
		}

		int* newBoxes = new int[this->noLocations + 1];
		for (int i = 0; i < this->noLocations; i++) {
			newBoxes[i] = this->noBoxes[i];
		}
		newBoxes[this->noLocations] = noBoxesForLocation;

		string* newLocations = new string[this->noLocations + 1];
		for (int i = 0; i < this->noLocations; i++) {
			newLocations[i] = this->locations[i];
		}
		newLocations[this->noLocations] = location;

		//remove the existing arrays
		delete[] this->noBoxes;
		delete[] this->locations;

		this->noBoxes = newBoxes;
		this->locations = newLocations;
		this->noLocations += 1;
	}

	void printJournal() {
		cout << endl << "Driver name: " << this->driverName;
		if (this->noLocations > 0) {
			for (int i = 0; i < this->noLocations; i++) {
				cout << endl << "Location: " << this->locations[i] << " no boxes: " << this->noBoxes[i];
			}
		}
		else {
			cout << endl << "No deliveries to do";
		}
	}

public:
	DeliveryVan(string driver, float vanVolume) : volume(vanVolume), driverName(driver) {
		//this->driverName = driver;

		DeliveryVan::NO_VANS += 1;
	}

	~DeliveryVan() {

		cout << endl << "Calling the class destructor";

		if (this->locations != nullptr) {
			delete[] this->locations;
		}
		delete[] this->noBoxes;

		DeliveryVan::NO_VANS -= 1;
	}

	//copy constructor
	DeliveryVan(const DeliveryVan& van): volume(van.volume), driverName(van.driverName) {
		//this->driverName = driverName;

		cout << endl << "Calling the copy constructor";

		this->locations = new string[van.noLocations];
		this->noBoxes = new int[van.noLocations];
		for (int i = 0; i < van.noLocations; i++) {
			this->locations[i] = van.locations[i];
			this->noBoxes[i] = van.noBoxes[i];
		}
		this->noLocations = van.noLocations;


		DeliveryVan::NO_VANS += 1;
	}

	//operator =
	void operator=(const DeliveryVan& van)   {
		//you can't for constant attributes
		//this->volume = van.volume;

		if (this->locations == van.locations && this->noBoxes == van.noBoxes) {
			//you get data from the same object
			return;
		}

		this->driverName = van.driverName;

		delete[] this->locations;
		delete[] this->noBoxes;

		this->locations = new string[van.noLocations];
		this->noBoxes = new int[van.noLocations];
		for (int i = 0; i < van.noLocations; i++) {
			this->locations[i] = van.locations[i];
			this->noBoxes[i] = van.noBoxes[i];
		}
		this->noLocations = van.noLocations;
	}

};

const int DeliveryVan::MAX_NO_BOXES = 5;
const int DeliveryVan::MIN_NAME_LENGTH = 3;
int DeliveryVan::NO_VANS = 0;


void printData(DeliveryVan van) {

}

DeliveryVan createDeliveryVan(string name, float volume) {
	DeliveryVan newVan(name, volume);
	return newVan;
}

int main() {
	DeliveryVan van1("John", 1000);
	van1.printJournal();

	van1.addDelivery("Piata Romana", 2);
	van1.addDelivery("Piata Unirii", 1);
	van1.addDelivery("Calea Dorobanti 15-17", 3);

	van1.printJournal();

	//create an object in HEAP
	DeliveryVan* pointerToVan = new DeliveryVan("Vader", 500);
	delete pointerToVan;

	cout << endl << "After delete";

	DeliveryVan van2("Bob", 500);
	van2.addDelivery("Ploiesti", 3);

	//test the copy constructor
	DeliveryVan van1Copy = van1;
	van1Copy.printJournal();

	printData(van1);

	van2 = van1;		//operator=(DeliveryVan, DeliveryVan)
	van2 = van2;
}