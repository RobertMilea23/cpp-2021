#include <iostream>
#include <string>
using namespace std;


class Product {
	char manufacturer[50] = "";
	char* name = nullptr;
	float price = 0;
	int* soldItemsEachMonth = nullptr;
	int noMonths = 0;
public:
	static int MIN_NAME_LENGTH;
	static float MIN_PRICE;
	static float LUXURY_LIMIT;
	static int NO_LUXURY_PRODUCTS;
public:
	Product(const char* name, float price, const int* soldItems, int noMonths, const char* manufacturer) {
		this->setName(name);
		this->setPrice(price);
		this->setData(soldItems, noMonths);
		this->setManufacturer(manufacturer);

		//if (this->price > Product::LUXURY_LIMIT) {
		//	Product::NO_LUXURY_PRODUCTS += 1;
		//}
	}

	Product(const char* name, float price, const char* manufacturer) {
		this->setName(name);
		this->setPrice(price);
		this->setManufacturer(manufacturer);

		//if (this->price > Product::LUXURY_LIMIT) {
		//	Product::NO_LUXURY_PRODUCTS += 1;
		//}
	}

	void setName(const char* newName) {

		if (newName == nullptr || strlen(newName) < MIN_NAME_LENGTH) {
			throw exception("Name too short or missing");
		}


		//avoid the memory leak
		if (this->name != nullptr) {
			delete[] this->name;
		}

		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}

	void setPrice(float newPrice) {
		if (newPrice < Product::MIN_PRICE) {
			throw exception("Wrong price");
		}

		if (this->price < Product::LUXURY_LIMIT && newPrice > Product::LUXURY_LIMIT) {
			Product::NO_LUXURY_PRODUCTS += 1;
		}

		if (this->price > Product::LUXURY_LIMIT && newPrice < Product::LUXURY_LIMIT) {
			Product::NO_LUXURY_PRODUCTS -= 1;
		}

		this->price = newPrice;
	}

	void setData(const int* data, int noMonths) {
		if (data == nullptr || noMonths == 0) {
			throw exception("No data");
		}

		//avoid the memory leak
		if (this->soldItemsEachMonth != nullptr) {
			delete[] this->soldItemsEachMonth;
		}

		this->soldItemsEachMonth = new int[noMonths];
		for (int i = 0; i < noMonths; i++) {
			this->soldItemsEachMonth[i] = data[i];
		}
		this->noMonths = noMonths;
	}

	void setManufacturer(const char* producer) {
		//this->manufacturer = new char[strlen(producer) + 1];

		int availableSpace = sizeof(this->manufacturer);
		if (strlen(producer) + 1 > availableSpace) {
			throw exception("Name is too long");
		}

		strcpy_s(this->manufacturer, strlen(producer) + 1, producer);
	}

	//class destructor
	~Product() {
		cout << endl << "Product destructor";

		if (this->name != nullptr) {
			delete[] this->name;
		}
		if (this->soldItemsEachMonth != nullptr) {
			delete[] this->soldItemsEachMonth;
		}

		if (this->price > Product::LUXURY_LIMIT) {
			Product::NO_LUXURY_PRODUCTS -= 1;
		}
	}
};

int Product::MIN_NAME_LENGTH = 3;
float Product::MIN_PRICE = 1;
float Product::LUXURY_LIMIT = 3000;
int Product::NO_LUXURY_PRODUCTS = 0;

int main() {

	int data[] = { 5,6,10,23 };
	int noMonths = 4;
	Product laptop("ASUS X1", 1400, data, 4, "Asus");
	Product smartphone("S22", 3800, "Samsung");

	//Product::NO_LUXURY_PRODUCTS += 1;

	char prodName[100];
	float prodPrice;
	char prodManufacturer[100];

	bool isValid = true;

	do {
		isValid = true;
		cout << endl << "The product name is ";
		cin >> prodName;

		if (strlen(prodName) < Product::MIN_NAME_LENGTH) {
			cout << endl << "Name to short !";
			isValid = false;
		}

		cout << endl << "The product price is ";
		cin >> prodPrice;

		if (prodPrice < Product::MIN_PRICE) {
			cout << endl << "Price is wrong";
			isValid = false;
		}
		cout << endl << "The product manufacturer is ";
		cin >> prodManufacturer;
	} while (!isValid);

	Product newProduct(prodName, prodPrice, prodManufacturer);

	laptop.setName("X21 Gaming");
	laptop.setName("X22 Gaming");
	
	Product* pointerToProduct = new Product("Test product", 10, "");
	delete pointerToProduct;

	cout << endl << "The end";
}