#ifndef CUPCAKE_H
#define CUPCAKE_H

#include "Cake.h"

class CupCake : public Cake {
public:
	CupCake(string resFlavor = "none", string resFrosting = "none", string resSprinkleColor = "none");
	virtual string ToStr() const;
	virtual double DiscountedPrice(int numGood) const;
private:
	string sprinkleColor;
};

#endif