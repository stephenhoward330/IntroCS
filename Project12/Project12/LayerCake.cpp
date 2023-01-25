#include <string>
#include <sstream>
#include "LayerCake.h"

const double LAYER_CAKE_COST = 9.0;
const double CREAM_CHEESE_LAYER = 1.0;
const double LAYER_COST = 3.0;
const int LAYER_COST_LIMIT = 1;
const int DISCOUNT_BOUND = 3;
const int DISCOUNT = 2;

LayerCake::LayerCake(string resFlavor, string resFrosting, int resNumLayers) {
	flavor = resFlavor;
	frosting = resFrosting;
	numLayers = resNumLayers;
	basePrice = LAYER_CAKE_COST;
	if (resFrosting == "cream-cheese") {
		basePrice += CREAM_CHEESE_LAYER * resNumLayers;
	}
	if (resNumLayers > LAYER_COST_LIMIT) {
		for (int i = 0; i < resNumLayers - 1; i++) {
			basePrice += LAYER_COST;
		}
	}
}

string LayerCake::ToStr() const {
	ostringstream oss;

	oss << numLayers << "-layer " << flavor << " cake with " << frosting << " frosting" << BakedGood::ToStr();

	return oss.str();
}

double LayerCake::DiscountedPrice(int numGood) const {
	double discountedPrice = 0;

	discountedPrice = basePrice * numGood;
	if (numGood >= DISCOUNT_BOUND) {
		discountedPrice -= numGood * DISCOUNT;
	}

	return discountedPrice;
}