#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include "Cake.h"

class LayerCake : public Cake {
public:
	LayerCake(string resFlavor = "none", string resFrosting = "none", int resNumLayers = 1);
	virtual string ToStr() const;
	virtual double DiscountedPrice(int numGood) const;
private:
	int numLayers;
};

#endif