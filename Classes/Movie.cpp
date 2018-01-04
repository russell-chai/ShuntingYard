#include "Movie.h"
#include <cstring>
#include <cstdio>

// will call base class constructor to initiate title and year fields
Movie::Movie(char title[], int year, char director[], int duration, char rating[]) : Media(title, year) {
    // set director
    this->director = new char[std::strlen(director) + 1];
    std::strcpy(this->director, director);
    // set duration
    this->duration = duration;
    // if rating is valid set it otherwise it's rated G
    if (strcmp(rating, "PG") == 0 || strcmp(rating, "PG-13") == 0 || strcmp(rating, "R") == 0) {
        this->rating = new char[std::strlen(rating) + 1];
        std::strcpy(this->rating, rating);
    } else {
        this->rating = new char[2];
        std::strcpy(this->rating, "G");
    }
}
// will call virtual base destructor as well
Movie::~Movie() {
    delete [] director;
}

// dealloc and realloc memory because it might be different size
void Movie::setDirector(char newDirector[]) {
    delete [] director;
    director = new char[std::strlen(newDirector) + 1];
    std::strcpy(director, newDirector);
}

void Movie::setDuration(int newDuration) {
    duration = newDuration;
}

// same method as in constructor check validity
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

// getters
char* Movie::getDirector() {
    return director;
}

int Movie::getDuration() {
    return duration;
}

char* Movie::getRating() {
    return rating;
}

// called by print in main
// calls base class print and then prints out unique fields appended
void Movie::print(bool newline) {
    Media::print(false);
    printf("Directed by %s, %d min, Rated %s\n", director, duration, rating);
}
