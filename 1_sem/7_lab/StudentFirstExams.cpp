#include "StudentFirstExams.h"

StudentFirstExams::StudentFirstExams(char* name, int course, int group, int numberGradebook,\
std::vector <int> &marksFirstExams) : Student(name, course, group, numberGradebook),\
_marksFirstExams(marksFirstExams) {}
StudentFirstExams::StudentFirstExams(const StudentFirstExams &student) : \
Student(student),  _marksFirstExams(student._marksFirstExams){};

std::vector <int> StudentFirstExams::getMarksFirstExams()
{
    return _marksFirstExams;
}

std::ostream& operator <<(std::ostream &out, const StudentFirstExams &student)
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
    return out;    
}

void StudentFirstExams::setMarksFirstExams(std::vector <int> &marksFirstExams)
{
    _marksFirstExams =marksFirstExams;
}

double StudentFirstExams::avgMark()
{
    double sum = 0;
    for (int i=0; i<4; i++)
        sum += _marksFirstExams[i];
    return sum/4;
}