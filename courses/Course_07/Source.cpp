#include <iostream>
#include <string>

using namespace std;

// today topics
// constant and static attributes
// memory leaks
// the class destructor
// copy constructor
// shallow-copy vs deep-copy
// remember enums
// shadowing

enum ProgramType {UNDERGRADUATE = 10, MASTER = 20, PHD = 30};

#define NMAX 100;

class Student {
private:
	string name = "";
	//int programType;		//undergraduate - 1, master - 2, phd - 3
	//string programType;		//"undergraduate", "master", "phd" - "Phd", "PHD", "pHD"

	//ProgramType program = ProgramType::UNDERGRADUATE; //"undergraduate"
	ProgramType program = ProgramType::UNDERGRADUATE;

	int* grades = nullptr;
	int noGrades = 0;
public:
	void printInfo() {
		cout << endl << "---------------------";
		cout << endl << "Name: " << this->name;
		cout << endl << "Program type: " << this->program;
		cout << endl << "Program name: " << this->getProgramName();
		if (this->grades != nullptr) {
			cout << endl << "Student grades: ";
			for (int i = 0; i < this->noGrades; i++) {
				cout << this->grades[i] << " ";
			}
		}
	}
public:
	string getProgramName() {
		switch (this->program)
		{
		case UNDERGRADUATE:
			return "Undergraduate";
		case MASTER:
			return "Master";
		case PHD:
			return "Phd";
		}
	}

	ProgramType getProgramType() {
		return this->program;
	}

	void setGrades(int* someGrades, int noReceivedGrades) {
		if (someGrades == nullptr) {
			throw exception("No grades");
		}

		//shallow-copy
		this->grades = someGrades;
		this->noGrades = noReceivedGrades;
	}

	Student(string name, ProgramType program, int* grades, int noGrades) {
		//shadowing
		//name = name;
		this->name = name;
		this->program = program;
		this->setGrades(grades, noGrades);
	}

	Student() {

	}
};

int main() {
	//default ctor
	Student student;
	student.printInfo();

	int grades[] = { 10,10,9 };
	int noGrades = 3;

	student.setGrades(grades, noGrades);
	student.printInfo();

	Student alice("Alice", ProgramType::UNDERGRADUATE, grades, noGrades);
	alice.printInfo();

}