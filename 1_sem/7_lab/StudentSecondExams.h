#ifndef STUDENTSE_H
#define STUDENTSE_H
#pragma once
#include "StudentFirstExams.h"
#include <vector>

class StudentSecondExams: public StudentFirstExams
{
    public:
    StudentSecondExams(char* name, int course, int group, int numberGradebook,\
    std::vector <int> marksFirstExams, std::vector <int> marksSecondExams);
    StudentSecondExams(const StudentSecondExams &student);
    StudentSecondExams() = delete;
    std::vector <int> getMarksSecondExams();
    friend std::ostream& operator <<(std::ostream &out, const StudentSecondExams &student); 
    void setMarksSecondExams(std::vector <int> &marksSecondExams);
    double avgMark() override;
    private:
    std::vector <int> _marksSecondExams = {0, 0, 0, 0, 0};
};

#endif