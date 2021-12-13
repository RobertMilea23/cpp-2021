#include <iostream>
#include <string>
using namespace std;

//composition - relations between classes
//arrays of objects

class Driver {
public:
	int id;
	string name;
	int age;

	~Driver() {
		cout << endl << "The Driver destructor";
	}

	Driver(int Id, string Name, int Age) :id(Id), name(Name), age(Age) {
		//this->id = Id;
		//this->name = Name;
		//this->age = Age;
	}
};

class Box {
public:
	int id;
	string content;
	string destinationAddress;
	float weight;

	~Box() {
		cout << endl << "The Box destructor";
	}
};

class DeliveryVan {
public:
	string licensePlateNumber;
	Driver driver;				//1:1 relation

	//static array
	//Box boxes[50];

	//dynamic array
	Box* boxes = nullptr;					//1:M relation
	int noBoxes = 0;

	~DeliveryVan() {
		delete[] boxes;
		cout << endl << "The DeliveryVan destructor";
	}

	DeliveryVan() : driver(2,"John Doe", 24) {
		//this->driver = Driver(2, "Bob", 24);
	}

	DeliveryVan(string licensePlate, Driver receivedDriver): driver(receivedDriver) {
		this->licensePlateNumber = licensePlate;
	}

	DeliveryVan(string licensePlate, int id, string name, int age): driver(id, name, age) {
		this->licensePlateNumber = licensePlate;
	}

};

int main() {
	Driver john(1,"John",25);
	Box gift;
	DeliveryVan van;

	//acceesing the van driver
	van.driver.name = "Bob";

}