#include "Media.h"
#ifndef MUSIC_H_
#define MUSIC_H_

// inheritance of public members from Media
class Music : public Media {

public:
    // extends Super(char title[], int year);
    // extends ~Super();
    // extends void setTitle(char newTitle[]);
    // extends void setYear(int newYear);
    // extends char* getTitle();
    // extends int getYear();
    Music(char title[], int year, char artist[], char publisher[], int duration);
    ~Music();

    // setters and getters for each field
    void setArtist(char newArtist[]);
    void setPublisher(char newPublisher[]);
    void setDuration(int newDuration);
    char* getArtist();
    char* getPublisher();
    int getDuration(); 
    void print(bool newline);

// 3 unique fields: artist publisher and duration
private:
    // extends char* title
    // extends int year
    char* artist;
    char* publisher;
    int duration; // in seconds

};

#endif
