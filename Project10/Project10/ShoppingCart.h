#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
	string GetName() const;
	string GetDate() const;

	void AddItem(ItemToPurchase newItem);
	void RemoveItem(string removeItem);
	void UpdateItemQuantity(string itemName, int updateQuantity);

	int ReturnTotalQuantity() const;
	double ReturnTotalCost() const;

	void PrintNumAndCosts() const;
	void PrintDescriptions() const;

	ShoppingCart(string resName = "none", string resDate = "January 1, 2016");
private:
	string customerName;
	string date;
	vector<ItemToPurchase> items;
};

#endif