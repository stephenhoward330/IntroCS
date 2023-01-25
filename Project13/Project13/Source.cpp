#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string userInput = "none";
	string newTag = "DIE";
	vector<string> tags;

	cout << "Tags: ";
	getline(cin, userInput);
	userInput += " DIE";
	istringstream iSS(userInput);

	iSS >> newTag;
	while (newTag != "DIE") {
		tags.push_back(newTag);
		iSS >> newTag;
	}

	for (int i = 0; i < tags.size(); i++) {
		cout << tags.at(i) << " ";
	}

	system("pause");
	return 0;
}