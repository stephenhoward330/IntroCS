#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "Song.h"
using namespace std;

class Playlist {
public:
	Playlist(string resName = "none");

	void AddSongToPlaylist(Song* newSong);

	void RemoveSongFromPlaylist(int songIndex);
	void FindAndDeleteSong(string songName);

	string GetName() const;
	int GetNumSongs() const;

	void playPlaylist() const;
	void PrintSongsInPlaylist() const;
private:
	string name;
	vector<Song*> songsInPlaylist;
};

#endif