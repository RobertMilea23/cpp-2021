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

	Driver(int Id, string Name, int Age) : id(Id), name(Name), age(Age){
		this->id = Id;
		this->name = Name;
		this->age = Age;
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

};

int main() {
	Driver john(1,"John", 25);
	Box gift;
	DeliveryVan van1("B-01-FAN",john);

	Driver* pDriver = new Driver(2,"Bob",24);
	delete pDriver;


	// accessing the driver name for a van
	// van1.driver.name = "John";
}

