#include <iostream>
#include <string>
using namespace std;

//Relation between classes
// has a - composition
// is a - inheritance

//An app to manage the students grades for different courses. 
// A student can have multiple grades and he/she is enrolled to a faculty
// A grade will record a value between 0 and 10 and the course name
// A faculty has a name and an address.

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
//private:
//	Faculty() {
//		cout << endl << "The Faculty default ctor";
//		strcpy_s(this->name, 100, "No name");
//		this->address = "No address";
//	}

public:

	Faculty(const char* name, string address) {
		strcpy_s(this->name, 100, name);
		this->address = address;
		cout << endl << "The Faculty args ctor";
	}

	Faculty(const Faculty& faculty) {
		cout << endl << "The Faculty copy ctor";
		strcpy_s(this->name, 100, faculty.name);
		this->address = faculty.address;
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


//composition
//The Student class "has a" Faculty and "has" multiple grades
class Student {
	int id = 0;
	string name = "";
	Faculty faculty; // = Faculty("ASE Generic", "Piata Romana");		//1-1 relation with a Faculty

	//static approach
	//Grade grades[100];

	//dynamic approach
	Grade* grades = nullptr;	//1-M relation with Grade

	int noGrades = 0;

public:
	Student() : faculty("CSIE", "Calea Dorbanti 15-17") {
		this->id = 0;
		cout << endl << "The Student default ctor";
	}

	Student(int Id, string Name, Faculty& receivedFaculty) : faculty(receivedFaculty){		//the Faculty copy ctor
		this->id = Id;
		this->name = Name;
		cout << endl << "The Student args ctor - with faculty";
	}

	Student(int Id, string Name, const char* facultyName, string facultyAddress)
		: faculty(facultyName, facultyAddress), id(Id), name(Name)
	{
		cout << endl << "The Student args ctor - with all data";
	}


	~Student() {
		cout << endl << "The Student destructor";
	}

	void takeExam(Grade grade) {
		Grade* newGrades = new Grade[this->noGrades + 1];
		for (int i = 0; i < this->noGrades; i++) {
			newGrades[i] = this->grades[i];
		}
		newGrades[this->noGrades] = grade;

		delete[] this->grades;
		this->grades = newGrades;
		this->noGrades += 1;
	}
};


class UndergraduateStudent {
protected:
	string name = "";
	int age = 0;
	string bachelorProgram = "";
	float admissionGrade = 0;;
public:
	//UndergraduateStudent() {
	//	cout << endl << "The UndergraduateStudent default ctor";
	//}

	UndergraduateStudent(string Name, int Age, string Program, float AdmissionGrade)
		:name(Name), age(Age), bachelorProgram(Program), admissionGrade(AdmissionGrade)
	{
		cout << endl << "The UndergraduateStudent ctor";
	}

	string getName() {
		return this->name;
	}
};

//MasterStudent inherits UndergraduateStudent
//MasterStudent "is a" UndergraduateStudent 
//MasterStudent extends UndergraduateStudent
class MasterStudent: public UndergraduateStudent {

	string masterProgram;
	float bachelorExamAverage;

public:
	MasterStudent() : UndergraduateStudent("John Doe", 19, "CSIE", 9.00) {
		cout << endl << "The MasterStudent default ctor";
	}

	MasterStudent(string name, int age, string masterProgram)
		:UndergraduateStudent(name, age, "", 0)
	{
		this->masterProgram = masterProgram;
		//this->name = name;
		//this->age = age;
		this->bachelorProgram = "";
		this->bachelorExamAverage = 0;
	}

};

int main() {
	//Student student;
	//Faculty csie("CSIE", "Calea Dorobanti");
	//Student john(1, "John", csie);

	//Student alice(2, "Alice", "MAN", "Mihai Eminescu");

	cout << endl << " --------------------------";

	MasterStudent bob;
	//bob.getName();
	//bob.name = "Bob";
}

