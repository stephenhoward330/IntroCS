#include <iostream>
#include <string>
#include "ItemToPurchase.h"

using namespace std;

void ItemToPurchase::SetName(string name) {
	itemName = name;
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
double ItemToPurchase::GetPrice() const {
	return itemPrice;
}
int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}