#include <iostream>
#include <string>
using namespace std;

//composition between classes
//array of objects

class Driver {
public:
	int id;
	string name;
	int age;

	~Driver() {
		cout << endl << "The Driver destructor";
	}

	//constructor with arguments
	Driver(int Id, string Name, int Age) : id(Id), name(Name), age(Age){
		//this->id = Id;
		//this->name = Name;
		//this->age = Age;
	}

	Driver(const Driver& driver) {
		this->id = driver.id;
		this->name = driver.name;
		this->age = driver.age;
	}
};

class Box {
public:

	int id;
	string content;
	float weight;

	~Box() {
		cout << endl << "The Box destructor";
	}
};

class DeliveryVan {
public:

	Driver driver;			//1-1 relation

	//static array
	//Box boxes[100];

	//dynamic array
	Box* boxes = nullptr;				//1-M relation
	int noBoxes = 0;

	string licensePlateNumber;

	~DeliveryVan() {
		delete[] boxes;
		cout << endl << "The DeliveryVan destructor";
	}

	DeliveryVan(string licensePlate, Driver receivedDriver) : driver(receivedDriver) {
		this->licensePlateNumber = licensePlate;
		//this->driver = driver;
	}

	DeliveryVan(string licensePlate, int driverId, string driverName, int driverAge)
		: driver(driverId,driverName,driverAge) {

	}

	//DeliveryVan(const DeliveryVan& van) : driver(van.driver.id, van.driver.name, van.driver.age)
	DeliveryVan(const DeliveryVan& van): driver(van.driver) {
		this->licensePlateNumber = van.licensePlateNumber;
		//shallow-copy
		//this->boxes = van.boxes;

		this->boxes = new Box[van.noBoxes];
		for (int i = 0; i < van.noBoxes; i++) {
			this->boxes[i] = van.boxes[i];			//operator = from Box - the default one
		}
		this->noBoxes = van.noBoxes;
	}

	void operator=(DeliveryVan& van) {
		this->licensePlateNumber = van.licensePlateNumber;
		this->driver = van.driver;
		delete[] this->boxes;

		this->boxes = new Box[van.noBoxes];
		for (int i = 0; i < van.noBoxes; i++) {
			this->boxes[i] = van.boxes[i];			//operator = from Box - the default one
		}
		this->noBoxes = van.noBoxes;
	}

	//van + box		//operator+(DeliveryVan, Box)
	//box + van
	//van += box

	DeliveryVan operator+(Box box) {
		DeliveryVan result = *this;
		Box* newBoxes = new Box[result.noBoxes + 1];
		for (int i = 0; i < result.noBoxes; i++) {
			newBoxes[i] = result.boxes[i];
		}
		newBoxes[result.noBoxes] = box;

		delete[] result.boxes;
		result.boxes = newBoxes;
		result.noBoxes += 1;
		return result;
	}

};

int main() {
	Driver john(1,"John", 25);
	Box gift;
	DeliveryVan van1("B-01-FAN",john);
	DeliveryVan van2("B-02-FAN", 3, "Vader", 25);

	Driver* pDriver = new Driver(2,"Bob",24);
	delete pDriver;

	Box box1;
	Box box2;
	Box boxes[] = { box1, box2 };

	//van2 = van1;


	// accessing the driver name for a van
	// van1.driver.name = "John";
}

