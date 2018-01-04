#ifndef STUDENT_H_
#define STUDENT_H_

class Student {

public:
    Student(char name[], int id, float gpa);
    ~Student(); // dealloc name
    char* getName();
    int getID();
    float getGPA();
    // don't need setters for this project

private:
    char* name;
    int id;
    float gpa;

};

#endif
