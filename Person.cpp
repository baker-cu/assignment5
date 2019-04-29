#include <iostream>
#include "Person.h"
using namespace std;

inline Person::Person()
{
    id = 0;
    name = "";
    subject = "";
}

inline Person::Person(int i, string n, string s)
{
    id = i;
    name = n;
    subject = s;
}

inline Person::~Person()
{
    //
}

inline int Person::getID()
{
    return id;
}

inline void Person::setID(int i)
{
    id = i;
}

inline string Person::getName()
{
    return name;
}

inline void Person::setName(string n)
{
        name = n;
}

inline string Person::getSubject()
{
    return subject;
}

inline void Person::setSubject(string s)
{
    subject = s;
}
