#ifndef STUBST_H
#define STUBST_H

#include <iostream>
#include "BST.h"
#include "Student.cpp"

using namespace std;

class StuBST: public BST
{
    public:
        void insert(Student p);
        bool deleteR(int k);

};

#endif
