#include "Student.h"
#include <cstring>

int globalId(0);

Student::Student(char* name, int course, int group, int numberGradebook) : _course(course), _group(group),\
_numberGradebook(numberGradebook)
{
    _name = new char[strlen(name)];
    strcpy(_name, name);
}

Student::Student(const Student &student) : _course(student._course), _group(student._group),\
_numberGradebook(student._numberGradebook)
{
    _name = new char[strlen(student._name)];
    strcpy(_name, student._name);
}

void Student::setName(char *name)
{
    _name = new char[strlen(name)];
    strcpy(_name, name);
}
char* Student::getName()
{
    char* name = new char[strlen(_name)];
    strcpy(name, _name);
    return name;
}

void Student::setCourse(int course)
{
    _course=course;
}

int Student::getCourse()
{
    return _course;
}

void Student::setGroup(int group)
{
    _group=group;
}

int Student::getGroup()
{
    return _group;
}

int Student::getId()
{
    return _id;
}

int Student::getNumberGradebood()
{
    return _numberGradebook;
}

std::ostream& operator <<(std::ostream &out, const Student &student)
{
    out << "Name: " << student._name << std::endl;
    out << "Course: " << student._course << std::endl;
    out << "Group: " << student._group << std::endl;
    out << "Number of Gradebook: " << student._numberGradebook << std::endl;
    out << "ID: " << student._id << std::endl;
    return out;
}