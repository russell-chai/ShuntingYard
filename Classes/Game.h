#include "Media.h"
#ifndef GAME_H_
#define GAME_H_

// extends public members of Media
class Game : public Media {

public:
    // extends Super(char title[], int year);
    // extends ~Super();
    // extends void setTitle(char newTitle[]);
    // extends void setYear(int newYear);
    // extends char* getTitle();
    // extends int getYear();
    Game(char title[], int year, char publisher[], char rating);
    ~Game();
    // setters and getters
    void setPublisher(char newPublisher[]);
    void setRating(char newRating);
    char* getPublisher();
    char getRating();
    void print(bool newline);   

// 2 unique fields publisher and rating
private:
    // extends char* title
    // extends int year
    char* publisher;
    char rating; // C, E, T, M, A
};

#endif
