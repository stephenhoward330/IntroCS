#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include<string>
using namespace std;

class ItemToPurchase {
public:
	void SetName(string name);
	void SetDescription(string description);
	void SetPrice(double price);
	void SetQuantity(int quantity);

	string GetName() const;
	string GetDescription() const;
	double GetPrice() const;
	int GetQuantity() const;

	void PrintCost() const;
	void PrintDescription() const;

	ItemToPurchase(string resItemName = "none", string resItemDescription = "none", double resItemPrice = 0.0, int resItemQuantity = 0);
private:
	string itemName;
	string itemDescription;
	double itemPrice;
	int itemQuantity;
};

#endif
