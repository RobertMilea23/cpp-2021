#include <iostream>
#include <string>
using namespace std;


class Person {
protected:
	string name;
	int age;
public:
	virtual string GetDescription() = 0;			//virtual pure method / abstract method


	string getName() {
		return this->name;
	}
};

class Student: public Person {
	string faculty;
public:

	string GetDescription() {
		return "Student description";
	}

};

class Prof: public Person {
	string courseName;
public:

	string GetDescription() {
		return "Prof description";
	}
};


template <typename T>
T add(T a, T b) { return a + b; }


int main() {

	//Person person;
	Person* pointerToPerson = nullptr;
	Person* persons[2];
	persons[0] = new Student();
	persons[1] = new Prof();

	for (int i = 0; i < 2; i++) {
		cout << endl << persons[i]->GetDescription();
	}

	int result = add<int>(3, 5);
	float otherResult = add<float>(3.5, 5.6);
}