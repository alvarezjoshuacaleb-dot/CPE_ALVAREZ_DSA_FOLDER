#ifndef CIRCULAR_LL_H
#define CIRCULAR_LL_H

#include <iostream>
#include <string>

template <typename T>
class CircularList {
public:
    T song;
    CircularList<T>* next = nullptr;
};

// Add a song to the playlist
template <typename T>
void insertSong(T newSong, CircularList<T>** head) {

    CircularList<T>* newNode = new CircularList<T>;
    newNode->song = newSong;

    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    CircularList<T>* temp = *head;

    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

// Remove a song from the playlist
template <typename T>
void removeSong(T targetSong, CircularList<T>** head) {

    if (*head == nullptr) {
        return;
    }

    CircularList<T>* current = *head;
    CircularList<T>* previous = nullptr;

do {

    if (current->song == targetSong) {

        if (previous == nullptr) {

            if (current->next == *head) {
                    delete current;
                    *head = nullptr;
                    return;
                }

                CircularList<T>* last = *head;

                while (last->next != *head) {
                    last = last->next;
                }

                *head = current->next;
                last->next = *head;
            }

            else {
                previous->next = current->next;
            }

            delete current;
            return;
        }

        previous = current;
        current = current->next;

    } while (current != *head);

    std::cout << "Song not found." << std::endl;
}

// Play all songs
template <typename T>
void playSongs(CircularList<T>* head) {

    if (head == nullptr) {
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    CircularList<T>* current = head;

    std::cout << "Now Playing Playlist:" << std::endl;

    do {
        std::cout << current->song << std::endl;
        current = current->next;
    } while (current != head);
}

// Next song
template <typename T>
CircularList<T>* nextSong(CircularList<T>* current) {

    if (current != nullptr)
        return current->next;

    return nullptr;
}

// Previous song
template <typename T>
CircularList<T>* previousSong(CircularList<T>* head, CircularList<T>* current) {

    if (head == nullptr || current == nullptr)
        return nullptr;

    CircularList<T>* temp = head;

    while (temp->next != current) {
        temp = temp->next;
    }

    return temp;
}

#endif