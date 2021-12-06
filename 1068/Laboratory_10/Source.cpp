#include <iostream>
#include <string>
using namespace std;

class DailySalesData {
	string productName = "";
	char* productDescription = nullptr;
	const int barCodeNumber;

	int* itemsPerDay = nullptr;
	int noDays = 0;

public:

	//constructor
	DailySalesData(string name, const char* description, int barCode)
		: barCodeNumber(barCode), productName(name) {
		//this->productName = name;

		//redundant - it will use the default from the definition
		//this->noDays = 0;

		//don't do the shallow copy
		//this->productDescription = description;

		this->productDescription = new char[strlen(description) + 1];
		strcpy_s(this->productDescription, strlen(description) + 1, description);
	}

	//default constructor
	DailySalesData(): barCodeNumber(0) {
		//we can reuse the default values from the definition

		//redundant if you have your own defaults in the definition
		//mandatory if you didn't use default values in the definition
		//this->noDays = 0;
		//this->itemsPerDay = nullptr;
		//this->productDescription = nullptr;
	}

	//destructor
	~DailySalesData() {
		cout << endl << "The class destructor";
		delete[] this->productDescription;
		delete[] this->itemsPerDay;
	}


	//copy constructor
	DailySalesData(const DailySalesData& object) :barCodeNumber(object.barCodeNumber) {
		this->productName = object.productName;
		//don't do the shallow copy
		//this->productDescription = object.productDescription;

		this->productDescription = new char[strlen(object.productDescription) + 1];
		strcpy_s(this->productDescription, strlen(object.productDescription) + 1, object.productDescription);

		this->itemsPerDay = new int[object.noDays];
		for (int i = 0; i < object.noDays; i++) {
			this->itemsPerDay[i] = object.itemsPerDay[i];
		}
		this->noDays = object.noDays;
	}

	//operator =
};

//operator +
//operator *
//operator []
//cast operator

int main() {
	DailySalesData laptopData("Laptop", "Gaming laptop with 8 GB of RAM", 224589);

	DailySalesData* newObject = new DailySalesData("Smartphone", "Some smartphone", 23);
	delete newObject;

	DailySalesData* productsData = new DailySalesData[5];

	DailySalesData laptopCopy = laptopData;

	cout << endl << "The end of the example";

}