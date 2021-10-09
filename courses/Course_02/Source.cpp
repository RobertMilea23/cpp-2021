#include <stdio.h>
#include <iostream>

using namespace std;


int global;

namespace myVariables {
	int vb;
}

namespace yourVariables {
	int vb;
}

using namespace myVariables;
using namespace yourVariables;

void doSomething(int inputValue) {
	int anIntegerValue;
	char aCharVariable;
	short int aShortIntValue;
}



int main() {

	printf("\n Bye Bye C");

	myVariables::vb = 10;
	yourVariables::vb = 20;
	//vb = 30;

	std::cout << "\n Hello C++";
	std::cout << std::endl << "Recap on pointers";
	cout << endl << "Let's take a break";

	int anIntegerValue;
	char aCharVariable;
	short int aShortIntValue;

	aCharVariable = 'a';
	//aCharVariable = "a";			//contains the 0 byte at the end of the array - '\0'
	aCharVariable = 10;
	aCharVariable = 108;		//aka  = 'm'
	anIntegerValue = 'a';

	aCharVariable = 'm';
	aCharVariable += 10;		//becomes 'v'

	cout << endl << "The number is " << anIntegerValue;

	int noStudents = 108;		// 108 students
	aCharVariable = 108;		// 'm'


	//pointers - variables used to store numbers, which represent an addresses

	//a pointer to an address of any type
	void *aPointerVariable = (void*)108;

	int* aPointerToAnInteger = (int*)108;
	char* aPointerToAChar;

	cout << endl << "The value from RAM at address 108 is " << aPointerVariable;	//you see the pointer value
	//cout << endl << "The value from RAM at address 108 is " << *aPointerToAnInteger;

	//aPointerToAnInteger = (int*)noStudents;
	aPointerToAnInteger = &noStudents;

	cout << endl << "The address of the noStudents variable is " << aPointerToAnInteger;
	cout << endl << "The value from RAM at address of noStudents is " << *aPointerToAnInteger;

	//return 0;
}