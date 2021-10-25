#include <iostream>
#include "myLibrary.h"

using namespace std;

int main() {

	int values[] = { 10,20,30,40 };
	int noValues = 4;

	int otherValues[4];

	char message[] = "Laboratory 05";

	printMessage(message);
	printArray(values, noValues);
	printArray(otherValues, noValues);

	int noElements = 10;
	int* newArray = createAndInitAnIntArray(noElements, 0);
	printArray(newArray, noElements);

	double aDoubleVb = 10.5;
	int* aPointer = nullptr;

	cout << endl << "The size of values is " << sizeof(values);
	cout << endl << "The size of otherValues is " << sizeof(otherValues);
	cout << endl << "The size of a double is " << sizeof(aDoubleVb);
	cout << endl << "The size of message is " << sizeof(message);
	cout << endl << "The size of the pointer is " << sizeof(aPointer);
	cout << endl << "The size of newArray is " << sizeof(newArray);

}