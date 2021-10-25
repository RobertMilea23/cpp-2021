#include "myFunctions.h"
#include <iostream>

using namespace std;

// myFunctions.h -> will contain only the methods/classes definitions
// myFunctions.cpp -> will contain the methods/classes implementations
// Source.cpp -> will contain main() and your project


int main() {
	std::cout << std::endl << "Laboratory 05";
	printMessage("Laboratory 05");

	int values[] = { 1,2,3,4 };
	int noValues = 4;

	printArray(values, noValues);

	short int shortValue;
	
	cout << endl << "Size = " << sizeof(shortValue);

	cout << endl << " is " << values;
	cout << endl << "Size of values = " << sizeof(values);
	cout << endl << "The 2nd value is " << values[1];

	int noElements = sizeof(values) / sizeof(int);

	cout << endl << "The number of elements is " << noElements;

	char endMessage[] = "The end of the laboratory";

	cout << endl << "The size of the message is " << sizeof(endMessage);


	int* newValues = nullptr;

	cout << endl << "Size of the pointer is " << sizeof(newValues);

	int noNewValues = 5;
	newValues = createAndInitArray(noNewValues, 0);
	printArray(newValues, noNewValues);

	cout << endl << "Size of the pointer is " << sizeof(newValues);

	printMessage(endMessage);

}