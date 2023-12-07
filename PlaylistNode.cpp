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
