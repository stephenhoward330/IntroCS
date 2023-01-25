#include <string>
#include <sstream>
#include "CupCake.h"

const double CUPCAKE_PRICE = 1.95;
const double CREAM_CHEESE_COST = 0.20;
const int HIGH_DISCOUNT_BOUND = 4;
const int LOW_DISCOUNT_BOUND = 2;
const double HIGH_DISCOUNT = 0.4;
const double LOW_DISCOUNT = 0.3;

CupCake::CupCake(string resFlavor, string resFrosting, string resSprinkleColor) {
	flavor = resFlavor;
	frosting = resFrosting;
	sprinkleColor = resSprinkleColor;
	if (resFrosting == "cream-cheese") {
		basePrice = CUPCAKE_PRICE + CREAM_CHEESE_COST;
	}
	else {
		basePrice = CUPCAKE_PRICE;
	}
}

string CupCake::ToStr() const {
	ostringstream oss;

	oss << flavor << " cupcake with " << frosting << " frosting and " << sprinkleColor << " sprinkles" << BakedGood::ToStr();

	return oss.str();
}

double CupCake::DiscountedPrice(int numGood) const {
	double discountedPrice = 0;

	discountedPrice = basePrice * numGood;
	if (numGood >= HIGH_DISCOUNT_BOUND) {
		discountedPrice -= numGood * HIGH_DISCOUNT;
	}
	else if (numGood >= LOW_DISCOUNT_BOUND) {
		discountedPrice -= numGood * LOW_DISCOUNT;
	}

	return discountedPrice;
}