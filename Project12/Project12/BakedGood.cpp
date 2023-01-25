#include <sstream>
#include <iomanip>
#include "BakedGood.h"

const int MONEY_PRECISION = 2;

BakedGood::BakedGood() {

}

string BakedGood::ToStr() const {
	ostringstream oss;

	oss << fixed << setprecision(MONEY_PRECISION) << " ($" << basePrice << ")";

	return oss.str();
}