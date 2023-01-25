#include<string>
using namespace std;

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

class ItemToPurchase {
	public:
		void SetName(string name);
		void SetPrice(double price);
		void SetQuantity(int quantity);
		string GetName() const;
		double GetPrice() const;
		int GetQuantity() const;
	private:
		string itemName = "none";
		double itemPrice = 0.0;
		int itemQuantity = 0;
};

#endif