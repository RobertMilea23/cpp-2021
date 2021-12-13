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

	Driver(const Driver& driver) {
		this->id = driver.id;
		this->age = driver.age;
		this->name = driver.name;
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

	//DeliveryVan(const DeliveryVan& van) : driver(van.driver.id, van.driver.name, van.driver.age)
	DeliveryVan(const DeliveryVan& van): driver(van.driver) {
		this->licensePlateNumber = van.licensePlateNumber;

		//shallow copy
		//this->boxes = van.boxes;

		this->boxes = new Box[van.noBoxes];
		for (int i = 0; i < van.noBoxes; i++) {
			this->boxes[i] = van.boxes[i];			//operator = from the Box class
		}

		this->noBoxes = van.noBoxes;
	}

	void operator=(DeliveryVan& van) {
		this->licensePlateNumber = van.licensePlateNumber;
		//this->driver.id = van.driver.id;
		//...
		this->driver = van.driver;

		delete[] this->boxes;
		this->boxes = new Box[van.noBoxes];
		for (int i = 0; i < van.noBoxes; i++) {
			this->boxes[i] = van.boxes[i];
		}
		this->noBoxes = van.noBoxes;
	}

	//DeliveryVan + Box
	//Box + DeliveryVan		//operator+(Box, DeliveryVan)
	//DeliveryVan += Box


	//if the class content was private then we will allow the operator+ to access it
	//friend DeliveryVan operator+(Box box, DeliveryVan& van);

};

DeliveryVan operator+(Box box, DeliveryVan& van) {
	DeliveryVan result = van;

	//DeliveryVan is public

	Box* newBoxes = new Box[result.noBoxes + 1];
	for (int i = 0; i < result.noBoxes; i++) {
		newBoxes[i] = result.boxes[i];
	}

	newBoxes[result.noBoxes] = box;
	result.noBoxes += 1;

	delete[] result.boxes;
	result.boxes = newBoxes;

	return result;
}


int main() {
	Driver john(1,"John",25);
	Box gift;

	DeliveryVan van;
	DeliveryVan van2("B-01-FAN", john);
	DeliveryVan van3("B-02-FAN", 2, "Bob", 24);

	Box box1;
	Box box2;

	Box boxes[] = { box1, box2 };


	//accessing the van driver
	van.driver.name = "Bob";

}