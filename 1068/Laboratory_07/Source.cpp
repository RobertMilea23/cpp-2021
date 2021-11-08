#include <iostream>
#include <string>
using namespace std;

enum UserType {ADMIN = 1, MANAGER, CLIENT = 50};
enum DiscountType {NONE, MINIMUM = 10, AVERAGE = 15, BLACK_FRIDAY = 50};

class Product {
	string name = "";
	char* description = nullptr;
	float price = 0;
	int availableStock = 0;
	DiscountType discount = DiscountType::NONE;
	bool isAvailable = false;

	int* monthlySoldItems = nullptr; //items sold each month since we open the shop or we added the Product
	int noMonths = 0;

public:
	string getName() {
		return this->name;
	}

	int* getMonthlySoldItems() {
		//don't
		//return this->monthlySoldItems;

		if (this->monthlySoldItems == nullptr && this->noMonths == 0) {
			return nullptr;
		}

		int* dataCopy = new int[this->noMonths];
		for (int i = 0; i < this->noMonths; i++) {
			dataCopy[i] = this->monthlySoldItems[i];
		}
		return dataCopy;
	}

	int getNoMonths() {
		return this->noMonths;
	}

	int getStock() {
		return this->availableStock;
	}

	bool IsAvailable() {
		return this->isAvailable;
	}

	void printInfo() {
		cout << endl << " ---------------------- ";
		cout << endl << "Name: " << this->name;
		if (this->description != nullptr) {
			cout << endl << "Description: " << this->description;
		}
		else {
			cout << endl << "No available description";
		}
		cout << endl << "Price: " << this->price;
		cout << endl << "Stock: " << this->availableStock;
		cout << endl << "Discount: " << this->discount << "%";
		cout << endl << (this->isAvailable ? "Is available" : "You can make a pre-order");
		if (this->monthlySoldItems != nullptr) {
			cout << endl << "Previous sold items: ";
			for (int i = 0; i < this->noMonths; i++) {
				cout << this->monthlySoldItems[i] << " ";
			}
		}
	}

	void setName(string name) {
		if (name.length() < 2) {
			throw exception("Wrong name. Too short");
		}
		this->name = name;
	}

	void setPrice(float newPrice) {
		if (newPrice <= 0) {
			throw exception("Price value not ok");
		}
		this->price = newPrice;
	}

	void setDescription(const char* newDescription) {
		if (strlen(newDescription) < 5) {
			throw exception("Description too short");
		}

		//don't do this
		//this->description = newDescription;

		//here we are generating a memory leak
		this->description = new char[strlen(newDescription) + 1];
		strcpy_s(this->description, strlen(newDescription) + 1, newDescription);
	}

	void setStock(int newStock) {
		if (newStock < 0) {
			throw exception("Wrong value. Negative stock");
		}
		this->availableStock = newStock;
		if (this->availableStock == 0) {
			this->isAvailable = false;
		}
		else {
			this->isAvailable = true;
		}
	}

	void setDiscount(DiscountType discount) {
		this->discount = discount;
	}

	void setPreviousMonthsValues(const int* backupData, int noValues) {
		if (backupData == nullptr) {
			throw exception("No input values");
		}

		//we generate another memory leak
		this->monthlySoldItems = new int[noValues];
		for (int i = 0; i < noValues; i++) {
			this->monthlySoldItems[i] = backupData[i];
		}

		//don't forget
		this->noMonths = noValues;
	}

public:
	Product(string name, float price, int stock) {
		this->setName(name);
		this->setPrice(price);
		this->setStock(stock);
	}

	Product(string name, const char* description, float price, int stock) {
		this->setName(name);
		this->setPrice(price);
		this->setStock(stock);
		this->setDescription(description);
	}

	Product(string name, const char* description, float price, int stock, DiscountType discount) {
		this->setName(name);
		this->setPrice(price);
		this->setStock(stock);
		this->setDescription(description);
		this->setDiscount(discount);
	}

	Product(string name, const char* description, float price, int stock, 
		DiscountType discount, const int* previousData, int noMonths) {
		this->setName(name);
		this->setPrice(price);
		this->setStock(stock);
		this->setDescription(description);
		this->setDiscount(discount);
		this->setPreviousMonthsValues(previousData, noMonths);
	}

	Product() {
		this->name = "No product name";
	}

};

class User {
	string userName;
	string passWord;

	//int numericType; //1 is admin, 2 is manager, 3 is marketing, 4 is client
	//string stringType; //"admin", "manager", "marketing", "client", "ADMIN", "Admin"
	UserType type;
};

class ShoppingCart {

};

class Order {

};

int main() {
	Product product;
	Product anotherProduct;

	product.printInfo();

	product.setName("Laptop");
	product.setDescription("Gaming laptop");
	product.setPrice(3500);
	product.setStock(15);
	product.setDiscount(DiscountType::BLACK_FRIDAY);

	product.printInfo();

	Product laptop("Asus M300", 3500, 25);
	laptop.printInfo();

	Product gamingLaptop("Asus M500", "Gaming laptop with 16 GB RAM", 4200, 10);
	gamingLaptop.printInfo();

	Product blackFridayLaptop("Asus M500", "Gaming laptop with 16 GB RAM", 
		4200, 10, DiscountType::BLACK_FRIDAY);
	blackFridayLaptop.printInfo();

	int previousData[] = { 6,10,20,12 };
	int noValues = 4;

	Product smartphone("X34", "The best smartphone", 2500, 16, DiscountType::MINIMUM, previousData, noValues);
	smartphone.printInfo();

}