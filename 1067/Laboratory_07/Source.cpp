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
		cout << endl << "Discount name: " << this->convertDiscountToString(this->discount);
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

	void setName(string name) {
		if (name.length() >= 2) {
			this->name = name;
		}
		else {
			throw exception("Name too short");
		}
	}

	void setDescription(const char* description) {
		if (strlen(description) < 5) {
			throw exception("Description too short");
		}

		//we generate a memory leak if we have a previous description
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	void setPrice(float newPrice) {
		if (newPrice <= 0) {
			throw exception("Wrong price");
		}
		this->price = newPrice;
	}

	void setStock(int newStock) {
		if (newStock < 0) {
			throw exception("No negative stock");
		}
		this->stock = newStock;
		if (this->stock == 0) {
			this->isAvailable = false;
		}
		else {
			this->isAvailable = true;
		}
	}

	void setDiscount(DiscountType discountType) {
		this->discount = discountType;
	}

	void setMonthlySales(int* historicData, int noHistoricMonths) {
		if (historicData == nullptr) {
			throw exception("No input data");
		}

		//we generate another memory leak
		this->monthlySales = new int[noHistoricMonths];
		for (int i = 0; i < noHistoricMonths; i++) {
			this->monthlySales[i] = historicData[i];
		}

		//don't forget
		this->noMonths = noHistoricMonths;
	}

public:
	Product(string name, float price, int stock) {
		this->setName(name);
		this->setPrice(price);
		this->setStock(stock);
	}

	Product(string name, const char* description, float price, int stock) {
		this->setName(name);
		this->setDescription(description);
		this->setPrice(price);
		this->setStock(stock);
	}

	Product(string name, const char* description, float price, int stock, DiscountType discount) {
		this->setName(name);
		this->setDescription(description);
		this->setPrice(price);
		this->setStock(stock);
		this->setDiscount(discount);
	}

	Product(string name, const char* description, float price, int stock, int discountValue) {
		this->setName(name);
		this->setDescription(description);
		this->setPrice(price);
		this->setStock(stock);

		this->setDiscount(this->convertToDiscount(discountValue));
	}

	Product(string name, const char* description, float price, int stock, 
		DiscountType discount, int* backupData, int noPreviousMonths) {
		this->setName(name);
		this->setDescription(description);
		this->setPrice(price);
		this->setStock(stock);
		this->setDiscount(discount);
		this->setMonthlySales(backupData, noPreviousMonths);
	}

	Product() {
		this->name = "No name for the product";
	}

private:
	DiscountType convertToDiscount(int value) {
		switch (value)
		{
		case 10:
			return DiscountType::MINIMUM;
		case 20:
			return DiscountType::AVERAGE;
		case 50:
			return DiscountType::BLACK_FRIDAY;
		default:
			return DiscountType::NONE;
		}
	}

	string convertDiscountToString(DiscountType discount) {
		switch (discount) {
		case DiscountType::NONE:
			return "NONE";
		case DiscountType::MINIMUM:
			return "MINIMUM";
		case DiscountType::AVERAGE:
			return "AVERAGE";
		case DiscountType::BLACK_FRIDAY:
			return "Black Friday Special";
		default:
			return "Just a discount";
		}
	}

};

int main() {
	Product product;			//will use the default ctor
	product.printInfo();
	product.setDescription("This is a gaming laptop");
	product.printInfo();

	Product laptop("IBM Laptop", 1400, 50);
	laptop.printInfo();

	Product gamingLaptop("Asus M200", "Gaming laptop with 16 GB of RAM", 3500, 15);
	gamingLaptop.printInfo();

	Product blackFridayGamingLaptop("Asus M300", "Gaming laptop with 16 GB of RAM", 
		3700, 15, DiscountType::BLACK_FRIDAY);

	blackFridayGamingLaptop.printInfo();

	Product blackFridayGamingLaptop2("Asus M300", "Gaming laptop with 16 GB of RAM",
		3700, 15, 50);
	blackFridayGamingLaptop2.printInfo();

	int previousData[] = { 5, 10, 3, 8 };
	int noPreviousMonths = 4;
	
	Product superProduct("Smartphone", "The latest Samsung smartphone", 4800, 25,
		DiscountType::NONE, previousData, noPreviousMonths);
	superProduct.printInfo();
}