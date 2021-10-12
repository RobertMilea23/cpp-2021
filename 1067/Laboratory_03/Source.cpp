#include <iostream>

//recap on arrays
// 
// based on value type
// 1. arrays of numbers
// 2. arrays of chars - strings

// based on the possibility to change its size
// 1. fix size arrays - static arrays
// 2. dynamic arrays - they can change their size

int main() {

	//define an array - static of numbers
	//all array variables/names are pointers to the first element
	//all static array variables/names are constant pointers

	int array[5];			//you get 0xcccc..cc for each value
	int noValues = 5;

	int variable = 10;
	variable = 25;

	const int constantVariable = 10;
	//constantVariable = 25;

	// Will never work
	// 	   you are trying to change the array pointer and not the values
	//array = { 1,2,3,4,5 };

	//init values
	for (int i = 0; i < noValues; i++) {
		array[i] = 0;
	}

	int incrementalArray[] = { 1,2,3,4,5 };
	int noValuesIncArray = 5;

	int singleValueArray[] = {1};
	int noValuesSingleArray = 1;

	//print the array values
	std::cout << std::endl << "The array address is " << array;

	std::cout << std::endl << "Array values are: ";
	for (int i = 0; i < noValues; i++) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl << "Array values are: ";
	for (int i = 0; i < noValuesIncArray; i++) {
		std::cout << incrementalArray[i] << " ";
	}

	//adding new values to a static array /increase the size
	//IT WILL NEVER WORK - draw the memory
	//noValues += 2;
	//array[5] = 10;
	//array[6] = 20;

	//std::cout << std::endl << "The new size of the array is " << noValues;
	//std::cout << std::endl << "Array values are: ";
	//for (int i = 0; i < noValues; i++) {
	//	std::cout << array[i] << " ";
	//}

	int values[1000];
	int no = 0;
	const int maxSize = 1000;

	//add a new value into values
	for (int i = 0; i < 5 && no < maxSize; i++) {
		no += 1;
		values[no - 1] = 10;
	}


	//dynamic arrays
	int* dynamicValues = nullptr;
	int noDynamicArrayValues = 0;

	//dynamicValues = (int*)malloc(100 * sizeof(int));
	noDynamicArrayValues = 10;
	dynamicValues = new int[noDynamicArrayValues];




}