#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Student {
private:
	char name[100];
	bool hasScholarship;
	int age;
public:

	//class constructor
	Student(const char* name, int age, bool hasScholarship) {
		this->setAge(age);
		this->setScholarship(hasScholarship);
		this->setName(name);
	}

	int getAge() {		//receives by default the address of the calling object
						//the pointer is names this
						//Student* this
		return this->age;
	}

	bool getHasScholarship() {
		return this->hasScholarship;
	}

	//IT'S NOT OK
	char* getName() {
		return this->name;
	}

	string getNameValue() {
		return string(this->name);
	}

	char* getNameValueAsPointer() {
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1,this->name);
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

	void setScholarship(bool value) {
		this->hasScholarship = value;
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

		strcpy_s(this->name,99,value);
	}
};

class Faculty {
	char* name;
	string address;
};

int main() {

	string message;
	message = "Course 05";
	message = "Hello " + message;

	cout << endl << message;
	cout << endl << "The length of the message is " << message.length();

	Student studentAlice("Alice", 20, true);
	Student studentJohn("John", 12, false);
	//student.age = -21;
	//int studentAge = student.age;

	int studentAge = studentAlice.getAge();
	studentAge = studentJohn.getAge();

	cout << endl << "Alice age is " << studentAlice.getAge();
	//cout << endl << "Alice name is " << studentAlice.getName();

	char* aliceName = studentAlice.getName();
	aliceName[0] = 'A';
	aliceName[1] = 'l';
	aliceName[2] = 'i';
	aliceName[3] = 'c';
	aliceName[4] = 'e';
	aliceName[5] = '\0';

	cout << endl << "Alice name is " << studentAlice.getName();

	//studentAlice.setAge(-21);

	//studentJohn.setName("John");
	studentJohn.setAge(21);
	studentJohn.gainsScholarship();

	cout << endl << "Student name is  " << studentJohn.getName();

	message = "The end";
}
