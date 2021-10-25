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

int* createAndInitArray(int size, int defaultValue) {
	int* newArray = new int[size];
	for (int i = 0; i < size; i++) {
		newArray[i] = defaultValue;
	}
	return newArray;
}