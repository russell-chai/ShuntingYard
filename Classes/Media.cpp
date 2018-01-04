#include "Media.h"
#include <cstring>
#include <cstdio> 

// sets title and year when object is made
Media::Media(char title[], int year) {
    this->title = new char[std::strlen(title + 1)];
    std::strcpy(this->title, title);
    this->year = year;
}

// only allocated field is title
// delete when object is destroyed
// to prevent memory leak
Media::~Media() {
    delete [] title;
}

// two setters in case fields need to be changed
void Media::setTitle(char newTitle[]) {
    delete [] title;
    title = new char[std::strlen(newTitle) + 1];
    std::strcpy(title, newTitle);
}

void Media::setYear(int newYear) {
    year = newYear;
}

// two getters in case fields need to be returned
char* Media::getTitle() {
    return title;
}

int Media::getYear() {
    return year;
}

// used in print function in main
void Media::print(bool newline) {
    printf("%s, %d%s", title, year, newline ? "\n" : ", ");
}
