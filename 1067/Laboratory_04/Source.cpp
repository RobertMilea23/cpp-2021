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
	if (strlen(text) > 999) {
		cout << endl << "The input array is too big !";
		return nullptr;
	}
	char newValue[1000];
	//strcpy(newValue, text);
	strcpy_s(newValue, text);
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] >= 'a' && text[i] <= 'z') {
			newValue[i] -= 32;
		}
	}
	return newValue;
}



void printMessage(const char message[]) {
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

	char helloMsg[] = "Laboratory 04";

	printMessage("Laboratory 04");
	printMessage(helloMsg);

	//toUpper(helloMsg);

	char* upperHello = toUpperWithReturn(helloMsg);
	printMessage(helloMsg);
	printMessage(upperHello);

	printMessage("The end");

}