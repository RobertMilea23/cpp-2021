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