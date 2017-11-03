#ifndef MEDIA_H_
#define MEDIA_H_

class Media {

public:
    Media(char title[], int year);
    virtual ~Media();
    void setTitle(char newTitle[]);
    void setYear(int newYear);
    char* getTitle();
    int getYear();
    virtual void print(bool newline);

private:
    char* title;
    int year;

};

#endif
