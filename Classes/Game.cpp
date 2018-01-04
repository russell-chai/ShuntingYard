#include "Game.h"
#include <cstring>
#include <cstdio>

// calls base class constructor to initialize title and year fields
// check validity of rating
// alloc memory for publisher char* field
Game::Game(char title[], int year, char publisher[], char rating) : Media(title, year) {
    this->publisher = new char[std::strlen(publisher) + 1];
    std::strcpy(this->publisher, publisher);
    if (rating == 'C' || rating == 'T' || rating == 'M' || rating == 'A') this->rating = rating;
    else this->rating = 'E';
}

// dealloc publisher along with base class destructor
Game::~Game() {
    delete [] publisher;
}

// dealloc and realloc for new size
// same as in constructor
void Game::setPublisher(char newPublisher[]) {
    delete [] publisher;
    publisher = new char[std::strlen(newPublisher) + 1];
    std::strcpy(publisher, newPublisher);
}

// same method as constructor, check validity otherwise rated E
void Game::setRating(char newRating) {
    if (newRating == 'C' || newRating == 'T' || newRating == 'M' || newRating == 'A') rating = newRating;
    else rating = 'E';
}

// getters
char* Game::getPublisher() {
    return publisher;
}

char Game::getRating() {
    return rating;
}

// called by print in main
void Game::print(bool newline) {
    Media::print(false);
    printf("(c) %s, Rated %c\n", publisher, rating);
}
