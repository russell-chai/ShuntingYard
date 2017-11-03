#include "Movie.h"
#include <cstring>
#include <cstdio>

Movie::Movie(char title[], int year, char director[], int duration, char rating[]) : Media(title, year) {
    this->director = new char[std::strlen(director) + 1];
    std::strcpy(this->director, director);
    this->duration = duration;
    if (strcmp(rating, "PG") == 0 || strcmp(rating, "PG-13") == 0 || strcmp(rating, "R") == 0) {
        this->rating = new char[std::strlen(rating) + 1];
        std::strcpy(this->rating, rating);
    } else {
        this->rating = new char[2];
        std::strcpy(this->rating, "G");
    }
}

Movie::~Movie() {
    delete [] director;
}

void Movie::setDirector(char newDirector[]) {
    delete [] director;
    director = new char[std::strlen(newDirector) + 1];
    std::strcpy(director, newDirector);
}

void Movie::setDuration(int newDuration) {
    duration = newDuration;
}

void Movie::setRating(char newRating[]) {
    delete [] rating;
    if (strcmp(newRating, "PG") == 0 || strcmp(newRating, "PG-13") == 0 || strcmp(newRating, "R") == 0) {
        this->rating = new char[std::strlen(newRating) + 1];
        std::strcpy(rating, newRating);
    } else {
        this->rating = new char[2];
        std::strcpy(this->rating, "G");
    }
}

char* Movie::getDirector() {
    return director;
}

int Movie::getDuration() {
    return duration;
}

char* Movie::getRating() {
    return rating;
}

void Movie::print(bool newline) {
    Media::print(false);
    printf("Directed by %s, %d min, Rated %s\n", director, duration, rating);
}
