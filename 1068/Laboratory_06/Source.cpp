#include <iostream>

void printArray(int* arrayAddr, int noElements) {
	std::cout << std::endl << "The values are: ";
	for (int i = 0; i < noElements; i++) {
		std::cout << arrayAddr[i] << " ";
	}
}


//it will not work
//wrong
void resizeArray(int* initialArray, int noElements, int newSize) {
	int* temp = new int[newSize];
	for (int i = 0; i < noElements; i++) {
		temp[i] = initialArray[i];
	}
	delete[] initialArray;
	initialArray = temp;
	noElements = newSize;
}

void resizeArrayWithPointers(int* *addrInitialArray, int * addrNoElements, int newSize) {
	int* temp = new int[newSize];
	for (int i = 0; i < *addrNoElements; i++) {
		temp[i] = (*addrInitialArray)[i];
	}
	delete[](*addrInitialArray);
	*addrInitialArray = temp;
	*addrNoElements = newSize;
}

void resizeArrayWithReferences(int* &initialArray, int &noElements, int newSize) {
	int* temp = new int[newSize];
	for (int i = 0; i < noElements; i++) {
		temp[i] = initialArray[i];
	}
	delete[] initialArray;
	initialArray = temp;
	noElements = newSize;
}

int main() {

	//static arrays
	int staticArray[5];			//they get 0xCC....CC by default
	int anotherStaticArray[] = { 10,20,30 };

	//dynamic arrays
	//is just a pointer - there is no array here

	//1. define the pointer to the 1st value in the array
	int* dynamicArray = nullptr;
	//2. create the array
	int noElements = 5;
	dynamicArray = new int[noElements];	//we get a 5 x int array in Heap
										//all values are by default 0xCDCDCD
	//3. init the values
	for (int i = 0; i < noElements; i++) {
		dynamicArray[i] = (i + 1);
	}

	std::cout << std::endl << "The array address in Heap is " << dynamicArray;

	printArray(dynamicArray, noElements);
	//resize version 1
	//not enough - your array has the same size in Heap
	//noElements = 10;

	//before resizing ask if you still need the previous values ?
	//no
	//you can delete the previous array
	//delete[] dynamicArray;
	//resize the dynamic array
	//dynamicArray = new int[10];

	//yes
	//create the new array
	int* newArray = new int[10];
	//copy values from the previous one
	for (int i = 0; i < noElements; i++) {
		newArray[i] = dynamicArray[i];
	}
	delete[] dynamicArray;
	//copy the addres of the new array
	dynamicArray = newArray;
	//update the noElements
	noElements = 10;

	std::cout << std::endl << "The new array address in Heap is " << dynamicArray;
	printArray(dynamicArray, noElements);

	//resizeArray(dynamicArray, noElements, 20);
	//resizeArrayWithPointers(&dynamicArray, &noElements, 20);
	resizeArrayWithReferences(dynamicArray, noElements, 20);

	std::cout << std::endl << "The new resized array address in Heap is " << dynamicArray;
	printArray(dynamicArray, noElements);

}