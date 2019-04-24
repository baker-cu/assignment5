#include <iostream>
#include "Faculty.h"
using namespace std;

inline Faculty::Faculty():Person()
{
    level = "";
    advisees = new int[10];
    numAdv = 0;
}

inline Faculty::Faculty(int i, string n, string s, string l):Person(i,n,s)
{
    level = l;
    advisees = new int[10];
    numAdv = 0;
}

inline Faculty::~Faculty()
{
    //delete advisees;
}

inline string Faculty::getLevel()
{
    return level;
}

inline void Faculty::setLevel(string l)
{
    level = l;
}

inline int* Faculty::getAdvisees()
{
    return advisees;
}

inline void Faculty::addAdvisee(int a)
{
    //check if advisees is full
    if(numAdv == advisees.size())
    {
        int size = advisees.size();
        //make larger array
        int* temp = new int[size+5]; //temporary pointer to a new array
        //copy all over
        for(int x = 0; x<size; x++)
        {
            temp[x] = advisees[x];
        }
        //insert new advisee
        temp[size+1] = a;
        advisees = temp;
    }
    //else
    else
    {
        //add new advisee
        advisees[numAdv-1] = a;
    }

    numAdv++;
}

inline bool Faculty::removeAdvisee(int a)
{
    //check if advisees is empty

    //check if advisees student is in advisee
        //delete advisee from list
        return true;
    //else
        return false;

    numAdv--;
}
