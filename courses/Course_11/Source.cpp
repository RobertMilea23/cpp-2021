#include <iostream>
#include <string>
using namespace std;

//Relation between classes
// has a - composition
// is a - inheritance

class Grade {
	int value = 0;
	string course = "";
public:
	Grade() {
		cout << endl << "Grade default ctor";
	}
	
	Grade(int Value, string Course) : value(Value), course(Course) {
		cout << endl << "Grade args ctor";
	}

	Grade(const Grade& grade) : value(grade.value), course(grade.course) {
		cout << endl << "Grade copy ctor";
	}

	Grade operator=(const Grade& grade) {
		cout << endl << "Grade operator =";
		this->value = grade.value;
		this->course = grade.course;
	}

	~Grade() {
		cout << endl << "Grade destructor";
	}

};

class Faculty {
	char name[100] = "";
	string address = "";
public:
	Faculty() {
		strcpy_s(this->name, 100, "No name");
		this->address = "No address";
	}

	Faculty(const Faculty& faculty) {
		strcpy_s(this->name, 100, faculty.name);
		this->address = faculty.address;
		cout << endl << "Faculty copy ctor";
	}

	~Faculty() {
		cout << endl << "Faculty destructor";
	}

	Faculty operator=(const Faculty& faculty) {
		cout << endl << "Faculty operator =";
		strcpy_s(this->name, 100, faculty.name);
		this->address = faculty.address;
	}
};

class Student {

};

int main() {

}

