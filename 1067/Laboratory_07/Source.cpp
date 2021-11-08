#include <iostream>
#include <string>
using namespace std;

enum UserType {ADMIN = 1, NORMAL};

class ShoppingCart {

};

class UserAccount {
	string userName;
	string password;
	//int userType;	//1 is admin, 2 is normal user
	//string type; //"admin", "normal", "ADMIN", "Admin"
	UserType type;
};

class Order {

};

enum DiscountType {NONE, MINIMUM = 10, AVERAGE = 20, BLACK_FRIDAY = 50};

class Product {
	string name = "";
	char* description = nullptr;
	float price = 0;
	int stock = 0;
	DiscountType discount = DiscountType::NONE;
	bool isAvailable = false;

	int* monthlySales = nullptr;		//the quantity sold each month
	int noMonths = 0;

public:
	void printInfo() {
		cout << endl << "-----------------------";
		cout << endl << "Name: " << this->name;
		if (this->description != nullptr) {
			cout << endl << "Description: " << this->description;
		}
		cout << endl << "Price: " << this->price;
		cout << endl << "Available stock: " << this->stock;
		cout << endl << "Discount: " << this->discount << "%";
		cout << endl << (this->isAvailable ? "Is available" : "You can place a reservation");
		if (this->noMonths > 0) {
			cout << endl << "Products sold each month";
			for (int i = 0; i < this->noMonths; i++) {
				cout << this->monthlySales[i] << " ";
			}
		}
	}

	bool IsAvailable() {
		return this->isAvailable;
	}

	string getName() {
		return this->name;
	}

	int getNoMonths() {
		return this->noMonths;
	}

	int* getMonthlySales() {
		//return this->monthlySales;
		if (this->noMonths == 0) {
			return nullptr;
		}
		int* copy = new int[this->noMonths];
		for (int i = 0; i < this->noMonths; i++) {
			copy[i] = this->monthlySales[i];
		}
		return copy;
	}

	DiscountType getDiscount() {
		return this->discount;
	}


};

int main() {
	Product product;			//will use the default ctor
	product.printInfo();
}