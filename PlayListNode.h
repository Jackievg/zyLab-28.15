#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H
#pragma once

#include <string>

class PlaylistNode {
public:
    // Default constructor
    PlaylistNode();

    // Parameterized constructor
    PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, int songLength);

    // Accessors
    std::string GetID() const;
    std::string GetSongName() const;
    std::string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;

    // Mutators
    void SetNext(PlaylistNode* nodePtr);
    void InsertAfter(PlaylistNode* nodePtr);

    // Other member functions
    void PrintPlaylistNode() const;
    static void ClearPlaylist(PlaylistNode* headNode);
    static PlaylistNode* RemoveSong(PlaylistNode* headNode, const std::string& uniqueID);
    void OutputSongsByArtist(const std::string& artistName) const;

private:
    std::string uniqueID;
    std::string songName;
    std::string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

#endif  // PLAYLISTNODE_H
