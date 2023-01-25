/* Matrix should end up
8 5
20 13
*/

#include <iostream>

using namespace std;

const int SIZE = 2;

void PrintArray(int myArray[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << myArray[i][j] << " ";
			if (j == SIZE-1) {
				cout << endl;
			}
		}
	}
	return;
}

int main() {
	int i;
	int j;
	int k;
	int numColumns1 = SIZE;
	int numRows2 = SIZE;

	int array1[SIZE][SIZE] = {
		{ 1,2 },
		{ 3,4 }
	};

	int array2[SIZE][SIZE] = {
		{ 4,3 },
		{ 2,1 }
	};

	int finalArray[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			finalArray[i][j] = 0;
		}
	}

	if (numColumns1 != numRows2) {
		cout << "Matrix Multiplication is not possible." << endl;
		cout << "The number of columns of the first array must equal the number of rows of the second array.\n" << endl;
	}
	else {
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				for (k = 0; k < SIZE; k++) {
					finalArray[k][j] += array1[k][i] * array2[i][j];
				}
			}
		}
		/*
		for (i = 0; i < SIZE; i++) {
				finalArray[0][0] += array1[0][0 + i] * array2[0 + i][0];
				finalArray[0][1] += array1[0][0 + i] * array2[0 + i][1];
				finalArray[1][0] += array1[1][0 + i] * array2[0 + i][0];
				finalArray[1][1] += array1[1][0 + i] * array2[0 + i][1];
		}
		*/
		cout << "Array 1: " << endl;
		PrintArray(array1);

		cout << "Array 2: " << endl;
		PrintArray(array2);

		cout << "Final Array: " << endl;
		PrintArray(finalArray);
	}

	system("pause");
	return 0;
}