#include "Music.h"
#include <cstring>
#include <cstdio>

Music::Music(char title[], int year, char artist[], char publisher[], int duration) : Media(title, year) {
    this->artist = new char[std::strlen(artist) + 1];
    std::strcpy(this->artist, artist);
    this->publisher = new char[std::strlen(publisher) + 1];
    std::strcpy(this->publisher, publisher);
    this->duration = duration;
}

Music::~Music() {
    delete [] artist;
    delete [] publisher;
}

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

char* Music::getArtist() {
    return artist;
}

char* Music::getPublisher() {
    return publisher;
}

int Music::getDuration() {
    return duration;
}

void Music::print(bool newline) {
    Media::print(false);
    printf("By %s, Prod. %s, %d sec\n", artist, publisher, duration);
}
