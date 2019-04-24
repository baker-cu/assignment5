#include <iostream>
#include "Person.h"
using namespace std;

Person::Person()
{
    id = 0;
    name = "";
    subject = "";
}

Person::Person(int i, string n, string s)
{
    id = i;
    name = n;
    subject = s;
}

Person::~Person()
{
    //
}

int Person::getID()
{
    return id;
}

void Person::setID(int i)
{
    id = i;
}

string Person::getName()
{
    return name;
}

void Person::setName(string n)
{
        name = n;
}

string Person::getSubject()
{
    return subject;
}

void Person::setSubject(string s)
{
    subject = s;
}
