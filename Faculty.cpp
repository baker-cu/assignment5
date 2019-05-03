#ifndef FACULTY_C
#define FACULTY_C

#include <iostream>
#include "Faculty.h"
using namespace std;

inline Faculty::Faculty():Person()
{
    level = "";
    advisees = new int[10];
    sizeAdv = 10;
    numAdv = 0;
}

inline Faculty::Faculty(int i, string n, string s, string l):Person(i,n,s)
{
    level = l;
    advisees = new int[10];
    sizeAdv = 10;
    numAdv = 0;
}

/*inline Faculty::~Faculty()
{
    delete [] advisees;
}*/

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
    if(numAdv == sizeAdv)
    {
        int size = sizeAdv;
        //make larger array
        int* temp = new int[sizeAdv+5]; //temporary pointer to a new array
        sizeAdv += 5;
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
    if(numAdv == 0)
        return false;

    //check if advisees student is in advisee
    int temp[sizeAdv];
    for(int x = -1; x<numAdv; x++)
    {
        //delete advisee from list
        if (advisees[x] == a)//x=index of int to delete

            for(int y = -1; y<sizeAdv+1; y++)
            {
                if(y==x)
                    y++;
                temp[y] = advisees[y];
            }
            return true;
    }
    return false;

    numAdv--;
}

inline int Faculty::getSizeAdv()
{
    return sizeAdv;
}

inline int Faculty::getNumAdv()
{
    return numAdv;
}

#endif
