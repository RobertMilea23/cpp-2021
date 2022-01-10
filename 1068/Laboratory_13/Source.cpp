#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//try-catch mechanism
//"is a" relation  - inheritance
//files - reading from text files

class NegativePriceException: public exception {
public:
	NegativePriceException(string msg): exception(msg.c_str()) {

	}
	NegativePriceException() {

	}
};

class PriceTooBigException : public exception {

};

class Product {
protected:
	string name = "No name";
	float price = 0;
public:

	static const int MIN_PRICE = 0;
	static int MAX_PRICE;

	Product() {

	}
	Product(string Name, float Price) {
		this->name = Name;
		this->price = Price;
	}

	void setPrice(float Price) {
		if (Price < MIN_PRICE) {
			throw NegativePriceException("The price is negative");
		}
		if (Price > MAX_PRICE) {
			throw PriceTooBigException();
		}
		this->price = Price;
	}

	void printInfo() {
		cout << endl << this->name << " has a price of " << this->price;
	}

	void setName(string Name) {
		if (Name.length() < 2) {
			throw exception();
		}
		this->name = Name;
	}
};

int Product::MAX_PRICE = 100000;

class GroceryProduct: public Product {
	string expirationDate = "no expiration date";
	float weight = 0;
public:
	GroceryProduct():Product("",0) {

	}

	//GroceryProduct(string expDate, float weight): Product("No name",0) {
	//	this->expirationDate = expDate;
	//	this->weight = weight;
	//}

	GroceryProduct(string name, float price, string expirationDate, float weight): Product(name, price) {
		//this->name = name;
		//this->price = price;
		this->expirationDate = expirationDate;
		this->weight = weight;
	}

	static void loadListFromFile(string fileName, GroceryProduct*& list, int& noProducts) {
		ifstream inputFile(fileName, ios::in);
		if (!inputFile.is_open()) {
			cout << endl << "File is not there: " << fileName;
		}
		else {
			inputFile >> noProducts;
			cout << endl << "No products from file: " << noProducts;

			if (list != nullptr) {
				delete[] list;
			}

			list = new GroceryProduct[noProducts];
			for (int i = 0; i < noProducts; i++) {
				string name;
				inputFile >> name;
				list[i].name = name;

				inputFile >> list[i].price;
				inputFile >> list[i].expirationDate;
				inputFile >> list[i].weight;
			}

			inputFile.close();
		}
	}
};

int main() {
	Product p1;
	p1.printInfo();

	Product p2("Laptop", 2500);
	p2.printInfo();

	bool isOk = false;

	while (!isOk) {
		try {
			float price;
			cout << endl << "Give us a price: ";
			cin >> price;
			p1.setPrice(price);
			string name;
			cout << endl << "Give us a name: ";
			cin >> name;
			p1.setName(name);
			p1.printInfo();
			isOk = true;
		}
		catch (NegativePriceException ex) {
			cout << endl << "Wrong value " << ex.what();
		}
		catch (PriceTooBigException ex) {
			cout << endl << "Price is too big";
		}
		catch (...) {
			cout << endl << "Houston we have a problem !";
		}
	}

	cout << endl << "--------------- Grocery section ----------";
	GroceryProduct gp1;
	gp1.printInfo();

	GroceryProduct apples("Apples", 5.2, "March 1, 2022", 1000);
	apples.printInfo();

	//reading a list of GroceryProducts from a text file
	GroceryProduct* list = nullptr;
	int noProducts = 0;

	GroceryProduct::loadListFromFile("ProductsList.txt", list, noProducts);

	for (int i = 0; i < noProducts; i++) {
		list[i].printInfo();
	}


}