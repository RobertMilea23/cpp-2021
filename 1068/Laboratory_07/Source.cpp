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

	Order oder;
}