#include <iostream>
using namespace std;


// Relation between pointers. Pointers to pointers
// Adding a * before function name ?
// Adding the .h file in the Google Test Project
// Receiving a char array and creating a new one and returning it from a function

//check this function
void filtrareElementeMaiMari2(const int* values, int noValues, int givenValue, int* * valuesAboveLimit) {
	int ct = 0;
	for (int i = 0; i < noValues; i++)
	{
		if (values[i] >= givenValue)
			ct++;
	}
	if (ct == 0)
	{
		*valuesAboveLimit = NULL;
		return;
	}
	int* valuesCopy = new int[ct];
	int noValuesAboveLimit = 0;
	for (int i = 0; i < noValues; i++)
	{
		if (values[i] >= givenValue)
		{
			valuesCopy[noValuesAboveLimit] = values[i];
			noValuesAboveLimit++;
		}
	}
	*valuesAboveLimit = valuesCopy;
}

int* filtrareElementeMaiMari2WithReturn(const int* values, int noValues, int givenValue) {
	int ct = 0;
	for (int i = 0; i < noValues; i++)
	{
		if (values[i] >= givenValue)
			ct++;
	}
	if (ct == 0)
	{
		return nullptr;
	}
	int* valuesCopy = new int[ct];
	int noValuesAboveLimit = 0;
	for (int i = 0; i < noValues; i++)
	{
		if (values[i] >= givenValue)
		{
			valuesCopy[noValuesAboveLimit] = values[i];
			noValuesAboveLimit++;
		}
	}
	return valuesCopy;
}

char* changesACharArray(const char* initialText) {
	char* newText = new char[strlen(initialText) + 1];
	strcpy_s(newText, strlen(initialText) + 1, initialText);

	for (int i = 0; i < strlen(newText); i++) {
		newText[i] += 1;
	}

	return newText;

}


void resizeValues(int * * pointerToValues, int* pointerToNoValues) {
	*pointerToNoValues = 1000;
	*pointerToValues = new int[1000];
}

void wrongResize(int* values, int noValues) {
	values = new int[1000];
	noValues = 1000;
}

void cppResize(int* &values, int &noValues) {
	values = new int[1000];
	noValues = 1000;
}


int main() {

	int vb = 10;
	vb = 20;

	int*** pointerToSomethingVeryComplex;

	int *pointerToVb;
	int*** * pointerToComplexPointer;

	pointerToVb = &vb;
	*pointerToVb = 30;

	int* *pointerToPointerToVb;
	pointerToPointerToVb = &pointerToVb;

	//pointerToPointerToVb = pointerToVb;

	int** * superPointer;
	superPointer = &pointerToPointerToVb;

	int* values = new int[5];
	int noValues = 5;

	values = new int[100];
	noValues = 100;

	resizeValues(&values, &noValues);


	int initialValues[] = { 1,2,3,4,5,6,7,8,9,10 };		//int*
	int noInitialValues = 10;
	int limitValue = 5;

	int* resultArray = nullptr;

	filtrareElementeMaiMari2(initialValues, noInitialValues, limitValue, &resultArray);

	int* secondResult = nullptr;

	secondResult = filtrareElementeMaiMari2WithReturn(initialValues, noInitialValues, limitValue);

	const char* msg = "abcd";
	char* newMsg = changesACharArray(msg);
}