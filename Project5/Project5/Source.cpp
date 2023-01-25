/* Stephen Howard, section 3, stephenhoward330@gmail.com

Test case 1: Multiple Chips
Input: (using fixed seed of 42) 2 5000 0 5
Expected output: Total winnings on 5000 chips: $3979000.00
Average winnings per chip: $795.80
Test case 2: Errors
Input: -1 4 2 -1 5 -5 10 5 -1 1 15 -1 2 4 9 5
Expected Output: Verify that an appropiate error message is given for each input error and that there is an
appropiate re-request until a correct input is given.
Passed
Test case 3: Multiple chips in each slot
Input: (using fixed seed of 42) 3 0 5 5
Expected output: for numbers 0-8:
Total Winnings on slot # chips: #####
Average winnings per chip: ####
in a bell curve shape.
Passed

*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

const int MONEY_PRECISION = 2;
const int NUM_SLOTS = 9;
const int LEFT_BOUND = 0;
const int RIGHT_BOUND = NUM_SLOTS-1;

int GetNum(string type) {
	const int UNASSIGNED = -1;
	int number = UNASSIGNED;

	while (true) {
		cin >> number;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (type != "menuOption") {
				number = UNASSIGNED;
			}
		}
		cout << endl;
		if (type == "numChips") { //Check for valid number of chips
			if (number > 0) {
				break;
			}
			else {
				cout << "Invalid number of chips." << endl << endl;
				cout << "How many chips do you want to drop (>0)? ";
			}
		}
		else if (type == "slot") {
			if ((number >= LEFT_BOUND) && (number <= RIGHT_BOUND)) {
				break;
			}
			else {
				cout << "Invalid slot." << endl << endl;
				cout << "Which slot do you want to drop the chip in (0-" << RIGHT_BOUND << ")? ";
			}
		}
		else if (type == "menuOption") {
			if ((number >= 1) && (number <= 5)) { //menuOption only goes from 1 to 5
				break;
			}
			else {
				cout << "Invalid selection.  Enter 4 to see options." << endl << endl;
				cout << "Enter your selection now: ";
			}
		}
		else {
			break;
		}
	}

	return number;
}

double ComputeWinnings(int slot) {
	const double winningsArray[NUM_SLOTS] = {100.0, 500.0, 1000.0, 0.0, 10000.0, 0.0, 1000.0, 500.0, 100.0};
	double winnings = winningsArray[slot];

	return winnings;
}

double DropAChip(double slot, int style = 0) {
	const int ROWS = 12;
	double totalWinnings = 0.0;

	if (style == 0) {
		cout << fixed << setprecision(1) //1 decimal place desired for slot number
			<< "Path: [" << slot << ", ";
	}
	for (int i = 0; i < ROWS; i++) {
		if (fabs(slot - LEFT_BOUND) < 0.0001) { //double comparison
			slot += 0.5;
		}
		else if (fabs(slot - RIGHT_BOUND) < 0.0001) { //double comparison
			slot -= 0.5;
		}
		else {
			if (rand() % 2) { //Returns a number 0 or 1, used to randomly 
							  //determine whether the chip falls left or right
				slot += 0.5;
			}
			else {
				slot -= 0.5;
			}
		}
		if (style == 0) {
			cout << fixed << setprecision(1) << slot; //1 decimal place
			if (i < (ROWS - 1)) { cout << ", "; }
		}
	}
	if (style == 0) {
		cout << "]\n";

		cout << "Winnings: $" << fixed << setprecision(MONEY_PRECISION) << ComputeWinnings(static_cast<int>(slot + .01));
		cout << endl << endl;
	}

	return ComputeWinnings(static_cast<int>(slot + .01));
}

void DropMultipleChips(double slot, int numChips, int style = 0) {
	double totalWinnings = 0.0;
	double averageWinningsPerChip = 0.0;
	int i;

	for (i = 0; i < numChips; i++) {
		totalWinnings += DropAChip(slot, 1);
	}

	averageWinningsPerChip = totalWinnings / numChips;

	if (style == 0) {
		cout << "Total winnings on " << numChips << " chips: $"
			<< fixed << setprecision(MONEY_PRECISION) << totalWinnings << endl;
		cout << "Average winnings per chip: $" << averageWinningsPerChip << endl << endl;
	}
	else {
		cout << "Total Winnings on slot " << static_cast<int>(slot) << " chips: "
			<< fixed << setprecision(MONEY_PRECISION) << totalWinnings << endl;
		cout << "Average winnings per chip: " << averageWinningsPerChip << endl << endl;
	}
}

int main() {
	//Initializations & Declarations
	const int OPTION_SINGLE_CHIP = 1;
	const int OPTION_MULTIPLE_CHIPS = 2;
	const int OPTION_EACH_SLOT = 3;
	const int OPTION_SHOW_MENU = 4;
	const int OPTION_QUIT = 5;
	bool continueRunning = true;
	int userOption = 0;
	int userSlot = 0;
	int numChips = 0;
	const int RANDOM_SEED = 42;
	srand(RANDOM_SEED);

	//Introduction
	cout << "Welcome to the Plinko simulator! Enter 4 to see options.\n\n";

	//while true do
	while (continueRunning)
	{
		cout << "Enter your selection now: ";
		userOption = GetNum("menuOption");

		switch (userOption)
		{
		case OPTION_SINGLE_CHIP: //Drop a single chip into one slot
			cout << "*** Drop a single chip ***\n\n"
				<< "Which slot do you want to drop the chip in (0-" << RIGHT_BOUND << ")? ";
			userSlot = GetNum("slot");

			cout << "*** Dropping chip into slot " << userSlot << " ***\n";

			DropAChip(userSlot);

			break;
		case OPTION_MULTIPLE_CHIPS: //Drop multiple chips into one slot
			cout << "*** Drop multiple chips ***\n\n"
				<< "How many chips do you want to drop (>0)? ";
			numChips = GetNum("numChips");

			cout << "Which slot do you want to drop the chip in (0-" << RIGHT_BOUND << ")? ";
			userSlot = GetNum("slot");

			DropMultipleChips(userSlot, numChips);

			break;
		case OPTION_EACH_SLOT:
			cout << "*** Sequentially drop multiple chips ***\n\n"
				<< "How many chips do you want to drop (>0)? ";
			numChips = GetNum("numChips");

			for (double i = 0.0; i <= static_cast<double>(RIGHT_BOUND); i++) {
				DropMultipleChips(i, numChips, 1);
			}

			break;
		case OPTION_SHOW_MENU: //Show options menu
			cout << "Menu: Please select one of the following options:\n\n"
				<< "1 - Drop a single chip into one slot\n"
				<< "2 - Drop multiple chips into one slot\n"
				<< "3 - Drop multiple chips into each slot\n"
				<< "4 - Show the options menu\n"
				<< "5 - Quit the program\n" << endl;

			break;
		case OPTION_QUIT:	//Quit
			continueRunning = false;
			cout << "Goodbye!" << endl;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}