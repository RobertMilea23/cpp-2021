#include <iostream>
#include <string>
using namespace std;

// inheritance - "is a"
// overriding
// virtual methods
// virtual pure methods - abstract methods
// abstract classes
// overloading + overriding  = polymorphism  

class AbstractPerson {
public:
	virtual void doSomething() = 0;		//virtual pure method aka abstract
};


class Person {
protected:
	string name = "";
	int age = 0;
public:
	Person() {
		this->name = "John Doe";
		this->age = 18;
	}
	Person(string Name, int Age): name(Name), age(Age){}

	virtual void printInfo() {
		cout << endl << this->name << " | " << this->age << " years old";
	}

	void payTax(float taxValue) {

	}
};

class Student : public Person
{
	string faculty;
public:

	Student() {

	}

	Student(string Name, int Age, string Faculty): Person(Name, Age) {
		//this->name = Name;
		//this->age = Age;
		this->faculty = Faculty;
	}

	//void printStudentInfo() {
	//	cout << endl << this->name << " | " << this->age << " year old";
	//	cout << endl << "Enrolled at " << this->faculty;
	//}

	//overriding
	//re-write methods inherited 
	void printInfo() {
		//cout << endl << this->name << " | " << this->age << " year old";
		//calling the Person version of printInfo()

		this->Person::printInfo();
		cout << endl << "Enrolled at " << this->faculty;
	}

	void payTax(float taxValue) {

	}
};

class SoftwareEngineer: public Person {
protected:
	string company = "Apple";
public:

	void printInfo() {
		this->Person::printInfo();
		cout << endl << "Company " << this->company;
	}
};

class Intern : public SoftwareEngineer, public Student {
	int minHours;

public:
	void doSomething() {
		this->Student::age = 23;
		this->SoftwareEngineer::age = 23;
	}

	void printOtherInfo() {
		this->Student::printInfo();
		this->Person::printInfo();
		this->SoftwareEngineer::printInfo();
	}
};

class Vehicle {

};



int main() {
	Person john("John", 21);
	john.printInfo();

	Student alice("Alice", 20, "CSIE");
	alice.printInfo();
	//alice.printStudentInfo();

	SoftwareEngineer engBob;
	engBob.printInfo();

	Person persons[5];
	Student students[5];
	SoftwareEngineer engineers[5];

	//can we manage them like a Person
	Person person;
	person = alice;			//up-casting

	//alice = person;			//down-casting

	//Vehicle vehicle;
	//person = vehicle;

	//Person everyone[3];
	//everyone[0] = john;
	//everyone[1] = alice;
	//everyone[2] = engBob;

	//Person* everyone;
	//everyone = new Person[3];
	//everyone[0] = john;
	//everyone[1] = alice;
	//everyone[2] = engBob;


	Person* everyone[3];			//array of pointers to Persons
	everyone[0] = &john;
	everyone[1] = &alice;
	everyone[2] = &engBob;

	cout << endl << "------- Up casting ------------";

	for (int i = 0; i < 3; i++) {
		everyone[i]->printInfo();
	}

	//AbstractPerson ap;


}
