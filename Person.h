#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person
{
    public:
        Person();
        ~Person();
        Person(int i, string n, string s);

        int getID();
        void setID(int i);
        string getName();
        void setName(string n);
        string getSubject();
        void setSubject(string s);

    protected:
        int id;
        string name;
        string subject;

};

#endif
