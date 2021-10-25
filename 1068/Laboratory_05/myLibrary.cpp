#include "myLibrary.h"
#include <iostream>

void printMessage(const char* message) {
	std::cout << std::endl << message;
}

void printArray(int* values, int noElements) {
	std::cout << std::endl << "The values are: ";
	for (int i = 0; i < noElements; i++) {
		std::cout << values[i] << " ";
	}
}

int* createAndInitAnIntArray(int noElements, int defaultValue) {
	int* array = new int[noElements];
	for (int i = 0; i < noElements; i++) {
		array[i] = defaultValue;
	}
	return array;
}