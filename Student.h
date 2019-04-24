#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"
using namespace std;

class Student: public Person
{
    public:
        Student();
        Student(int i, string n, string l, string s, double g, int a);//(id,name,level,subject,gpa,advisor)
        ~Student();

        string getLevel();
        void setLevel(string s);

        double getGPA();
        void setGPA(double d);

        int getAdvisor();
        void setAdvisor(int i);

    private:
        string level;
        double gpa;
        int advisor;

};

#endif
