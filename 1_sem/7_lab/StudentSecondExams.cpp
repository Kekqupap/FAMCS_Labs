#include "StudentSecondExams.h"

StudentSecondExams::StudentSecondExams(char* name, int course, int group, int numberGradebook,\
std::vector <int> marksFirstExams, std::vector <int> marksSecondExams): StudentFirstExams(name, course, group, \
numberGradebook, marksFirstExams), _marksSecondExams(marksSecondExams) {}

StudentSecondExams::StudentSecondExams(const StudentSecondExams &student) : StudentFirstExams(student), \
_marksSecondExams(student._marksSecondExams) {}

std::vector <int> StudentSecondExams::getMarksSecondExams()
{
    return _marksSecondExams;
}
std::ostream& operator <<(std::ostream &out, const StudentSecondExams &student)
{
    out << "Name: " << student._name << std::endl;
    out << "Course: " << student._course << std::endl;
    out << "Group: " << student._group << std::endl;
    out << "Number of Gradebook: " << student._numberGradebook << std::endl;
    out << "ID: " << student._id << std::endl;
    out << "Marks for first term: ";
    for (int i=0; i<4; i++)
        out << student._marksFirstExams[i] << ' ';
    out << std::endl;
        out << "Marks for second term: ";
    for (int i=0; i<5; i++)
        out << student._marksSecondExams[i] << ' ';
    out << std::endl;
    return out;        
}

void StudentSecondExams::setMarksSecondExams(std::vector <int> &marksSecondExams)
{
    _marksSecondExams=marksSecondExams;
}

double StudentSecondExams::avgMark()
{
    double sum = 0;
    for (int i=0; i<4; i++)
        sum += _marksFirstExams[i];
    for (int i=0; i<5; i++)
        sum += _marksSecondExams[i];
    return sum/9;    
}