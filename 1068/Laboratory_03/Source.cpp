#include <iostream>

//Arrays
//1. Arrays of numbers
//2. Arrays of characters
//3. Arrays of objects/structures

//1. Static arrays - their size is fix
//2. Dynamic arrays - they can change

int main() {
	std::cout << std::endl << "Laboratory 03";

	//Static arrays 
	//Definition

	int dummy[20];

	//it's a pointer 
	//all array variables are pointers
	int numbers[10] = { 0 };
	int noNumbers = 10;

	int oddNumbers[] = { 1,3,5,7,9,11 };
	int noOddNumbers = 6;

	int oneValueArray[] = {10};
	int noOneValueArray = 1;

	//Init the first array
	//By default all the 10 values are 0xccccc...ccc.
	for (int i = 0; i < noNumbers; i++) {
		numbers[i] = 0;
	}

	//Using the array
	std::cout << std::endl << "The array address is :" << numbers;
	std::cout << std::endl << "The array values are :";
	for (int i = 0; i < noNumbers; i++) {
		std::cout << numbers[i] << " ";
	}


	//Resizing a static array
	//NEVER DO IT - you don't have extra space after the array
	//noNumbers += 3;
	//numbers[10] = 10;
	//numbers[11] = 20;
	//numbers[12] = 30;

	//Using the array
	std::cout << std::endl << "The array values are :";
	for (int i = 0; i < noNumbers; i++) {
		std::cout << numbers[i] << " ";
	}


	//we had a mistake
	std::cout << std::endl << "The odd array values are :";
	for (int i = 0; i < noOddNumbers; i++) {
		std::cout << oddNumbers[i] << " ";
	}

	int aLotOfValues[1000];
	int n = 0;
	int maxSize = 1000;

	n += 1;
	aLotOfValues[n-1] = 10;
	n += 1;
	aLotOfValues[n-1] = 10;
}