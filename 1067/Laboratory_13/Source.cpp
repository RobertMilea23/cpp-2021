#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class PriceException : public exception {
public:
	PriceException(string msg): exception(msg.c_str()) {

	}
};

class PriceTooBigException : public exception {

};

class Product {
protected:
	string name = "";
	float price = 0;
public:

	static const int MIN_PRICE = 0;
	static int MAX_PRICE;

	Product() :name("No name"), price(0) {

	}
	Product(string Name, float Price) {
		this->name = Name;
		this->price = Price;
	}

	void setPrice(float Price) {
		if (Price < Product::MIN_PRICE) {
			throw PriceException("Price is too low");
		}

		if (Price > Product::MAX_PRICE) {
			throw PriceTooBigException();
		}

		this->price = Price;
	}

	void printInfo() {
		cout << endl << "The product " << this->name << " has a price of " << this->price;
	}
};

int Product::MAX_PRICE = 100000;

//the "is-a" relation aka inheritance
class GroceryProduct : public Product {
	string expirationDate = "";
	float weight = 0;
public:
	GroceryProduct(): Product("No name for grocery product", 0) {
		this->expirationDate = "for ever";
	}
	//GroceryProduct(string expirationDate, float weight): Product("",0) {
	//	this->expirationDate = expirationDate;
	//	this->weight = weight;
	//}
	GroceryProduct(string name, float price, string expirationDate, float weight): Product(name, price) {
		//this->name = name;
		//this->price = price;
		this->expirationDate = expirationDate;
		this->weight = weight;
	}


	//GroceryList loadData(string fileName) {}
	static void loadData(string fileName, GroceryProduct*& list, int& noProducts) {
		//1 create the file object
		ifstream inputFile(fileName, ios::in);
		if (!inputFile.is_open()) {
			cout << endl << "************ There is no file there " << fileName;
		}
		else {
			//read the 1st line - number of products
			inputFile >> noProducts;
			cout << endl << "No of products " << noProducts;

			//create the array
			if (list != nullptr) {
				delete[] list;
			}
			list = new GroceryProduct[noProducts];

			for (int i = 0; i < noProducts; i++) {
				string name;
				inputFile >> name;
				float price;
				inputFile >> price;
				string expirationDate;
				inputFile >> expirationDate;
				float weight;
				inputFile >> weight;
				list[i].name = name;
				list[i].price = price;
				list[i].expirationDate = expirationDate;
				list[i].weight = weight;
			}
			inputFile.close();
		}
	}
};

class GroceryList {
public:
	GroceryProduct* groceriesList;
	int noProducts;

	//TO DO
	//overload Copy Constructor
	//overload =
	//implement destructor
	//overload + or += to add new products | define a addProduct()
};


int main() {
	Product p1;
	p1.printInfo();
	Product p2("Laptop", 2300);
	p2.printInfo();

	try {
		float price;
		cout << endl << "Give me a price for p1: ";
		cin >> price;
		p1.setPrice(price);
		p1.printInfo();
	}
	catch (PriceException ex) {
		cout << endl << "Issue with the price: " << ex.what();
	}
	catch (PriceTooBigException ex) {
		cout << endl << "Price is too big";
	}
	catch (...) {
		cout << endl << "Houston we have a problem !";
	}

	bool isFinished = false;
	while (!isFinished) {
		try {
			float price;
			cout << endl << "Give me another price for p1: ";
			cin >> price;
			p1.setPrice(price);
			isFinished = true;
		}
		catch (PriceException ex) {
			cout << endl << "Give me a correct value";
		}
	}

	p1.printInfo();

	cout << endl << "------------ GroceryProduct --------------";

	GroceryProduct gp1;
	gp1.printInfo();

	GroceryProduct* groceriesList = nullptr;
	int noProducts = 0;

	GroceryProduct::loadData("List.txt", groceriesList, noProducts);
	for (int i = 0; i < noProducts; i++) {
		groceriesList[i].printInfo();
	}

}