/*
Stephen Howard, stephenhoward330@gmail.com, section 3
Test Case 1: Songs
Check add songs(song 1 and song 2) and list songs.
Output: correct
Test Case 2: Playlists
Check add playlists(good jams and cool music), list playlists, add song(song 1) to playlist(good jams), and play playlist.
Output: all correct
Test Case 3: Deletes
Check delete playlist(cool music), delete song from playlist(song 1 from good jams), and delete song from library(song 2).
Output: all correct
Memory is freed on lines 163 and 220 of main.cpp.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Song.h"
#include "Playlist.h"

using namespace std;

void GetLineNotWS(string& inpString) {

	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos) {
		getline(cin, inpString);
	}
}

void PrintMenu() {
	cout << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "delp     Deletes a playlist" << endl;
	cout << "delsp    Deletes a song from a playlist" << endl;
	cout << "delsl    Deletes a song from the library (and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl << endl;
}

void AddSong(vector<Song*>& songPtrs) {
	string name = "none";
	string firstLine = "none";
	string userInput = "none";
	string newTag = "none";

	cout << "Read in Song names, first lines, and tags (type \"STOP\" when done):" << endl;
	while (true) {
		vector<string> tags;

		cout << "Song Name: ";
		GetLineNotWS(name);
		if (name == "STOP") {
			cout << endl;
			break;
		}

		cout << "Song's first line: ";
		GetLineNotWS(firstLine);

		cout << "Tags: ";
		getline(cin, userInput);
		istringstream iSS(userInput);
		while (iSS >> newTag) {
			tags.push_back(newTag);
		}

		Song* songPtr = nullptr;
		songPtr = new Song(tags, name, firstLine);
		songPtrs.push_back(songPtr);
	}
}

void ListSongs(const vector<Song*>& songPtrs) {
	for (int i = 0; i < songPtrs.size(); i++) {
		songPtrs.at(i)->ListSong();
	}
	cout << endl;
}

void AddPlaylist(vector<Playlist>& playlists) {
	string playlistName = "none";

	cout << "Playlist name: ";
	GetLineNotWS(playlistName);
	cout << endl;

	Playlist newPlaylist(playlistName);

	playlists.push_back(newPlaylist);
}

void ListPlaylists(const vector<Playlist>& playlists) {
	for (int i = 0; i < playlists.size(); i++) {
		cout << "  " << i << ": " << playlists.at(i).GetName() << endl;
	}
	cout << endl;
}

void PutSongInPlaylist(vector<Playlist>& playlists, const vector<Song*>& songPtrs) {
	int playlistIndex = 0;
	int songIndex = 0;

	for (int i = 0; i < playlists.size(); i++) {
		cout << "  " << i << ": " << playlists.at(i).GetName() << endl;
	}
	cout << endl;
	cout << "Pick a playlist index number: ";
	cin >> playlistIndex;
	cout << endl;
	for (int i = 0; i < songPtrs.size(); i++) {
		cout << "  " << i << ": " << songPtrs.at(i)->GetName() << endl;
	}
	cout << endl;
	cout << "Pick a song index number: ";
	cin >> songIndex;
	cout << endl;

	playlists.at(playlistIndex).AddSongToPlaylist(songPtrs.at(songIndex));
}

void DeletePlaylist(vector<Playlist>& playlists) {
	int playlistIndex = 0;

	ListPlaylists(playlists);
	cout << "Pick a playlist index number to delete: ";
	cin >> playlistIndex;
	cout << endl;

	playlists.erase(playlists.begin() + playlistIndex);
}

void DeleteSongFromPlaylist(vector<Playlist>& playlists, const vector<Song*>& songPtrs) {
	int playlistIndex = 0;
	int songIndex = 0;

	for (int i = 0; i < playlists.size(); i++) {
		cout << "  " << i << ": " << playlists.at(i).GetName() << endl;
	}
	cout << endl;
	cout << "Pick a playlist index number: ";
	cin >> playlistIndex;
	cout << endl;
	playlists.at(playlistIndex).PrintSongsInPlaylist();
	cout << endl;
	cout << "Pick a song index number to delete: ";
	cin >> songIndex;
	cout << endl;

	playlists.at(playlistIndex).RemoveSongFromPlaylist(songIndex);
}

void DeleteSongFromLibrary(vector<Playlist>& playlists, vector<Song*>& songPtrs) {
	int songIndex = 0;
	string songName = "none";

	for (int i = 0; i < songPtrs.size(); i++) {
		cout << "  " << i << ": " << songPtrs.at(i)->GetName() << endl;
	}
	cout << endl;
	cout << "Pick a song index number: ";
	cin >> songIndex;
	cout << endl;

	songName = songPtrs.at(songIndex)->GetName();

	for (int i = 0; i < playlists.size(); i++) {
		playlists.at(i).FindAndDeleteSong(songName);
	}

	delete songPtrs.at(songIndex); //FREES MEMORY
	songPtrs.erase(songPtrs.begin() + songIndex);
}

int main() {
	string userInput = "none";
	bool continueRunning = true;
	vector<Song*> songPtrs;
	vector<Playlist> playlists;
	int playlistIndex = 0;

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

	while (continueRunning) {
		cout << "Enter your selection now: ";
		cin >> userInput;
		cout << endl;
		if (userInput == "add") {
			AddSong(songPtrs);
		}
		else if (userInput == "list") {
			ListSongs(songPtrs);
		}
		else if (userInput == "addp") {
			AddPlaylist(playlists);
		}
		else if (userInput == "addsp") {
			PutSongInPlaylist(playlists, songPtrs);
		}
		else if (userInput == "listp") {
			ListPlaylists(playlists);
		}
		else if (userInput == "play") {
			ListPlaylists(playlists);
			cout << "Pick a playlist index number: ";
			cin >> playlistIndex;
			playlists.at(playlistIndex).playPlaylist();
		}
		else if (userInput == "delp") {
			DeletePlaylist(playlists);
		}
		else if (userInput == "delsp") {
			DeleteSongFromPlaylist(playlists, songPtrs);
		}
		else if (userInput == "delsl") {
			DeleteSongFromLibrary(playlists, songPtrs);
		}
		else if (userInput == "quit") {
			cout << "Goodbye!" << endl;
			continueRunning = false;
		}
		else {
			PrintMenu();
		}
	}
	
	for (int i = 0; i < songPtrs.size(); i++) { //FREES MEMORY
		delete songPtrs.at(i);
	}

	return 0;
}

/*
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
}*/