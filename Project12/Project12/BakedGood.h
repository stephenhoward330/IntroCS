#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

#include <string>

using namespace std;

class BakedGood {
public:
	BakedGood();
	virtual string ToStr() const = 0;
	virtual double DiscountedPrice(int numGood) const = 0;
protected:
	double basePrice;
};

#endif