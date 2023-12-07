#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const std::string playlistTitle) {
    std::cout << playlistTitle << " PLAYLIST MENU" << std::endl;
    std::cout << "a - Add song" << std::endl;
    std::cout << "d - Remove song" << std::endl;
    std::cout << "c - Change position of song" << std::endl;
    std::cout << "s - Output songs by specific artist" << std::endl;
    std::cout << "t - Output total time of playlist (in seconds)" << std::endl;
    std::cout << "o - Output full playlist" << std::endl;
    std::cout << "q - Quit" << std::endl;
    std::cout << std::endl;
}

PlaylistNode* ExecuteMenu(char option, std::string playlistTitle, PlaylistNode* headNode) {
    switch (option) {
        case 'a': // Add song
            {
               cin.ignore();
                cout << "ADD SONG" << endl;
                string uniqueID, songName, artistName;
                int songLength;
                
                cout << "Enter song's unique ID:" << endl;
                cin >> uniqueID;
                 
                cout << "Enter song's name:"<< endl;
                cin.ignore(); 
                getline(cin, songName);


                cout << "Enter artist's name:"<< endl;
                getline(cin, artistName);
                  

                cout << "Enter song's length (in seconds):"<< endl <<endl;
                cin >> songLength;
                 
               
               
                PlaylistNode* newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);
                if (headNode == nullptr) {
                    headNode = newNode;
                } else {
                    PlaylistNode* current = headNode;
                    while (current->GetNext() != nullptr) {
                        current = current->GetNext();
                    }
                    current->SetNext(newNode);
                }

            }
            break;

        case 'd': // Remove song
            {
               cout << "REMOVE SONG" << endl;
               string uniqueID;
               cout << "Enter song's unique ID:" << endl;
               cin >> uniqueID ;
               
               headNode = PlaylistNode::RemoveSong(headNode, uniqueID);

            }
            break;

        case 'c': // Change position of song
            {
                std::cout << "CHANGE POSITION OF SONG" << std::endl;
                // Implement the logic to change the position of a song in the playlist
            }
            break;

        case 's': // Output songs by specific artist
{
    std::cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << std::endl;
    std::string artistName;
    std::cout << "Enter artist's name:"<< endl <<endl;
    std::cin.ignore();
    std::getline(std::cin, artistName);

    headNode->OutputSongsByArtist(artistName);
}
break;

        case 't': // Output total time of playlist
    {
        std::cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << std::endl;
        int totalTime = 0;

        PlaylistNode* current = headNode;
        while (current != nullptr) {
            totalTime += current->GetSongLength();
            current = current->GetNext();
        }

        std::cout << "Total time: " << totalTime << " seconds"<< endl<<endl; //<< std::endl;
    }
    break;

        case 'o': // Output full playlist
            std::cout <<endl << playlistTitle << " - OUTPUT FULL PLAYLIST" << std::endl;
            if (headNode == nullptr) {
                std::cout << "Playlist is empty" << std::endl<<endl;
            } else {
                int position = 1;
                PlaylistNode* current = headNode;
                while (current != nullptr) {
                    std::cout << position << "."<<endl;
                    current->PrintPlaylistNode();
                    std::cout << std::endl;
                    current = current->GetNext();
                    position++;
                }
            }
            break;

        case 'q': // Quit
            std::cout << std::endl;
            PlaylistNode::ClearPlaylist(headNode);
            headNode = nullptr;  
            break;

    }

    return headNode; // Return the updated head node
}
int main() {
   std::string playlistTitle;
    std::cout << "Enter playlist's title:" << std::endl;
    cout << endl;
    std::getline(std::cin, playlistTitle);



    PlaylistNode* headNode = nullptr;
    char option;

    do {
        // Display the menu and get user input
        PrintMenu(playlistTitle);
        std::cout << "Choose an option:";
        std::cin >> option;
         
        // Execute the chosen option
        headNode = ExecuteMenu(option, playlistTitle, headNode);

    } while (option != 'q');



    return 0;
}
