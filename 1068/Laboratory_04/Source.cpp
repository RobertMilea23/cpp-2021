#include <iostream>
using namespace std;

void toUpperCase(char* text);

void printArray(const int array[], int size) {
	cout << endl << "The array is:";
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
}

void printMessage(const char text[]) {
	cout << endl << text;
	//toUpperCase(text);
}

void toUpperCase(char* text) {
	for (int i = 0; i < strlen(text); i++) {
		//if (text[i] >= 'a' && text[i] <= 'z')
		if (text[i] >= 97 && text[i] <= 122) {
			text[i] -= 32;
		}
	}
}

char* toUpperCaseWithReturn(const char text[]) {

	//if (strlen(text) > 999) {
	//	return nullptr;
	//}

	//char newText[1000];
	char* newText = new char[strlen(text) + 1];

	strcpy_s(newText, strlen(text)+1, text);

	for (int i = 0; i < strlen(newText); i++) {
		if (newText[i] >= 'a' && newText[i] <= 'z') {
			newText[i] -= 32;
		}
	}

	return newText;
}

int main() {

	char helloMsg[] = "Laboratory 04";

	printMessage("Laboratory 04");
	printMessage(helloMsg);

	char aLetter = 'a';
	//char aLetter = 97;

	//char aMessage = "a";			//has a '\0' at the end - 0 byte value

	int values[] = { 10,20,30,40 };
	int noValues = 4;

	printArray(values, noValues);

	//toUpperCase(helloMsg);
	char* upperHello = nullptr;
	upperHello = toUpperCaseWithReturn(helloMsg);

	printMessage(helloMsg);
	printMessage(upperHello);

}