/*
Stephen Howard, Section 3, stephenhoward330@gmail.com
First iteration: ([1][0], [1][1], [1,2], [2][1], and [2][2])
100
25 25
0  0
Second iteration: ([1][0], [1][1], [1,2], [2][1], and [2][2])
100
31.25 37.5
6.25 6.25
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
	const int SIZE = 10;
	double oldArray[SIZE][SIZE];
	double newArray[SIZE][SIZE];
	double maxChange = 100.0;
	const int LEFT_BOUND = 0;
	const int RIGHT_BOUND = SIZE - 1;
	const int PRECISION = 3;
	const int WIDTH = 9;
	int i;
	int j;
	int k;
	ifstream inFS;
	ofstream outFS;

	//initialize oldArray
	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) {
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			oldArray[i][j] = 0.0;
		}
	}
	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) {
		oldArray[LEFT_BOUND][i] = 100.0;
		oldArray[RIGHT_BOUND][i] = 100.0;
	}
	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) {
		oldArray[i][LEFT_BOUND] = 0.0;
		oldArray[i][RIGHT_BOUND] = 0.0;
	}

	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Initialize newArray
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			newArray[i][j] = oldArray[i][j];
		}
	}

	cout << "Hotplate simulator" << endl << endl;

	cout << "Printing initial plate..." << endl;
	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Print oldArray
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			cout << fixed << setprecision(PRECISION) << setw(WIDTH) << oldArray[i][j];
			if (j == RIGHT_BOUND) {
				cout << endl;
			}
			else {
				cout << ",";
			}
		}
	}
	cout << endl;

	for (i = LEFT_BOUND + 1; i <= RIGHT_BOUND - 1; i++) { //Set newArray elements to the 4 surrounding elements from oldArray
		for (j = LEFT_BOUND + 1; j <= RIGHT_BOUND - 1; j++) {
			newArray[i][j] = (oldArray[i + 1][j] + oldArray[i - 1][j] + oldArray[i][j + 1] + oldArray[i][j - 1]) / 4;
		}
	}

	cout << "Printing plate after one iteration..." << endl;
	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Print plate
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			cout << fixed << setprecision(PRECISION) << setw(WIDTH) << newArray[i][j];
			if (j == RIGHT_BOUND) {
				cout << endl;
			}
			else {
				cout << ",";
			}
		}
	}
	cout << endl;

	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Set oldArray to newArray 
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			oldArray[i][j] = newArray[i][j];
		}
	}

	while (maxChange > 0.1) { //Find stable plate
		maxChange = 0;
		for (i = LEFT_BOUND + 1; i <= RIGHT_BOUND - 1; i++) {
			for (j = LEFT_BOUND + 1; j <= RIGHT_BOUND - 1; j++) {
				newArray[i][j] = (oldArray[i + 1][j] + oldArray[i - 1][j] + oldArray[i][j + 1] + oldArray[i][j - 1]) / 4;
				if (fabs(newArray[i][j] - oldArray[i][j]) > maxChange) {
					maxChange = fabs(newArray[i][j] - oldArray[i][j]);
				}
			}
		}
		for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Set oldArray to newArray 
			for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
				oldArray[i][j] = newArray[i][j];
			}
		}
	}

	cout << "Printing final plate..." << endl;
	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Print plate
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			cout << fixed << setprecision(PRECISION) << setw(WIDTH) << newArray[i][j];
			if (j == RIGHT_BOUND) {
				cout << endl;
			}
			else {
				cout << ",";
			}
		}
	}
	cout << endl;

	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl << endl;
	outFS.open("Hotplate.csv");
	if (!outFS.is_open()) {
		cout << "Could not open file Hotplate.csv" << endl << endl;
	}
	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Output plate
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			outFS << fixed << setprecision(PRECISION) << setw(WIDTH) << newArray[i][j];
			if (j == RIGHT_BOUND) {
				outFS << endl;
			}
			else {
				outFS << ",";
			}
		}
	}
	outFS.close();

	inFS.open("Inputplate.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file Inputplate.txt." << endl << endl;
	}

	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //inputplate elements to oldArray
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			inFS >> oldArray[i][j];
		}
	}
	inFS.close();

	for (k = 0; k < 3; k++) { //3 iterations
		for (i = LEFT_BOUND + 1; i <= RIGHT_BOUND - 1; i++) { //Set newArray elements to the 4 surrounding elements from oldArray
			for (j = LEFT_BOUND + 1; j <= RIGHT_BOUND - 1; j++) {
				newArray[i][j] = (oldArray[i + 1][j] + oldArray[i - 1][j] + oldArray[i][j + 1] + oldArray[i][j - 1]) / 4;
			}
		}
		for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Set oldArray to newArray 
			for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
				oldArray[i][j] = newArray[i][j];
			}
		}
	}

	cout << "Printing input plate after 3 updates..." << endl;
	for (i = LEFT_BOUND; i <= RIGHT_BOUND; i++) { //Print plate
		for (j = LEFT_BOUND; j <= RIGHT_BOUND; j++) {
			cout << fixed << setprecision(PRECISION) << setw(WIDTH) << oldArray[i][j];
			if (j == RIGHT_BOUND) {
				cout << endl;
			}
			else {
				cout << ",";
			}
		}
	}
	cout << endl;

	system("pause");
	return 0;
}