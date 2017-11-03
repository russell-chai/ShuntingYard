#include "Game.h"
#include <cstring>
#include <cstdio>

Game::Game(char title[], int year, char publisher[], char rating) : Media(title, year) {
    this->publisher = new char[std::strlen(publisher) + 1];
    std::strcpy(this->publisher, publisher);
    if (rating == 'C' || rating == 'T' || rating == 'M' || rating == 'A') this->rating = rating;
    else this->rating = 'E';
}

Game::~Game() {
    delete [] publisher;
}

void Game::setPublisher(char newPublisher[]) {
    delete [] publisher;
    publisher = new char[std::strlen(newPublisher) + 1];
    std::strcpy(publisher, newPublisher);
}

void Game::setRating(char newRating) {
    if (newRating == 'C' || newRating == 'T' || newRating == 'M' || newRating == 'A') rating = newRating;
    else rating = 'E';
}

char* Game::getPublisher() {
    return publisher;
}

char Game::getRating() {
    return rating;
}

void Game::print(bool newline) {
    Media::print(false);
    printf("(c) %s, Rated %c\n", publisher, rating);
}
