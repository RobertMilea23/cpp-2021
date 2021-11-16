#include <iostream>
#include <string>
#include <exception>
using namespace std;



class Product {
	char* name = nullptr;
	char manufacturer[50] = "";
	float price = 0;
	int* soldItemsPerMonth = nullptr;
	int noMonths = 0;
public:
	static int MIN_NAME_LENGTH;
	static float MIN_PRICE;
	static float LUXURY_LIMIT;
	static int NO_LUXURY_PRODUCTS;
public:
	Product(const char* name, const char* manufacturer, float price, const int* previousData, int noRecords) {
		this->setName(name);
		this->setManufacturer(manufacturer);
		this->setPrice(price);
		this->setData(previousData, noRecords);

		//if (this->price > Product::LUXURY_LIMIT) {
		//	Product::NO_LUXURY_PRODUCTS += 1;
		//}
	}

	Product(const char* name, const char* manufacturer, float price) {
		this->setName(name);
		this->setManufacturer(manufacturer);
		this->setPrice(price);

		//if (this->price > Product::LUXURY_LIMIT) {
		//	Product::NO_LUXURY_PRODUCTS += 1;
		//}
	}

	void setName(const char* newName){
		if (newName == nullptr || strlen(newName) < Product::MIN_NAME_LENGTH) {
			throw exception("Name missing or is too short");
		}
		else {

			//avoid the memory leak
			if (this->name != nullptr) {
				delete[] this->name;
			}

			this->name = new char[strlen(newName) + 1];
			strcpy_s(this->name, strlen(newName) + 1, newName);
		}
	}

	void setManufacturer(const char* newProducer) {
		if (newProducer == nullptr || strlen(newProducer) < MIN_NAME_LENGTH) {
			throw exception("Manufacturer is missing or is too short");
		}
		else {
			strcpy_s(this->manufacturer, strlen(newProducer) + 1, newProducer);
		}
	}

	void setPrice(float newPrice) {
		if (newPrice < Product::MIN_PRICE) {
			throw exception("Wrong price");
		}
		else {

			if (this->price < Product::LUXURY_LIMIT && newPrice > LUXURY_LIMIT) {
				Product::NO_LUXURY_PRODUCTS += 1;
			}


			if (this->price > Product::LUXURY_LIMIT && newPrice < LUXURY_LIMIT) {
				Product::NO_LUXURY_PRODUCTS -= 1;
			}

			this->price = newPrice;
		}
	}

	void setData(const int* previousData, int noRecords) {

		//avoid the memory leak
		if (this->soldItemsPerMonth != nullptr) {
			delete[] this->soldItemsPerMonth;
		}

		this->soldItemsPerMonth = new int[noRecords];
		for (int i = 0; i < noRecords; i++) {
			this->soldItemsPerMonth[i] = previousData[i];
		}
		this->noMonths = noRecords;
	}

	//class destructor
	~Product() {
		cout << endl << "The Product destructor !";

		if (this->name != nullptr) {
			delete[] this->name;
		}

		if (this->soldItemsPerMonth != nullptr) {
			delete[] this->soldItemsPerMonth;
		}

		if (this->price > Product::LUXURY_LIMIT) {
			Product::NO_LUXURY_PRODUCTS -= 1;
		}
	}
};

float Product::MIN_PRICE = 1;
int Product::MIN_NAME_LENGTH = 3;
float Product::LUXURY_LIMIT = 10000;
int Product::NO_LUXURY_PRODUCTS = 0;

int main() {
	cout << endl << "Minimum length for the name is " << Product::MIN_NAME_LENGTH;

	int previousData[] = { 5,23,10,7 };
	int noMonths = 4;

	Product laptop("X21 Gaming", "ASUS", 2400, previousData, noMonths);
	Product smartphone("S2000", "Samsung", 34000);

	char name[100];
	char manufacturer[100];
	float price;

	bool isValid = true;

	do {
		isValid = true;

		cout << endl << "Product price: ";
		cin >> price;
		if (price < Product::MIN_PRICE) {
			cout << endl << "Wrong price";
			isValid = false;
		}
		cout << endl << "Product name: ";
		cin >> name;
		if (strlen(name) < Product::MIN_NAME_LENGTH) {
			cout << endl << "Wrong name";
			isValid = false;
		}
		cout << endl << "Product manufacturer: ";
		cin >> manufacturer;
	} while (!isValid);

	Product newProduct(name, manufacturer, price);

	Product* pointerToProduct = new Product("Test product", "Test", 1000);
	delete pointerToProduct;

	cout << endl << "After deleting test product";

	laptop.setName("X22 Gaming");
	laptop.setName("X_22 Gaming");

	cout << endl << "The number of Luxury products is " << Product::NO_LUXURY_PRODUCTS;

}