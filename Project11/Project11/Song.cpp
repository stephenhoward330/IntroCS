#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

Song::Song(vector<string> resTags, string resName, string resFirstLine) {
	name = resName;
	firstLine = resFirstLine;
	tags = resTags;
	numPlays = 0;
}

void Song::ListSong() const {
	cout << name << ": \"" << firstLine << "\", " << numPlays << " play(s)." << endl;
	cout << "Tags: ";
	for (int i = 0; i < tags.size(); i++) {
		cout << tags.at(i) << " ";
	}
	cout << endl;
}

void Song::SetName(string newName) {
	name = newName;
}
void Song::SetFirstLine(string newFirstLine) {
	firstLine = newFirstLine;
}

string Song::GetName() const {
	return name;
}
string Song::GetFirstLine() const {
	return firstLine;
}
int Song::GetNumPlays() const {
	return numPlays;
}

void Song::IncrementNumPlays() {
	numPlays += 1;
}