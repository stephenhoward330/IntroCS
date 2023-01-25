#include <iostream>
#include <string>
#include <iomanip>
#include "ShoppingCart.h"

using namespace std;

ShoppingCart::ShoppingCart(string resName, string resDate) {
	customerName = resName;
	date = resDate;
}

string ShoppingCart::GetName() const {
	return customerName;
}
string ShoppingCart::GetDate() const {
	return date;
}

void ShoppingCart::AddItem(ItemToPurchase newItem) {
	for (int i = 0; i < items.size(); i++) {
		if (newItem.GetName() == items.at(i).GetName()) {
			cout << "Item is already in cart. Nothing added." << endl;
			return;
		}
	}

	items.push_back(newItem);
	return;
}
void ShoppingCart::RemoveItem(string removeItem) {
	for (int i = 0; i < items.size(); i++) {
		if (removeItem == items.at(i).GetName()) {
			items.erase(items.begin() + i);
			cout << endl;
			return;
		}
	}

	cout << "Item not found in cart. Nothing removed." << endl << endl;
	return;
}
void ShoppingCart::UpdateItemQuantity(string itemName, int updateQuantity) {
	for (int i = 0; i < items.size(); i++) {
		if (itemName == items.at(i).GetName()) {
			items.at(i).SetQuantity(updateQuantity);
			cout << endl;
			return;
		}
	}

	cout << "Item not found in cart. Nothing modified." << endl << endl;
	return;
}

int ShoppingCart::ReturnTotalQuantity() const {
	int totalQuantity = 0;

	for (int i = 0; i < items.size(); i++) {
		totalQuantity += items.at(i).GetQuantity();
	}

	return totalQuantity;
}
double ShoppingCart::ReturnTotalCost() const {
	double totalCost = 0.0;

	for (int i = 0; i < items.size(); i++) {
		totalCost += items.at(i).GetPrice() * items.at(i).GetQuantity();
	}

	return totalCost;
}

void ShoppingCart::PrintNumAndCosts() const {
	const int PRECISION = 2;

	cout << customerName << "'s Shopping Cart - " << date << endl;

	if (items.size() == 0) {
		cout << "Shopping cart is empty." << endl << endl;
	}
	else {
		cout << "Number of Items: " << ReturnTotalQuantity() << endl << endl;

		for (int i = 0; i < items.size(); i++) {
			items.at(i).PrintCost();
		}

		cout << endl << "Total: $" << fixed << setprecision(PRECISION) << ReturnTotalCost() << endl << endl;
	}
}
void ShoppingCart::PrintDescriptions() const {
	cout << customerName << "'s Shopping Cart - " << date << endl;

	if (items.size() == 0) {
		cout << "Shopping cart is empty." << endl << endl;
	}
	else {
		cout << endl << "Item Descriptions" << endl;
		for (int i = 0; i < items.size(); i++) {
			items.at(i).PrintDescription();
		}
		cout << endl;
	}
}