#ifndef CIRCULAR_LL_H
#define CIRCULAR_LL_H

#include <iostream>
#include <string>

template <typename T>
class SingleSongNode {
public:
    T SongTitle;
    SingleSongNode<T>* next;
    SingleSongNode<T>* prev;

    SingleSongNode(T title) {
        SongTitle = title;
        next = nullptr;
        prev = nullptr;
    }
};

// Add Songs
template <typename T>
void addSong(T newTitle, SingleSongNode<T>*& PlayListHead) {

    SingleSongNode<T>* newNode = new SingleSongNode<T>(newTitle);

   // this checks if the playlist is empty, then the new song will point to itself
    if (PlayListHead == nullptr) {
        PlayListHead = newNode;
        PlayListHead->next = PlayListHead;
        PlayListHead->prev = PlayListHead;
        std::cout << "Add initial song: " << newTitle << "\n";
        return;
    }

    // Insert at end (circular)
    SingleSongNode<T>* tail = PlayListHead->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = PlayListHead;
    PlayListHead->prev = newNode;

    std::cout << "Added song: " << newTitle << "\n";
}

// Next Song
template <typename T>
void NextSong(SingleSongNode<T>*& PlayListHead) {
    if (PlayListHead == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    PlayListHead = PlayListHead->next; // this checks if the playlist is empty, then the new song will point to itself
    std::cout << "Now playing: " << PlayListHead->SongTitle << "\n";
}

// Prev Song | same function as next song but it moves to the previous song in the playlist
template <typename T>
void PrevSong(SingleSongNode<T>*& PlayListHead) {
    if (PlayListHead == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }
    PlayListHead = PlayListHead->prev; //responsible for moving to the previous song in the playlist
    std::cout << "Now playing: " << PlayListHead->SongTitle << "\n";
}

// Play All
template <typename T>
void PlayAll(SingleSongNode<T>*& PlayListHead) {
    if (PlayListHead == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    SingleSongNode<T>* current = PlayListHead; //creates a pointer for the head of the playlist and traverse each node to find songs

    do {
        std::cout << "Now playing: " << current->SongTitle << "\n";
        current = current->next;
    } while (current != PlayListHead);
}

// Delete Song
template <typename T>
void DeleteSong(T title, SingleSongNode<T>*& PlayListHead) {

    if (PlayListHead == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    SingleSongNode<T>* current = PlayListHead;

    do {
        if (current->SongTitle == title) {

            // if only one node
            if (current->next == current) {
                delete current;
                PlayListHead = nullptr;
                std::cout << "Deleted song: " << title << "\n";
                return;
            }

            // Removing of node
            current->prev->next = current->next;
            current->next->prev = current->prev;

            // Deleting head
            if (current == PlayListHead) {
                PlayListHead = current->next;
            }

            delete current;
            std::cout << "Deleted song: " << title << "\n";
            return;
        }

        current = current->next;

    } while (current != PlayListHead);

    std::cout << "Song not found.\n";
}

#endif