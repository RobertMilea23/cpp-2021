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

	//overloading operator = for the GradeBook class
	void operator=(GradeBook source) {
		this->courseName = source.courseName;
		this->noGrades = source.noGrades;
		//this->grades = source.grades;


		if (this->grades == source.grades) {
			//is the same object
			return;
		}
		else {
			delete[] this->grades;
			this->grades = new int[this->noGrades];
			for (int i = 0; i < this->noGrades; i++) {
				this->grades[i] = source.grades[i];
			}
		}
	}

	void operator+=(int newGrade) {
		this->addGrade(newGrade);
	}

	friend void operator>>(istream& console, GradeBook& gradeBook);
};

ostream& operator<<(ostream& console, GradeBook gradeBook) {
	console << endl << "The gradebook data is :";
	console << endl << "Course name: " << gradeBook.getName();
	if (gradeBook.getNoGrades() > 0) {
		int* grades = gradeBook.getGrades();
		console << endl << "Grades: ";
		for (int i = 0; i < gradeBook.getNoGrades(); i++) {
			console << grades[i] << " ";
		}
	}

	else {
		console << endl << "No grades";
	}

	return console;
}

void operator>>(istream& console, GradeBook& gradeBook) {
	cout << endl << "The course name is: ";
	string courseName;
	console >> courseName;
	gradeBook.courseName = courseName;		//we have access because this method is the class friend
	cout << endl << "The new number of grades is:";
	console >> gradeBook.noGrades;
	delete[] gradeBook.grades;
	gradeBook.grades = new int[gradeBook.noGrades];
	for (int i = 0; i < gradeBook.noGrades; i++) {
		cout << endl << "Grade " << i + 1 << ":";
		console >> gradeBook.grades[i];
	}
}

GradeBook createAGradeBook() {
	GradeBook newGradeBook("An empty gradebook");
	return newGradeBook;
}

//overloading operators
//	1. overload them in the class - they will receive the this pointer as the 1st argument
//  2. overload them as global methods 

int main() {

	GradeBook oopGradeBook("OOP");
	oopGradeBook.addGrade(10);
	oopGradeBook.addGrade(10);
	oopGradeBook.addGrade(9);
	oopGradeBook.print();

	cout << oopGradeBook;		//operator<<(std::ostream, GradeBook)
	//operator<<(cout, oopGradeBook);

	GradeBook webGradeBook("WT");
	//cin >> webGradeBook;		//operator>>(std::istream, GradeBook)
	//cout << webGradeBook;

	cout << oopGradeBook << webGradeBook;
	//cout << webGradeBook;

								//oopGradeBook = oopGradeBook + 10
	oopGradeBook += 10;			//operator+=(GradeBook, int)


}
