#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

Playlist::Playlist (string resName) {
	name = resName;
}

string Playlist::GetName() const {
	return name;
}

int Playlist::GetNumSongs() const {
	return songsInPlaylist.size();
}

void Playlist::AddSongToPlaylist(Song* newSong) {
	songsInPlaylist.push_back(newSong);
}

void Playlist::RemoveSongFromPlaylist(int songIndex) {
	songsInPlaylist.erase(songsInPlaylist.begin() + songIndex);
}

void Playlist::playPlaylist() const {
	cout << "Playing first lines of playlist: " << name << endl;
	for (int i = 0; i < songsInPlaylist.size(); i++) {
		cout << songsInPlaylist.at(i)->GetFirstLine() << endl;
		songsInPlaylist.at(i)->IncrementNumPlays();
	}
	cout << endl;
}

void Playlist::FindAndDeleteSong(string songName) {
	for (int i = 0; i < songsInPlaylist.size(); i++) {
		if (songsInPlaylist.at(i)->GetName() == songName) {
			songsInPlaylist.erase(songsInPlaylist.begin() + i);
		}
	}
}

void Playlist::PrintSongsInPlaylist() const {
	for (int i = 0; i < songsInPlaylist.size(); i++) {
		cout << "  " << i << ": " << songsInPlaylist.at(i)->GetName() << endl;
	}
}