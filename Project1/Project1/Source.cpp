#include <iostream>
#include <cmath>
using namespace std;

int main() {
	const int FED_BY_LARGE = 7;
	const int FED_BY_MEDIUM = 3;
	const int FED_BY_SMALL = 1;

	int numGuests = 0;
	int numGuestsSet = 0;
	cout << "Please enter the number of guests: " << endl;
	cin >> numGuests;
	numGuestsSet = numGuests;

	int numLarges = 0;
	numLarges = numGuests / FED_BY_LARGE;

	numGuests = numGuests - (numLarges * FED_BY_LARGE);
	int numMediums = 0;
	numMediums = numGuests / FED_BY_MEDIUM;

	numGuests = numGuests - (numMediums * FED_BY_MEDIUM);
	int numSmalls = 0;
	numSmalls = numGuests / FED_BY_SMALL;

	cout << numLarges << " large pizzas, " << numMediums << " medium pizzas, and " << numSmalls;
	cout << " small pizzas will be needed." << endl << endl;


	const int RADIUS_OF_LARGE = 10;
	const int RADIUS_OF_MEDIUM = 8;
	const int RADIUS_OF_SMALL = 6;
	const double PI = 3.14159265;

	double areaOfLarge = 0;
	areaOfLarge = pow(RADIUS_OF_LARGE, 2) * PI;
	areaOfLarge = areaOfLarge * numLarges;

	double areaOfMedium = 0;
	areaOfMedium = pow(RADIUS_OF_MEDIUM, 2) * PI;
	areaOfMedium = areaOfMedium * numMediums;

	double areaOfSmall = 0;
	areaOfSmall = pow(RADIUS_OF_SMALL, 2) * PI;
	areaOfSmall = areaOfSmall * numSmalls;

	double totalArea = 0;
	totalArea = areaOfLarge + areaOfMedium + areaOfSmall;

	double individualArea = 0;
	individualArea = totalArea / numGuestsSet;

	cout << "A total of " << totalArea << " square inches of pizza will be purchased (";
	cout << individualArea << " per guest)." << endl << endl;


	const double COST_OF_LARGE = 14.68;
	const double COST_OF_MEDIUM = 11.48;
	const double COST_OF_SMALL = 7.28;
	const double DECIMAL_MAKER = 100;

	double tip = 0;
	cout << "Please enter the tip as a percentage (i.e. 10 means 10%): " << endl;
	cin >> tip;
	tip = tip / DECIMAL_MAKER;

	double costLarges = 0;
	costLarges = COST_OF_LARGE * numLarges;

	double costMediums = 0;
	costMediums = COST_OF_MEDIUM * numMediums;

	double costSmalls = 0;
	costSmalls = COST_OF_SMALL * numSmalls;

	double totalCost = 0;
	totalCost = costLarges + costMediums + costSmalls;

	double totalTip = 0;
	totalTip = totalCost * tip;

	totalCost = totalCost + totalTip;
	int roundCost = totalCost + 0.5;

	cout << "The total cost of the event will be: $" << roundCost << endl;

	system("pause");

	return 0;
}