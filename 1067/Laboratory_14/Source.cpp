#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
	string description = "No description";
	float price = 0;
public:
	Product() {
		cout << endl << "Product default ctor";
	}
	Product(string Description, float Price) {
		this->description = Description;
		this->price = Price;
	}

	virtual void printDescription() {
		cout << endl << "Product: " << this->description << " with price " << this->price;
	}

	float getPrice() {
		return this->price;
	}
};

class ProductWithDiscount: public Product{
	float discountPercent;

	float getPrice() {
		return this->price - (this->price * this->discountPercent / 100);
	}
};

class Toy: public Product {
	int minAge;
public:
	Toy() {
		cout << endl << "Toy default ctor";
	}
	Toy(string Description, float Price, int MinAge): Product(Description, Price) {
		this->minAge = MinAge;
		//this->description = Description;
	}

	//override the parent method
	void printDescription() {
		cout << endl << "Toy: " << this->description << "with price "
			<< this->price << " for kids above " << this->minAge;
	}
};

class Monitor : public Product {
protected:
	int diagonal;
public:
	Monitor() {
		cout << endl << "Monitor default ctor";
	}
	Monitor(string Description, float Price, int Diagonal)
		: Product(Description, Price), diagonal(Diagonal) {
	}

	void printDescription() {
		//call the parent version of the method
		this->Product::printDescription();
		cout << endl << "It's a monitor with a diagonal of " << this->diagonal;
	}
};

class TouchScreen : public Monitor {
	float sensitivity;
public:
	TouchScreen() {
		cout << endl << "TouchScreen default ctor";
	}
	TouchScreen(string Description, float Price, int Diagonal, float Sensitivity)
	: Monitor(Description, Price, Diagonal){
		this->sensitivity = Sensitivity;
	}

	void printDescription() {
		cout << endl << "TouchScreen " << this->description << " with sensitivity of " << this->sensitivity;
	}
};


int main() {
	Product p("Pepsi",2.5);
	Toy t("Doll",35, 5);
	Monitor m("Dell",500,19);
	TouchScreen ts("Dell Touch", 900, 21, 0.7);

	//upcasting at object level
	p = ts;
	//upcasting at pointer level
	Product* productPointer = &p;
	productPointer = &ts;

	//managing everything together
	Product* products[5];

	Product** listOfProducts;
	listOfProducts = new Product* [5];

	int noProducts = 5;

	products[0] = &p;
	products[1] = &t;
	products[2] = &m;
	products[3] = &ts;
	products[4] = new TouchScreen("Samsung screen", 1200, 24, 0.9);

	listOfProducts[0] = &p;
	listOfProducts[1] = &t;
	listOfProducts[2] = &m;
	listOfProducts[3] = &ts;
	listOfProducts[4] = new Toy("RC Plane", 560, 10);


	for (int i = 0; i < noProducts; i++) {
		products[i]->printDescription();		//EARLY - BINDING
												//LATE - BINDING with virtual methods
	}

	cout << endl << "---------------------------";

	t.printDescription();
	ts.printDescription();


}