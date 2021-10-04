#include <stdio.h>
#include <string>
#include <string.h>


//Steps for programming
//Step 1 - Editing your source code
//Step 2 - Check the syntax by building your project - compile it (Build -> Build solution)
//Step 3 - If you have compiler errors - check & fix the 1st one and rebuild
//Step 4 - Run the program without debugger (Ctrl + F5/ Debug -> Start Without Debuggin)
//Step 5 - If you have strange exit codes / runtime exceptions run it again in Debug mode
//				F5 or Debug -> Start Debugging 

int getArrayElementsSum();

int main() {

	int initialValueForTesting = 0;

	// int* pointerToValue = NULL;
	// int* pointerToValue = 0;
	int* pointerToValue = nullptr;


	printf("The test value is %d", initialValueForTesting);
	if (pointerToValue != nullptr) {
		printf("The value at the pointer address is %d", *pointerToValue);
	}

	int arraySum = getArrayElementsSum();
	printf("\n The sum is %d", arraySum);

	printf("\nSee you again !");

	//return 0;
}

int getArrayElementsSum() {

	//please don't write the size
	int values[] = { 10,20,30,40,50,60,70,80};
	int noValues = 8;
	int sum = 0;
	for (int i = 0; i < noValues; i++) {
		sum += values[i];
	}
	return sum;
}
