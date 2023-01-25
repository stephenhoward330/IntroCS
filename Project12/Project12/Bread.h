#ifndef BREAD_H
#define BREAD_H

#include <string>
#include "BakedGood.h"

class Bread : public BakedGood {
public:
	Bread(string resVariety = "none");
	virtual string ToStr() const;
	virtual double DiscountedPrice(int numGood) const;
private:
	string variety;
};

#endif