#include "Media.h"
#ifndef MOVIE_H_
#define MOVIE_H_

class Movie : public Media {

public:
    // extends Super(char title[], int year);
    // extends ~Super();
    // extends void setTitle(char newTitle[]);
    // extends void setYear(int newYear);
    // extends char* getTitle();
    // extends int getYear();
    Movie(char title[], int year, char director[], int duration, char rating[]);
    ~Movie();
    
    // setters and getters for each field
    void setDirector(char newDirector[]);
    void setDuration(int newDuration);
    void setRating(char newRating[]);
    char* getDirector();
    int getDuration();
    char* getRating(); 
    void print(bool newline);    

// 3 unique fields: director duration and rating
private:
    // extends char* title
    // extends int year
    char* director;
    int duration; // in minutes 
    char* rating; // G, PG, PG-13, R
};

#endif
