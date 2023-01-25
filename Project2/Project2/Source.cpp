#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int SIZE = 5;
	vector <int> playerNums(SIZE);
	vector <int> playerRatings(SIZE);
	int anotherNum = 0;
	int anotherRating = 0;
	int i;
	bool continuePlaying = true;
	char userInput = ' ';

	for (i = 0; i<SIZE; i++) {
		cout << "Enter player " << i + 1 << "'s jersey number: " << endl;
		cin >> playerNums.at(i);
		cout << "Enter player " << i + 1 << "'s rating: " << endl;
		cin >> playerRatings.at(i);
		cout << endl;
	}

	cout << endl << "ROSTER" << endl;
	for (i = 0; i<SIZE; i++) {
		cout << "Player " << i + 1 << " -- Jersey number: " << playerNums.at(i) << ", Rating: " << playerRatings.at(i) << endl;
	}
	cout << endl << endl;

	while (continuePlaying == true) {
		cout << "MENU" << endl << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl
			<< "r - Output players above a rating" << endl << "o - Output roster" << endl << "q - Quit" << endl << endl <<
			"Choose an option: " << endl << endl;
		cin >> userInput;
		switch (userInput) {
		case 'a':
			cout << "Enter another player's jersey number: " << endl;
			cin >> anotherNum;
			cout << "Enter another player's rating: " << endl;
			cin >> anotherRating;
			cout << endl;
			playerNums.push_back(anotherNum);
			playerRatings.push_back(anotherRating);
			break;
		case 'd':
			cout << "Enter a jersey number: " << endl;
			cin >> anotherNum;
			for (i = 0; i < playerNums.size(); i++) {
				if (playerNums.at(i) == anotherNum) {
					playerNums.erase(playerNums.begin() + i);
					playerRatings.erase(playerRatings.begin() + i);
				}
			}
			cout << endl;
			break;
		case 'u':
			cout << "Enter a jersey number: " << endl;
			cin >> anotherNum;
			cout << "Enter a new rating for player: " << endl;
			cin >> anotherRating;
			for (i = 0; i < playerNums.size(); i++) {
				if (playerNums.at(i) == anotherNum) {
					playerRatings.at(i) = anotherRating;
				}
			}
			cout << endl;
			break;
		case 'r':
			cout << "Enter a rating: " << endl;
			cin >> anotherRating;
			cout << endl << endl << "ABOVE " << anotherRating << endl;
			for (i = 0; i < playerNums.size(); i++) {
				if (playerRatings.at(i) > anotherRating) {
					cout << "Player " << i + 1 << " -- Jersey number: " << playerNums.at(i) << ", Rating: " << playerRatings.at(i) << endl;
				}
			}
			cout << endl;
			break;
		case 'o':
			cout << endl << "ROSTER" << endl;
			for (i = 0; i<playerNums.size(); i++) {
				cout << "Player " << i + 1 << " -- Jersey number: " << playerNums.at(i) << ", Rating: " << playerRatings.at(i) << endl;
			}
			cout << endl << endl;
			break;
		case 'q':
			continuePlaying = false;
			break;
		}
	}

	return 0;
}