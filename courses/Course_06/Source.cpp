#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Student {
private:

	//you can choose your own defaults - do it
	char name[100] = "";
	bool hasScholarship = false;
	int age = 0;
	int* grades = nullptr;
	int noGrades = 0;
public:
	//public interface
	//class constructor
	Student(const char* name, int age, bool hasScholarship) {
		this->setAge(age);
		//if (hasScholarship) {
		//	this->gainsScholarship();
		//}
		//else {
		//	this->losesScholarship();
		//}

		//it's ok also like this
		//if you need validation it's better to call the set method
		//this->hasScholarship = hasScholarship;

		hasScholarship ? this->gainsScholarship() : this->losesScholarship();
		this->setName(name);

	}


	//just for this course
	//it might createa confusion with the previous one because they ask for the data
	Student(const char* name, bool hasScholarship, int age) {
		this->setAge(age);
		hasScholarship ? this->gainsScholarship() : this->losesScholarship();
		this->setName(name);
	}

	Student(const char* name, int age) {
		this->setAge(age);
		this->hasScholarship = false;
		this->setName(name);
	}

private:
	//default constructor
	//made it private because allows Student with inconsistent data
	Student() {
		this->setName("John Doe");
		this->age = 0;
		this->hasScholarship = false;
	}

public:
	//we choose not to implement it because we consider that name and age are mandatory
	//Student(const char* name) {
	//	//this->setAge(0);
	//	this->age = 0;
	//	this->hasScholarship = false;
	//	this->setName(name);
	//}


	int getAge() {		//receives by default the address of the calling object
						//the pointer is names this
						//Student* this
		return this->age;
	}

	bool getHasScholarship() {
		return this->hasScholarship;
	}

	string getNameValue() {
		return string(this->name);
	}

	char* getNameValueAsPointer() {
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);
		return nameCopy;
	}

	//write access
	void setAge(int value) {
		//VALIDATE THE INPUT
		if (value >= 10 && value <= 100) {
			this->age = value;
		}
		else {
			//throw "Wrong value for age";
			throw exception("Wrong value for age");
		}
	}

	void gainsScholarship() {
		this->hasScholarship = true;
	}

	void losesScholarship() {
		this->hasScholarship = false;
	}

private:
	void setName(const char* value) {
		if (strlen(value) > 99) {
			throw exception("Value too long");
		}

		strcpy_s(this->name, 99, value);
	}

public: 
	void printInfo() {
		cout << endl << "------------------------------";
		cout << endl << "Name " << this->getNameValue();	//this->name;
		cout << endl << "Age " << this->age;
		cout << endl << "Has scholarship " << (this->hasScholarship ? "true" : "false");
		if (this->noGrades != 0) {
			cout << endl << "Grades: ";
			for (int i = 0; i < this->noGrades; i++) {
				cout << this->grades[i] << " ";
			}
		}
	}
};

//overloading
//definfing multiple methods with the same name but with different arguments list
// - the number of arguments
// - the type of the arguments from left to right
int addNumbers(int a, int b) {
	return a + b;
}

int addNumbers(int a, int b, int c) {
	return a + b + c;
}

float addNumbers(float a, float b) {
	return a + b;
}

class Faculty {
	string name;
	string address;
public:
	//Faculty(string name, string address) {
	//	this->name = name;
	//	this->address = address;
	//}

	Faculty() {

	}
};

void incrementCounter(int value) {
	value += 1;
}

void incrementCounterWithPointer(int* pointerToCounter) {
	*pointerToCounter += 1;
}

void incrementCounterWithReferences(int &value) {
	value += 1;
}


int main() {
	int result = addNumbers(10, 20);
	result = addNumbers(10, 20, 30);
	float realResult = addNumbers((float)1.2, (float)3.4);

	//testing the constructors
	Student alice("Alice", true, 21);
	Student john("John", 21, false);
	Student bob("Bob", 20);

	alice.gainsScholarship();
	bob.gainsScholarship();

	alice.printInfo();
	john.printInfo();
	bob.printInfo();

	//Student vader("Vader");

	//vader.printInfo();

	//Student vader;
	Faculty csie;

	//vader.printInfo();

	int counter = 0;

	//increment 
	counter += 1;

	cout << endl << "The counter value is " << counter;

	incrementCounter(counter);
	cout << endl << "The counter value is " << counter;

	incrementCounterWithPointer(&counter);
	cout << endl << "The counter value is " << counter;

	incrementCounterWithReferences(counter);
	cout << endl << "The counter value is " << counter;
}