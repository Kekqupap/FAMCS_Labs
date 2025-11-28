#ifndef STUDENTFE_H
#define STUDENTFE_H
#pragma once
#include "Student.h"
#include <vector>

class StudentFirstExams: public Student
{
    public:
    StudentFirstExams(char* name, int course, int group, int numberGradebook, std::vector <int> &marksFirstExams);
    StudentFirstExams(const StudentFirstExams &student);
    StudentFirstExams() = delete;
    std::vector <int> getMarksFirstExams();
    friend std::ostream& operator <<(std::ostream &out, const StudentFirstExams &student); 
    void setMarksFirstExams(std::vector <int> &marksFirstExams);
    void setMarksFirstExams(int firstEx, int secondEx, int thirdEx, int fourthEx);
    virtual double avgMark() override;
    protected:
    std::vector <int> _marksFirstExams = {0, 0, 0, 0};
};

#endif