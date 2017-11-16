#ifndef MEDIA_H_
#define MEDIA_H_

class Media {

public:
    // constructor will be called in all
    // derived classes
    Media(char title[], int year);
    // virtual destructor allows derived
    // classes to implement base destructor
    virtual ~Media();
    void setTitle(char newTitle[]);
    void setYear(int newYear);
    char* getTitle();
    int getYear();
    virtual void print(bool newline);

private: // inherited to all derived classes
    char* title;
    int year;

};

#endif
