/*
Stephen Howard, stephenhoward330@gmail.com, section 3
Test Case 1: Errors
Check error on menu input (resulting in showing options menu), error on number input for cut (should reprompt),
(error in battle checked later)
Passed
Test Case 2:
Input: add a add b add c remove c add c shuffle add d shuffle display
Output: a added, b added, c added, c removed, c added, must be power of 2 to shuffle, d added, cadb
Passed
Test Case 3: Battle
With restaurants a, b, c, and d, and input 1 3 2 2
Should reprompt when 3 is entered, and should declare d the winner.
Passed
*/

#include<iostream>
#include<string>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;

bool CheckNumRestaurants(int numRestaurants) {
	const int MAX_POWER = 10;

	for (int i = 0; i < MAX_POWER; i++) {
		if (pow(2, i) == numRestaurants) { // 2 to the i power
			return true;
		}
	}

	return false;
}

bool FindRestaurant(vector<string> restaurantNames, string searchString) {
	int size = restaurantNames.size();

	for (int i = 0; i < size; i++) {
		if (searchString == restaurantNames.at(i)) {
			return true;
		}
	}

	return false;
}

void GetLineNotWS(string& inpString) {

	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos) {
		getline(cin, inpString);
	}
}

int GetNum(string type, int size) {
	const int UNASSIGNED = -1;
	int number = UNASSIGNED;

	while (true) {
		cin >> number;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			number = UNASSIGNED;
		}
		if (type == "cutNum") {
			if ((number >= 0) && (number <= size)) {
				break;
			}
			else {
				cout << endl;
				cout << "The cut number must be between 0 and " << size << endl << endl;
				cout << "How many restaurants should be taken from the top and put on the bottom? ";
			}
		}
		else if (type == "battleNum") {
			if ((number >= 1) && (number <= 2)) { //battle response should be 1 or 2
				break;
			}
			else {
				cout << endl;
				cout << "Invalid choice" << endl << endl;
				return 0;
			}
		}
		else {
			break;
		}
	}

	return number;
}

void PrintMenu() {
	cout << "Please select one of the following options:" << endl << endl;
	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl << endl;
}

void DisplayRestaurants(vector<string> restaurantNames) {
	int size = restaurantNames.size();

	cout << "Here are the current restaurants:" << endl << endl;

	for (int i = 0; i < size; i++) {
		cout << "\t\"" << restaurantNames.at(i) << "\"" << endl;
	}

	cout << endl;
}

void AddRestaurant(vector<string>& restaurantNames) {
	string newRestaurant;

	cout << "What is the name of the restaurant you want to add? ";
	GetLineNotWS(newRestaurant);
	cout << endl;

	if (FindRestaurant(restaurantNames, newRestaurant)) {
		cout << "That restaurant is already on the list, you can not add it again." << endl << endl;
		return;
	}

	restaurantNames.push_back(newRestaurant);
	cout << newRestaurant << " has been added." << endl << endl;
}

void RemoveRestaurant(vector<string>& restaurantNames) {
	string restaurantToRemove;

	cout << "What is the name of the restaurant you want to remove? ";
	GetLineNotWS(restaurantToRemove);
	cout << endl;

	if (FindRestaurant(restaurantNames, restaurantToRemove)) {
		for (int i = 0; i < restaurantNames.size(); i++) {
			if (restaurantToRemove == restaurantNames.at(i)) {
				restaurantNames.erase(restaurantNames.begin() + i);
			}
		}
		cout << restaurantToRemove << " has been removed." << endl << endl;
	}
	else {
		cout << "That restaurant is not on the list, you can not remove it." << endl << endl;
	}
}

vector<string> CutRestaurants(vector<string> restaurantNames) {
	vector<string> newRestaurantNames = restaurantNames;
	int size = restaurantNames.size();
	int cutNum = 0;

	cout << "How many restaurants should be taken from the top and put on the bottom? ";
	cutNum = GetNum("cutNum", size);
	cout << endl;

	for (int i = 0; i < cutNum; i++) {
		newRestaurantNames.erase(newRestaurantNames.begin());
		newRestaurantNames.push_back(restaurantNames.at(i));
	}
	
	return newRestaurantNames;
}

vector<string> ShuffleRestaurants(vector<string> restaurantNames) {
	vector<string> newRestaurantNames;
	vector<string> secondHalf;
	int size = restaurantNames.size();

	if (CheckNumRestaurants(size)) {
		int numIterations = (size / 2);
		for (int i = numIterations; i < size; i++) {
			secondHalf.push_back(restaurantNames.at(i));
		}
		for (int i = 0; i < numIterations; i++) {
			newRestaurantNames.push_back(secondHalf.at(i));
			newRestaurantNames.push_back(restaurantNames.at(i));
		}
	}
	else {
		cout << "The current tournament size (" << size << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl << endl;
		return restaurantNames;
	}

	return newRestaurantNames;
}

void BattleRestaurants(vector<string> restaurantNames) {
	int size = restaurantNames.size();
	vector<string> battleNames = restaurantNames;
	//int battleSize = battleNames.size();
	int numRemoved = 0;
	int userChoice = 0;
	int battleIndex = 0;

	if (CheckNumRestaurants(size)) {
		int numRounds = log2(size);
		for (int i = 1; i <= numRounds; i++) {
			cout << "Round: " << i << endl << endl;
			numRemoved = 0;
			battleIndex = 0;
			while (battleNames.size() != numRemoved) {
				userChoice = 0;
				while (userChoice == 0) {
					cout << "Type \"1\" if you prefer " << battleNames.at(battleIndex) << " or" << endl;
					cout << "type \"2\" if you prefer " << battleNames.at(battleIndex + 1) << endl;
					cout << "Choice: ";
					userChoice = GetNum("battleNum", 0);
				}
				if (userChoice == 1) {
					battleNames.erase(battleNames.begin() + (battleIndex + 1));
				}
				else if (userChoice == 2) {
					battleNames.erase(battleNames.begin() + battleIndex);
				}
				else {
					cout << "ERROR";
					return;
				}
				cout << endl;
				numRemoved += 1;
				battleIndex += 1;
			}
			if (battleNames.size() == 1) { //one restaurant left
				cout << "The winning restaurant is " << battleNames.at(0) << "." << endl << endl;
			}
		}
	}
	else {
		cout << "The current tournament size (" << size << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl << endl;
	}
}

int main() {
	vector<string> restaurantNames;
	string userInput;
	bool continueRunning = true;

	cout << "Welcome to the restaurant battle! Enter \"options\" to see options." << endl << endl;

	while (continueRunning) {
		cout << "Enter your selection: ";
		cin >> userInput;
		cout << endl;
		if (userInput == "quit") {
			continueRunning = false;
			cout << "Goodbye!" << endl << endl;
		}
		else if (userInput == "display") {
			DisplayRestaurants(restaurantNames);
		}
		else if (userInput == "add") {
			AddRestaurant(restaurantNames);
		}
		else if (userInput == "remove") {
			RemoveRestaurant(restaurantNames);
		}
		else if (userInput == "cut") {
			restaurantNames = CutRestaurants(restaurantNames);
		}
		else if (userInput == "shuffle") {
			restaurantNames = ShuffleRestaurants(restaurantNames);
		}
		else if (userInput == "battle") {
			BattleRestaurants(restaurantNames);
		}
		else if (userInput == "options") {
			PrintMenu();
		}
		else {
			cout << "Invalid Selection" << endl << endl;
			PrintMenu();
		}
	}

	system("pause");
	return 0;
}