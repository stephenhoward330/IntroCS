#include <iostream>
#include <string>
#include <iomanip>
#include "ItemToPurchase.h"

using namespace std;

ItemToPurchase::ItemToPurchase(string resItemName, string resItemDescription, double resItemPrice, int resItemQuantity) {
	itemName = resItemName;
	itemDescription = resItemDescription;
	itemPrice = resItemPrice;
	itemQuantity = resItemQuantity;
}

void ItemToPurchase::SetName(string name) {
	itemName = name;
	return;
}
void ItemToPurchase::SetDescription(string description) {
	itemDescription = description;
	return;
}
void ItemToPurchase::SetPrice(double price) {
	itemPrice = price;
	return;
}
void ItemToPurchase::SetQuantity(int quantity) {
	itemQuantity = quantity;
	return;
}

string ItemToPurchase::GetName() const {
	return itemName;
}
string ItemToPurchase::GetDescription() const {
	return itemDescription;
}
double ItemToPurchase::GetPrice() const {
	return itemPrice;
}
int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}

void ItemToPurchase::PrintCost() const {
	const int PRECISION = 2;

	cout << fixed << setprecision(PRECISION) << GetName() << " " << GetQuantity() << " @ $" << GetPrice()
		<< " = $" << GetPrice() * GetQuantity() << endl;
}
void ItemToPurchase::PrintDescription() const {
	cout << GetName() << ": " << GetDescription() << endl;
}