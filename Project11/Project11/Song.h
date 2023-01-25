#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>
using namespace std;

class Song {
public:
	Song(vector<string> resTags, string resName = "none", string resFirstLine = "none");

	void SetName(string newName);
	void SetFirstLine(string newFirstLine);

	void ListSong() const;

	void IncrementNumPlays();

	string GetName() const;
	string GetFirstLine() const;
	int GetNumPlays() const;
private:
	string name;
	string firstLine;
	vector<string> tags;
	int numPlays;
};

#endif