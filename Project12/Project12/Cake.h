#ifndef CAKE_H
#define CAKE_H

#include <string>
#include "BakedGood.h"

class Cake : public BakedGood {
public:
	Cake();
protected:
	string flavor;
	string frosting;
};

#endif