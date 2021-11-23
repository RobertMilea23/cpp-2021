#include <iostream>
#include <string>

using namespace std;

class GradeBook {
	string courseName = "";
	int* grades = nullptr;
	int noGrades = 0;
public:
	GradeBook(string name) : courseName(name) {

	}

	void addGrade(int grade) {
		int* newArray = new int[this->noGrades + 1];
		for (int i = 0; i < this->noGrades; i++) {
			newArray[i] = this->grades[i];
		}
		newArray[this->noGrades] = grade;
		this->noGrades += 1;

		if (this->grades != nullptr) {
			delete[] this->grades;
		}
		this->grades = newArray;
	}

	void print() {
		cout << endl << "Grades for  " << this->courseName << ": ";
		for (int i = 0; i < this->noGrades; i++) {
			cout << this->grades[i] << " ";
		}
	}

	string getName() {
		return this->courseName;
	}

	int getNoGrades() {
		return this->noGrades;
	}


	int* getGrades() {
		int* gradesCopy = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			gradesCopy[i] = this->grades[i];
		}
		return gradesCopy;
	}


	//class destructor
	~GradeBook() {
		delete[] this->grades;
	}

	//class copy constructor
	GradeBook(const GradeBook& object) : courseName(object.courseName) {

		cout << endl << "Calling copy constructor";
		//object.courseName = this->courseName;

		//DON'T do the shallow copy
		//this->grades = object.grades;

		this->grades = new int[object.noGrades];
		for (int i = 0; i < object.noGrades; i++) {
			this->grades[i] = object.grades[i];
		}
		this->noGrades = object.noGrades;
	}
};

int main() {

}
