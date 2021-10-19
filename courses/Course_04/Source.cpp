#include <iostream>
using namespace std;

struct Student {
	char name[100];		// name is a char*
	int age;
	bool hasScholarship;
};

//char* <-> char[] ; char[100]
Student initStudent(const char* name, const int age, const bool hasScholarship) {
	Student student;
	student.age = age;
	student.hasScholarship = hasScholarship;
	//does not work for char arrays
	//student.name = name;
	strcpy_s(student.name, name);

	return student;
}

void printStudent(Student student) {
	cout << endl << "Student name: " << student.name;
	cout << endl << "Student age: " << student.age;
	cout << endl << "Has scholarship: " << student.hasScholarship;
}

int main() {


	//data for only 1 student
	char studentName[100];
	int studentAge;
	bool hasScholarship;

	//data for 1000 students
	const int noStudents = 1000;
	char* studentNames[noStudents];
	//char* studentNames[1000][100];
	int studentAges[noStudents];
	bool studentScholarships[noStudents];

	//with data structures
	Student student;
	Student students[noStudents];		//students is Student*

	//char initialName[] = "John";

	//printStudent(student);

	student = initStudent("John", 21, true);
	printStudent(student);

}