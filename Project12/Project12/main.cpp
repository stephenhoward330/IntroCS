/*
Stephen Howard, stephenhoward330@gmail.com, section 3
Test Case 1: Bread
Create 4 breads, should be 4.50 each and total of 13.50 after discount
Passed
Test Case 2: Cupcake
Create 2 cream-cheese cupcakes, should be 2.15 each and total of 3.70 after discount
Passed
Test Case 3: Layer-cake
Create 3 non-cream-cheese 2-layer cakes, should be 12.00 each and total of 30.00 after discount
Passed
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"

using namespace std;

const int BAKED_GOOD_WIDTH = 75;
const int QUANT_WIDTH = 9;
const int MONEY_MAKER = 2;

int main() {
	string userInput = "none";
	string variety = "none";
	string flavor = "none";
	string frosting = "none";
	string sprinkleColor = "none";
	int numLayers = 0;
	int quantity = 0;
	int numGood = 0;
	int totalNumGoods = 0;
	double totalCost = 0.0;
	vector <BakedGood*> orderVtr;

	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	while (userInput != "done") {
		cout << "Sub-order: ";
		cin >> userInput;
		if (userInput == "Bread") {
			cin >> variety;
			cin >> quantity;
			for (int i = 0; i < quantity; i++) {
				Bread* newBreadPtr = nullptr;
				newBreadPtr = new Bread(variety);
				orderVtr.push_back(newBreadPtr);
			}
		}
		else if (userInput == "Layer-cake") {
			cin >> flavor;
			cin >> frosting;
			cin >> numLayers;
			cin >> quantity;
			for (int i = 0; i < quantity; i++) {
				LayerCake* newLayerCakePtr = nullptr;
				newLayerCakePtr = new LayerCake(flavor, frosting, numLayers);
				orderVtr.push_back(newLayerCakePtr);
			}
		}
		else if (userInput == "Cupcake") {
			cin >> flavor;
			cin >> frosting;
			cin >> sprinkleColor;
			cin >> quantity;
			for (int i = 0; i < quantity; i++) {
				CupCake* newCupCakePtr = nullptr;
				newCupCakePtr = new CupCake(flavor, frosting, sprinkleColor);
				orderVtr.push_back(newCupCakePtr);
			}
		}
	}
	cout << endl;

	cout << "Order Confirmations:" << endl;
	for (int i = 0; i < orderVtr.size(); i++) {
		cout << orderVtr.at(i)->ToStr() << endl;
	}
	cout << endl;

	cout << "Invoice:" << endl;
	cout << setw(BAKED_GOOD_WIDTH) << left << "Baked Good" << setw(QUANT_WIDTH) << right << "Quantity"
		<< setw(QUANT_WIDTH) << right << "Total" << endl;
	while (orderVtr.size() > 0) {
		numGood = 0;
		for (int i = 0; i < orderVtr.size(); i++) {
			if (orderVtr.at(0)->ToStr() == orderVtr.at(i)->ToStr()) {
				numGood += 1;
				totalNumGoods += 1;
			}
		}
		cout << setw(BAKED_GOOD_WIDTH) << left << orderVtr.at(0)->ToStr() << setw(QUANT_WIDTH) << right << numGood
			<< fixed << setprecision(MONEY_MAKER) << setw(QUANT_WIDTH) << right << orderVtr.at(0)->DiscountedPrice(numGood) << endl;
		totalCost += orderVtr.at(0)->DiscountedPrice(numGood);
		for (int i = orderVtr.size()-1; i >= 0; i--) {
			if (orderVtr.at(0)->ToStr() == orderVtr.at(i)->ToStr()) {
				delete orderVtr.at(i);
				orderVtr.erase(orderVtr.begin() + i);
			}
		}
	}
	cout << setw(BAKED_GOOD_WIDTH) << left << "Totals" << setw(QUANT_WIDTH) << right << totalNumGoods
		<< setw(QUANT_WIDTH) << right << totalCost << endl << endl;

	cout << "Good Bye" << endl;
	
	return 0;
}