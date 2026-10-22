#include <iostream>
#include <string>
#include "circular_ll.h"

int main() {

    CircularList<std::string>* playlist = nullptr;

    // Create the playlist
    insertSong(std::string("Blue"), &playlist);
    insertSong(std::string("Yellow"), &playlist);
    insertSong(std::string("Perfect"), &playlist);

    std::cout << "=== Original Playlist ===\n";
    playSongs(playlist);

    // Add a new song
    std::cout << "\n=== Add Song ===\n";
    insertSong(std::string("Photograph"), &playlist);
    playSongs(playlist);

    // Remove a song
    std::cout << "\n=== Remove Song ===\n";
    removeSong(std::string("Yellow"), &playlist);
    playSongs(playlist);

    // Demonstrate next and previous
    CircularList<std::string>* current = playlist;

    std::cout << "\n=== Music Playlist ===\n";

    std::cout << "Current Song : " << current->song << std::endl;

    current = nextSong(current);
    std::cout << "Next Song    : " << current->song << std::endl;

    current = nextSong(current);
    std::cout << "Next Song    : " << current->song << std::endl;

    current = previousSong(playlist, current);
    std::cout << "Previous Song: " << current->song << std::endl;

    current = previousSong(playlist, current);
    std::cout << "Previous Song: " << current->song << std::endl;

    return 0;
}