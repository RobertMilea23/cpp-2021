#include <iostream>
#include <string>
using namespace std;

//= with another operator, like object  = object + value
//* between objects or object and a value
//the index operator

class DailySalesInfo {
	string productName = "";
	char* productDescription = nullptr;
	const int codeBarNumber;
	int* noItemsPerDay = nullptr;
	int noDays = 0;
public:
	DailySalesInfo(string name, const char* description, int codeBar) : codeBarNumber(codeBar), productName(name) {
		//this->productDescription = description;

		this->productDescription = new char[strlen(description) + 1];
		strcpy_s(this->productDescription, strlen(description) + 1, description);

		//this->noItemsPerDay = nullptr;
		//this->noDays = 0;
	}

	~DailySalesInfo() {
		delete[] this->noItemsPerDay;
		delete[] this->productDescription;
	}

	DailySalesInfo(const DailySalesInfo& object): codeBarNumber(object.codeBarNumber) {
		this->productName = object.productName;

		this->productDescription = new char[strlen(object.productDescription) + 1];
		strcpy_s(this->productDescription, strlen(object.productDescription) + 1, object.productDescription);

		this->noItemsPerDay = new int[object.noDays];
		for (int i = 0; i < object.noDays; i++) {
			this->noItemsPerDay[i] = object.noItemsPerDay[i];
		}
		this->noDays = object.noDays;
	}

	DailySalesInfo(): codeBarNumber(0) {
		this->productName = "No name";
		this->productDescription = nullptr;
		this->noItemsPerDay = 0;
	}

	void operator=(const DailySalesInfo& object2) {

		cout << endl << "Calling operator =";

		//only when operator = receives a reference
		if (this == &object2) {
			cout << endl << "Is the same object";
			return;
		}

		//this->codeBarNumber = object2.codeBarNumber;

		//this->productDescription = object2.productDescription;

		//for operator = that receives the object by value
		if (this->productDescription == object2.productDescription) {
			//the same object
			return;
		}

		this->productName = object2.productName;

		delete[] this->productDescription;
		this->productDescription = new char[strlen(object2.productDescription) + 1];
		strcpy_s(this->productDescription, strlen(object2.productDescription) + 1, object2.productDescription);

		delete[] this->noItemsPerDay;
		this->noItemsPerDay = new int[object2.noDays];
		for (int i = 0; i < object2.noDays; i++) {
			this->noItemsPerDay[i] = object2.noItemsPerDay[i];
		}

		this->noDays = object2.noDays;
	}

	DailySalesInfo operator+(int value) {
		DailySalesInfo result = *this;

		int* newArray = new int[result.noDays + 1];
		for (int i = 0; i < result.noDays; i++) {
			newArray[i] = result.noItemsPerDay[i];
		}
		newArray[this->noDays] = value;

		delete[] result.noItemsPerDay;
		result.noItemsPerDay = newArray;

		result.noDays += 1;

		return result;

	}

	DailySalesInfo operator*(int value) {
		DailySalesInfo copy = *this;
		for (int i = 0; i < copy.noDays; i++) {
			copy.noItemsPerDay[i] *= value;
		}
		return copy;
	}

	int& operator[](int index) {
		if (index < 0 || index >= this->noDays) {
			throw exception("Wrong index");
		}
		return this->noItemsPerDay[index];
	}

};



int main() {

	DailySalesInfo laptop("Laptop", "Gaming laptop with 8 GB of RAM", 11231);
	DailySalesInfo generic("Generic product", "Test", 20);

	DailySalesInfo laptopClone = laptop;			//is not =, is the copy constructor

	DailySalesInfo* newProduct = new DailySalesInfo("Some product", "Testing product", 1);
	delete newProduct;
	DailySalesInfo* listOfProducts = new DailySalesInfo[5];

	DailySalesInfo smartphone("Phone", "Smartphone", 222555);

	smartphone = laptop;				//operator=(DailySalesInfo, DailySalesInfo)	

	//smartphone = laptop = generic;

	smartphone = generic;
	laptop = generic;

	smartphone = smartphone;


	smartphone = smartphone + 10;

	smartphone = smartphone * 2;

	int salesFrom1stDay = smartphone[0];
	smartphone[0] = 26;

}