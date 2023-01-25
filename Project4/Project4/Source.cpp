#include <iostream>
#include <string>
using namespace std;

void ShortenSpace(string& userString) {
	char thing = ' ';
	char thing2 = ' ';
	int size = userString.size();

	for (int i = 0; i < size - 1; i++) {
		if (i < size - 1) {
			thing = userString.at(i);
			thing2 = userString.at(i + 1);
			if (isspace(thing) && isspace(thing2)) {
				userString.erase(i, 1);
			}
			size = userString.size();
		}
	}

	return;
}

void ReplaceExclamation(string& userString) {
	int size = userString.size();

	for (int i = 0; i < size; i++) {
		if (userString.at(i) == '!') {
			userString.at(i) = '.';
		}
	}

	return;
}

int FindText(string userString, const string searchString) {
	int bigSize = userString.size();
	int littleSize = searchString.size();
	int numInstances = 0;

	for (int i = 0; i < bigSize; i++) {
		if (userString.find(searchString) != string::npos) {
			userString.erase(userString.find(searchString), littleSize);
			numInstances += 1;
		}
	}

	return numInstances;
}

int GetNumOfWords(const string userString) {
	int numWords = 1;
	char thing = ' ';
	char thing2 = ' ';
	int size = userString.size();

	for (int i = 0; i < size-1; i++) {
		thing = userString.at(i);
		thing2 = userString.at(i + 1);
		if (isspace(thing) && !isspace(thing2)) {
			numWords += 1;
		}
	}

	return numWords;
}

int GetNumOfNonWSCharacters(const string userString) {
	int numCharacters = 0;
	char thing = ' ';
	int size = userString.size();

	for (int i = 0; i < size; i++) {
		thing = userString.at(i);
		if (!isspace(thing)) {
			numCharacters += 1;
		}
	}

	return numCharacters;
}

char PrintMenu(string& userString) {
	char userInput = 'b';
	string searchString = " ";

	while ((userInput != 'c') && (userInput != 'w') && (userInput != 'f') && (userInput != 'r')
		&& (userInput != 's') && (userInput != 'q')) {
		cout << "MENU" << endl;
		cout << "c - Number of non-whitespace characters" << endl;
		cout << "w - Number of words" << endl;
		cout << "f - Find text" << endl;
		cout << "r - Replace all !'s" << endl;
		cout << "s - Shorten spaces" << endl;
		cout << "q - Quit" << endl << endl;
		cout << "Choose an option: ";

		cin >> userInput;
		cout << endl;
	}

	switch (userInput) {
	case 'c':
		cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userString) << endl << endl;
		break;
	case 'w':
		cout << "Number of words: " << GetNumOfWords(userString) << endl << endl;
		break;
	case 'f':
		cout << "Enter a word or phrase to be found: ";
		cin.ignore();
		getline (cin, searchString);
		cout << "\"" << searchString << "\" instances: " << FindText(userString, searchString) << endl << endl;
		break;
	case 'r':
		ReplaceExclamation(userString);
		cout << "Edited text: " << userString << endl << endl;
		break;
	case 's':
		ShortenSpace(userString);
		cout << "Edited text: " << userString << endl << endl;
		break;
	case 'q':
		break;
	}

	return userInput;
}

int main() {
	string userString;
	char output = 'a';

	cout << "Enter a sample text: ";
	getline(cin, userString);
	cout << endl;

	cout << "You entered: " << userString << endl << endl;

	while (output != 'q') {
		output = PrintMenu(userString);
	}

	system("pause");
	return 0;
}