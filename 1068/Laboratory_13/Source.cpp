#include<iostream>
#include<string>

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
};

int Product::MAX_PRICE = 100000;

int main() {
	Product p1;
	p1.printInfo();

	Product p2("Laptop", 2500);
	p2.printInfo();
}