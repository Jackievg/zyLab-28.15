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
