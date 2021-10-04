#include <stdio.h>
#include <string>
#include <string.h>


// this is an IDE
// 
//1. what main returns ? void vs int
//2. how do we run it
//	2.1 step 1 - compile it -> Build -> Build Solution
//	2.2 step 2 - if you have compiler errors - always fix the 1st
//  2.3.step 3 - run it without debugger - Ctrl + F5
//  2.4 step 4 - for strange exit codes / runtime exceptions run it with debugger - F5
//  2.5 step 5 - fix the reason and go back to step 2


//defining the function name and signature
int arrayElementsSum();


int main() {
	int value = 0;


	//int* pointerToValue = NULL;
	//int* pointerToValue = 0;
	int* pointerToValue = nullptr;


	printf("The value is %d", value);
	if(pointerToValue != nullptr)
		printf("The value at the pointer address is %d",*pointerToValue);


	int sumValue = arrayElementsSum();
	//printf("\n The array sum is %d", arrayElementsSum());
	printf("\n The array sum is %d", sumValue);

	printf("\n Bye !");
	//return 0;
}

int arrayElementsSum() {
	int values[] = { 10, 20, 30, 40, 50, 60 };
	int noValues = 6;
	int sum = 0;
	for (int i = 0; i < noValues; i++) {
		sum += values[i];
	}
	return sum;
}


