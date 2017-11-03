#include "Media.h"
#ifndef MUSIC_H_
#define MUSIC_H_

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
    void setArtist(char newArtist[]);
    void setPublisher(char newPublisher[]);
    void setDuration(int newDuration);
    char* getArtist();
    char* getPublisher();
    int getDuration(); 
    void print(bool newline);

private:
    // extends char* title
    // extends int year
    char* artist;
    char* publisher;
    int duration; // in seconds

};

#endif
