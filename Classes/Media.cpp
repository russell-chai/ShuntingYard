#include "Media.h"
#include <cstring>
#include <cstdio> 

Media::Media(char title[], int year) {
    this->title = new char[std::strlen(title + 1)];
    std::strcpy(this->title, title);
    this->year = year;
}

Media::~Media() {
    delete [] title;
}

void Media::setTitle(char newTitle[]) {
    delete [] title;
    title = new char[std::strlen(newTitle) + 1];
    std::strcpy(title, newTitle);
}

void Media::setYear(int newYear) {
    year = newYear;
}

char* Media::getTitle() {
    return title;
}

int Media::getYear() {
    return year;
}

void Media::print(bool newline) {
    printf("%s, %d%s", title, year, newline ? "\n" : ", ");
}
