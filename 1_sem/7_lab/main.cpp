#include "StudentSecondExams.h"
#include <map>

using namespace std;

int main()
{
    map <pair<int,int>, vector<Student*>> avgGroup;
    vector <Student*> allStudents;
    int n, m;
    cout << "Enter amount of fisrt-term students and amount second-term students: ";
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        char name[1000];
        int course, group, numberGradebook;
        vector <int> marksFirstTerm(4);
        cout << "Enter name, course, group, number of gradebook and marks for first term for " << i+1 \
        <<"th student: ";
        cin >> name >> course >> group >> numberGradebook;
        for(int j=0; j<4; j++)
            cin >> marksFirstTerm[j];
        Student* studentPtr = new StudentFirstExams(name, course, group, numberGradebook, marksFirstTerm);
        avgGroup[{course, group}].push_back(studentPtr);
        allStudents.push_back(studentPtr);
    }
    for(int i=0; i<m; i++)
    {
        char name[1000];
        int course, group, numberGradebook;
        vector <int> marksFirstTerm(4);
        vector <int> marksSecondTerm(5);
        cout << "Enter name, course, group, number of gradebook, marks for first term" \
        << "and marks for second term for " << i+1 <<"th student: ";
        cin >> name >> course >> group >> numberGradebook;
        for(int j=0; j<4; j++)
            cin >> marksFirstTerm[j];
        for(int j=0; j<5; j++)
            cin >> marksSecondTerm[j];
        Student* studentPtr = new StudentSecondExams(name, course, group, numberGradebook,\
        marksFirstTerm,  marksSecondTerm);
        avgGroup[{course, group}].push_back(studentPtr);
        allStudents.push_back(studentPtr);
    }
    for (auto& element : avgGroup)
    {
        double _sum=0;
        for(int i=0; i<element.second.size(); i++)
           for(auto j: dynamic_cast<StudentFirstExams*>(element.second[i])->getMarksFirstExams())
                _sum += j;
        cout << "Avarage mark for " << element.first.first <<" course " << element.first.second\
        << " group after 1 term is " << _sum/element.second.size()/4 << endl;
        double sum = 0;
        for(int i=0; i<element.second.size(); i++)
            if(dynamic_cast<StudentSecondExams*>(element.second[i])!=nullptr)
                sum += dynamic_cast<StudentSecondExams*>(element.second[i])->avgMark();
        cout << "Avarage mark for " << element.first.first <<" course " << element.first.second\
        << " group after 2 terms is " << sum/element.second.size() << endl;
    }
    double avgOfAllStudents = 0;
    for(int i=0; i<allStudents.size(); i++)
        avgOfAllStudents+=allStudents[i]->avgMark();
    cout << "Avarage mark of all students is " << avgOfAllStudents/allStudents.size();
    return 0;
}