#include "Music.h"
#include <cstring>
#include <cstdio>

// calls base class constructor to initialize title and year fields
// make sure to alloc memory for char* fields
Music::Music(char title[], int year, char artist[], char publisher[], int duration) : Media(title, year) {
    this->artist = new char[std::strlen(artist) + 1];
    std::strcpy(this->artist, artist);
    this->publisher = new char[std::strlen(publisher) + 1];
    std::strcpy(this->publisher, publisher);
    this->duration = duration;
}

// two things to dealloc
Music::~Music() {
    delete [] artist;
    delete [] publisher;
}

// setters use same method as constructor
// dealloc and realloc to deal with different sizes
void Music::setArtist(char newArtist[]) {
    delete [] artist;
    artist = new char[std::strlen(newArtist) + 1];
    std::strcpy(artist, newArtist);
}

void Music::setPublisher(char newPublisher[]) {
    delete [] publisher;
    publisher = new char[std::strlen(newPublisher) + 1];
    std::strcpy(publisher, newPublisher);
}

void Music::setDuration(int newDuration) {
    duration = newDuration;
}

// getters
char* Music::getArtist() {
    return artist;
}

char* Music::getPublisher() {
    return publisher;
}

int Music::getDuration() {
    return duration;
}

// called by print in main
void Music::print(bool newline) {
    Media::print(false);
    printf("By %s, Prod. %s, %d sec\n", artist, publisher, duration);
}
