#include <iostream>
#include "Student.h"

using namespace std;

inline Student::Student():Person()
{
    level = "";
    gpa = 0.0;
    advisor = 0;
}

inline Student::Student(int i, string n, string l, string s, double g, int a):Person(i,n,s)
{
    level = l;
    gpa = g;
    advisor = a;
}

inline Student::~Student()
{
    //
}

inline string Student::getLevel()
{
    return level;
}

inline void Student::setLevel(string s)
{
    level = s;
}

inline double Student::getGPA()
{
    return gpa;
}

inline void Student::setGPA(double d)
{
    gpa = d;
}

inline int Student::getAdvisor()
{
    return advisor;
}

inline void Student::setAdvisor(int i)
{
    advisor = i;
}
