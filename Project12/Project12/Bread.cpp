#include <string>
#include <sstream>
#include "Bread.h"

const double BREAD_PRICE = 4.50;
const int BREAD_FOR_DISCOUNT = 3;

Bread::Bread(string resVariety) {
	variety = resVariety;
	basePrice = BREAD_PRICE;
}

string Bread::ToStr() const {
	ostringstream oss;

	oss << variety << " bread" << BakedGood::ToStr();

	return oss.str();
}

double Bread::DiscountedPrice(int numGood) const {
	double discountedPrice = 0;

	discountedPrice = basePrice * numGood;
	while (numGood >= BREAD_FOR_DISCOUNT) {
		discountedPrice -= basePrice;
		numGood -= BREAD_FOR_DISCOUNT;
	}

	return discountedPrice;
}