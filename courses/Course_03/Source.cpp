#include <iostream>
using namespace std;

void interchange(int vbX, int vbY) {
	int temp = vbX;
	vbX = vbY;
	vbY = temp;
}

void interchange2(int* pX, int* pY) {
	int temp = *pX;
	*pX = *pY;
	*pY = temp;
}


int main() {

	std::cout << std::endl << "Course 03";

	int valueA = 10;
	int valueB = 20;

	int values[] = { 1,2,3,4,5,6 };
	int noValues = 6;

	int* pointerA = nullptr;
	void* genericPointer = nullptr;

	cout << endl << "A value is " << valueA;
	//a mistake
	//the pointer value is going to be 10
	//pointerA = (int*)valueA;

	pointerA = &valueA;

	cout << endl<< "The value (address) of the pointer is " << pointerA;
	cout << endl << "The value at the pointer address " << *pointerA;

	*pointerA = 90;
	cout << endl << "A value is " << valueA;


	//check the 2 varaibles addresses
	cout << endl << "Address of A is " << &valueA;
	cout << endl << "Address of B is " << &valueB;

	int* pointerB = &valueB;
	cout << endl << "B value is " << *pointerB;

	//on my machine the difference is 12 bytes
	pointerB += 3;
	cout << endl << "A value is " << *pointerB;

	//pointer to another pointer
	int* (*pointerOfPointerA) = &pointerA;
	//same
	//int** pointerOfPointerA = &pointerA;

	int vbX = 10;
	int vbY = 20;

	cout << endl << "x = " << vbX << " and y = " << vbY;

	int temp = vbX;
	vbX = vbY;
	vbY = temp;

	cout << endl << "x = " << vbX << " and y = " << vbY;

	interchange(vbX, vbY);

	cout << endl << "x = " << vbX << " and y = " << vbY;

	interchange2(&vbX, &vbY);

	cout << endl << "x = " << vbX << " and y = " << vbY;
}