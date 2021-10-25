#include "myFunctions.h"


void printMessage(const char* message) {
	std::cout << std::endl << message;
}

void printArray(int values[], int noValues) {
	std::cout << std::endl << "Values: ";
	for (int i = 0; i < noValues; i++) {
		std::cout << values[i] << " ";
	}
}

int* createAndInitArray(int noElements, int defaultValue) {

	int* newArray = new int[noElements];
	for (int i = 0; i < noElements; i++) {
		newArray[i] = defaultValue;
	}
	return newArray;
}