#ifndef FACULTY_H
#define FACUTLY_H

#include <iostream>
#include "Person.h"
using namespace std;

class Faculty: public Person
{
    public:
        Faculty();
        Faculty(int i, string n, string s, string l);
        //~Faculty();

        string getLevel();
        void setLevel(string l);

        int* getAdvisees();
        void addAdvisee(int a);
        bool removeAdvisee(int a);
        int getSizeAdv();

    private:
        string level;
        int *advisees;
        int sizeAdv;
        int numAdv; //keeps track of num advisees
};

#endif
