#include <iostream>
#include <string.h>
using namespace std;


void toUpper(char text[]) {
	for (int i = 0; i < strlen(text); i++) {
		//if (text[i] >= 'a' && text[i] <= 'z')
		if (text[i] >= 97 && text[i] <= 122) {
			text[i] -= 32;
		}
	}
}

char* toUpperWithReturn(const char text[]) {
	//if (strlen(text) > 999) {
	//	cout << endl << "The input array is too big !";
	//	return nullptr;
	//}

	//don't do it if you return it - it's on the function stack
	//char newValue[1000];
	// 

	//char* newValue = new char[1000];
	//+1 for the the string terminator '\0'
	char* newValue = new char[strlen(text)+1];

	// 
	//strcpy(newValue, text);
	strcpy_s(newValue,strlen(text)+1,text);
	for (int i = 0; i < strlen(newValue); i++) {
		if (newValue[i] >= 'a' && newValue[i] <= 'z') {
			newValue[i] -= 32;
		}
	}
	return newValue;
}



void printMessage(const char message[]) {
	//cout << endl << "The address of the message is " << (void*)message;
	cout << endl << message;
	//toUpper(message);
}

void printArray(int values[], int noValues) {
	cout << endl << "The array is: ";
	for (int i = 0; i < noValues; i++) {
		cout << values[i] << " ";
	}
}

int main() {

	//'a' vs "a" -> "a" is a char array and ends with '\0' aka a bytes with all bits 0

	char aLetter = 'a';
	char *pointerToALetter;


	int values[] = { 10,20,30,40 };
	char helloMsg[] = "Laboratory 04";

	printMessage("Laboratory 04");
	printMessage(helloMsg);

	//toUpper(helloMsg);

	char* upperHello = toUpperWithReturn(helloMsg);
	printMessage(helloMsg);
	printMessage(upperHello);

	printMessage("The end");

}