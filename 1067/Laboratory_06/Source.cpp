#include <iostream>
#include <string>

class Product {
private:
	std::string name;
	char* description;
	float price;
public:

	Product(std::string name, float price) {
		this->name = name;
		this->price = price;
	}

	std::string getName() {
		return this->name;
	}
	float getPrice() {
		return this->price;
	}
	char* getDescription() {
		//don't
		//return this->description;

		char* copy = new char[strlen(this->description) + 1];
		strcpy_s(copy, strlen(this->description) + 1, this->description);
		return copy;
	}

	void setPrice(float newPrice) {
		if (newPrice / this->price > 1.5 || newPrice / this->price < 0.5) {
			throw std::exception("Wrong new price");
		}

		this->price = newPrice;
	}

};

void resizeExistingArray(int* existingArray, int noElements, int newNoElements) {
	//do you need the previous values ?
	//no
	//existingArray = new int[newNoElements];

	//yes
	//1 create a new array with the new size
	int* temp = new int[newNoElements];

	//copy existing values
	for (int i = 0; i < noElements; i++) {
		temp[i] = existingArray[i];
	}

	//delete existing
	delete[] existingArray;

	//init the pointer with the new address
	existingArray = temp;
}

void resizeExistingArrayOk(int* *pointerToTheDynamicArray, int* pointertoNoElements, int newNoElements) {
	//do you need the previous values ?

	//yes
	//1 create a new array with the new size
	int* temp = new int[newNoElements];

	//copy existing values
	for (int i = 0; i < *pointertoNoElements; i++) {
		temp[i] = (*pointerToTheDynamicArray)[i];
	}

	//delete existing
	delete[](*pointerToTheDynamicArray);

	//init the pointer with the new address
	(*pointerToTheDynamicArray) = temp;

	//change the array size
	*pointertoNoElements = newNoElements;
}

void resizeExistingArrayWithReferences(int* &existingArray, int &noElements, int newNoElements) {
	//do you need the previous values ?
	//no
	//existingArray = new int[newNoElements];

	//yes
	//1 create a new array with the new size
	int* temp = new int[newNoElements];

	//copy existing values
	for (int i = 0; i < noElements; i++) {
		temp[i] = existingArray[i];
	}

	//delete existing
	delete[] existingArray;

	//init the pointer with the new address
	existingArray = temp;

	//change the array size
	noElements = newNoElements;
}


int main() {

	//they exist on this function stack
	int anotherStaticArray[5];
	int staticArray[] = { 10,20,30 };

	//1. define the pointer to the 1st value in the array
	int* dynamicArray = nullptr;
	int noElements = 0;

	//2. create the array in HEAP
	dynamicArray = new int[5];		//by default the values are 0xCDCD....
	noElements = 5;

	//3. init the values
	for (int i = 0; i < noElements; i++) {
		dynamicArray[i] = i+1;
	}

	std::cout << std::endl << "The address of the initial array is " << dynamicArray;

	//recreate the dynamic array
	//do you need the previous values ???

	//for no
	//dynamicArray = new int[10];
	
	//for yes
	int* tempArray = new int[10];
	//copy the values from the old one
	for (int i = 0; i < noElements; i++) {
		tempArray[i] = dynamicArray[i];
	}

	//delete the old array
	delete[] dynamicArray;
	dynamicArray = tempArray;

	std::cout << std::endl << "The address of the array is " << dynamicArray;

	//with the function
	//resizeExistingArray(dynamicArray, noElements, 20);
	//noElements = 20;

	//resizeExistingArrayOk(&dynamicArray, &noElements, 20);
	resizeExistingArrayWithReferences(dynamicArray, noElements, 20);

	std::cout << std::endl << "The new address of the array is " << dynamicArray;

	std::cout << std::endl << "The new array is: ";
	for (int i = 0; i < noElements; i++) {
		std::cout << dynamicArray[i] << " ";
	}


	Product p("Laptop", 1000);
	p.setPrice(900);
	//you force others to validate the new price
	// 
	//p.setPrice(1);
}