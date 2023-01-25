#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "ItemToPurchase.h"

using namespace std;

int main() {
	string name;
	double price;
	int quantity;
	ItemToPurchase item1;
	ItemToPurchase item2;

	cout << "Item 1" << endl;
	cout << "Enter the item name: ";
	getline(cin, name);
	item1.SetName(name);
	cout << endl << "Enter the item price: ";
	cin >> price;
	item1.SetPrice(price);
	cout << endl << "Enter the item quantity: ";
	cin >> quantity;
	item1.SetQuantity(quantity);
	cout << endl << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Item 2" << endl;
	cout << "Enter the item name: ";
	getline(cin, name);
	item2.SetName(name);
	cout << endl << "Enter the item price: ";
	cin >> price;
	item2.SetPrice(price);
	cout << endl << "Enter the item quantity: ";
	cin >> quantity;
	item2.SetQuantity(quantity);
	cout << endl << endl;

	cout << "TOTAL COST" << endl;
	cout << fixed << setprecision(2) << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice()
		<< " = $" << item1.GetPrice() * item1.GetQuantity() << endl;
	cout << fixed << setprecision(2) << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice()
		<< " = $" << item2.GetPrice() * item2.GetQuantity() << endl << endl;
	cout << "Total: $" << (item1.GetPrice() * item1.GetQuantity()) + (item2.GetPrice() * item2.GetQuantity()) << endl;

	return 0;
}