#ifndef STUDENT_H
#define STUDENT_H
#pragma once
#include <iostream>

extern int globalId;

class Student
{
public:
    Student(char* name, int course, int group, int numberGradebook);
    Student(const Student &student);
    Student() = delete;
    void setName(char *name);
    char* getName();
    void setCourse(int course);
    int getCourse();
    void setGroup(int group);
    int getGroup();
    int getId();
    virtual double avgMark(){return 0;};
    int getNumberGradebood();
    friend std::ostream& operator <<(std::ostream &out, const Student &student); 
protected:
    const int _id=globalId++;
    char* _name;
    int _course;
    int _group;
    int _numberGradebook;
};

#endif