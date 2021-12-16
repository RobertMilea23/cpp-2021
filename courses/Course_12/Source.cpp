#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class DivisionByZeroException : public exception {
public:
	DivisionByZeroException(string message) : exception(message.c_str()) {
	}

	DivisionByZeroException() {

	}
};

class ValueTooBigException : public exception {
public:
	ValueTooBigException(const char* message) : exception(message) {

	}
};

float division(int a, int b) {
	if (b == 0) {
		//cout << endl << "We can't divide to 0";
		//return -1; 
		throw exception("B is 0");
	}
	if (a > 1000) {
		throw exception("A is too big");
	}
	return (float)a / b;
}

float divisionV2(int a, int b) {
	if (b == 0) {
		//cout << endl << "We can't divide to 0";
		//return -1; 
		throw DivisionByZeroException("B is 0");
	}
	if (a > 1000) {
		throw ValueTooBigException("A is too big");
	}
	return (float)a / b;
}

void doSomethingWrong() {
	throw exception();
}

class Student {
	string name;
	int age;
	string faculty;
	int* grades;
	int noGrades;

public:
	Student(string name) : name(name) {

	}

	Student(string name, int age, string faculty, int* grades, int noGrades) 
		:name(name), age(age), faculty(faculty), noGrades(noGrades)
	{
		this->grades = new int[noGrades];
		for (int i = 0; i < noGrades; i++) {
			this->grades[i] = grades[i];
		}
	}

	friend void operator<<(ostream& out, Student& student);
};

void operator<<(ostream& out, Student& student) {
	out << endl << "The name of the student is " << student.name;
}

int main() {
	int vb1 = 10;
	int vb2 = 0;

	if (vb2 != 0) {
		float result = division(vb1, vb2);
		cout << endl << "The result is " << result;
	}

	try {
		float result = division(vb1, vb2);
		cout << endl << "The result is " << result;
	}
	catch (exception e) {
		cout << endl << "Sorry. I didn't check vb2";
		cout << endl << "Error: " << e.what();
	}

	cout << endl << "-----------------";

	try {
		vb2 = 10;
		vb1 = 100000;
		float result = division(vb1, vb2);
		cout << endl << "The result is " << result;
	}
	catch (exception e) {
		cout << endl << "Sorry. I didn't check vb2";
		cout << endl << "Error: " << e.what();
	}

	cout << endl << "-----------------";


	try {
		vb2 = 5;
		vb1 = 10;
		float result = divisionV2(vb1, vb2);
		cout << endl << "The result is " << result;

		//int values[5];
		//values[500] = 90;

		//throw exception("Error");
		doSomethingWrong();

		cout << endl << "The end of the try block";
	}

	catch (DivisionByZeroException e) {
		cout << endl << "Sorry. I didn't check vb2";
		cout << endl << "Error: " << e.what();
	}
	catch (ValueTooBigException e) {
		cout << endl << "Sorry. I didn't check vb1";
		cout << endl << "Error: " << e.what();
	}
	catch (...) {
		cout << endl << "We have a problem";
	}

	//files
	//The C approach
	//FILE* pf;
	//pf = fopen("Report.txt", "rw+");

	fstream file();
	ofstream outputFile("Report.txt", ios::out | ios::app);

	
	ifstream inputFile("StudentsReport.txt", ios::in);


	ofstream reportFile;
	reportFile.open("Report2.txt", ios::out);

	if (outputFile.is_open()) {
		cout << endl << "The Report.txt file has created. We can use it";
	}


	

	//text files
	//writing

	outputFile << "This is my report";
	outputFile << endl << "Number of students = 10";
	outputFile << endl << "John";

	Student john("John");
	cout << john;
	outputFile << john;

	outputFile.close();

	//reading
	if (!inputFile.is_open()) {
		cout << endl << "The StudentsReport.txt is missing";
	}
	else {
		cout << endl << "The StudentsReport.txt is available";
	}

	cout << endl << "The students names are: ";
	while (!inputFile.eof()) {
		string studentName = "";
		inputFile >> studentName;
		cout << endl << "Student name is " << studentName;
	}

	inputFile.close();

	//reading the Student data
	ifstream studentData("StudentData.txt", ios::in);
	if (studentData.is_open()) {

		//follow the one line one value pattern
		string name;
		//studentData >> name;
		
		
		//for strings with space
		char buffer[50];
		studentData.getline(buffer, 50);
		name = string(buffer);

		int age;
		studentData >> age;
		string faculty;
		studentData >> faculty;
		int noGrades;
		studentData >> noGrades;
		int* grades = new int[noGrades];
		for (int i = 0; i < noGrades; i++) {
			studentData >> grades[i];
		}
		Student student(name, age, faculty, grades, noGrades);
		cout << student;

		studentData.close();
	}
	else {
		cout << endl << "*************** The file is not here";
	}

	//binary files
	//NEVER use <<

	ofstream outputBinaryFile("MyData.bin", ios::out | ios::binary | ios::trunc);
	if (outputBinaryFile.is_open()) {
		int vb = 10;
		//outputBinaryFile << vb;  is a mistake

		float vb2 = 20;
		bool vbBool = true;
		char name[] = "John";

		outputBinaryFile.write((char*)&vb, sizeof(int));
		outputBinaryFile.write((char*)&vb2, sizeof(float));
		outputBinaryFile.write((char*)&vbBool, sizeof(bool));

		//when you write a string or a char array into a binary file
		//always write its size before the value

		int nameSize = strlen(name) + 1;
		outputBinaryFile.write((char*)&nameSize, sizeof(int));
		outputBinaryFile.write(name, strlen(name) + 1);


		string faculty = "CSIE";
		int facultySize = faculty.size() + 1;
		outputBinaryFile.write((char*)&facultySize, sizeof(int));
		outputBinaryFile.write(faculty.c_str(), facultySize);

		outputBinaryFile.close();
	}
}