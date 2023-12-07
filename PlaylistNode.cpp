#include "PlaylistNode.h"
#include <iostream>
using namespace std;


   PlaylistNode::PlaylistNode()
       : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}
   
   
   PlaylistNode::PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, int songLength)
       : uniqueID(std::move(uniqueID)), songName(std::move(songName)), artistName(std::move(artistName)),
         songLength(songLength), nextNodePtr(nullptr) {}
   
   
   std::string PlaylistNode::GetID() const {
       return uniqueID;
         }
   
   std::string PlaylistNode::GetSongName() const {
       return songName;
   }
   
   std::string PlaylistNode::GetArtistName() const {
       return artistName;
            }
   
   int PlaylistNode::GetSongLength() const {
       return songLength;
         }
   
   PlaylistNode* PlaylistNode::GetNext() const {
       return nextNodePtr;
         }
   
   // Mutators
   void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
       nextNodePtr = nodePtr;
       }
   
   void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
       nodePtr->nextNodePtr = this->nextNodePtr;
       this->nextNodePtr = nodePtr;
      }
   void PlaylistNode::ClearPlaylist(PlaylistNode* headNode) {
       PlaylistNode* current = headNode;
       while (current != nullptr) {
           PlaylistNode* next = current->GetNext();
           delete current; // Free memory for the current node
           current = next;
    }
}
PlaylistNode* PlaylistNode::RemoveSong(PlaylistNode* headNode, const std::string& uniqueID) {
    PlaylistNode* current = headNode;
    PlaylistNode* previous = nullptr;

    // Traverse the linked list to find the node with the specified uniqueID
    while (current != nullptr && current->GetID() != uniqueID) {
        previous = current;
        current = current->GetNext();
    }

    // If the node with the specified uniqueID is found
    if (current != nullptr) {
        // Print the information before removing the node
        cout << "\"" << current->GetSongName() << "\" removed." << endl<< endl;

        // Update the pointers to remove the node
        if (previous != nullptr) {
            previous->SetNext(current->GetNext());
        } else {
            // If the node to be removed is the head, update the head
            headNode = current->GetNext();
        }

        // Free the memory of the removed node
        delete current;
    } else {
        cout << "Song with ID \"" << uniqueID << "\" not found." << endl;
    }

    return headNode;  // Return the updated headNode
}
void PlaylistNode::OutputSongsByArtist(const std::string& artistName) const {
    const PlaylistNode* current = this;
    int position = 1;

    while (current != nullptr) {
        if (current->GetArtistName() == artistName) {
            std::cout << position << ".\n";
            current->PrintPlaylistNode();
            std::cout << std::endl;
        }

        current = current->GetNext();
        position++;
    }
}
// Other member functions
void PlaylistNode::PrintPlaylistNode() const {
    std::cout << "Unique ID: " << GetID() << std::endl;
    std::cout << "Song Name: " << GetSongName() << std::endl;
    std::cout << "Artist Name: " << GetArtistName() << std::endl;
    std::cout << "Song Length (in seconds): " << GetSongLength() << std::endl; //<< std::endl;
}
